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

cmake .. -DCMAKE_CXX_STANDARDS=$1
make

echo "Finished!"
exit 0
  
