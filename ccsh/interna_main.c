//
//  internal_main.c
//  ccsh
//
//  Created by xichen on 12-4-10.
//  Copyright (c) 2012 xichen. All rights reserved.
//

#include <stdio.h>
#include "internal_main.h"
#include "tip_info.h"
#include <string.h>
#include "buf_to_arglist.h"
#include "error.h"
#include "str_process.h"
#include "version.h"
#include <stdlib.h>
#include "echo.h"

int cc_internal_main(int argc, const char *argv[])
{
    char    buf[4096];
    char    *temp_buf = (char *)buf;
    
repeat:  
    cc_print_tipinfo();

    memset(buf, 0, sizeof(buf));
    temp_buf = fgets(buf, sizeof(buf), stdin);

    if(temp_buf == NULL)
    {
        goto repeat;
    }
    else
    {
        cc_process_string(buf);
        goto repeat;
    }
    
    return 0;
}

static int cc_process_string(char *str)
{
    if(str[0] == '\n')
        return 0;
    str[strlen(str) - 1] = '\0';
    
    cc_arg_list *list = cc_buf_to_arglist(str);
    if(!list)
    {
        return errno;
    }
    // cc_arg_list_show_all_args(list);
    if(cc_str_is(list->head->str, "echo"))  // like print command
    {
        cc_execute_echo(list, str);
    }
    else if(cc_str_is(list->head->str, "hello"))
    {
        printf("hello, i am a interpreter!\n");
    }
    else if(cc_str_is(list->head->str, "ver"))
    {
        cc_show_version();
    }
    else if(cc_str_is(list->head->str, "quit") || cc_str_is(list->head->str, "exit"))
    {
        exit(0);
    }
    else
    {
        printf("no such command...\n");
    }
    cc_arg_list_free(list);
    
    return 0;
}

