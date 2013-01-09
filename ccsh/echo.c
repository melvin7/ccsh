//
//  echo.c
//  ccsh
//
//  Created by xichen on 12-4-10.
//  Copyright (c) 2012 xichen. All rights reserved.
//

#include <stdio.h>
#include "echo.h"
#include "str_process.h"
#include <string.h>

int     cc_execute_echo(cc_arg_list    *arg_list, const char *buf)
{
    cc_arg_obj *arg = arg_list->head->next;
    if(!arg)
        return 0;
    if(cc_str_begin_with(arg->str, '-'))
    {
        size_t len = strlen(arg->str);
        if(len != 2)
        {
            printf("%s\n", arg->buf_pointer);
            return 0;
        }
        else
        {
            if(arg->str[1] == 'n')
            {
                arg = arg->next;
                printf("%s", arg->buf_pointer);
                return 0;
            }
            else
            {
                printf("%s\n", arg->buf_pointer);
                return 0;
            }
        }
    }
    else
    {
        printf("%s\n", arg->buf_pointer);
        return 0;
    }
    
    return 0;
}