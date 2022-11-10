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

# ./minishell -p echo '$'
# ./minishell -p echo "'$'"
# ./minishell -p echo '"$"'
# ./minishell -p echo '$$'
# ./minishell -p echo "'\$$'"
# ./minishell -p echo '"$$"'
# ./minishell -p echo '$USER'
# ./minishell -p echo '"$USER"'
# ./minishell -p echo "'\$USER'"
# ./minishell -p echo "Hello \$USER Welcome"
# ./minishell -p echo "Hello, \$USER Welcome"
# ./minishell -p echo "Hello \$USER, Welcome"

./minishell -p 'ls'
./minishell -p 'ls -la'
./minishell -p 'ls -la | grep 14 | cat'

# ./minishell -p 'echo Hello'
# ./minishell -p 'echo -n Hello'
# ./minishell -p 'echo USER'
# ./minishell -p 'echo $USER'

# ./minishell -p '>a'
# ./minishell -p '<a'
# ./minishell -p '>>a'
# ./minishell -p '<<a'
# ./minishell -p '> a'
# ./minishell -p '< a'
# ./minishell -p '>> a'
# ./minishell -p '<< a'

# ./minishell -p '$'
# ./minishell -p '$$'
# ./minishell -p '$$$'
# ./minishell -p '$$$$'
# ./minishell -p '$?'
# ./minishell -p '$?$'

# ./minishell -p 'echo $'
# ./minishell -p 'echo $$'
# ./minishell -p 'echo $$$'
# ./minishell -p 'echo $$$$'
# ./minishell -p 'echo $?'
# ./minishell -p 'echo $?$'

# ./minishell -p 'env'
# ./minishell -p 'top'
