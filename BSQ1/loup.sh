make re
w=1000
h=1000
d=2
i=0
while [ $i -lt $1 ]
do
	touch map.txt
	clear
	perl scripts/map_gen.pl $w $h $d > map.txt
	time ./BSQ map.txt
	i=`expr $i + 1`
	sleep 1
	rm map.txt
done
