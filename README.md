> simple_shell > Team project

Start -> Display prompt -> Read command line -> Check if command is a built-in (cd, exit, setenv, unsetenv, env, alias) -> If built-in, execute built-in -> If not built-in, check if command exists in PATH -> If command exists, fork and execute command -> Wait for child process to complete -> Display prompt -> Repeat

+------------------+                        +--------------------+
|     Start        |                        |       End          |
|                  |                        |                    |
|  Display prompt  |                        |  Display prompt    |
|    and wait for  |                        |  and exit shell    |
|    user input    |                        |                    |
+------------------+                        +--------------------+
           |                                           ^
           v                                           |
+------------------+         Command doesn't exist     |
|  Parse input and |  <--------------------------------+
|  execute command |      or execution fails
+------------------+                   |
           |                           |
           v                    Command exists
+------------------+      and execution succeeds
|  Handle built-in |  <----------------+
|     commands     |    or exec external program
+------------------+
           |
           v
+------------------+
| Handle commands  |
|      separator   |
|      operators   |
|   and variable   |
|    replacement   |
+------------------+
           |
           v
+------------------+                         +------------------+
| Handle comments  |     +--------------->   | Handle file mode |
+------------------+                         +------------------+