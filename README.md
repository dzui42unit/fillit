# fillit Made by: dzui and mpaziuk
Fillit is a project who let you discover and/or familiarize yourself with a recurring
problematic in programming : searching for the optimal solution among a huge set of possibilities.
In this particular project, you will be charged of creating an algorithm which
fits some Tetriminos together into the smallest possible square.

The goal of this project is to arrange the Tetriminos among themselves to make the
smallest possible square, but in some cases, this square may have holes when some given
pieces won’t fit perfectly with others.

Program must display the smallest square solution on the standard output. To
identify each Tetriminos in the square solution, you will assign a capital letter (starting
with ’A’) to each Tetriminos in the order they appear in the file. A file will contain 26
Tetriminos maximum.

A few examples of valid descriptions of Tetriminos :
* .... 	
* ..## 		
* ..#. 		
* ..#. 		

* .... 		
* .... 		
* ..## 	
* ..## 

* ####
* ....
* ....
* ....

an example of a valid file a program must resolve :
$> cat -e valid_sample.fillit
* ...#$
* ...#$
* ...#$
* ...#$
$
* ....$
* ....$
* ....$
* ####$
$
* .###$
* ...#$
* ....$
* ....$
$
* ....$
* ..##$
* .##.$
* ....$
$>

Example how the program works:
$> cat sample.fillit | cat -e
* ....$
* ##..$
* .#..$
* .#..$
$
* ....$
* ####$
* ....$
* ....$
$
* #...$
* ###.$
* ....$
* ....$
* $
* ....$
* ##..$
* .##.$
* ....$
$> ./fillit sample.fillit | cat -e
* DDAA$
* CDDA$
* CCCA$
* BBBB$
* $>
