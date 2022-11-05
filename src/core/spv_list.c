/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


static spv_inline void
spv_list_add_core(struct list_head *node, struct list_head *prev,
                  struct list_head *next)
{
    /* prev <--> node <--> next */
    next->prev = node;
    node->next = next;
    node->prev = prev;
    prev->next = node;
}


static spv_inline void
spv_list_del_core(struct list_head *prev, struct list_head *next)
{
    /* prev <--> node <--> next */
    next->prev = prev;
    prev->next = next;
}


spv_inline void
INIT_LIST_HEAD(struct list_head *list)
{
    list->next = list;
    list->prev = list;
}


spv_inline void
spv_list_add(struct list_head *node, struct list_head *head)
{
    spv_list_add_core(node, head, head->next);
}


spv_inline void
spv_list_add_tail(struct list_head *node, struct list_head *head)
{
    spv_list_add_core(node, head->prev, head);
}


spv_inline void
spv_list_del(struct list_head *entry)
{
    spv_list_del_core(entry->prev, entry->next);
}


spv_inline void
spv_list_replace(struct list_head *old, struct list_head *new)
{
    new->next = old->next;
    new->next->prev = new;
    new->prev = old->prev;
    new->prev->next = new;
}


spv_int_t
spv_list_empty(const struct list_head *head)
{
    return head->next == head;
}


spv_int_t
spv_list_is_first(const struct list_head *list,
                  const struct list_head *head)
{
    return list->prev == head;
}


spv_int_t
spv_list_is_last(const struct list_head *list,
                 const struct list_head *head)
{
    return list->next == head;
}
