# 自动化编译和运行的脚本
rm -rf build
mkdir build
cd build/
cmake -G "Visual Studio 14 2015" -A x64 -DCMAKE_BUILD_TYPE=Release ./../
#cmake ..
# make  
# cd ../bin
# ./main