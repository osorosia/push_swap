#!/bin/bash
assert() {
    input="$1"

    echo "$input" | ./checker "4 1 3 2 5" 1>/dev/null 2>tmp.stderr
    expected=$(cat tmp.stderr)

    echo "$input" | ../checker "4 1 3 2 5" 1>/dev/null 2>tmp.stderr
    actual=$(cat tmp.stderr)

    if [ "$actual" = "$expected" ]; then
        echo "OK: $input => $expected"
    else
        echo "**NG: $input => $expected expected, but got $actual."
        exit 1
    fi
}

echo "------$0------"
# 正常系
assert "ss"
assert "sa"
assert "sb"
assert "pa"
assert "pb"
assert "ra"
assert "rb"
assert "rr"
assert "rra"
assert "rrb"
assert "rrr"
assert "pa
pa"

# 異常系
assert "ss "
assert "sa "
assert "sb "
assert "pa "
assert "pb "
assert "ra "
assert "rb "
assert "rr "
assert "rra "
assert "rrb "
assert "rrr "
assert " ss"
assert " sa"
assert " sb"
assert " pa"
assert " pb"
assert " ra"
assert " rb"
assert " rr"
assert " rra"
assert " rrb"
assert " rrr"
assert "sss"
assert "sas"
assert "sas"
assert "sbs"
assert "rrrr"
assert "rrar"
assert "rrbr"
assert "pa 
pa"
