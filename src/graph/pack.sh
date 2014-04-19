#!/bin/bash

# Use xxd to convert each asset into a C string literal that can be baked into
# the executionable.


# Prepend a common header to the given  file
# Note: This has the important side-effect of truncating any existing file.
function prepend_comment {

    echo "/* THIS FILE IS AUTOMATICALLY GENERATED */" > $1

}



# Append a common include directive to a given .c file
function append_c {

    echo "#include \"graph/baked.h\"" >> "$1"
    
}



# Messy function to append externs prototype to the given .h file
function append_h {

    echo -n "extern unsigned char "                 >> "baked.h"
    echo -n $1 | sed 's/-/_/g' | sed 's/\./_/g'     >> "baked.h"
    echo    "[];"                                   >> "baked.h"
    
    echo -n "extern unsigned int "                  >> "baked.h"
    echo -n $1 | sed 's/-/_/g' | sed 's/\./_/g'     >> "baked.h"
    echo    "_len;"                                 >> "baked.h"
    
}



prepend_comment "baked.h"
prepend_comment "baked.c"
append_c "baked.c"

for f in *.png
do
    xxd -i "$f" >> "baked.c"
    append_h $f
done


