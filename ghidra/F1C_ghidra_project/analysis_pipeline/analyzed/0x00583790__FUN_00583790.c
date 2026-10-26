// Function: FUN_00583790 @ 00583790
// Size (bytes): 83


undefined4 __thiscall
FUN_00583790(int param_1,double *param_2,int *param_3,undefined4 *param_4,double param_5)

{
  if (*(char *)(param_1 + 0xc) == '\0') {
    return 0;
  }
  *(undefined1 *)(param_1 + 0xc) = 0;
  *param_2 = (param_5 - *(double *)(param_1 + 0x10)) + *(double *)(param_1 + 0x18);
  *param_4 = *(undefined4 *)(param_1 + 0x120);
  if (0 < *(int *)(param_1 + 0x120)) {
    *param_3 = param_1 + 0x20;
    return 1;
  }
  *param_3 = 0;
  return 1;
}


