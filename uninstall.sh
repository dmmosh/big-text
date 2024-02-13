#!/bin/bash

# UNINSTALLER 

# ask for sudo permissions

# ROOT PERMISSIONS

if [ ! "$UID" -eq 0 ] 
then
    echo -e "FATAL ERROR:"
    echo -e "   Can't uninstall without root permissions."
    echo -e "   Please run 'sudo ./$(basename "$0")'."
    exit 1
fi



os="$(uname)"

home_dir="$HOME"

# for linux
# find user home dir
if [ ! "$os" == "Darwin" ]
then
home_dir="/home/${SUDO_USER}"
fi





echo -e "DELETING EXECUTABLE..." 
rm "/usr/bin/btxt"


# if LINUX 
if [ ! "$os" == "Darwin" ] 
then

echo -e "DELETING .DESKTOP FILE..." 
sudo rm /usr/share/applications/btxt.desktop

fi

echo -e "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀"
echo -e "▀█▀ █ █ ▄▀█ █▄ █ █▄▀   █▄█ █▀█ █ █ █"
echo -e " █  █▀█ █▀█ █ ▀█ █ █    █  █▄█ █▄█ ▄"
echo -e "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄"
echo -e "\n        for using btxt. -Dmytro" 


