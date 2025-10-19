# STEP 1: The Lexer (Lexical Analyzer)

- Convert raw SensorLang code (plain text) into a list of tokens.
- Each token represents one meaningful unit: a keyword, identifier, literal, symbol, or comment.

## Token Types in our Compiler

| **Token Code** | **Token Type**        | **Formal Definition / Regex Pattern**                   | **Description**                                                                                | **Example**                  |
| ------- |--------------------- | ------------------------------------------------------- | ---------------------------------------------------------------------------------------------- | ---------------------------- |
| 0. | **KEYWORD**           | `read \| write \| alert`                                | Reserved words for sensor operations.                                                          | `read`, `write`, `alert`     |
| 1. | **IDENTIFIER**        | `[a-zA-Z_][a-zA-Z0-9_]*`                                | User-defined names for sensors, devices, or variables. Must start with a letter or underscore. | `tempSensor`, `humidity1`    |
| 2. | **INTEGER_LITERAL**   | `[0-9]+`                                                | Integer constants used for numeric data or thresholds.                                         | `100`, `25`, `999`           |
| 3. | **TIMESTAMP_LITERAL** | `[0-9]{4}-[0-9]{2}-[0-9]{2}T[0-9]{2}:[0-9]{2}:[0-9]{2}` | Timestamp value in ISO 8601 format (YYYY-MM-DDThh:mm:ss).                                      | `2025-10-09T13:00:00`        |
| 4. | **SYMBOL**            | `[=;,]`                                                 | Single-character punctuation symbols.                                                          | `=`, `;`, `,`                |
| 5. | **COMMENT**           | `#.*`                                                   | Single-line comment (ignored by compiler, but counted for line tracking).                      | `# Sensor node config`       |
| 6. | **INVALID**           | Any unrecognized or malformed token.                    | Used to flag lexical errors.                                                                   | `@temp`, `20-25-01T15:99:00` |
| #. | **WHITESPACE**        | `[ \t\r\n]+`                                            | Spaces, tabs, and newlines (ignored except for line count).                                    | —                            |


## Example

```cpp
# Temperature monitoring
read tempSensor
write output, 100
alert 2025-10-09T13:00:00
```

## Output
```cpp
COMMENT(# Temperature monitoring) [Line 1]
KEYWORD(read) [Line 2]
IDENTIFIER(tempSensor) [Line 2]
KEYWORD(write) [Line 3]
IDENTIFIER(output) [Line 3]
SYMBOL(,) [Line 3]
INTEGER_LITERAL(100) [Line 3]
KEYWORD(alert) [Line 4]
TIMESTAMP_LITERAL(2025-10-09T13:00:00) [Line 4]
EOF [Line 5]
```


## Weaknesses
- **Large files:**
stringstream reads the entire file into memory. For huge files, this may be inefficient. You could process line by line.

- **Error handling inside lexer:**
If the lexer throws exceptions (e.g., regex failures), you might want a try/catch around tokenize().

- **Invalid command-line arguments:**
Could check for non-existent paths, directories instead of files, or file permission issues.

- **Output formatting:**
For huge token lists, consider writing to a file or summarizing counts.



## Running the Lexer

### Prerequisites
- A **C++ compiler** (GCC or Clang recommended).  
- Terminal or command prompt to run commands.  
- Project structure should look like:

```

SensorLang/
├─ build/
├─ lexer/
│  ├─ lexer.cpp
│  ├─ lexer.h
│  └─ token.h
├─ main.cpp
├─ example.slang
├─ Makefile

````


### Compile the Lexer

Use the provided Makefile:

```bash
make
````

* This will compile your lexer and produce an executable in the `build/` directory:

```
build/sensorLang
```

---

### Run the Lexer on a `.slang` file

The lexer reads the filename from the command line:

```bash
./build/sensorLang <filename>
```

**Example:**

```bash
./build/sensorLang example.slang
```

* The lexer will read the file, tokenize it, and print all tokens with their type and line number.

**Sample output:**

```
5 # Temperature monitoring [Line 1]
0 read [Line 2]
1 tempSensor [Line 2]
0 write [Line 3]
1 output [Line 3]
4 , [Line 3]
2 100 [Line 3]
0 alert [Line 4]
3 2025-10-09T13:00:00 [Line 4]
7  [Line 5]
```

> Numbers correspond to token types (see token table in README).

---

### Clean Build Artifacts

To remove compiled object files and the executable:

```bash
make clean
```

* Deletes the `build/` folder and all compiled files.

---

### Notes

* The lexer **requires exactly one argument** (the filename).
* If the file does not exist, it will print:

```
ERROR :: FILE NOT FOUND :: <filename>
```

* Large files may take longer since the lexer reads the entire file into memory.


