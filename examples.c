#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arena.h"

void arena_test() {
    Arena arena = {0};
    arena_init(&arena, 1024);
    printf("capacity: %zu, size: %zu, data ptr: %p\n", arena.capacity, arena.size, arena.data);

    void *ptr = arena_alloc(&arena, 24);
    printf("capacity: %zu, size: %zu, data ptr: %p\n", arena.capacity, arena.size, arena.data);

    void *ptr2 = arena_alloc(&arena, 1000);
    printf("capacity: %zu, size: %zu, data ptr: %p\n", arena.capacity, arena.size, arena.data);

    void *ptr3 = arena_alloc(&arena, 100);
    printf("capacity: %zu, size: %zu, data ptr: %p\n", arena.capacity, arena.size, arena.data);
    strcpy(ptr3, "Hello");
    printf(ptr3); printf("\n");

    void *ptr4 = arena_realloc(&arena, ptr3, 100, 150);
    printf("capacity: %zu, size: %zu, data ptr: %p\n", arena.capacity, arena.size, arena.data);
    printf(ptr4); printf("2\n");


    Arena *current = &arena;
    printf("\n");
    while (current != NULL) {
        printf("current: capacity: %zu, size: %zu, data ptr: %p\n", current->capacity, current->size, current->data);
        current = current->next;
    }

    void *ptr5 = arena_reset(&arena);
    printf("capacity: %zu, size: %zu, data ptr: %p\n", arena.capacity, arena.size, arena.data);

    arena_free(&arena);
}

int main(void) {
    arena_test();
}
