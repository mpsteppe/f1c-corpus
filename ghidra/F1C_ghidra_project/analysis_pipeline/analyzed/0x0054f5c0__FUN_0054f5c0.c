// Function: FUN_0054f5c0 @ 0054f5c0
// Size (bytes): 330


undefined4 __thiscall FUN_0054f5c0(int param_1,int param_2,uint param_3)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  
  uVar8 = 0;
  if ((*(uint *)(param_2 + 0x3c) & 2) == 0) {
    if (DAT_008c5f40 < *(int *)(*(int *)(param_1 + 0x1e0) + 4)) {
      iVar6 = *(int *)(param_2 + 0x204);
      if ((*(uint *)(param_2 + 0x3c) & 0x10) != 0) {
        FUN_0054b570(0,iVar6);
        if ((*(uint *)(iVar6 + 0x14) & 0x20000000) == 0) {
          *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) | 0x20000000;
          (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,iVar6 + 0xdc,iVar6 + 0xe8,param_2 + 0x114);
        }
      }
      if ((*(byte *)(iVar6 + 0x14) & 0x40) != 0) {
        uVar7 = *(uint *)(param_2 + 0x3c) & 0x10;
        iVar2 = *(int *)(param_1 + 0x204);
        if (uVar7 == 0) {
          fVar1 = *(float *)(iVar6 + 0xe4);
          fVar5 = *(float *)(iVar2 + 0xec) - *(float *)(iVar6 + 0xe0);
          fVar4 = *(float *)(iVar2 + 0xe8) - *(float *)(iVar6 + 0xdc);
        }
        else {
          fVar1 = *(float *)(iVar6 + 0xf0);
          fVar5 = *(float *)(iVar2 + 0xec) - *(float *)(iVar6 + 0xec);
          fVar4 = *(float *)(iVar2 + 0xe8) - *(float *)(iVar6 + 0xe8);
        }
        fVar1 = *(float *)(iVar2 + 0xf0) - fVar1;
        fVar3 = *(float *)(iVar6 + 0x18) + **(float **)(param_1 + 0x1e0);
        if ((fVar1 * fVar1 + fVar5 * fVar5 + fVar4 * fVar4 < fVar3 * fVar3) && ((param_3 & 1) != 0))
        {
          if (uVar7 == 0) {
            iVar6 = FUN_0054f2f0(param_2,iVar6,param_3);
          }
          else {
            iVar6 = FUN_0054eed0(param_2,iVar6,param_3);
          }
          if (0 < iVar6) {
            DAT_008c5f40 = DAT_008c5f40 + iVar6;
            return 0;
          }
        }
      }
    }
    else {
      uVar8 = 1;
    }
  }
  return uVar8;
}


