#  DSL编译项目指导
## 克隆项目
利用vscode,使用`git clone https://github.com/shijiandeliushi/DSL-compile.git`命令克隆项目，执行`git fetch`获取项目的所有分支（main和DSL-test），再执行`git checkout DSL-
test`切换目前工作区的分支到DSL-test分支，以后就编辑这个分支。
## 项目推送准备
为了三个人写的代码项目可以共享，大家创建一个github账号，把创建账户的邮箱发给我，我给你发送授权邀请，然后你同意。授权成功之后就可以用vscode登陆账号进行推送，实现项目仓库共享，用`git push origin DSL-test`命令推送
## 项目更新获取
先用`git fetch`,然后用`git checkout DSL-test`实现分支更新。可以用`git branch`来查看本地的分支以及当前工作区的分支。
## 后续项目进行
后续我们就用这种方式来写代码，完成项目
## 目前进度
目前大家克隆之后可以看见一个用于语法分析的文件夹，里面有.md说明文件（使用预览），对使用flex产生语法分析器作了一个说明，后面针对我们的DSL来写代码。