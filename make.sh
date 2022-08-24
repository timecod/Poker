for FILE in $(find ./src -name *.cpp)
do
    filename=${FILE/src/build}
    g++ $FILE -c -o ${filename/cpp/o}
done
g++ $(find ./build -name *.o) -o main
