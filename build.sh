#!/bin/bash

mkdir -p Debug
cd Debug && frcmake .. && make $@

