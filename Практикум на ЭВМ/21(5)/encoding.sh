#!/bin/bash
help="encoding.sh 'directory' 'final encoding'"
error1="You have to enter the directory!"
error2="You must specify encoding parameter"
error3=" is not a directory or doesn't exist"
error4=": invalid encoding."

if [ $1 ]; then
	dir=$1 #директория, в которой будут перекодироваться файлы
fi
if [ $2 ]; then
	to=$2 #желаемая кодировка файлов
fi
if [ $dir = "-h" ]; then #если введен флаг -h(help)
	echo $help
	exit 0
fi
if [ -z $dir ]; then #если не ввели кодировку 
	echo $help
	echo $error1
	exit -1
fi
if [ -z $to ]; then #если не введена желаемая кодировка
	echo $help
	echo $error2
	exit -1
fi
if [ ! -d $dir ]; then #если указанной директории не существует
	echo $help
	echo $dir $error3
	exit -1
fi

FLAG="" 

for enc in `iconv -l`; do
	if [ $to"//" = $enc ]; then
		FLAG="found"
	fi
done


if [ -z $FLAG ]; then #не существует кодировки to
        echo $help
        echo $to $error4
        exit -1
fi

LIST=`find $dir -type f | xargs file -i | grep "text/plain" | awk -F: '{ print $1 }'` #получаем список всех текстовых файлов в директориях и поддиректориях

STATUS=0

for file in $LIST; do #проходим по файлам и меняем кодировку
	temp=`enca -i $file` #получаем кодировку файла в формате для iconv
	echo "Converting: $file Сurrent encoding: $temp"
	cat $file | iconv -f $temp -t $to - -o $file #меняем кодировку файла!
	if [ $? -ne 0 ]; then #проверяем выполнилось ли перекодирование
		echo "Converting $file failed."
		STATUS=-1
	else
		echo "Converted!"
	fi
done

exit $STATUS