// Function: FUN_00554f80 @ 00554f80
// Size (bytes): 279


undefined4 __thiscall FUN_00554f80(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_3 + 0x54);
  if ((*(uint *)(iVar1 + 0x18) & 0x400) == 0) {
    iVar3 = FUN_00554e90(param_3);
    *param_1 = iVar3;
    if (iVar3 == -1) {
      if (param_2 != 0) {
        iVar3 = FUN_00545f40();
        for (iVar3 = *(int *)(iVar3 + 0x28); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x5c)) {
          iVar2 = *(int *)(iVar3 + 0x54);
          if (((((*(uint *)(iVar2 + 0x18) & 0x80000) == 0) &&
               ((*(uint *)(iVar2 + 0x18) & 0x400) != 0)) &&
              (DAT_0059e440 < *(float *)(iVar2 + 0x38))) &&
             (((*(int *)(iVar3 + 0x50) == *(int *)(param_3 + 0x50) &&
               (*(int *)(iVar2 + 0x30) == *(int *)(iVar1 + 0x30))) &&
              ((*(int *)(iVar2 + 0x1c) == *(int *)(iVar1 + 0x1c) &&
               (*(int *)(iVar2 + 0x20) == *(int *)(iVar1 + 0x20))))))) {
            *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | 8;
            *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0x14);
            *(undefined4 *)(iVar2 + 0x14) = 0;
            *(undefined4 *)(iVar2 + 0x38) = 0xbf800000;
            *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) & 0xfffffbf7;
            goto LAB_00555056;
          }
        }
      }
      iVar3 = FUN_0055c9b0();
      if (iVar3 != 0) {
        return 0;
      }
      FUN_00554e10(param_2);
      iVar3 = FUN_00554e90(param_3);
      *param_1 = iVar3;
      if (iVar3 != 0) {
        return 0;
      }
    }
LAB_00555056:
    if (*(int *)(iVar1 + 0x10) != 0) {
      iVar3 = (**(code **)(*(int *)param_1[0x440] + 0x74))
                        ((int *)param_1[0x440],*(int *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14))
      ;
      *param_1 = iVar3;
      if (iVar3 != 0) {
        return 0;
      }
      *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | 0x400;
    }
  }
  *(undefined4 *)(iVar1 + 0x38) = 0;
  return 1;
}


