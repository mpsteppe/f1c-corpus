// Function: FUN_00554700 @ 00554700
// Size (bytes): 142


void __thiscall FUN_00554700(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    param_1[0x4e6] = 0;
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 0x14c))((int *)param_1[0x440],0,0,0);
    *param_1 = uVar2;
  }
  else {
    if (param_1[0x4e6] != *(int *)(param_2 + 0x20)) {
      param_1[0x4e6] = *(int *)(param_2 + 0x20);
      uVar2 = (**(code **)(*(int *)param_1[0x440] + 0x14c))
                        ((int *)param_1[0x440],0,*(undefined4 *)(param_2 + 0x20),
                         *(undefined4 *)(param_2 + 8));
      *param_1 = uVar2;
    }
    iVar1 = *(int *)(param_2 + 4);
    if ((param_1[0x4e7] != iVar1) && (iVar1 != -1)) {
      param_1[0x4e7] = iVar1;
      uVar2 = (**(code **)(*(int *)param_1[0x440] + 0x130))
                        ((int *)param_1[0x440],*(undefined4 *)(param_2 + 4));
      *param_1 = uVar2;
      return;
    }
  }
  return;
}


