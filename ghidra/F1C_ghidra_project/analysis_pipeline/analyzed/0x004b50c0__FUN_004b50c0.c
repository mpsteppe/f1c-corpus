// Function: FUN_004b50c0 @ 004b50c0
// Size (bytes): 82


ushort __thiscall FUN_004b50c0(int param_1,float param_2)

{
  float fVar1;
  ushort uVar2;
  
  if (*(float *)(param_1 + 0x84) != DAT_005acd10) {
    fVar1 = *(float *)(param_1 + 0x84);
    if (param_2 < fVar1) {
      return (ushort)(param_2 < fVar1) << 8 | (ushort)(NAN(param_2) || NAN(fVar1)) << 10 |
             (ushort)(param_2 == fVar1) << 0xe;
    }
  }
  fVar1 = *(float *)(param_1 + 0x88);
  uVar2 = (ushort)(fVar1 < DAT_005acd10) << 8 | (ushort)(NAN(fVar1) || NAN(DAT_005acd10)) << 10 |
          (ushort)(fVar1 == DAT_005acd10) << 0xe;
  if (fVar1 != DAT_005acd10) {
    fVar1 = *(float *)(param_1 + 0x88);
    uVar2 = (ushort)(param_2 < fVar1) << 8 | (ushort)(NAN(param_2) || NAN(fVar1)) << 10 |
            (ushort)(param_2 == fVar1) << 0xe;
    if (param_2 < fVar1 == (param_2 == fVar1)) {
      return uVar2;
    }
  }
  return CONCAT11((char)(uVar2 >> 8),1);
}


