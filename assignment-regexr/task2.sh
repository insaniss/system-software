#!/bin/bash
grep -oE "\([0-9]{3}\) [0-9]{3}-[0-9]{4}" db
grep -i "dan" db | grep -oE "\([0-9]{3}\) [0-9]{3}-[0-9]{4}"
grep -i "susan" db | grep -oiE "[a-z]+ [a-z]+.\([0-9]{3}\) [0-9]{3}-[0-9]{4}"
grep -ioE "[a-z]+:" db | grep -ioE "^d[a-z]*"
grep -ioE "^(c|e)[a-z]*" db
grep -ioE "^[a-z]+" db | grep -ioE "^[a-z]{4}$"
grep -E "\(916\)" db | grep -ioE "^[a-z]+"
grep -iE "mike" db | grep -oE ":[0-9]{3}:" | grep -oE "[0-9]+"
grep -oE "^[A-Z][a-z]+ [A-Z][a-z]+" db | sed -E "s/[a-z]+/./;s/[a-z]+/./"
grep -E "1(1|2)/[0-9]+/[0-9]+" db
