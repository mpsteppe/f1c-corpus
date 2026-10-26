// Function: FUN_00495930 @ 00495930
// Size (bytes): 61


undefined4 FUN_00495930(int *param_1)

{
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  do {
    (**(code **)(*param_1 + 0xa0))();
    FUN_00495930(param_1[0x24]);
    param_1 = (int *)param_1[0x23];
  } while (param_1 != (int *)0x0);
  return 0;
}


