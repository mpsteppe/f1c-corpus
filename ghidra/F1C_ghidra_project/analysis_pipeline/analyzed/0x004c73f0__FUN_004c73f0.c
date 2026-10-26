// Function: FUN_004c73f0 @ 004c73f0
// Size (bytes): 899


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c73f0(int param_1,int param_2,float param_3)

{
  float *pfVar1;
  float fVar2;
  byte bVar3;
  undefined4 uVar4;
  float *pfVar5;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  float10 fVar9;
  float10 fVar10;
  float local_8c;
  float local_88;
  float local_84;
  float *local_80;
  float local_7c;
  float local_78;
  float local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 local_58 [12];
  undefined1 local_4c [12];
  float local_40 [4];
  undefined1 local_30 [12];
  undefined4 local_24 [9];
  
  local_74 = param_3 - *(float *)(param_1 + 0x48b8);
  *(float *)(param_1 + 0x48b8) = param_3;
  FUN_004b2420(&local_70,local_58);
  FUN_00566e40();
  FUN_004e23d0(&local_70,local_58,local_24);
  fVar9 = (float10)FUN_004b2a80();
  local_8c = (float)fVar9;
  if ((float10)_DAT_0059e670 <= fVar9) {
    if (local_8c <= _DAT_0059e43c) {
      fVar2 = _DAT_0059e670;
      if (((local_8c < _DAT_0059e670) || (fVar2 = _DAT_0059e43c, _DAT_0059e43c < local_8c)) ||
         (fVar2 = _DAT_0059e670, local_8c < _DAT_0059e670)) goto LAB_004c747f;
    }
    else {
      local_8c = 1.0;
    }
  }
  else {
    local_8c = -1.0;
  }
  fVar2 = local_8c;
LAB_004c747f:
  *(float *)(param_1 + 0x1040) = fVar2;
  local_80 = (float *)(param_1 + 0x8c0);
  local_78 = *(float *)(param_1 + 0x1044) * local_8c;
  iVar6 = 0;
  pfVar5 = local_40;
  do {
    FUN_004b28f0(iVar6,&local_84,pfVar5);
    local_7c = local_74 * *pfVar5 + *local_80;
    if (iVar6 < 2) {
      local_88 = local_78;
    }
    else {
      local_88 = 0.0;
    }
    FUN_004e24a0(iVar6,local_84,local_7c,local_88);
    iVar6 = iVar6 + 1;
    local_80 = local_80 + 0x4a;
    pfVar5 = pfVar5 + 1;
  } while (iVar6 < 4);
  FUN_004b2580(&local_64);
  FUN_004b26d0(local_30);
  FUN_004b2800(local_4c);
  fVar9 = (float10)FUN_004b2980();
  fVar10 = (float10)FUN_004b29f0();
  local_84 = (float)fVar10;
  *(float *)(param_1 + 0xa4) = (float)fVar10;
  *(undefined4 *)(param_1 + 0x1c) = local_70;
  *(undefined4 *)(param_1 + 0x20) = local_6c;
  *(undefined4 *)(param_1 + 0x24) = local_68;
  puVar7 = local_24;
  puVar8 = (undefined4 *)(param_1 + 0x34);
  for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  *(undefined4 *)(param_1 + 0x58) = local_64;
  *(undefined4 *)(param_1 + 0x5c) = local_60;
  *(undefined4 *)(param_1 + 0x60) = local_5c;
  *(float *)(param_1 + 0xa0) = (float)fVar9;
  *(byte *)(param_1 + 0x1069) = (byte)(*(uint *)(param_2 + 0x34) >> 7) & 1;
  if (*(int *)(param_1 + 13000) == 2) {
    *(float *)(param_1 + 0x3580) = local_8c;
    uVar4 = FUN_004b2a30();
    FUN_004f1650(&local_70,local_58,local_24,&local_64,local_30,local_4c,uVar4);
    FUN_004f17a0((float)fVar9,0x3f000000,local_84);
    iVar6 = 0;
    pfVar5 = (float *)(param_1 + 0x35bc);
    do {
      pfVar1 = local_40 + iVar6;
      iVar6 = iVar6 + 1;
      *pfVar5 = *pfVar1;
      pfVar5 = pfVar5 + 0x3e;
    } while (iVar6 < 4);
    *(byte *)(param_1 + 0x344c) = (byte)((uint)*(undefined4 *)(param_2 + 0x38) >> 0x1f);
    if (_DAT_0059e8d8 < ABS(param_3 - *(float *)(param_1 + 0x48b4))) {
      *(float *)(param_1 + 0x48b4) = param_3;
      iVar6 = 0;
      do {
        uVar4 = FUN_004b2ad0(iVar6);
        FUN_004e17c0(iVar6,uVar4);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0xe);
    }
  }
  else if (*(int *)(param_1 + 13000) == 3) {
    FUN_004f17d0(local_24,local_4c);
    iVar6 = 0;
    do {
      FUN_004e2230(iVar6,local_40[iVar6]);
      iVar6 = iVar6 + 1;
    } while (iVar6 < 4);
    iVar6 = 0;
    do {
      uVar4 = FUN_004b2ad0(iVar6);
      FUN_004e17c0(iVar6,uVar4);
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0xe);
  }
  bVar3 = (byte)((uint)*(undefined4 *)(param_2 + 0x38) >> 0x1b) & 1;
  if (*(byte *)(param_1 + 0x105d) != bVar3) {
    *(byte *)(param_1 + 0x105d) = bVar3;
    FUN_004e0ed0(*(undefined4 *)(param_1 + 0x1054));
  }
  FUN_0059d6ff(unaff_EBP,unaff_EBX);
  return;
}


