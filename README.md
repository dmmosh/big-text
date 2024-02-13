```
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
█▄▄ █ █▀▀   ▀█▀ █▀▀ █▀█ █▀▄▀█ █ █▄ █ ▄▀█ █     ▀█▀ █▀▀ ▀▄▀ ▀█▀
█▄█ █ █▄█    █  ██▄ █▀▄ █ ▀ █ █ █ ▀█ █▀█ █▄▄    █  ██▄ █ █  █ 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
```


A function from my Inficonnect4 project made into a separate executable.
Makes the text real big.

TO MANUALLY COMPILE:
```
git clone https://github.com/wettestsock/big-text/
cd ./big-text
g++ main.cc utils.cc -o btxt
```
will make an install script, but for now youre welcome to manually compile and enjoy big terminal text through an alias



I'm trying to get it to work on Windows but so far it's only available on Linux, MacOS, and Android.

```
USAGE: 
    btxt [options] text ...

OPTIONS:
    -h, --help          help page
    -n, --newline       prints following text in a newline
    -nl, --no-lines     removes the top and bottom lines, enabled by default
    -x=, --repeat=<value> repeats the text a given N times
    -t, --test          tests the text
```
