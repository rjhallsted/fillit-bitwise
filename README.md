# fillit-bitwise
A faster and more interesting implementation of my fillit project, using bitwise operators.

See the original project here: <https://github.com/rjhallsted/fillit>

This version uses an `unsigned long long` to hold map, and each piece. Due to that limitation, it will not work correctly if the map is bigger than 8 (on most machines). `unsigned long long` represents an unsigned 64-bit integer, meaning 64 usable spaces. If the map is bigger than 8x8, we run out of space and things will start breaking.

It then uses bitwise operators, primarily bit-shifting and the bitwise `AND` operator (`&`) to determine whether it's possible to place a piece at the given position. If so, then it uses a bitwise `OR` (`|`) to place the piece on the map.

Surrounding that is a an implementation of the backtracking algorithm ([Wikipedia](https://en.wikipedia.org/wiki/Backtracking))

## How to use
`make`

`./fillit testfile`

`testfile` should consist of tetris pieces laid out as such:
```
....
##..
.##.
....

...#
...#
...#
...#
```

Incorrectly formatted files will not be handled.

## Results
The program will print the smallest possible square, with each piece denoted by a letter, corresponding with that pieces position in the input file.

So given the input file:
```
....
.##.
..##
....

...#
...#
...#
...#

....
....
###.
#...
```

fillit would print
```
AA.B
.AAB
CCCB
C..B
```

### Appendix
For info on the `libft` directory, see <https://github.com/rjhallsted/libft>
