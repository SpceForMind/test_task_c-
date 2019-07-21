### instructions for running test tasks:


###First task
**Build and run:**
1. CMakeLists.txt located in task1/src
2. To build programm use follow command
```
~/test_task_c-/task1$ cmake src
~/test_task_c-/task1$ make
```
3. Now just execute main
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
2. Also you will see file DATA.txt where will be result of thread work

**Where the application was tested**
+ Ubuntu 18.04
+ CMake version 3.10.2
+ GNU Make 4.1
+ g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
