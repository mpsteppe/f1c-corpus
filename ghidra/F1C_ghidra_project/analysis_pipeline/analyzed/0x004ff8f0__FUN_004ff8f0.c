// Function: FUN_004ff8f0 @ 004ff8f0
// Size (bytes): 1705


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004ff8f0(float param_1,uint *param_2,int param_3,int param_4)

{
  uint uVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  float10 fVar12;
  float local_98;
  float local_94;
  int local_8c;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 local_48 [12];
  undefined1 local_3c [12];
  undefined1 local_30 [16];
  undefined1 local_20 [32];
  
  fVar5 = (float)param_2[1];
  if (((float)param_2[1] <= param_1) && (fVar5 = param_1, *(float *)(param_3 + 4) < param_1)) {
    fVar5 = *(float *)(param_3 + 4);
  }
  param_1 = fVar5;
  uVar1 = *param_2;
  FUN_004b33b0(uVar1 >> 0x1d,uVar1 >> 0x12 & 0x3f,uVar1 >> 8 & 0x3ff,uVar1 & 0xff,param_1,0);
  fVar5 = *(float *)(param_3 + 4) - (float)param_2[1];
  if (fVar5 <= _DAT_0059e7ec) {
    fVar3 = *(float *)(param_3 + 8) - (float)param_2[2];
    fVar4 = *(float *)(param_3 + 0x10) - (float)param_2[4];
    if (_DAT_005ad35c <= (fVar3 * fVar3 + fVar4 * fVar4) * (_DAT_0059e43c / fVar5))
    goto LAB_004ffb79;
    if (fVar5 == DAT_0059e440) goto LAB_004ff9b2;
    local_98 = (param_1 - (float)param_2[1]) * (_DAT_0059e43c / fVar5);
    local_94 = _DAT_0059e43c - local_98;
    if ((DAT_0059e440 < local_94) && (local_94 < _DAT_0059e43c)) {
      local_5c = param_2[3];
      local_60 = param_2[2];
      local_58 = param_2[4];
      FUN_004b2580(local_48);
      local_54 = *(undefined4 *)(param_3 + 8);
      local_50 = *(undefined4 *)(param_3 + 0xc);
      local_4c = *(undefined4 *)(param_3 + 0x10);
      FUN_004b2580(local_3c);
      FUN_004ff3a0(&local_54,local_3c,local_98,&local_6c);
      *(undefined4 *)(param_4 + 8) = local_6c;
      *(undefined4 *)(param_4 + 0xc) = local_68;
      *(undefined4 *)(param_4 + 0x10) = local_64;
      goto LAB_004ff9fd;
    }
  }
  else {
    cVar6 = FUN_005001d0();
    if (cVar6 == '\0') {
LAB_004ffb79:
      local_98 = 1.0;
      local_94 = 0.0;
    }
    else {
LAB_004ff9b2:
      local_98 = 0.0;
      local_94 = 1.0;
    }
  }
  *(float *)(param_4 + 8) = local_98 * *(float *)(param_3 + 8) + local_94 * (float)param_2[2];
  *(float *)(param_4 + 0xc) = local_98 * *(float *)(param_3 + 0xc) + local_94 * (float)param_2[3];
  *(float *)(param_4 + 0x10) = local_98 * *(float *)(param_3 + 0x10) + local_94 * (float)param_2[4];
LAB_004ff9fd:
  FUN_00567030();
  FUN_00567030();
  FUN_00567580(local_20,local_30,local_98);
  FUN_00567010();
  uVar8 = __ftol();
  *(undefined2 *)(param_4 + 0x14) = uVar8;
  uVar8 = __ftol();
  *(undefined2 *)(param_4 + 0x16) = uVar8;
  uVar8 = __ftol();
  *(undefined2 *)(param_4 + 0x18) = uVar8;
  local_8c = param_3 + 0x1e;
  iVar10 = param_3 + 0x1a;
  do {
    uVar7 = __ftol();
    *(undefined1 *)((param_4 - param_3) + iVar10) = uVar7;
    uVar8 = __ftol();
    *(undefined2 *)((param_4 - param_3) + local_8c) = uVar8;
    local_8c = local_8c + 2;
    iVar10 = iVar10 + 1;
  } while ((-0x1a - param_3) + iVar10 < 4);
  uVar8 = __ftol();
  *(undefined2 *)(param_4 + 0x26) = uVar8;
  uVar8 = __ftol();
  *(undefined2 *)(param_4 + 0x28) = uVar8;
  uVar8 = __ftol();
  *(undefined2 *)(param_4 + 0x2a) = uVar8;
  uVar8 = __ftol();
  *(undefined2 *)(param_4 + 0x30) = uVar8;
  uVar8 = __ftol();
  *(undefined2 *)(param_4 + 0x32) = uVar8;
  uVar7 = __ftol();
  *(undefined1 *)(param_4 + 0x2c) = uVar7;
  cVar6 = __ftol();
  *(short *)(param_4 + 0x2e) = (short)cVar6;
  uVar7 = __ftol();
  fVar5 = DAT_0059e440;
  *(undefined1 *)(param_4 + 0x2d) = uVar7;
  if (local_98 <= fVar5) {
    *(uint *)(param_4 + 0x34) = param_2[0xd];
    *(uint *)(param_4 + 0x38) = param_2[0xe];
  }
  else {
    bVar2 = local_98 < _DAT_0059e43c;
    *(undefined4 *)(param_4 + 0x34) = *(undefined4 *)(param_3 + 0x34);
    *(undefined4 *)(param_4 + 0x38) = *(undefined4 *)(param_3 + 0x38);
    if (bVar2) {
      fVar11 = (float10)FUN_004b2a80();
      fVar12 = (float10)FUN_004b2a80();
      FUN_004b2a40((float)(fVar12 * (float10)local_98 + (float10)(float)(fVar11 * (float10)local_94)
                          ));
      fVar11 = (float10)FUN_004b29f0();
      fVar12 = (float10)FUN_004b29f0();
      FUN_004b29b0((float)(fVar12 * (float10)local_98 + (float10)(float)(fVar11 * (float10)local_94)
                          ));
      iVar10 = FUN_004b2a30();
      iVar9 = FUN_004b2a30();
      if (iVar10 == iVar9) {
        fVar11 = (float10)FUN_004b2980();
        fVar12 = (float10)FUN_004b2980();
        FUN_004b2930((float)(fVar12 * (float10)local_98 +
                            (float10)(float)(fVar11 * (float10)local_94)));
        return 1;
      }
      if (param_1 < ((float)param_2[1] + *(float *)(param_3 + 4)) * _DAT_0059e450) {
        fVar11 = (float10)FUN_004b2980();
        FUN_004b2930((float)fVar11);
        return 1;
      }
    }
  }
  return 1;
}


