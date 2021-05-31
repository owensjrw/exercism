#!/usr/bin/env bash

if [[ $# > 1 ]] || [[ $# < 1 ]]
  then
    echo "Usage: leap.sh <year>"
    exit 1
fi

year=$1

if [[ $year != ?(----)+([0 -9]) ]]
    then
      echo "Usage: leap.sh <year>"
      exit 1
  elif [[ ${#year} < 4 ]] || [[ ${#year} > 4 ]]
    then
      echo "Usage: leap.sh <year>"
      exit 1
fi


if [[ $(($year % 4)) == 0 ]] && [[ $(($year % 100)) != 0 ]]
  then
    echo "true"
  elif [[ $(($year % 400)) == 0 ]]
    then
      echo "true"
  else
    echo "false"
fi
