// Function: FUN_005063a5 @ 005063a5
// Size (bytes): 282


int __thiscall FUN_005063a5(int *param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  param_1[1] = 0;
  *param_1 = 0;
  param_1[2] = param_4;
  if ((((param_4 & 0xffff) == 0) || (5 < (param_4 & 0xffff))) || ((param_4 & 0xfff00000) != 0)) {
    return -0x7789f794;
  }
  *(uint *)(param_2 + 0x40) = param_4 & 0x80000;
  iVar1 = FUN_0050b8a9(param_2);
  param_1[1] = iVar1;
  if (iVar1 != 0) {
    iVar1 = FUN_0050b8a9(param_3);
    *param_1 = iVar1;
    if (iVar1 != 0) {
      iVar1 = FUN_005076fe(iVar1);
      if (iVar1 < 0) goto LAB_00506491;
      iVar1 = FUN_00504508();
      if ((((-1 < iVar1) || (iVar1 = FUN_00504640(), -1 < iVar1)) ||
          ((iVar1 = FUN_00504731(), -1 < iVar1 ||
           ((iVar1 = FUN_00504933(), -1 < iVar1 || (iVar1 = FUN_00504b37(), -1 < iVar1)))))) ||
         ((iVar1 = FUN_00504f5a(), -1 < iVar1 ||
          ((((iVar1 = FUN_005054ec(), -1 < iVar1 || (iVar1 = FUN_005058d2(), -1 < iVar1)) ||
            (iVar1 = FUN_00506003(), -1 < iVar1)) || (iVar1 = FUN_00502f31(), -1 < iVar1)))))) {
        iVar1 = 0;
        goto LAB_00506491;
      }
    }
  }
  iVar1 = -0x7fffbffb;
LAB_00506491:
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1])(1);
    param_1[1] = 0;
  }
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*param_1)(1);
    *param_1 = 0;
  }
  return iVar1;
}


