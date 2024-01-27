#!/bin/bash


echo -e '\n\n█▀█ █ █▄ █ █▀▀ ▄▀█ █▀█ █▀█ █   █▀▀\n█▀▀ █ █ ▀█ ██▄ █▀█ █▀▀ █▀▀ █▄▄ ██▄\n'
check=""
read -p "What does above text say?  " check 

if [ ! "${check^^}" == "PINEAPPLE" ] 
then
    echo no
fi

