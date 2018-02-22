# GNU screen cheatsheet
As configured in my [screenrc](https://github.com/xiaotdl/Docs/blob/master/terminal_multiplexer/screenrc).

C-a x => hit ctrl+a and then x.
## Basics
    C-a ?    help
    C-a x    lock screen session

## Getting in
    screen ls|list    check screen session
    screen -r <name>  reattach, e.g. <7924.pts-6.xili-ubuntu-vm>, [pid.]tty.host, default to last active session

## Getting out
    C-a d       deattach
    C-a k       kill one screen window
    C-a \       kill one screen session
    C-a C-\     (force exit, not recommended)
    C-a :quit   kill all windows

## Window Management
    C-a c    create windows
    C-a A    rename current window
    C-w      show window bar

    *switch between windows*
    C-a "               show window list and go to a chosen one
    C-a n|<space>       go to next window
    C-a p|<backspace>   go to previous window
    C-a a               go back to last selected window
    C-a <number>        go to window number
    C-a '               go to window number or name

## Pane Management
    C-a S        create a horizontal pane
    C-a | or V   create a vertical pane
    C-a tab      go to next pane 
    C-a X        remove current region
    C-a Q        remove all panes but the current one

## Misc
    C-a [|<esc> enter copy mode
    C-a ]       paste buffer
