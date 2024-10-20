current_hour= $(date + %H)
if ["$current_hour" -ge 0] && ["$current_hour" -lt 12];
then 
    echo "good morning"
elif ["$current_hour" -ge 12] && ["$current_hour" -lt 18];
then 
    echo "good afternoon"
else
    echo "good evening"
fi