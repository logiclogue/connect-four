# Connect Four

A command line Connect Four engine.

```
0123456
.......
.......
.......
...O...
...X...
...XO..
```

## Goals

- To create a polymorphic C program.
- To provide a low level Connect Four engine.
- To create a command line Connect Four game.

## To do

- Create a naughts-and-crosses game
- Create a separate program which just validates whether there is a connect four
- Create an AI bot

## Arguments

```
--columns  <number>   Columns on the board (default 7)
--rows     <number>   Rows on the board (default 6)
--length   <number>   Length of line required to win (default 4)
--moves   <numbers>  Starting position of the board (e.g. 334)
```

## Example

### Play a standard game

Command:

`./build/main`

Output:

```
7, 6

0123456
.......
.......
.......
.......
.......
.......

Column to move: 
```

### Create a bigger board

Command:

`./build/main --columns 10 --rows 10`

Output:

```
10, 10

0123456789
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........

Column to move: 
```

### Connect Five!

Command:

`./build/main --columns 10 --rows 10 --length 5`

Output:

```
10, 10

0123456789
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........

Column to move: 
```

### Starting Board Position

Command:

`./build/main --moves 3344251`

Output:

```
7, 6
0123456
.......
.......
.......
.......
...OO..
.XXXXO.
Game over
```

## License

Licensed user the GNU GPLv3

## Author

Jordan Lord
