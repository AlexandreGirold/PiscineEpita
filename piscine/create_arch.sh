#!/bin/sh

if [ "$#" -ne 1 ]; then
    echo " Provide 1 argument (name of file and folder)"
else
    mkdir "$1"
    cd "$1"
    touch "$1.c"
    touch "$1.h"
    touch "test.c"
    var="$1_H"
    varupp="${var^^}"

    echo -e "#include <stddef.h>\n#include <stdio.h>\n" > "$1.c"
    echo -e "#ifndef $varupp\n#define $varupp\n\n#include <stddef.h>\n\n#endif /* !$varupp */" > "$1.h"
fi
