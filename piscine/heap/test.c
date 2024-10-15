#include <criterion/criterion.h>
#include <stdio.h>

#include "heap.h"

// Test for heap creation
Test(heap_tests, create_heap)
{
    struct heap *heap = create_heap();
    cr_assert_not_null(heap, "Heap should be created successfully");
    cr_assert_eq(heap->size, 0, "Initial size should be 0");
    cr_assert_eq(heap->capacity, 8, "Initial capacity should be 8");
    delete_heap(heap);
}

// Test adding elements
Test(heap_tests, add_elements)
{
    struct heap *heap = create_heap();
    add(heap, 10);
    add(heap, 20);
    add(heap, 5);

    cr_assert_eq(heap->size, 3,
                 "Heap size should be 3 after adding three elements");
    cr_assert_eq(heap->array[0], 20,
                 "Root should be 20 after adding 10, 20, 5");

    delete_heap(heap);
}

// Test popping elements
Test(heap_tests, pop_elements)
{
    struct heap *heap = create_heap();
    add(heap, 8);
    print_heap(heap);
    putchar('\n');
    add(heap, 6);
    print_heap(heap);
    putchar('\n');
    add(heap, 1);
    print_heap(heap);
    putchar('\n');
    add(heap, 3);
    print_heap(heap);
    putchar('\n');
    add(heap, 4);

    print_heap(heap);
    putchar('\n');

    int popped_value = pop(heap);
    cr_assert_eq(popped_value, 8, "Popped value should be 8");
    // cr_assert_eq(heap->size, 4, "Heap size should be 2 after pop");
    print_heap(heap);
    putchar('\n');

    popped_value = pop(heap);
    cr_assert_eq(popped_value, 6, "Popped value should be 8");
    cr_assert_eq(heap->size, 3, "Heap size should be 2 after pop");
    print_heap(heap);
    putchar('\n');

    popped_value = pop(heap);
    cr_assert_eq(popped_value, 12, "Popped value should be 10");

    cr_assert_eq(heap->size, 3, "Heap size should be 1 after another pop");

    delete_heap(heap);
}
