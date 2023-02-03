# Zappy
## Run the project
In the route file you can find a Makefile, to compile all files you just need to run

    make 
Re-compile all files by running:
    
    make re

### Server

Usage : 
    
    ./zappy_server -p port -x width -y height -x name1 name2 ... -c clientsNb -f freq


<strong>port</strong> is the port number\
<strong>width</strong> is the width of the world\
<strong>height</strong> is the height of the world\
<strong>nameX</strong> is the name of the team X\
<strong>clientsNb</strong> is the number of authorized clients per team\
<strong>freq</strong> is the reciprocal of time unit for execution of actions


### Gui
Usage:

    ./zappy_gui
You can type port and ip spectate which party you want


### AI

Usage:

    ./zappy_ai -p port -n name -h machine

<strong>port</strong> is the port number\
<strong>name</strong> is the name of the team\
<strong>machine</strong> is the name of the machine, localhost is by default\