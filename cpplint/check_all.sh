#! /bin/bash
set -e
dir=$(dirname "$(readlink -f "$0")")
cd $dir/../
find include src test -name "*.cpp" -o -name "*.h" | xargs python3 ./cpplint/cpplint.py --quiet
