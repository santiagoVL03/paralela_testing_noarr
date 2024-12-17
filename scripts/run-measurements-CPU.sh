#!/bin/bash

export USE_SLURM=${USE_SLURM:-0}

if [ "$(basename "$(pwd)")" = "scripts" ]; then
    cd ..
fi

( cd PolybenchC-Noarr && DATASET_SIZE=SMALL DATA_DIR=../results/PolybenchC/small-data ./collect.sh & wait )