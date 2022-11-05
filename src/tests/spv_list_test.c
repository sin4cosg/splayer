/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


struct stu {
    int id;
    struct list_head list;
};


struct stu *make_stu(int id)
{
    struct stu *s = (struct stu *) malloc(sizeof(struct stu));
    s->id = id;
    return s;
}


void
SPV_LIST_TEST()
{
    struct stu s;
    INIT_LIST_HEAD(&s.list);

    int stu_num = 5;
    struct stu *students[stu_num];
    for (int i = 0; i < stu_num; i++) {
        students[i] = make_stu(i);
        spv_list_add_tail(&students[i]->list, &s.list);
        spv_log_debug(NULL, 0, "alloc id:%d", students[i]->id);
    }

    struct list_head *it;
    spv_list_for_each(it, &s.list) {
        spv_log_debug(NULL, 0, "id:%d", spv_list_entry(it, struct stu, list)->id);
    }

    struct stu *tmp;
    spv_list_for_each_entry(tmp, &s.list, list) {
        spv_log_debug(NULL, 0, "each id:%d", tmp->id);
    }


    for (int i = 0; i < stu_num; i++) {
        spv_log_debug(NULL, 0, "free id:%d", students[i]->id);
        free(students[i]);
    }

}
