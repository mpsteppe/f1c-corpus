// Function: FUN_0054c510 @ 0054c510
// Strings:  [Surface / mat lib mismatch]


undefined4 __thiscall FUN_0054c510(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = param_3;
  *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + param_1 + param_3;
  *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + param_1 + param_3;
  iVar7 = 0;
  *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x124) + param_1 + param_3;
  *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + param_1 + param_3;
  param_3 = 0;
  if (0 < *(int *)(param_1 + 0x118)) {
    do {
      piVar1 = (int *)(iVar7 + 0xc + *(int *)(param_1 + 0x11c));
      *piVar1 = *piVar1 + param_1 + iVar5;
      *(int *)(iVar7 + 0x18 + *(int *)(param_1 + 0x11c)) = param_1;
      piVar1 = (int *)(iVar7 + 0x14 + *(int *)(param_1 + 0x11c));
      *piVar1 = *piVar1 + param_1 + iVar5;
      uVar2 = FUN_00548850(*(undefined4 *)(iVar7 + 4 + *(int *)(param_1 + 0x11c)));
      iVar3 = FUN_005477f0(uVar2);
      if (iVar3 == 0) {
        FUN_0053c590(0xffffffff,s_Surface___mat_lib_mismatch_005dbfd0);
        return 0xffffffff;
      }
      *(int *)(iVar7 + 4 + *(int *)(param_1 + 0x11c)) = iVar3;
      iVar6 = 0;
      if (0 < *(int *)(iVar3 + 0xa4)) {
        iVar4 = *(int *)(iVar3 + 0xa8) + 0x60;
        do {
          if (1 < *(int *)(iVar4 + -0x18)) {
            *(byte *)(param_1 + 0x16) = *(byte *)(param_1 + 0x16) | 8;
          }
          if ((*(byte *)(iVar3 + 0x9c) & 0x40) != 0) {
            *(byte *)(param_1 + 0x16) = *(byte *)(param_1 + 0x16) | 0x10;
          }
          if ((*(byte *)(iVar4 + 2) & 0x20) != 0) {
            *(byte *)(param_1 + 0x16) = *(byte *)(param_1 + 0x16) | 0x10;
          }
          iVar4 = iVar4 + 0x94;
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(int *)(iVar3 + 0xa4));
      }
      *(undefined4 *)(iVar7 + 0x1c + *(int *)(param_1 + 0x11c)) = 0;
      *(undefined4 *)(iVar7 + 0x24 + *(int *)(param_1 + 0x11c)) = 0;
      param_3 = param_3 + 1;
      iVar7 = iVar7 + 0x40;
    } while (param_3 < *(int *)(param_1 + 0x118));
  }
  if (0 < *(int *)(param_1 + 0x130)) {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x800000;
  }
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x120)) {
    iVar7 = 0;
    do {
      *(int *)(iVar7 + 8 + *(int *)(param_1 + 0x124)) =
           *(int *)(iVar7 + 8 + *(int *)(param_1 + 0x124)) * 0x40 + *(int *)(param_1 + 0x11c);
      iVar5 = iVar5 + 1;
      iVar7 = iVar7 + 0x24;
    } while (iVar5 < *(int *)(param_1 + 0x120));
  }
  return 0;
}


