#!bin/bash

for module in Module0*; do
	cd $module
	for ex in ex0*; do
		make -C $ex format
	done
	cd ..
done
