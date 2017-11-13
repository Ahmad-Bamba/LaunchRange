# usage ./build.sh [C++ VERSION] [CLEAN]

if [ -d ".build" ]; then
    cd .build
else
    print ".build folder not found!"
    exit 1
fi

if [ $2 ]; then
  rm -rf *
fi

v=$1

export CPPV=${v}

printf "Building with ${v}\n"

cmake ..
make

echo "Finished!"
exit 0
