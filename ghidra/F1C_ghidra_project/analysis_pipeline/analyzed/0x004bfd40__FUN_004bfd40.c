// Function: FUN_004bfd40 @ 004bfd40
// Size (bytes): 74


undefined4 __thiscall FUN_004bfd40(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_2 < (int)param_1[3]) {
    if (param_2 < 0) {
      param_1[2] = 0;
    }
    else {
      param_1[2] = *param_1;
      while ((0 < param_2 && (param_1[2] != 0))) {
        param_2 = param_2 + -1;
        param_1[2] = *(undefined4 *)(param_1[2] + 4);
      }
    }
    if (((int *)param_1[2] != (int *)0x0) &&
       (puVar1 = *(undefined4 **)param_1[2], puVar1 != (undefined4 *)0x0)) {
      uVar2 = *puVar1;
    }
  }
  return uVar2;
}


