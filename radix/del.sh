#!/bin/bash
for file in step_*.txt; do
	rm $file
done
frames="frames"
rm -r "$frames"

