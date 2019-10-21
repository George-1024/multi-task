# multi-task
This is a simple implementation of multitask system.

Files in /switch are from https://github.com/epicsdeb/cothread.
These files are originally used to implement python cothread extention package.

I viewed the ASM code for x86 and ARM, and believed it can be used to develop a RTOS core. So I wrote a very simple file to show how to use it as a multi-task core.

To compile the code, run"gcc -o test testco.c ./switch/switch.c -I switch/ -g"

I only tested it in x86 Windows environment.
It should also works in x86 linux or in arm linux.
