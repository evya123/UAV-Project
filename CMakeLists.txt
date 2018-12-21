cmake_minimum_required(VERSION 3.13)
project(UAV_Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
include_directories(.)

add_executable(Dev
        main.cpp README.md Expression.h Command.h BinaryExpression.h BinaryExpression.cpp Minus.cpp Minus.h Plus.cpp Plus.h Mult.cpp Mult.h Div.cpp Div.h Num.cpp Num.h ShuntingYard.cpp ShuntingYard.h Lexer.cpp Commends/OpenDataServerCommand.cpp Commends/TcpServer.cpp Commends/OpenDataServerCommand.h Commends/TcpServer.h Commends/TcpClient.cpp Commends/TcpClient.h)
