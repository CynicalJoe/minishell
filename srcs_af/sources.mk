
SOURCES += builtin/cd.c
SOURCES += builtin/echo.c
SOURCES += builtin/env.c
SOURCES += builtin/export.c
SOURCES += builtin/pwd.c
SOURCES += builtin/unset.c
SOURCES += builtin/exit.c
SOURCES += builtin/get_builtin.c
SOURCES += cmd/cmd_container.c
SOURCES += cmd/cmds.c
SOURCES += cmd/get_cmd_size.c
SOURCES += cmd/next_cmd.c
SOURCES += execute/check_path.c

#SOURCES += execute/execute_command.c
#SOURCES += execute/execute_program.c

SOURCES += execute/parse_cmd.c
SOURCES += execute/process_utils.c
SOURCES += parser/all_cmds_filled.c
SOURCES += parser/check_and_give_token.c 
SOURCES += parser/next_token.c
SOURCES += parser/quotes_closed.c
SOURCES += parser/realloc_cmds.c
SOURCES += parser/tokenise.c
SOURCES += parser/tokenise_pipe.c
SOURCES += parser/tokenise_quote.c
SOURCES += parser/tokenise_redir.c
SOURCES += shell/create_env.c
SOURCES += shell/create.c
SOURCES += shell/destroy.c
SOURCES += shell/prompt.c
SOURCES += shell/unset_env.c
SOURCES += shell/set_env.c
SOURCES += signals/signals.c
SOURCES += main.c 
SOURCES += error.c

