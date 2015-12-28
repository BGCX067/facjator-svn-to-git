#!/bin/bash
tolua++ -o tolua_terminal.cpp -H tolua_terminal.hpp -n terminal terminal.hpp
tolua++ -o tolua_operation.cpp -H tolua_operation.hpp -n Operation Operation.hpp
