### instructions for running test tasks:


### First task
**Build and run:**
1. CMakeLists.txt located in task1/src
2. To build program use follow command
```
~/test_task_c-/task1$ cmake src
~/test_task_c-/task1$ make
```
3. Now just execute **main**
```
~/test_task_c-/task1$ ./main 
```

**Result of application working:**
1. After executing application will print set of thread works
```
Thread 2
Thread 1
Thread 4
Thread 3
Thread 6
Thread 5
Thread 8
Thread 7
Thread 10
Thread 9
```
2. Also you will see file **DATA.txt** where will be result of thread work

**Where the application was tested**
+ Ubuntu 18.04
+ CMake version 3.10.2(Minimum required 2.6)
+ GNU Make 4.1
+ g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0

### Second task
**Build and run:**
. CMakeLists.txt located in task2

2. To build program use follow command
```
~/test_task_c-/task2$ cmake .
~/test_task_c-/task2$ make
```
3. Now just execute **test_task_2**
```
~/test_task_c-/task2$ ./test_task_2  
```

**Result of application working:**
1. After executing application will print set of thread works
```
Thread 2
Thread 1
Thread 4
Thread 3
Thread 6
Thread 5
Thread 8
Thread 7
Thread 10
Thread 9
```
2. Also you will see file **DATA.db** where will be result of thread work

3. That see sql table follow next command:
```
~/test_task_c-/task2$ sqlite3 DATA.db 
sqlite> SELECT * FROM Arrays;
```
And you will see:
```
1|2|3|4|5|6|7|8|9|10
31|32|33|34|35|36|37|38|39|40
21|22|23|24|25|26|27|28|29|30
51|52|53|54|55|56|57|58|59|60
41|42|43|44|45|46|47|48|49|50
71|72|73|74|75|76|77|78|79|80
61|62|63|64|65|66|67|68|69|70
91|92|93|94|95|96|97|98|99|100
81|82|83|84|85|86|87|88|89|90
```

**Where the application was tested**
+ Ubuntu 18.04
+ CMake version 3.10.2(Minimum required 3.0)
+ GNU Make 4.1
+ SQLite version 3.22.0
+ POCO version 1.9.2
+ g++ (Ubuntu 7.3.0-ls27ubuntu1~18.04) 7.3.0