cmake_minimum_required(VERSION 3.13)
project(UAV_Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
include_directories(.)

add_executable(Dev
        README.md Expression/Expression.h Commends/Command.h
        Expression/BinaryExpression.h
        Expression/BinaryExpression.cpp Expression/Minus.cpp
        Expression/Minus.h Expression/Plus.cpp Expression/Plus.h
        Expression/Mult.cpp
        Expression/Mult.h Expression/Div.cpp Expression/Div.h
        Expression/Num.cpp Expression/Num.h
        Expression/ShuntingYard.cpp Expression/ShuntingYard.h Control/LexerParser.cpp
        Control/LexerParser.h
        Maps/Data.cpp Maps/Data.h Commends/OpenDataServerCommand.cpp
        Commends/PullAndPush/TcpServer.cpp Commends/OpenDataServerCommand.h
        Commends/PullAndPush/TcpServer.h
        Commends/PullAndPush/TcpClient.cpp Commends/PullAndPush/TcpClient.h
        Commends/VarCommand.cpp Commends/VarCommand.h Commends/ConnectCommand.cpp
        Commends/ConnectCommand.h
        Commends/WhileCommand.cpp Commends/WhileCommand.h Commends/PrintCommand.cpp
        Commends/PrintCommand.h Commends/SleepCommand.cpp
        Commends/SleepCommand.h Commends/ArithmeticConditions.cpp
        Commends/ArithmeticConditions.h Utils.cpp Utils.h
        Commends/PullAndPush/XmlFormat.h Var.cpp Var.h
        ExpressionCommand.cpp ExpressionCommand.h Commends/EntercCommand.h
        Commends/EntercCommand.cpp
        main.cpp Commends/IfCommand.cpp Commends/IfCommand.h)