#!/bin/bash

assert_args1() {
    expected="$1"
    input="$2"

    echo 'sa' | ../checker "$input" 1>/dev/null 2> tmp.stderr
    actual=$(cat tmp.stderr)

    if [ "$actual" = "$expected" ]; then
        echo "OK: $input => $expected"
    else
        echo "**NG: $input => $expected expected, but got $actual."
        exit 1
    fi
}

assert_args2() {
    expected="$1"
    input="$2"

    echo 'sa' | ../checker $input 1>/dev/null 2> tmp.stderr
    actual=$(cat tmp.stderr)

    if [ "$actual" = "$expected" ]; then
        echo "OK: $input => $expected"
    else
        echo "**NG: $input => $expected expected, but got $actual."
        exit 1
    fi
}

assert_stdin() {
    expected="$1"
    input="$2"

    echo "$input" | ../checker 1 1>/dev/null 2> tmp.stderr
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
assert_args1 Error "1 1"
assert_args1 Error "1 3 1"
assert_args1 Error "--1"
assert_args1 Error "--1 2"
# 引数が複数
assert_args2 Error "1 1"
assert_args2 Error "1 3 1"
assert_args2 Error "--1"
assert_args2 Error "--1 2"
