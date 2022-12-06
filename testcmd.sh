#!/bin/bash

# ./minishell -p 'ls'
#./minishell -p 'export'
# ./minishell -p 'export'  'export' 'export'
# ./minishell -p 'export test'
# ./minishell -p 'export test=mooi'
# ./minishell -p 'export test='

# ./minishell -p 'cd'
# ./minishell -p 'cd ~'
# ./minishell -p 'cd .'
# ./minishell -p 'cd ..'
# ./minishell -p 'cd obj'
# ./minishell -p 'cd ob'

./minishell -p 'echo Hello' '|' 'echo Hello' 
./minishell -p 'echo -nn Hello'
./minishell -p 'echo -nns Hello'
# ./minishell -p 'echo -n -n Hello'
# ./minishell -p 'echo -n-n -nnn -n -n- Hello'
# ./minishell -p 'echo USER'
# ./minishell -p 'echo USER'
# ./minishell -p 'echo $USER'
# ./minishell -p 'echo ~'

# ./minishell -p '> a'
# ./minishell -p '< a'
# ./minishell -p '>> a'
# ./minishell -p '<< a'

# ./minishell -p '$'
# ./minishell -p '$$'
# ./minishell -p '$$$'
# ./minishell -p '$?'
# ./minishell -p '$?$'

# ./minishell -p 'env'
# ./minishell -p 'top'
