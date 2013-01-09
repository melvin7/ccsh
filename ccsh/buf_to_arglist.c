//
//  buf_to_arglist.c
//  ccsh
//
//  Created by xichen on 12-4-10.
//  Copyright (c) 2012 xichen. All rights reserved.
//

#include <stdio.h>
#include "buf_to_arglist.h"
#include <stdlib.h>
#include "error.h"
#include "str_process.h"

cc_arg_list *cc_buf_to_arglist(const char *buf)
{
    char    *temp = (char *)buf;
    cc_arg_list *list = cc_arg_list_make(NULL);
    if(!list)
    {
        cc_err(CC_ERR_NOMEM);
        return NULL;
    }
    while (*temp)
    {
        char    *next_blank = cc_get_next_blank(temp);
        if(temp != next_blank)
        {
            size_t len = next_blank - temp;
            cc_arg_obj *obj = cc_arg_obj_make(temp, len, NULL, temp);
            if(!obj)
            {
                cc_err(CC_ERR_NOMEM);
                cc_arg_list_free(list);
                return NULL;
            }
            cc_arg_list_append(list, obj);
        }
        temp = next_blank;
        cc_skip_blank(&temp);
    }
    return list;
}

