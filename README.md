# minishell

Usefull doc : 
- https://github.com/Swoorup/mysh
- https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf
- https://web.mit.edu/gnu/doc/html/rlman_2.html

For parsing a split should do the work, and a array of struct where each one contain the cmd id, flags, redirect or no (bolean) and potential input/output files path :
 - using split with space will create some "artefacts" like a lone pipe, we can use those to check what's part of the same cmd.
 - the data will need to be sorted and cleaned to be usable. any non-builtin function will need to have its name added to the relevant path. Pipex already have an algo for that.

we need to redirect signals like ctrl-d  to our own functions using signal() ==> Check 


for the non-builtin functions, we can simply reuse pipex as a base to execute them (need tweaking but still a good base)

need struct for the redir fds and back up 
each command has its own struct and they are connected through a linked list. Each command is linked to a t_redir struct for the fds.
each redir struct has 2 element: backup fd and new replaced fd.ß
each command has its own pipe[2] array to conserve the fds.

Piping reworked for the structs and consistency through the different levels of the executable.
Need to work on redirections for files.