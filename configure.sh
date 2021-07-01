#!/bin/bash

if [ -d "bin" ]
then 
		echo "checked build directory exist name: bin ...done [OK]"
else
		echo "creating building directory \"bin\""&& mkdir bin
fi


if [ -d temp ]
then
			echo "temp...[ok]"
else
			mkdir temp
			echo "temp dir is created"
fi
