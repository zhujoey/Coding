time = str(input())
hour = 0
minute = 0

if time[0] == "R":
    hour += 1
    
elif time[0] == "G":
    minute += 1
    
elif time[0] == "B":
    minute += 1
    hour += 1

if time[2] == "R":
    hour += 1
    
elif time[2] == "G":
    minute += 1
    
elif time[2] == "B":
    minute += 1
    hour += 1

if time[4] == "R":
    hour += 2
    
elif time[4] == "G":
    minute += 2
    
elif time[4] == "B":
    minute += 2
    hour += 2
    
if time[6] == "R":
    hour += 3
    
elif time[6] == "G":
    minute += 3
    
elif time[6] == "B":
    minute += 3
    hour += 3

if time[8] == "R":
    hour += 5
    
elif time[8] == "G":
    minute += 5
    
elif time[8] == "B":
    minute += 5
    hour += 5

minute = minute * 5

if hour < 10 and minute >= 10:
    hour = "0" + str(hour)

elif minute < 10 and hour >= 10:
    minute = "0" + str(minute)
    
elif hour < 10 and minute < 10:
    minute = "0" + str(minute)
    hour = "0" + str(hour)

hour = str(hour)
minute = str(minute)

print(hour + ":" + minute)