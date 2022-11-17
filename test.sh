#!/bin/bash

# This is a simple tester for minishell

# echo '$'
# echo "'$'"
# echo '"$"'
# echo '$$'
# echo "'$$'"
# echo '"$$"'
# echo '$USER'
# echo '"$USER"'
# echo "'$USER'"
# echo 'Hello $USER Welcome'
# echo "Hello $USER Welcome"
# echo "Hello $USER, Welcome!"

# ./minishell -c 'ls'
# bash -c 'ls'
# ./minishell -c 'ls -la'
# bash -c 'ls -la'

./minishell -c 'echo $'
bash -c 'echo $'
./minishell -c "echo '$'"
bash -c "echo '$'"
./minishell -c 'echo "$"'
bash -c 'echo "$"'
./minishell -c "echo \$$"
bash -c "echo \$$"
./minishell -c "echo '\$$'"
bash -c "echo '\$$'"
./minishell -c '"echo $$"'
bash -c '"echo $$"'
./minishell -c 'echo $USER'
bash -c 'echo $USER'
./minishell -c "echo \$USER"
bash -c "echo \$USER"
./minishell -c "echo '\$USER'"
bash -c "echo '\$USER'"
# ./minishell -c echo Hello \$USER Welcome
# echo Hello $USER Welcome
# ./minishell -c echo Hello, \$USER Welcome
# echo Hello, $USER Welcome
# ./minishell -c echo "'Hello \$USER Welcome'"
# echo 'Hello $USER Welcome'
# ./minishell -c echo '"Hello $USER Welcome"'
# echo "Hello $USER Welcome"
# ./minishell -c echo Hello \$USER, Welcome
# echo Hello $USER, Welcome

# ./minishell -c echo Hello \$USER Welcome
# bash -c 'echo Hello $USER Welcome'
# ./minishell -c echo "'Hello \$USER Welcome'"
# bash -c echo 'Hello $USER Welcome'
# ./minishell -c echo '"Hello $USER Welcome"'
# bash -c echo "Hello $USER Welcome"

./minishell -c 'echo Hello'
bash -c 'echo Hello'
./minishell -c 'echo Hello USER'
bash -c 'echo Hello USER'
./minishell -c 'echo $USER'
bash -c 'echo $USER'
./minishell -c 'echo Hello $USER welcome'
bash -c 'echo Hello $USER welcome'
./minishell -c 'echo Hello $USER, welcome'
bash -c 'echo Hello $USER, welcome'
./minishell -c 'echo Hello $USER , welcome'
bash -c 'echo Hello $USER , welcome'
./minishell -c 'echo Hello $US,ER welcome'
bash -c 'echo Hello $US,ER welcome'

./minishell -c 'ls > outfile'

# ./minishell -c '>a'2
# ./minishell -c '<a'
# ./minishell -c '>>a'
# ./minishell -c '<<a'
# ./minishell -c '> a'
# ./minishell -c '< a'
# ./minishell -c '>> a'
# ./minishell -c '<< a'

# ./minishell -c '$'
# ./minishell -c '$$'
# ./minishell -c '$$$'
# ./minishell -c '$$$$'
# ./minishell -c '$?'
# ./minishell -c '$?$'

# ./minishell -c 'echo $'
# ./minishell -c 'echo $$'
# ./minishell -c 'echo $$$'
# ./minishell -c 'echo $$$$'
# ./minishell -c 'echo $?'
# ./minishell -c 'echo $?$'

# ./minishell -c 'env'
# ./minishell -c 'top'

# head=0x0000603000001450
# head=0x0000603000001450