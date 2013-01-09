//
//  arglist.h
//  ccsh
//
//  Created by xichen on 12-4-10.
//  Copyright (c) 2012 xichen. All rights reserved.
//

#ifndef CCSH_ARGLIST_H
#define CCSH_ARGLIST_H

typedef struct _cc_arg_obj
{
    char    *str;
    size_t  len;
    struct  _cc_arg_obj    *next;
    char    *buf_pointer;       // the pointer that points the buf, for possible use, eg. echo command
}cc_arg_obj;

typedef struct _cc_arg_list
{
    cc_arg_obj              *head;
    cc_arg_obj              *tail;
}cc_arg_list;


cc_arg_obj  *cc_arg_obj_make(const char *str, 
                             size_t len, 
                             cc_arg_obj *next,
                             char       *buf_pointer);
void        cc_arg_obj_free(cc_arg_obj *obj);

cc_arg_list *cc_arg_list_make(cc_arg_obj    *head);
cc_arg_obj *cc_arg_list_append(cc_arg_list *list, cc_arg_obj     *obj);
void        cc_arg_list_free(cc_arg_list    *list);
void        cc_arg_list_show_all_args(cc_arg_list   *list);

#endif
