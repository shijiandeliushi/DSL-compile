# 构建运行整个项目的命令行集合
## 词法和语法分析的联合运行
+ 从DSL-compile目录开始执行

+ `& win_bison -d parser\parser.y -o parser\parser.tab.c`

+ `cd lexer/src`

+ `win_flex lexer.l` 
+ `cd ..`
+ `cd ..`

+ `& gcc parser\parser.tab.c lexer\src\lex.yy.c parser\ast.c parser\symbol.c parser\semantic.c codegen\codegen.c -Iparser -o dsl.exe`  （相对路径不用打引号，gcc命令-o后面是编译生成的文件名，可能也是指定的路径，但只会创建最后一个可执行文件，不会创建目录）
+ `.\dsl.exe`


+ 提示：在cmd中不需要加&，而在powershell中则需要加&