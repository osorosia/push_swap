#!/bin/bash

# 引数が1つ
assert1() {
    expected="$1"
    input="$2"

    ../push_swap "$input" 2>/dev/null | ./checker "$input" 1> tmp.stdout
    actual=$(cat tmp.stdout)

    if [ "$actual" = "$expected" ]; then
        echo "OK: $input => $expected"
    else
        echo "**NG: $input => $expected expected, but got $actual."
        exit 1
    fi
}

# 引数が複数
assert2() {
    expected="$1"
    input="$2"

    ../push_swap $input 2>/dev/null | ./checker $input 1> tmp.stdout
    actual=$(cat tmp.stdout)

    if [ "$actual" = "$expected" ]; then
        echo "OK: $input => $expected"
    else
        echo "**NG: $input => $expected expected, but got $actual."
        exit 1
    fi
}

echo "------$0------"
# 引数1つ
assert1 OK "2 4 1 5 7"
assert1 OK "2147483647"
assert1 OK "-2147483648"
assert1 OK "2147483647 -2147483648"
assert1 OK "-00002    001"
# 引数が複数
assert2 OK "2 4 1 5 7"
assert2 OK "2147483647"
assert2 OK "-2147483648"
assert2 OK "2147483647 -2147483648"
assert2 OK "-00002    001"
