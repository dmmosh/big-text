#!/bin/bash


# BIG TEXT INSTALL SCRIPT
# DONT TOUCH THIS

if [[ ! "$(echo $LANG)" == *"UTF-8"* ]]
then
    echo -e "SUPER ERROR\nYour terminal is not currently running UTF-8 character encoding. Change your character encoding to UTF-8 and rerun this script.\n"
    exit 1
fi

# checks if can see the text
echo -e '\n\n█▀█ █ █▄ █ █▀▀ ▄▀█ █▀█ █▀█ █   █▀▀\n█▀▀ █ █ ▀█ ██▄ █▀█ █▀▀ █▀▀ █▄▄ ██▄\n'



if [ -z "$(gcc -v --help 2> /dev/null | sed -n '/^ *-std=\([^<][^ ]\+\).*/ {s//\1/p}' | grep c++11)" ] 
then
    echo -e "No g++11 found."
fi

terminal=/dev/pts/1
columns=$(stty -a <"$terminal" | grep -Po '(?<=columns )\d+')
rows=$(stty -a <"$terminal" | grep -Po '(?<=rows )\d+')

echo $columns $rows