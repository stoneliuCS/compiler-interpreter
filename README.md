# A Very Distant Compiler

Actually the repo is a lie, I'm building an interpreter because I love my interpreted, scripted languages.

Ensure that you have `nix` installed for package management.

Run the nix shell by using:

```bash
nix develop # In the root directory
```

Compile the interpreter into an executable object file using:
```bash
make
```

Run the executable by supplying command line arguments like so:
```bash
./main.o <FILE_PATH> # Or no arguments to run it in REPL mode.
```
