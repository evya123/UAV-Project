cmake_minimum_required(VERSION 3.13)
project(UAV_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Dev main.cpp README.md Expression.h Command.h BinaryExpression.h BinaryExpression.cpp Minus.cpp Minus.h Plus.cpp Plus.h Mult.cpp Mult.h Div.cpp Div.h Num.cpp Num.h ShuntingYard.cpp ShuntingYard.h Commends/OpenDataServerCommand.cpp Commends/TcpServer.cpp Commends/OpenDataServerCommand.h Commends/TcpServer.h LexerParser.cpp LexerParser.h Data.cpp Data.h)
