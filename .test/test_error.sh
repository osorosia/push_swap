#!/bin/bash

assert1() {
    expected="$1"
    input="$2"

    ../push_swap "$input" 2> tmp.stderr
    actual=$(cat tmp.stderr)

    if [ "$actual" = "$expected" ]; then
        echo "OK: $input => $expected"
    else
        echo "**NG: $input => $expected expected, but got $actual."
        exit 1
    fi
}

assert2() {
    expected="$1"
    input="$2"

    ../push_swap $input 2> tmp.stderr
    actual=$(cat tmp.stderr)

    if [ "$actual" = "$expected" ]; then
        echo "OK: $input => $expected"
    else
        echo "**NG: $input => $expected expected, but got $actual."
        exit 1
    fi
}

echo "------$0------"
# 引数1つ
assert1 Error "1 1"
assert1 Error "--1"
assert1 Error "--1 1"
assert1 Error "++1"
assert1 Error "++1 1"
assert1 Error "2147483648"
assert1 Error "2147483648 1"
assert1 Error "-2147483649"
assert1 Error "-2147483649 1"
# 引数が複数
assert2 Error "1 1"
assert2 Error "--1"
assert2 Error "--1 1"
assert2 Error "++1"
assert2 Error "++1 1"
assert2 Error "2147483648"
assert2 Error "2147483648 1"
assert2 Error "-2147483649"
assert2 Error "-2147483649 1"
