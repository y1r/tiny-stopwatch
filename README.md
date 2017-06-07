# tiny-stopwatch
A tiny-stopwatch written in C lang.

## Usage
```
$ gcc tiny-stopwatch.c -o tiny-stopwatch
$ ./tiny-stopwatch
2017-06-07 10:17:46 00:00:00
2017-06-07 10:17:47 00:00:01
2017-06-07 10:17:48 00:00:02
2017-06-07 10:17:49 00:00:03
2017-06-07 10:17:50 00:00:04
... (in one line)
(Ctrl-C)
5 (shows elapsed_time)

$ ./tiny-stopwatch.c 5
2017-06-07 10:17:46 00:00:05 (counts starts from 5)
```

## LICENSE
MIT
