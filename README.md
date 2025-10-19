# SensorLang
SensorLang is a mini programming language created as a project to simulate how compilers work.
It’s a small, compiled language, where the compiler (written in C++) reads .slang source code and generates equivalent C++ code, which can then be compiled and executed.

The language supports only a few basic commands used for IoT-like operations — reading sensor data, writing outputs, and generating alerts.

## Purpose
The goal of SensorLang is to provide:
- A lightweight scripting interface for IoT developers.
- An easy-to-learn syntax for basic sensor operations.
- The foundation for a real-time, event-driven execution model in C++.

## Language Features

| Component       | Description                                 | Example                      |
| --------------- | ------------------------------------------- | ---------------------------- |
| **Keywords**    | Built-in commands for sensor operations     | `read`, `write`, `alert`     |
| **Identifiers** | Alphanumeric names for sensors or variables | `tempSensor`, `humidity1`    |
| **Literals**    | Integers or timestamps                      | `100`, `2025-10-09T13:00:00` |
| **Symbols**     | Syntax characters                           | `=`, `;`, `,`                |
| **Comments**    | Single-line, start with `#`                 | `# this is a comment`        |

## Example Program
```cpp
# Read data from temperature sensor
read tempSensor

# Write a fixed value to output
write output, 100

# Trigger an alert
alert "Temperature high!"
```

## Compiler Output
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Reading tempSensor..." << endl;
    cout << "Writing 100 to output" << endl;
    cout << "ALERT: Temperature high!" << endl;
    return 0;
}
```

## Architecture
The compiler will have three simple parts:
- Lexer: Breaks code into tokens (like words).
- Parser: Checks if the order of tokens makes sense.
- Code Generator: Writes equivalent C++ code into an output file.

## Complete Process
- STEP 1: Lexer
- STEP 2: Parser


