make re
w=100
h=100
d=10
i=0
while [ $i -lt $1 ]
do
	touch map.txt
	clear
	perl scripts/map_gen.pl $w $h $d > map.txt
	time ./BSQ map.txt
	i=`expr $i + 1`
	sleep 0.5
	rm map.txt
done
