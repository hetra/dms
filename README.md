# dms - The Dead Man's Switch #
---

dms is a dead man's switch for Windows. I was inspired to write it by [an article](http://blog.viktorpetersson.com/post/108852454049/a-dead-mans-switch-for-your-computer) I found while on [Hacker News](https://news.ycombinator.com/item?id=8931735).

Basically, it accepts two arguments from the command line - the path to the "canary file" (as I call it) and an unsigned integer representing the number of seconds to wait after each check (inversely proportional to your paranoia) - like so:

`dms canaryfile seconds`

For example, check for the file `foo.txt` every `5` seconds:

`dms foo.txt 5`

It makes use of the Win32 API, so factor that in if you're playing with the code. Although, this is very simple to do with pretty much any programming language worth learning.
