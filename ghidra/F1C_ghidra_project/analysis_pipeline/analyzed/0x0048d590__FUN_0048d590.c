// Function: FUN_0048d590 @ 0048d590
// Size (bytes): 198


undefined4 __thiscall FUN_0048d590(int *param_1,int param_2,int param_3)

{
  short sVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  
  uVar2 = 0;
  iVar4 = 0;
  if (0 < param_3) {
    do {
      sVar1 = *(short *)(param_2 + iVar4 * 2);
      if (sVar1 == 0xcb) {
        if ((char)param_1[0x3c] == '\0') {
          param_1[0x38] = param_1[0x38] + -1;
          FUN_00488970();
        }
        else {
          piVar3 = (int *)(**(code **)(*param_1 + 0xb4))();
          if (piVar3 != (int *)0x0) {
            *piVar3 = *piVar3 + -1;
            (**(code **)(*param_1 + 0xa4))();
          }
        }
        (**(code **)(*param_1 + 0x2c))(1);
LAB_0048d644:
        uVar2 = 1;
      }
      else if (sVar1 == 0xcd) {
        if ((char)param_1[0x3c] == '\0') {
          param_1[0x38] = param_1[0x38] + 1;
          FUN_00488970();
        }
        else {
          piVar3 = (int *)(**(code **)(*param_1 + 0xb4))();
          if (piVar3 != (int *)0x0) {
            *piVar3 = *piVar3 + 1;
            (**(code **)(*param_1 + 0xa4))();
            (**(code **)(*param_1 + 0x2c))(1);
            goto LAB_0048d644;
          }
        }
        (**(code **)(*param_1 + 0x2c))(1);
        goto LAB_0048d644;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_3);
  }
  return uVar2;
}


