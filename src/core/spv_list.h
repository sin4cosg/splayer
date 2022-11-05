/*
 * Copyright (C) SUMMER
 */


#ifndef SPV_LIST_H
#define SPV_LIST_H


#include <spv_config.h>
#include <spv_core.h>


struct list_head {
    struct list_head *next, *prev;
};


#define SPV_LIST_HEAD_INIT(name) { &(name), &(name) }

#define SPV_LIST(name)                                                      \
    struct list_head name = SPV_LIST_HEAD_INIT(name)

#define spv_list_entry(ptr, type, member)                                   \
    container_of(ptr, type, member)

#define spv_list_first_entry(ptr, type, member)                             \
    spv_list_entry((ptr)->next, type, member)

#define spv_list_last_entry(ptr, type, member)                              \
    spv_list_entry((ptr)->prev, type, member)

#define spv_list_for_each(pos, head)                                        \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#define spv_list_for_each_entry(pos, head, member)                          \
    for (pos = spv_list_entry((head)->next, typeof(*pos), member);          \
         &pos->member != (head);                                            \
         pos = spv_list_entry(pos->member.next, typeof(*pos), member))


void INIT_LIST_HEAD(struct list_head *list);
void spv_list_add(struct list_head *node, struct list_head *head);
void spv_list_add_tail(struct list_head *node, struct list_head *head);
void spv_list_del(struct list_head *entry);
void spv_list_replace(struct list_head *old, struct list_head *new);
spv_int_t spv_list_empty(const struct list_head *head);
spv_int_t spv_list_is_first(const struct list_head *list, const struct list_head *head);
spv_int_t spv_list_is_last(const struct list_head *list, const struct list_head *head);


#endif  // SPV_LIST_H
