# COP 1334 Assignment - Introduction to C++

## Chapter 11 Auto Graded Programming Project

## Title: File Analyzer

### Exercise Description:

Assume a file named `words.txt` exists. The file contains exactly 50 lines, and each line contains a single word. Some of the words appear only once in the file, but some of them appear two or more times. For this project, you will write a program that reads the contents of the file and counts the number of times each unique word appears in the file.

The program should use a **structure** that has two members:

- A `string` to hold a word from the file
- An `int` to hold the number of times the word appears in the file

The program should create an array of the structures and use the array to hold all the unique words from the file and the number of times each word appears. After the program has processed the contents of the file, it should step through the array and display each unique word from the file, followed by a space, followed by the number of times that word appears in the file.

Note: Your program should disregard case when processing the words from the file. For example, the words "eagle" and "EAGLE" should be considered equal.

The following sample run shows an example of the expected output of the program. In this sample run, the program found 10 unique words in the file. The word "option" appears 1 time, the word "eagle" appears 1 time, the word "popular" appears 4 times, and so on.

```terminal
option 1
eagle 1
popular 4
observation 7
formulate 2
cheat 4
cattle 9
peace 6
underline 9
simplicity 7
```

**<End Sample Run>**

## Execution from the Terminal (Alternative way without an IDE):

We must provide to the Compiler the same switches that we usually do in the IDE:

```terminal
g++ -Wall -std=c++17 main.cpp
```

That will create a file named 'a.out' if you are working in MacOS or a .exe file if you are on Windows. That's the default executable file's name when we don't provide a name.

But we can also specify the name of the resulting executable file:

```terminal
g++ -Wall -std=c++17 main.cpp -o your_prefered_executable_file_name
```

And in order to run that a.out file, we must execute on the terminal:

```terminal
 % ./a.out
```

## Result of Execution on the Terminal (MacOS example):

```terminal
reinier@reinier % ./your_prefered_executable_file_name



Process finished with exit code 0
reinier@reinier % 
```

### Author

**Reinier Garcia**

* [Github](https://github.com/reymillenium)
* [Twitter](https://twitter.com/ReinierGarciaR)
* [Linkedin](https://www.linkedin.com/in/reiniergarcia/)
* [Website](https://www.reiniergarcia.dev/)
* [Stack Overflow](https://stackoverflow.com/users/9616949/reinier-garcia)

### License

Copyright © 2024, [Reinier Garcia](https://github.com/reymillenium).


