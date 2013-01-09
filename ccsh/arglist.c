//
//  arglist.c
//  ccsh
//
//  Created by xichen on 12-4-10.
//  Copyright (c) 2012 xichen. All rights reserved.
//

#include <stdio.h>
#include "arglist.h"
#include "common.h"
#include "error.h"

cc_arg_obj  *cc_arg_obj_make(const char *str, 
                             size_t len, 
                             cc_arg_obj *next,
                             char       *buf_pointer)
{
    cc_arg_obj  *obj = (cc_arg_obj *)malloc(sizeof(cc_arg_obj));
    if(!obj)
    {
        cc_err(CC_ERR_NOMEM);
        return NULL;
    }
    char *obj_str = (char *)malloc(len + 1);
    if(!obj_str)
    {
        cc_err(CC_ERR_NOMEM);
        free(obj);
        return NULL;
    }
    strncpy(obj_str, str, len);
    obj->str = obj_str;
    obj->len = len;
    obj->next = next;
    obj->buf_pointer = buf_pointer;
    return obj;
}


void        cc_arg_obj_free(cc_arg_obj *obj)
{
    free(obj->str);
    free(obj);
}


cc_arg_list *cc_arg_list_make(cc_arg_obj    *head)
{
    cc_arg_list *list = (cc_arg_list *)malloc(sizeof(cc_arg_list));
    if(!list)
    {
        cc_err(CC_ERR_NOMEM);
        return NULL;
    }
    
    list->head = list->tail = head;
    return list;
}

cc_arg_obj *cc_arg_list_append(cc_arg_list *list, cc_arg_obj     *obj)
{
    if(list->head == NULL)
    {
        list->head = list->tail = obj;
        return obj;
    }
    list->tail->next = obj;
    list->tail = obj;
    return obj;
}

void        cc_arg_list_free(cc_arg_list    *list)
{
    cc_arg_obj *head = list->head;
    while(head)
    {
        cc_arg_obj *next = head->next;
        cc_arg_obj_free(head);
        head = next;
    }
}

void        cc_arg_list_show_all_args(cc_arg_list   *list)
{
    cc_arg_obj *head = list->head;
    while (head != NULL)
    {
        printf("arg:%s", head->str);
        head = head->next;
    }
}


