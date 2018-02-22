session_name='example_session_name'
path='~'
cmd='pwd'

screen -d -m -S $session_name
sleep 1
screen -S $session_name -X stuff $"schroot\n"
screen -S $session_name -X stuff $"cd $path\n"
screen -S $session_name -X stuff $"$cmd\n"
