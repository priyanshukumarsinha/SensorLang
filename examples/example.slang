# Example SensorLang file

# Temperature monitoring
read tempSensor            # read value from tempSensor
write output, 100          # write 100 to output
alert 2025-10-09T13:00:00 # alert at this timestamp

# Another comment
read humiditySensor
write output, 50
alert 2025-10-09T14:30:00

# Invalid examples
@invalidToken
123abc
write output; extraSymbol
