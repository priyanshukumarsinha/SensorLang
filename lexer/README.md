# STEP 1: The Lexer (Lexical Analyzer)

- Convert raw SensorLang code (plain text) into a list of tokens.
- Each token represents one meaningful unit: a keyword, identifier, literal, symbol, or comment.

## Token Types in our Compiler

| **Token Type**        | **Formal Definition / Regex Pattern**                   | **Description**                                                                                | **Example**                  |
| --------------------- | ------------------------------------------------------- | ---------------------------------------------------------------------------------------------- | ---------------------------- |
| **KEYWORD**           | `read \| write \| alert`                                | Reserved words for sensor operations.                                                          | `read`, `write`, `alert`     |
| **IDENTIFIER**        | `[a-zA-Z_][a-zA-Z0-9_]*`                                | User-defined names for sensors, devices, or variables. Must start with a letter or underscore. | `tempSensor`, `humidity1`    |
| **INTEGER_LITERAL**   | `[0-9]+`                                                | Integer constants used for numeric data or thresholds.                                         | `100`, `25`, `999`           |
| **TIMESTAMP_LITERAL** | `[0-9]{4}-[0-9]{2}-[0-9]{2}T[0-9]{2}:[0-9]{2}:[0-9]{2}` | Timestamp value in ISO 8601 format (YYYY-MM-DDThh:mm:ss).                                      | `2025-10-09T13:00:00`        |
| **SYMBOL**            | `[=;,]`                                                 | Single-character punctuation symbols.                                                          | `=`, `;`, `,`                |
| **COMMENT**           | `#.*`                                                   | Single-line comment (ignored by compiler, but counted for line tracking).                      | `# Sensor node config`       |
| **WHITESPACE**        | `[ \t\r\n]+`                                            | Spaces, tabs, and newlines (ignored except for line count).                                    | —                            |
| **INVALID**           | Any unrecognized or malformed token.                    | Used to flag lexical errors.                                                                   | `@temp`, `20-25-01T15:99:00` |


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

## Commands

### 1. read command
- Purpose: Read data from a sensor or device.
- Syntax : 
```cpp
read <IDENTIFIER> [, <TIMESTAMP>]

<IDENTIFIER> → sensor or node name 
(alphanumeric, starts with a letter/underscore)

<TIMESTAMP> → optional; ISO 8601 timestamp 
(YYYY-MM-DDThh:mm:ss)

Comma , separates identifier and timestamp 
if both are provided
```

- Identifier is mandatory. Timestamp is optional but can only appear after a valid identifier, separated by a comma.
- Example:
```cpp
read tempSensor              # read current temperature
read humiditySensor, 2025-10-09T13:00:00   # read past humidity value
```
- Token sequence: `KEYWORD(read) IDENTIFIER SYMBOL(',') TIMESTAMP_LITERAL`

### 2. write command
- Purpose: Write a value to a sensor, actuator, or output node.
- Syntax : 
```cpp
write <IDENTIFIER>, <INTEGER_LITERAL>

<IDENTIFIER> → sensor or node name 
(alphanumeric, starts with a letter/underscore)

<INTEGER_LITERAL> → numeric value to write

Comma , is mandatory between identifier and value
```

- Example:
```cpp
write output, 100         # set output to 100
write motorSpeed, 50      # set motor speed to 50
```
- Token sequence: `KEYWORD(write) IDENTIFIER SYMBOL(',') INTEGER_LITERAL`

### 3. alert command
- Purpose: Trigger an alert or log an event, possibly with a timestamp.
- Syntax : 
```cpp
alert <IDENTIFIER> [, <TIMESTAMP>]

<IDENTIFIER> → sensor or node name 
(alphanumeric, starts with a letter/underscore)

<TIMESTAMP> → optional; when the alert occurred

Comma , separates the identifier and timestamp if provided
```

- Example:
```cpp
alert tempSensor             # current alert
alert tempSensor, 2025-10-09T13:00:00  # historical alert
```
- Token sequence: `KEYWORD(alert) IDENTIFIER [SYMBOL(',') TIMESTAMP_LITERAL]`
- Error if identifier is invalid or timestamp malformed.


### 4. comments
- Purpose: Add a human-readable comment in code.
- Syntax : 
```cpp
# comment text

Everything after # on that line is ignored by the compiler.
Useful for documenting sensor programs.
```

- Example:
```cpp
# Read temperature every 10 seconds
read tempSensor
```
- Token sequence: COMMENT("# comment text")

## Summary
| Command | Arguments                   | Example             | Behavior                       |
| ------- | --------------------------- | ------------------- | ------------------------------ |
| `read`  | IDENTIFIER [, TIMESTAMP]    | `read tempSensor`   | Read current sensor value      |
| `write` | IDENTIFIER, INTEGER_LITERAL | `write output, 100` | Write value to device/variable |
| `alert` | IDENTIFIER [, TIMESTAMP]    | `alert tempSensor`  | Trigger an alert event         |
| `#`     | comment text                | `# Log every read`  | Comment, ignored by compiler   |
