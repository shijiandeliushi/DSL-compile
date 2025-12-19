# flex源文件
对源文件进行扫描之后自动生成词法分析函数 int yylex(),并输入到lex.yy.c文件中。
fex的输入文件由3段组成，用一行中只有%%来分隔；
```
定义: definition
%%
规则: rules
%%
用户代码：code
```

## 定义部分（其中定义有变量声明，正则表达式声明）：
   ### 变量声明
   同c ++
   ### 表达式声明
   ```
   表达式名称+表达式
   ```

## 规则部分
   一个规则一行，格式为
   ```
   正则表达式{动作函数}
   ```
   下面是两个例子：
   ```
   %{
	#include<stdio.h>
	#include<stdlib.h>
	int line=1;
%}

DIGIT [0-9]
OINTEGER [1-9]{DIGIT}*

%%
\n {++line;}
{DIGIT} {printf("line%d:(integer, %s)\n",line,yytext);} 
{OINTEGER} {printf("line%d:(integer, %s)\n",line,yytext);} 
. {}
[ \t]+ {}

%%
int main(){
	yyin=fopen("F:/data.txt","r");
	yylex();
	return 0;
}
int yywrap(){
	return 1;
}

```
```
%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	int line=1;
%}
LETTER [a-zA-Z]
ID ({LETTER}|_)({LETTER}|_|{DIGIT})* 
OPT ("+"|"-"|"*"|"/"|"+="|"-="|"*="|"/="|">="|"<="|"=="|">"|"<"|"="|"++"|"--") 
BRACKET ("("|")"|"["|"]"|"{"|"}"|";"|","|"\'"|"\""|"#") 
DIGIT [0-9]
OINTEGER [1-9]{DIGIT}*
INTEGER ("+"|"-")?{OINTEGER}
DECIMAL {INTEGER}(.{OINTEGER})
FLOAT ([0-9])*+[.]([0-9])*+[Ee]([+-]?[0-9]([0-9])*|[0])
ERROEFLOAT ([0-9])*+[.](0-9)*+("E"|"e")
TYPE void|int|double|char
KEYWORD if|else|do|while|for|scanf|printf|sqrt|abs|main|return|float
TYPEIDENTIFY %d|%c|%s|%f|&{ID}
SGPS \/\/.*
DBPS \/\*(.|\n)*\*\/ 

%%
\n {++line;}
{TYPE} {printf("line%d:(type, %s)\n",line,yytext);}
{KEYWORD} {printf("line%d:(keyword, %s)\n",line,yytext);}
{DIGIT} {printf("line%d:(integer, %s)\n",line,yytext);} 
{OINTEGER} {printf("line%d:(integer, %s)\n",line,yytext);} 
{ID} {printf("line%d:(identify, %s)\n",line,yytext);} 
{BRACKET} {printf("line%d:(bracket, %s)\n",line,yytext);} 
{OPT} {printf("line%d:(OPT, %s)\n",line,yytext);}
{INTEGER} {printf("line%d:(integer, %s)\n",line,yytext);}
{DECIMAL} {printf("line%d:(decimal, %s)\n",line,yytext);}
{FLOAT} {printf("line%d:(float, %s)\n",line,yytext);}
{TYPEIDENTIFY} {printf("line%d:(typeidentify, %s)\n",line,yytext);}
{ERROEFLOAT} {printf("ERROEFLOAT\n");}
({SGPS}|{DBPS}) {}
. {}
[ \t]+ {}

%%
int main(){
	yyin=fopen("F:/data.txt","r");
	yylex();
	return 0;
}
int yywrap(){
	return 1;
}

```
测试用例如下：
```
int main(){

    int a = 10;

    double b = -20.9;

    if(a<=b)        

    a+=b;

    return a;
}
```
测试结果如下：
   ![alt text](image.png)
   ## 用户代码部分

   用户代码部分可以包含C/C++代码，这些代码在词法分析过程中是不处理的，只有在词法分析结束后才会执行。  

   ## 实现Homelang DSL
   根据计划书中的定义在lexer.l中修改代码，与Homelang的词法分析相匹配。可以根据上面的例子的代码框架来实现，然后用测试用例来测试，只进行进行打印，看词法分析是否正确。
   然后可以进一步在动作中完善相应操作，为后面的语法分析实现相关复制等等。
   ### 环境配置
   在github上下载[win_flex_bison.zip](https://github.com/lexxmark/winflexbison/releases/download/v2.5.25/win_flex_bison-2.5.25.zip),然后解压放到一个目录下，再将文件夹所在目录添加到Path环境变量中，例如`D:\win_flex_bison-2.5.25`。然后在终端中运行`win_flex --version`,如果能看到版本号，说明成功，可能在vscode中运行检测不到命令，将vscode关闭后重启即可，实在不行可以重启电脑试试。
   ### 一些注意事项
   + 删除`#include "parser.tab.h"`,这是与后面语法分析共同使用时才用得到，单纯的词法分析用不到。
   + 源语言（Homelang）的输入文件打开地址为`D:/input.txt`中，不要放到更深的目录中，否则在运行时可能会卡住，没有结果。
   + 修改好lexer.l文件后，在lexer.l文件所在目录下运行`win_flex lexer.l`，会生成lex.yy.c文件，然后运行`gcc lex.yy.c -o lex.yy.exe`生成lex.yy.exe文件，然后运行`lex.yy.exe`即可得到结果。
   + parser目录是语法分析，暂时不管。
   + 还可能有些我没遇到的问题，可以随时来问我。

## lexer.l文件修改
 ### 12.17晚上修改内容
  + 将`LIGHT`、`AIR-CONDITIONER`、`WATER-HEATER`、`TELEVISION`、`WASHER`、`FRIDGE`、`ELECTRIC-FAN`的类型定义为关键字。
  + 所有的以`"`开头和结尾的单词都被识别为string 类型，除了string（字符串）类型，其余源代码均不使用`"`。
  + 所有变量的定义不允许使用连字符`-`，可以使用下划线`_`。
  + 将`true`、`false`定义为boolean类型，将`on`、`off`定义为state类型，将`mon`、`tue`、`wed`、`thu`、`fri`、`sat`、`sun`周日期表示定义为date类型，在语句`day of week in [...]`中，将`week`,`in`定义为关键字。
  + 以上改动的词法识别测试均已成功
  + 变量声明只能用identify类型，不能用其他类型