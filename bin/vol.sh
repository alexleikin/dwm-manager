#!/usr/bin/ksh


VOL=$(pamixer --get-volume-human | tr -d '%')
printf "%s" "$SEP1"
    if [ "$VOL" = "muted" ] || [ "$VOL" -eq 0 ]; then
        printf "^c#cc241d^🔇"
    elif [ "$VOL" -gt 0 ] && [ "$VOL" -le 33 ]; then
        printf "^c#cc241d^🔈 %s%%" "$VOL"
    elif [ "$VOL" -gt 33 ] && [ "$VOL" -le 86 ]; then
        printf "^c#000100^🔉 %s%%" "$VOL"
    elif [ "$VOL" -gt 86 ] && [ "$VOL" -le 150 ]; then
        printf "^c#cc241d^🔊 %s%%" "$VOL"
    else
        printf "^c#000100^🔊 %s%%" "$VOL"
    fi
