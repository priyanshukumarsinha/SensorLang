# SensorLang
The lexer reads .slang source code and converts it into a list of tokens. Each token represents a meaningful unit, such as a keyword, identifier, literal, symbol, or comment.

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


## How It Works
1. Lexer Initialization
- Reads the source code from a file.
- Initializes position and line counters.

2. Tokenization Loop
- Skips whitespace.
- Identifies keywords, identifiers, integers, timestamps, symbols, and comments.
- Marks invalid tokens with INVALID.
- Appends an EOF token at the end.

3. Output
- Each token is printed with its type, value, and line number


