// Function: FUN_005518a0 @ 005518a0
// Size (bytes): 314


undefined4 __thiscall FUN_005518a0(int param_1,int *param_2,undefined4 param_3,byte param_4)

{
  byte bVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  bool bVar8;
  
  pvVar2 = operator_new(0x34);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_00550870();
  }
  iVar4 = FUN_005508a0(param_3);
  if (iVar4 != 0) {
    if (iVar3 != 0) {
      FUN_00557470();
      FUN_00587bcf(iVar3);
    }
    if (param_2 != (int *)0x0) {
      *param_2 = 0;
    }
    return 0xffffffff;
  }
  if (((param_4 & 1) == 0) && (iVar4 = *(int *)(param_1 + 0x118), iVar4 != 0)) {
    do {
      pbVar5 = (byte *)(iVar4 + 0x1c);
      pbVar7 = (byte *)(iVar3 + 0x1c);
      do {
        bVar1 = *pbVar5;
        bVar8 = bVar1 < *pbVar7;
        if (bVar1 != *pbVar7) {
LAB_00551949:
          iVar6 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_0055194e;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar5[1];
        bVar8 = bVar1 < pbVar7[1];
        if (bVar1 != pbVar7[1]) goto LAB_00551949;
        pbVar5 = pbVar5 + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar1 != 0);
      iVar6 = 0;
LAB_0055194e:
      if (iVar6 == 0) {
        FUN_00550ac0();
        if (iVar3 != 0) {
          FUN_00557470();
          FUN_00587bcf(iVar3);
        }
        if (param_2 != (int *)0x0) {
          *param_2 = iVar4;
        }
        return 0xfffffffe;
      }
      iVar4 = *(int *)(iVar4 + 0x30);
    } while (iVar4 != 0);
  }
  iVar6 = 0;
  iVar4 = *(int *)(param_1 + 0x118);
  if (iVar4 == 0) {
    *(int *)(param_1 + 0x118) = iVar3;
  }
  else {
    iVar6 = iVar4;
    for (iVar4 = *(int *)(iVar4 + 0x30); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x30)) {
      iVar6 = iVar4;
    }
    *(int *)(iVar6 + 0x30) = iVar3;
  }
  *(int *)(iVar3 + 0x2c) = iVar6;
  *(undefined4 *)(iVar3 + 0x30) = 0;
  if (param_2 != (int *)0x0) {
    *param_2 = iVar3;
  }
  return 0;
}


