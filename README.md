# `pipex`

The purpose of this project is the discovery in detail of the UNIX mechanism - `pipe`.

[Subject](en.subject.pdf)

### Discription of mandatory part
The program `pipex` should repeat the behaviour of the next shell command
```bash
$> < file1 cmd1 | cmd2 > file2
```
Running like this:
```bash
$> ./pipex file1 cmd1 cmd2 file2
```
All errors like: wrong commands,  permission to files and etc, need be handle.


