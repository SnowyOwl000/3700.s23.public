#! /bin/sh

# do each sort technique

for stype in ./ssort ./isort ./bsort ./qsort ./msort ./hsort
do

    # do random and sorted data

    for dtype in r s
    do

	# go through each list

	for count in 1000 5000 10000 15000 20000 25000 30000 100000
	do

	    # print a message indicating what we're sorting

	    echo "=================================================="
	    echo

	    if [ $dtype = r ]
	    then
		echo $stype "sorting random list with" $count "items"
	    else
		echo $stype "sorting sorted list with" $count "items"
	    fi

	    # do the sort three times for good timing

	    for i in 1 2 3
	    do
		time $stype < ${dtype}${count}.dat > /dev/null
	    done

	done

    done

done
