#test
#!/bin/bash

# Get the current hour
current_hour=$(date +"%H")
# Get the login name
login_name=$(whoami)

# Determine the greeting based on the time of day
if [ "$current_hour" -ge 5 ] && [ "$current_hour" -lt 12 ]; then
    greeting="Good Morning, $login_name!"
elif [ "$current_hour" -ge 12 ] && [ "$current_hour" -lt 17 ]; then
    greeting="Good Afternoon, $login_name!"
elif [ "$current_hour" -ge 17 ] && [ "$current_hour" -lt 21 ]; then
    greeting="Good Evening, $login_name!"
else
    greeting="Hello, $login_name!"
fi

# Check if greetingmsg file exists; if so, delete it
if [ -f greetingmsg ]; then
    rm greetingmsg
fi

# Output the greeting to greetingmsg
echo "$greeting" > greetingmsg
