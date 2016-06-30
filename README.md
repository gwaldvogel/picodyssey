PicOdyssey
==========

PicOdyssey is a project originally started for the [Hackathon Freiburg 2016](http://hackathon-freiburg.de/). It's a mobile game for Android & iOS written in C++ and QML using the Qt framework. OpenStreetMap is used to display the map used in the game.

The backend of the game was written in Python using the Flask framework and can be found [here](https://github.com/gwaldvogel/picodyssey_backend)

About the idea
--------------

The base idea is to give newcomers in Freiburg a playful way to get to know Freiburg (and in the future pretty much any city on this planet). The game is based on a community-driven database of images and corresponding geodata which are used to set up the game. Every user can take images inside the app and upload them into the database.

While playing the game you are presented with an image of a place taken from the database, after you have recognized the image you go on the the next phase of the game. Now that you have hopefully recognized the place you have 30 seconds to place a marker on a map. Once you locked in the position of your marker or the 30 seconds are over you will be presented with your result. You get points based on your performance and, of course, the chance to brag about your success on Facebook or Twitter.

Todo
----

The following things are not working properly yet or are just not yet implemented:

-	OAuth login
-	Social Media Sharing
-	full picture upload
-	Calculating the score & storing it in the database
