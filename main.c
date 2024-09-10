#include <stdio.h>

#include "example/Animal.h"
#include "example/Dog.h"
#include "example/Cat.h"
#include "ooc/src/malloc.h"

int main() {
    Animal *cat = (Animal *) new(Cat, 21);
    Animal *dog = (Animal *) new(Dog, 22);

    cat $call talk(cat);
    cat $call type(cat);

    printf("\n");

    dog $call talk(dog);
    dog $call type(dog);

    del(cat);
    del(dog);
}
