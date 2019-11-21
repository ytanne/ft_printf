# ft_printf
The goal of project is to discover a feature of the C language – variadic functions, and to practice detailed management of the printing options.

# Description
This project teaches how to use variadic functions and function dispatch table. The thing that didn't take into consideration is to write **CLEAN CODE**. Therefore my work can be a little bit messy and hard to understand. But I admit my mess, and it will serve me as a reminder how a "dirty" code can cause a problem as soon as the project escalates.
So... You, the person who is reading this page and searching for the tips how to start this project... Before you the start, learn how to write **clean code**. You will thank me later.

# Installation
Clone the repository to a directory.
```
git clone https://github.com/ytanne/ft_printf.git ft_printf
```
Run make to get `libftprintf.a` library.
```
cd ft_printf && make && make clean
```
Finally, include `libftprintf.a` in your compilation of binary file.
For example, create a `test.c` file in a directory where you cloned ft_printf and run the following command:
```
gcc -o test test.c -L . -lftprintf.a -I ft_printf/includes
```

# P.S.

Here is a list of motivational posters you can find in the office of Barney Stinson in the various seasons of How I Met Your Mother:
- Awesomeness : “When I get sad, I stop being sad and be Awesome Instead. True Story. Barney Stinson”
- Conformity : “It’s the one who is different that gets left out in the cold.”
- Courage : “True greatness comes when you’re tested. Theodore Roosevelt”
- Challenge : “We either find a way or we make one”
- Opportunity : “You will always miss 100% of the shots you don’t take.”
- Teamwork : “Coming together is the beginning. Keeping together is progress. Working together is success. Henry Ford.”
- Teamwork : “The chain is only as strong as the weakest link”
- Perseverance : “Continuous effort is the key to unlocking your potential. Sir Win-ston Churchill”
- Perfection : “It is not good enough to win, everybody else should lose”
- Strength : “What the mind can conceive, it can achieve"

<img src="https://s.tcdn.co/7da/007/7da00787-9d79-4b11-a016-730c1825c5dc/5.png" width="300" height="300"/>
