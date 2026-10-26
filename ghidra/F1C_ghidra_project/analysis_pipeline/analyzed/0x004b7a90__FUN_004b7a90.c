// Function: FUN_004b7a90 @ 004b7a90
// Size (bytes): 464


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_004b7a90(int param_1,int *param_2,int param_3,float param_4)

{
  float fVar1;
  float10 fVar2;
  float fVar3;
  undefined4 in_EAX;
  undefined2 extraout_var;
  uint uVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  float10 fVar8;
  uint local_1b0 [108];
  
  uVar4 = CONCAT31((int3)((uint)in_EAX >> 8),*(char *)(param_1 + 0xf78));
  if (*(char *)(param_1 + 0xf78) == '\0') {
    if (param_3 != 0) {
      FUN_004b5c50(param_3);
    }
    fVar8 = (float10)FUN_00568d90();
    fVar2 = (float10)_DAT_0059e87c;
    uVar4 = CONCAT22(extraout_var,
                     (ushort)(fVar8 < fVar2) << 8 | (ushort)(NAN(fVar8) || NAN(fVar2)) << 10 |
                     (ushort)(fVar8 == fVar2) << 0xe);
    if (fVar8 >= fVar2 && (fVar8 == fVar2) == 0) {
      fVar1 = ABS(param_4 - *(float *)(param_1 + 0xd78));
      fVar3 = (float)_DAT_0059ea08;
      uVar4 = CONCAT22(extraout_var,
                       (ushort)(fVar1 < fVar3) << 8 | (ushort)(NAN(fVar1) || NAN(fVar3)) << 10 |
                       (ushort)(fVar1 == fVar3) << 0xe);
      if (fVar1 >= fVar3 && (fVar1 == fVar3) == 0) {
        FUN_00568c60();
        iVar7 = DAT_005c329c;
        iVar5 = 0;
        if (0 < DAT_005c329c) {
          pfVar6 = (float *)(param_1 + 0xd7c);
          do {
            fVar1 = *pfVar6;
            *pfVar6 = (float)fVar8 + fVar1;
            if (*(float *)(param_1 + 0xf7c) < (float)fVar8 + fVar1) {
              *pfVar6 = 0.0;
              FUN_004c71c0(local_1b0);
              FUN_004b5da0(local_1b0,param_4);
            }
            iVar5 = iVar5 + 1;
            pfVar6 = pfVar6 + 1;
          } while (iVar5 < iVar7);
        }
        for (iVar7 = *(int *)(param_1 + 0xd28); iVar7 < 0x68; iVar7 = iVar7 + 0xc) {
          FUN_004b6190(iVar7);
        }
        iVar7 = *(int *)(param_1 + 0xd28) + 1;
        uVar4 = iVar7 / 0xc;
        *(int *)(param_1 + 0xd28) = iVar7 % 0xc;
      }
    }
    *(float *)(param_1 + 0xd78) = param_4;
    if (0 < *param_2) {
      FUN_004b3b30();
      iVar7 = FUN_004b3af0(local_1b0);
      while (iVar7 != 0) {
        switch(local_1b0[0] >> 0x1d) {
        case 1:
          uVar4 = local_1b0[0] >> 0x12 & 0x3f;
          if ((uVar4 != 0) && (uVar4 != 7)) goto switchD_004b7bdf_caseD_2;
          break;
        case 2:
        case 3:
        case 4:
        case 6:
switchD_004b7bdf_caseD_2:
          FUN_004b5da0(local_1b0,param_4);
        }
        iVar7 = FUN_004b3af0(local_1b0);
      }
      iVar7 = *(int *)(param_1 + 0x9b8) * 0xb0 + *(int *)(param_1 + 0x9b0);
      uVar4 = 0;
      if (iVar7 != 0) {
        fVar1 = *(float *)(param_1 + 0xf7c) + *(float *)(iVar7 + 0x6c);
        uVar4 = CONCAT22((short)((uint)iVar7 >> 0x10),
                         (ushort)(fVar1 < param_4) << 8 | (ushort)(NAN(fVar1) || NAN(param_4)) << 10
                         | (ushort)(fVar1 == param_4) << 0xe);
        if (fVar1 < param_4 != (fVar1 == param_4)) {
          uVar4 = FUN_004b6940(param_4);
        }
      }
    }
  }
  return uVar4 & 0xffffff00;
}


