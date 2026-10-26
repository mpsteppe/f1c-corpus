// Function: FUN_0046fe80 @ 0046fe80
// Size (bytes): 157


undefined4 * __thiscall FUN_0046fe80(undefined4 *param_1,undefined4 param_2)

{
  FUN_0048fe60();
  param_1[0x3b] = 0;
  param_1[0x3c] = 0xffffffff;
  *param_1 = &PTR_FUN_005a01a0;
  switch(param_2) {
  case 1:
    param_1[0x3a] = &DAT_007ceb64;
    return param_1;
  case 2:
    param_1[0x3a] = &DAT_007ceb7c;
    return param_1;
  case 3:
    param_1[0x3a] = &DAT_007ceb94;
    return param_1;
  case 4:
    param_1[0x3a] = &DAT_007cebac;
    return param_1;
  case 5:
    param_1[0x3a] = &DAT_007cebc4;
    return param_1;
  case 6:
    param_1[0x3a] = &DAT_007cebdc;
    return param_1;
  default:
    param_1[0x3a] = 0;
    return param_1;
  }
}


