//
//  str_process.c
//  ccsh
//
//  Created by xichen on 12-4-10.
//  Copyright (c) 2012 xichen. All rights reserved.
//

#include <stdio.h>
#include "str_process.h"
#include <string.h>

inline bool    cc_is_blank(char ch)
{
    return ch == '\n' 
        || ch == '\t' 
        || ch == ' ';
}

char *cc_get_next_blank(const char *str)
{
    while (!cc_is_blank(*str) && *str != '\0')
        ++str;
    return (char *)str;
}

void    cc_skip_blank(char  **str)
{
    while(cc_is_blank(**str) && *str != '\0')
    {
        (*str)++;
    }
}

bool    cc_str_is(const char *str1, const char *str2)
{
    return strcmp(str1, str2) == 0;
}

inline bool    cc_str_begin_with(const char *str, char ch)
{
    return str[0] == ch;
}


