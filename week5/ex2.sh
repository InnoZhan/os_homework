touch test.txt

value=`tail -1 test.txt.lock`
echo `$value == ''`
then
	value=$((value + 1))
	echo $value >> test.txt.lock
else
	echo "1" >> test.txt.lock
fi
rm test.txt.lock
