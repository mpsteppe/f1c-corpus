// Function: FUN_0059bb00 @ 0059bb00
// Size (bytes): 175


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0059bb00(FILE *param_1,int *param_2,uint param_3,uint param_4)

{
  undefined4 local_8;
  
  local_8 = 0;
  if ((param_3 != 4) &&
     (((param_4 < 2 || (0x7fffffff < param_4)) || ((param_3 != 0 && (param_3 != 0x40)))))) {
    return 0xffffffff;
  }
  param_4 = param_4 & 0xfffffffe;
  FUN_0058c1b1(param_1);
  FUN_0058a05a(param_1);
  __freebuf(param_1);
  *(ushort *)&param_1->_flag = (ushort)param_1->_flag & 0xc2f3;
  if ((param_3 & 4) == 0) {
    if (param_2 == (int *)0x0) {
      param_2 = _malloc(param_4);
      if (param_2 == (int *)0x0) {
        _DAT_008d3ec8 = _DAT_008d3ec8 + 1;
        local_8 = 0xffffffff;
        goto LAB_0059bba0;
      }
      *(ushort *)&param_1->_flag = (ushort)param_1->_flag | 0x408;
    }
    else {
      param_1->_flag = param_1->_flag | 0x500;
    }
  }
  else {
    param_1->_flag = param_1->_flag | 4;
    param_2 = &param_1->_charbuf;
    param_4 = 2;
  }
  param_1->_cnt = 0;
  param_1->_bufsiz = param_4;
  param_1->_base = (char *)param_2;
  param_1->_ptr = (char *)param_2;
LAB_0059bba0:
  FUN_0058c203(param_1);
  return local_8;
}


