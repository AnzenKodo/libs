#include "arena.h"
#include "hash.h"
#include "str.h"
#include "base.h"
#include "args.h"

void arena_test(void) {
    Arena arena = {0};
    arena_init(&arena, 1024);
    printf("capacity: %zu, size: %zu, data ptr: %p\n", arena.capacity, arena.size, arena.data);
    arena_alloc(&arena, 24);
    printf("capacity: %zu, size: %zu, data ptr: %p\n", arena.capacity, arena.size, arena.data);

    arena_alloc(&arena, 1000);
    printf("capacity: %zu, size: %zu, data ptr: %p\n", arena.capacity, arena.size, arena.data);

    void *ptr3 = arena_alloc(&arena, 100);
    printf("capacity: %zu, size: %zu, data ptr: %p\n", arena.capacity, arena.size, arena.data);
    str_cpy(ptr3, "Hello");
    printf(ptr3); printf("\n");

    void *ptr4 = arena_realloc(&arena, ptr3, 100, 150);
    printf("capacity: %zu, size: %zu, data ptr: %p\n", arena.capacity, arena.size, arena.data);
    base_print(ptr4); base_print("2");

    Arena *current = &arena;
    base_print("\n");
    while (current != NULL) {
        printf("current: capacity: %zu, size: %zu, data ptr: %p\n", current->capacity, current->size, current->data);
        current = current->next;
    }

    arena_reset(&arena);
    printf("capacity: %zu, size: %zu, data ptr: %p\n", arena.capacity, arena.size, arena.data);

    arena_free(&arena);
}

void ht_test(void) {
    assert(hash_stb6432shift("Hello", 1) == 7871771224773941061);
    assert(hash_djbx33a("Hello") == 140207504);
    assert(hash_djb2("Hello") == 210676686969);
    assert(hash_sdbm("Hello") == 5142962386210502930);
    assert(hash_2lose("Hello") == 500);
    assert(hash_adler32("Hello") == 93061621);
    assert(hash_crc32("Hello") == (unsigned int) -137262718);
    assert(hash_xor8("Hello") == 12);

    unsigned int num_mix = hash_int_mix(420, 12, 69);
    assert(num_mix == 1501094981);
    assert(hash_int_jenkins(num_mix) == 317653115);
    assert(hash_int_wang32shift(num_mix) == 1265322998);
    assert(hash_int_wang32shiftmult(num_mix) == 608512410);
    assert(hash_int_wang6432shift(num_mix) == 981695088);
    assert(hash_int_wang64shift(num_mix) == 5360857491066763507);
}

void args_test(int argc, char **argv) {
    args_init(argc, argv);
    args_get("--name", "-n", "Name of person");
    args_get_int("--age", "-a", "Age of person");
    args_get_int("--weight", "-w", "Weight of person");
    if (args_has("--help", "-h", "Show help")) {
        args_print_help(
            "example.c",
            "Examples of AK Libs.",
            "[options] [value]",
            "SPDX-License-Identifier: MIT (https://spdx.org/licenses/MIT)"
        );
    }
}

int main(int argc, char *argv[]) {
    arena_test();
    ht_test();
    args_test(argc, argv);
}
