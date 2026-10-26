// Function: FUN_004ccdc0 @ 004ccdc0
// Size (bytes): 201


void __thiscall FUN_004ccdc0(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  
  fVar1 = *param_3;
  fVar2 = *param_2;
  fVar3 = param_3[1];
  fVar4 = param_2[1];
  fVar5 = param_3[2];
  fVar6 = param_2[2];
  fVar7 = *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4);
  uVar10 = DAT_008aae70 + 1;
  DAT_008aae70 = DAT_008aae70 + 2;
  fVar8 = *(float *)(&DAT_008ab274 + (uVar10 & 0xff) * 4);
  iVar11 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    do {
      iVar9 = *(int *)(*(int *)(param_1 + 0x68) + iVar11 * 4);
      iVar11 = iVar11 + 1;
      *(float *)(iVar9 + 0x2c) = fVar7 + fVar7 + (fVar1 - fVar2) + *(float *)(iVar9 + 0x2c);
      *(float *)(iVar9 + 0x30) = (fVar3 - fVar4) + *(float *)(iVar9 + 0x30);
      *(float *)(iVar9 + 0x34) = fVar8 + fVar8 + (fVar5 - fVar6) + *(float *)(iVar9 + 0x34);
    } while (iVar11 < *(int *)(param_1 + 100));
  }
  FUN_004ccb30();
  return;
}


