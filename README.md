```
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
█▄▄ █ █▀▀   ▀█▀ █▀▀ █▀█ █▀▄▀█ █ █▄ █ ▄▀█ █     ▀█▀ █▀▀ ▀▄▀ ▀█▀
█▄█ █ █▄█    █  ██▄ █▀▄ █ ▀ █ █ █ ▀█ █▀█ █▄▄    █  ██▄ █ █  █ 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
```

Prints really big text in the terminal. Designed for use in other CLI tools, mainly to deliver some big and very important message, whatever that may be. A function from my Inficonnect4 project turned into an advanced CLI tool.

Optimized and made easy for Linux, MacOS, and Android.

FOR WINDOWS:
It is possible to run this program (by manually compiling into an executable), but only if you have enabled UTF-8 character encoding within the terminal, which by default isn't. You can enable UTF-8 encoding by default by following  <a href="https://akr.am/blog/posts/using-utf-8-in-the-windows-terminal#:~:text=Enable%20the%20new%20UTF%2D8,Restart%20your%20computer." target="_blank">THIS TUTORIAL</a>. Temporary, session-long support can be enabled by running the `chcp 65001` command. I tried creating big text using just ASCII characters, which is a possible addition to this program in the near future, but currently there is just 1 type of big text: the big, bright boxes.
```
USAGE: 
    btxt [options] <text> ...

OPTIONS:
    -h, --help          help page
    -n, --newline       prints following text in a newline
    -nl, --no-lines     removes the top and bottom lines, enabled by default
    -x=, --repeat=<value> repeats the text a given N times
    -t, --test          tests the text
```




```
#
#
#   █ █▄ █ █▀ ▀█▀ ▄▀█ █   █   ▀
#   █ █ ▀█ ▄█  █  █▀█ █▄▄ █▄▄ ▄
# go to the dir you want to clone into
git clone https://github.com/wettestsock/big-text
cd ./big-text
chmod +x ./install.sh
./install.sh
cd ..
```

```
#
#
#   █ █ █▄ █ █ █▄ █ █▀ ▀█▀ ▄▀█ █   █   ▀
#   █▄█ █ ▀█ █ █ ▀█ ▄█  █  █▀█ █▄▄ █▄▄ ▄
# go to the cloned repo location
cd ./big-text
sudo ./uninstall.sh
cd ..
rm -rf ./big-text
```

```
#
#
#   █▀▄▀█ ▄▀█ █▄ █ █ █ ▄▀█ █     █▀▀ █▀█ █▀▄▀█ █▀█ █ █   █▀▀ ▀
#   █ ▀ █ █▀█ █ ▀█ █▄█ █▀█ █▄▄   █▄▄ █▄█ █ ▀ █ █▀▀ █ █▄▄ ██▄ ▄
#
git clone https://github.com/wettestsock/big-text/
cd ./big-text
g++ src/main.cc src/utils.cc -o btxt
```


