```
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
█▄▄ █ █▀▀   ▀█▀ █▀▀ █▀█ █▀▄▀█ █ █▄ █ ▄▀█ █     ▀█▀ █▀▀ ▀▄▀ ▀█▀
█▄█ █ █▄█    █  ██▄ █▀▄ █ ▀ █ █ █ ▀█ █▀█ █▄▄    █  ██▄ █ █  █ 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
```


A function from my Inficonnect4 project made into a separate executable.
Makes the text real big.

I'm trying to get it to work on Windows but so far it's only available on Linux, MacOS, and Android.

USAGE: 
    btxt [options] <text> ...

OPTIONS:
-h, --help          help page
-n, --newline       prints following text in a newline
-nl, --no-lines     removes the top and bottom lines, enabled by default
-x=, --repeat=<value> repeats the text a given N times
-t, --test          tests the text


```
echo -e "█ █▄ █ █▀ ▀█▀ ▄▀█ █   █   ▀"
echo -e "█ █ ▀█ ▄█  █  █▀█ █▄▄ █▄▄ ▄"
echo
# clone the repo
git clone https://github.com/wettestsock/big-text
cd ./big-text
chmod +x ./install.sh
./install.sh
cd ..
```

```
echo -e "█ █ █▄ █ █ █▄ █ █▀ ▀█▀ ▄▀█ █   █   ▀"
echo -e "█▄█ █ ▀█ █ █ ▀█ ▄█  █  █▀█ █▄▄ █▄▄ ▄"
# go to the cloned repo location
echo
sudo ./big-text/uninstall.sh
```

```
echo -e "█▀▄▀█ ▄▀█ █▄ █ █ █ ▄▀█ █     █▀▀ █▀█ █▀▄▀█ █▀█ █ █   █▀▀ ▀"
echo -e "█ ▀ █ █▀█ █ ▀█ █▄█ █▀█ █▄▄   █▄▄ █▄█ █ ▀ █ █▀▀ █ █▄▄ ██▄ ▄"
echo
git clone https://github.com/wettestsock/big-text/
cd ./big-text
g++ src/main.cc src/utils.cc -o btxt
```


