# Tic Tac Toe SDL
The classic game of Tic Tac Toe ported to modern systems using the [SDL](https://www.libsdl.org/index.php).

<img src="https://media.giphy.com/media/MBI5KshGeu79U5QqSC/giphy.gif">

# Intro

Cloning the classic game of Tic Tac Toe served as an introduction to the game development field as well as my first time trying to figure out a powerful multipurpose development library such as the SDL. 

Main purpose of this project was to get familiar with basic systems such as :

* Creating and using a main game loop
* Loading Images
* Using mouse actions as input

# Overview

* The game supports two players via hotseat. 
* Win by aligning three of the same symbol horizontally, vertically or diagonally.

# Building in Linux

1) Grab the dependencies using the following commands in terminal : 
`sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev`
2) Clone the project's repository 
3) Open a terminal window inside the cloned folder
4) Use the following command : `make`
5) Run the executable : `./tictactoe`


