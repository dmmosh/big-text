```
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
█▄▄ █ █▀▀   ▀█▀ █▀▀ █▀█ █▀▄▀█ █ █▄ █ ▄▀█ █     ▀█▀ █▀▀ ▀▄▀ ▀█▀
█▄█ █ █▄█    █  ██▄ █▀▄ █ ▀ █ █ █ ▀█ █▀█ █▄▄    █  ██▄ █ █  █ 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
```

Makes the terminal text really big. Designed for use in other CLI tools, mainly to deliver some big and very important text, whatever that may be. A function from my Inficonnect4 project turned into an advanced CLI tool.

I'm trying to get it to work on Windows but so far it's only available on Linux, MacOS, and Android.

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
#   █ █ █▄ █ █ █▄ █ █▀ ▀█▀ ▄▀█ █   █   ▀
#   █▄█ █ ▀█ █ █ ▀█ ▄█  █  █▀█ █▄▄ █▄▄ ▄
# go to the cloned repo location
cd ./big-text
sudo ./uninstall.sh
```

```
#   █▀▄▀█ ▄▀█ █▄ █ █ █ ▄▀█ █     █▀▀ █▀█ █▀▄▀█ █▀█ █ █   █▀▀ ▀
#   █ ▀ █ █▀█ █ ▀█ █▄█ █▀█ █▄▄   █▄▄ █▄█ █ ▀ █ █▀▀ █ █▄▄ ██▄ ▄
#
git clone https://github.com/wettestsock/big-text/
cd ./big-text
g++ src/main.cc src/utils.cc -o btxt
```


