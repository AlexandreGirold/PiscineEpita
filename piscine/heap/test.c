#include <criterion/criterion.h>
#include "heap.h"

// Test for heap creation
Test(heap_tests, create_heap) {
    struct heap *heap = create_heap();
    cr_assert_not_null(heap, "Heap should be created successfully");
    cr_assert_eq(heap->size, 0, "Initial size should be 0");
    cr_assert_eq(heap->capacity, 8, "Initial capacity should be 8");
    delete_heap(heap);
}

// Test adding elements
Test(heap_tests, add_elements) {
    struct heap *heap = create_heap();
    add(heap, 10);
    add(heap, 20);
    add(heap, 5);
    
    cr_assert_eq(heap->size, 3, "Heap size should be 3 after adding three elements");
    cr_assert_eq(heap->array[0], 20, "Root should be 20 after adding 10, 20, 5");
    
    delete_heap(heap);
}

// Test popping elements
Test(heap_tests, pop_elements) {
    struct heap *heap = create_heap();
    add(heap, 10);
    add(heap, 20);
    add(heap, 5);
    
    int popped_value = pop(heap);
    cr_assert_eq(popped_value, 20, "Popped value should be 20");
    cr_assert_eq(heap->size, 2, "Heap size should be 2 after pop");

    popped_value = pop(heap);
    cr_assert_eq(popped_value, 10, "Popped value should be 10");
    
    cr_assert_eq(heap->size, 1, "Heap size should be 1 after another pop");
    
    delete_heap(heap);
}

// Test heap print (output captured)
Test(heap_tests, print_heap) {
    struct heap *heap = create_heap();
    add(heap, 10);
    add(heap, 20);
    add(heap, 5);

    // Redirect stdout to capture print_heap output
    FILE *output = fopen("output.txt", "w");
    if (output) {
        fflush(stdout);
        int saved_stdout = dup(fileno(stdout));
        dup2(fileno(output), fileno(stdout));

        print_heap(heap);
        
        fflush(stdout);
        dup2(saved_stdout, fileno(stdout));
        close(saved_stdout);
        fclose(output);
        
        // Check the output
        FILE *file = fopen("output.txt", "r");
        char buffer[100];
        fgets(buffer, sizeof(buffer), file);
        cr_assert_str_eq(buffer, "20 10 5 \n", "Print output does not match expected format");
        fclose(file);
        remove("output.txt");
    }

    delete_heap(heap);
}

// Test for deleting the heap
Test(heap_tests, delete_heap) {
    struct heap *heap = create_heap();
    add(heap, 10);
    
    cr_assert_not_null(heap, "Heap should be created successfully");
    delete_heap(heap);
    cr_assert_eq(heap->size, 0, "Heap should not be usable after deletion");
}

