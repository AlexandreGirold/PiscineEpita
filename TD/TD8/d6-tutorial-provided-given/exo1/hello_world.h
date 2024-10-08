#ifndef HELLO_WORLD_H
#define HELLO_WORLD_H

void hello_world(char *s);

#endif

#ifdef FRENCH
#define TOTO hello_world("Bonjour le monde")

#else
#define TOTO hello_world("Hello, world");


#endif
