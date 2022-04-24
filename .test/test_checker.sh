#!/bin/bash

assert1() {
    expected="$1"
    input="$2"

    ../push_swap "$input" 2>/dev/null | ../checker "$input" 1>tmp.stdout 2>/dev/null
    actual=$(cat tmp.stdout)

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

    ../push_swap $input 2>/dev/null | ../checker $input 1>tmp.stdout 2>/dev/null
    actual=$(cat tmp.stdout)

    if [ "$actual" = "$expected" ]; then
        echo "OK: $input => $expected"
    else
        echo "**NG: $input => $expected expected, but got $actual."
        exit 1
    fi
}

echo "------$0------"
assert1 OK "2 4 1 5 7"
assert2 OK "2 4 1 5 7"
