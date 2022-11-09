#!/bin/bash
it=0
a=1
ans=1
while [ "$ans" == "1" ]
do
echo Enter the option
echo "1 for creating database"
echo "2 for adding records"
echo "3 for display records"
echo "4 search record"
echo "5 delete record"
echo "6 Modify record"
echo "7 Exit"
read op

if [ "$op" == "1" ];then
echo "Enter name of database "
read db
touch "$db" 
fi
echo

if [ "$op" == "2" ];then
echo "Enter name of Database"
read db
echo "enter No. of Records"
read nr
while [ "$it" -lt "$nr" ]
do
echo "Enter Id"
read i
re='^[0-9]+$'
while [[ ! $i =~ $re ]]
	do
	echo "error: Not a number" 
	read i
done
echo i
echo "Enter name"
read n
echo "Enter email"
read em
patem="^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$"
while [[ ! $em =~ $patem ]]
do
    echo "Email address $em is invalid."
	read em
done
echo "Enter address"
read add
echo "Enter phone No."
read pn
re='^[0-9]+$'
while [[ ! $pn =~ $re ]]
	do
	echo "error: Not a number" 
	read pn
done
echo "$i,$n,$add,$em,$pn" >> "$db"
it=`expr $it + 1`
echo "$it records Entered"
done
fi
echo

if [ "$op" == "3" ];then
echo "Enter Name oF Database"
read db
cat $db
fi
echo

if [ "$op" == "4" ];then
echo "Enter Name oF Database"
read db
echo "enter Email"
read em
echo \"$em\"
grep  "$em" $db
RETURNSTATUS=`echo $?`
if [ $RETURNSTATUS -eq 1 ]
then 
echo "No Record"
fi
echo
fi
echo

if [ "$op" == "5" ];then
echo "Enter Name oF Database"
read db
echo "enter Id"
read i
echo Enter Line number u want to delete
read linenumber
for line in `grep -n "$i" $db`
do
number=`echo "$line" | cut -c1`
echo $number
if [ $number == $linenumber ]
then
lineRemove="${linenumber}d"
sed -i -e "$lineRemove" $db
echo "record removed"
fi
echo
done
fi
echo

if [ "$op" == "6" ];then
echo "Enter Name oF Database"
read db
echo "enter Id"
read i
echo Enter Line number u want to change
read linenumber
for line in `grep -n "$i" $db`
do
number=`echo "$line" | cut -c1`
echo $number
if [ $number == $linenumber ]
then
echo "What would u like to change"
echo "\"ID,Name,Address,Mobileno,email\""
read edit
linechange="${linenumber}s"
sed -i -e "$linechange/.*/$edit/" $db
echo record edited
fi 
done
fi
echo

if [ "$op" == "7" ];then
exit 1
fi
echo
done
