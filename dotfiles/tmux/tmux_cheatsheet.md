# tmux cheatsheet
As configured in my [tmux.conf](https://github.com/xiaotdl/Docs/blob/master/terminal_multiplexer/tmux.conf).

C-b x => hit ctrl+b and then x.
## Basics
    C-b ?    help/list all keybindings
    C-b :    prompt/type command

## Session Management
    tmux new -s <session name>             create session
    tmux ls|list-sessions                  list sessions, go to seleceted session
    tmux a|attach -t <session name>        reattach session [default: last session]
    tmux kill-session -t <session name>    kill session
    killall tmux                           kill sessions
    C-b s    list sessions, go to selected session
    C-b $    rename session
    C-b d    deattach session

## Window Management
    C-b c    create window
    C-b ,    rename window
    C-b w    list windows, go to selected window
    C-b &    kill window
    C-b f    find window

    *switch between windows*
    C-b n           go to next window
    C-b p           go to previous window
    C-b l           go to last selected window 
    C-b <number>    go to window number
    C-b '           go to window number or name

## Pane Management
    C-b "          create pane horizontally
    C-b %          create pane vertically
    C-b !          break panes
    C-b x          kill pane
    C-b <space>    swap pane layout, vertical <-> horizontal

    *switch between panes*
    C-b o      go to next pane
    C-b q      show pane numbers, go to selected pane
    C-b {|}    go to left|right pane

## Misc
    C-b t    show time
    C-b [    enter copy mode
    C-b ]    paste buffer
