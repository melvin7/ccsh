//
//  error.c
//  ccsh
//
//  Created by xichen on 12-4-10.
//  Copyright (c) 2012 xichen. All rights reserved.
//

#include <stdio.h>
#include "error.h"

cc_err_info errs[] = 
{
    {   CC_OK,              "no error"},
    {   CC_ERR_NOMEM,       "no enough mem"}
};

int         errno;

void    cc_err(CC_ERR err_no)
{
    printf("%s\n", errs[err_no].err_str);
    errno = CC_ERR_NOMEM;
}