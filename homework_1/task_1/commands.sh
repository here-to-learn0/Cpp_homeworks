#!/usr/bin/env bash
wc -l <data.dat
grep -c 'dolor\|dalor' data.dat
wc -w <data.dat
grep -o '\<mol' data.dat| wc -w
