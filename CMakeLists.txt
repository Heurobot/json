cmake_minimum_required(VERSION 3.10)
project(json_checkpart)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

set(THIRDLIB_ROUTE "/home/ziliang/Desktop/lib")

include_directories( 
                    inc 
                    ${THIRDLIB_ROUTE}/json/jsoncpp/build/include

                      #注意:头文件的搜索路径要和引用的时候一致

                )
#搜集全部源文件，生成可执行文件
file(GLOB_RECURSE SOURCES 
                        "src/*.cpp" 
                             
     )# Recursively find all .cpp files in the code directory

# 生成可执行文件
add_executable(json_test ${SOURCES})

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} \
    -s -lm -Wl,-z,relro -Wl,-z,now\
    -L${THIRDLIB_ROUTE}/json/jsoncpp/build/lib")

target_link_libraries(json_test jsoncpp)
    