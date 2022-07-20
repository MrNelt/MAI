#!/bin/bash
dir=$1
LIST=`find $dir -type f | xargs file -i | awk -F: '{ print $1 }'` #получаем список всех файлов в директориях и поддиректориях
for file in $LIST; do #проходим по файлам
	temp=`enca -i $file` #получаем кодировку файла в формате для iconv
	echo "$file Сurrent encoding: $temp"
done