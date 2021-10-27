# minishell

Usefull doc : 
- https://github.com/Swoorup/mysh
- https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf

For parsing a split should do the work, and a array of struct where each one contain the cmd id, flags, redirect or no (bolean) and potential input file path :
 - using split with space will create some "artefacts" like a lone pipe, we will need to parse the split again to get rid of those

we need to redirect signals like ctrl-d  to our own functions

for the non-builtin functions, we can simply reuse pipex as a base to execute them (need tweaking but still a good base)
