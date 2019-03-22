#!/bin/bash

RANG=$1
if [[ -z $RANG ]]; then
    RANG="10"
fi

sequence=(`echo $(seq 0 $RANG) | tr ' ' '\n' | sort -gr | tr '\n' ' '`)

if [[ $2 == "-r" ]]; then
	sec=(${sequence[@]})
	rnd=""
	for line in "${sec[@]}"; do
		nc=${#sequence[@]}
		nm=$(( $RANDOM % $nc ))
		tmp=${sequence[$nm]}
		rnd="$rnd $tmp"
		for i in "${!sequence[@]}"; do
			if [[ ${sequence[i]} = "$tmp" ]]; then
				unset 'sequence[i]'
			fi
		done
		for i in "${!sequence[@]}"; do
		    new_array+=( "${sequence[i]}" )
		done
		sequence=("${new_array[@]}")
		unset new_array
	done
	sequence=($rnd)
fi
echo ${sequence[@]}

./ps_part/push_swap ${sequence[@]} | ./checker_part/checker ${sequence[@]}

./ps_part/push_swap ${sequence[@]} | ./checker_llopez ${sequence[@]}

# ./num_gen.sh nb_arg
#			tri a l'envers
# ./num_gen.sh nb_arg -r
#			tri random
# ./num_gen.sh
#			tri a l'envers avec 0 - 10 par defaut