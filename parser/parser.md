# 语法分析部分说明
## parser.y文件注意事项
+ parser.y文件时bison工具语法分析的规则源文件，由parser.y文件生成parser.tab.h头文件和语法分析器文件parser.tab.c。语法分析器提供的函数接口为yyparse()。在parser.y的主函数中，调用yyparse()函数，接受词法分析yylex()函数提供的token进行语法分析。
+ bison采用的是LALR(1)分析方法，故在语法分析时不需要考虑左递归和消除回溯的问题。
+ %{ ... %} 中的 C 代码被直接复制到生成的 parser.tab.c。%code requires { ... } 内容会被写入到生成的 parser.tab.h 的开头（在 union/YYSTYPE 之前）；任何在 prologue 之外直接写的 C 声明通常不会以你期望的方式出现在生成的文件里。
+ 在增加语法规则中，如果对某个非终结符号只是定义，但是没有修改或者说增加前面规则对该非终结符的运用则会报错。
+ 在语法分析过程中，根据名称能辨别是表示类型的关键字还是变量的值本身
+ 语法分析（词法识别错误时）有可能是规则的定义所指的内容有冲突。比如理所当然把”on”视为IDENTIFIER，而“on”，作为一个关键字有单独的返回，故不能视为IDENTIFIER
+ 一个非终结符有多个候选表达式时，动作的最后要打分号。没有分支则不需要打分号。


## 代码有待优化的地方
+ 对于一个非终结符的所有分支执行相同的动作模式有没有简洁的代码写法，不用一个一个写

## 以及测试成功的非终结符推导规则
+ day,
+ days,
+ dayList,
+ timeCondition,
+ ifStatement
+ expression
+ WhileStatement
+ ForStatement
+ range
+ condition
+ switch
+ number
+ status
+ action
+ state
+ stateList
+ rule
+ ruleList
+ primary
+ variableAssignment
+ variableAssignmentList
+ idnetifierList
+ valueType
+ variableDeclaration
+ variableDeclarationList
+ deviceType
+ deviceDeclaration
+ deviceDeclarationList
+ program