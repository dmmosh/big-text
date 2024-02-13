#!/bin/bash

: '
    AN INIT FILE FOR btxt
    dsd
'


# GET DEPENDENCIES (linux and macos)

# Determine OS name
os="$(uname)" # default for macos
# Desktop manager
pkg_manager=""

#finds linux distro
if [ -f /etc/os-release ]
then
    source "/etc/os-release"
    os=$ID

# checks if it's android
elif [ ! -z "$(echo $TERMUX_VERSION)" ]
then
    os="android"
fi


# IF LINUX - FIND THE DISTRO
#TODO: dont forget to add sudo
case "$os" in
    # ARCH
    arch)
    pkg_manager="yay -S"        
    ;;

    # MANJARO
    manjaro)
    pkg_manager="sudo pacman -Sy"
    ;;

    # UBUNTU AND DLINUX MINT
    ubuntu | linuxmint)
    pkg_manager="sudo apt install"
    ;;

    # FEDORA
    fedora)
    pkg_manager="sudo dnf install"
    ;;

    # RASBERRY PI
    raspbian)
    pkg_manager="sudo apt-get install"
    ;;

    # CENT OS
    centos)
    pkg_manager="yum -y install"
    ;;

    # MACOS
    Darwin)
    # if brew isn't installed, install it
    if [ -z "$(command -v brew)" ] 
    then
        /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    fi
    pkg_manager="brew install"
    ;;

    # android
    android)
    pkg_manager="pkg install"
    ;;
    
esac


#dir path of the executable
#dir="$(realpath $(dirname $0))"
dir="$(pwd)"

# have to do sudo user for linux whereas macos keeps it at home variable

# if os is supported, install the dependencies
if [ ! -z "$pkg_manager" ] && [ -z "$(command -v gcc)" ] 
then
    eval "$pkg_manager gcc"
fi

# checking if dependencies are installed 
if [ -z "$(command -v gcc)" ]
then
    echo -e "FATAL ERROR:"
    echo -e "   GCC not found.\n   Please install gcc and run 'sudo ./$(basename "$0")' again."
    exit 1
fi

[ "$UID" -eq 0 ] || exec sudo bash "$0" "$@"

# TEXT CHECK

echo -e "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀"
echo -e "█▀█ █ █▄ █ █▀▀ ▄▀█ █▀█ █▀█ █   █▀▀"
echo -e "█▀▀ █ █ ▀█ ██▄ █▀█ █▀▀ █▀▀ █▄▄ ██▄"
echo -e "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n"
read -p "What does the above text say?   " input

if [ ! "${input,,}" == "pineapple" ]
then
    echo -e "FATAL ERROR:"
    echo -e "   Wrong word. Please run this file again."
    exit 1
fi


home_dir="$HOME"

# for linux
# find user home dir
if [ ! "$os" == "Darwin" ]
then
home_dir="/home/${SUDO_USER}"
fi


chmod +x "$dir/src/btxt.desktop"
chmod +x "$dir/uninstall.sh"

echo -e "COMPILING THE EXECUTABLE..."
g++ "$dir/src/main.cc" "$dir/src/utils.cc" -o "btxt"
mv "$dir/btxt" "/usr/bin/btxt"

# different installation for macosdvsvdfsdsffdsfsfds
#linux only
if [ ! "$os" == "Darwin" ]
then
    # for linux
    echo -e "COPYING THE .DESKTOP FILE..."
    sudo cp -r "$dir/src/btxt.desktop" /usr/share/applications
fi


# says if everything got installed
# if not raises an error
if [ ! -z "$(command -v btxt)" ]
then
    echo -e "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀"
    echo -e "▄▀█ █   █     █▀ █▀▀ ▀█▀ █"
    echo -e "█▀█ █▄▄ █▄▄   ▄█ ██▄  █  ▄"
    echo -e "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n"
else
    echo -e "FATAL ERROR:"
    echo -e "   Big terminal text has, for whatever reason, not installed."
    echo -e "   Try manually compiling using the command 'g++ main.cc utils.cc -o btxt'"
fi


