cmake_minimum_required(VERSION 3.13)
project(UAV_Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
include_directories(.)

add_executable(Dev
        main.cpp README.md Expression/Expression.h Command.h BinaryExpression.h
        BinaryExpression.cpp Expression/Minus.cpp Expression/Minus.h Expression/Plus.cpp Expression/Plus.h Expression/Mult.cpp Expression/Mult.h Expression/Div.cpp Expression/Div.h Expression/Num.cpp Expression/Num.h Expression/ShuntingYard.cpp Expression/ShuntingYard.h LexerParser.cpp LexerParser.h Data.cpp Data.h Commends/OpenDataServerCommand.cpp Commends/TcpServer.cpp Commends/OpenDataServerCommand.h Commends/TcpServer.h Commends/TcpClient.cpp Commends/TcpClient.h)