#!/bin/bash
grep -E "Sun" datebook
grep -E "^J" datebook
grep -E "700$" datebook
grep -Ev "834" datebook
grep -E "12/[0-9]+/[0-9]+" datebook
grep -E "408-[0-9]{3}-[0-9]{4}" datebook
grep -E "[A-Z][a-z]{4}, [A-Z]" datebook
grep -iE "^[^ ]* [k]" datebook
grep -E "[0-9]{6}$" datebook
grep -E "Lincoln|lincoln" datebook
