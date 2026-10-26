// Function: FUN_004542d0 @ 004542d0
// Size (bytes): 126


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004542d0(int param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  undefined2 uVar6;
  
  iVar5 = param_1 + 0xd88;
  if (param_3 != 0) {
    iVar5 = param_1 + 0x1184;
  }
  fVar1 = (*(float *)(iVar5 + 0x398 + param_2 * 4) - *(float *)(iVar5 + 0x60 + param_2 * 4)) *
          *(float *)(iVar5 + 0x40 + param_2 * 4) - *(float *)(param_4 + param_2 * 4);
  uVar6 = (undefined2)((uint)iVar5 >> 0x10);
  if (fVar1 < _DAT_0059ef80) {
    fVar1 = *(float *)(param_4 + param_2 * 4);
    bVar2 = NAN(_DAT_0059ef7c);
    bVar3 = fVar1 < _DAT_0059ef7c;
    bVar4 = fVar1 == _DAT_0059ef7c;
    if (bVar3 == 0 && bVar4 == 0) {
      param_2 = param_2 + param_3 * 8;
      (&DAT_007d1490)[param_2 * 0x1b] = 0x3f800000;
      return CONCAT31((int3)((uint)(param_2 * 0x6c) >> 8),1);
    }
    (&DAT_007d1490)[(param_2 + param_3 * 8) * 0x1b] = 0x3f000000;
    return CONCAT31((int3)(CONCAT22(uVar6,(ushort)bVar3 << 8 | (ushort)(NAN(fVar1) || bVar2) << 10 |
                                          (ushort)bVar4 << 0xe) >> 8),1);
  }
  return CONCAT22(uVar6,(ushort)(fVar1 < _DAT_0059ef80) << 8 |
                        (ushort)(NAN(fVar1) || NAN(_DAT_0059ef80)) << 10 |
                        (ushort)(fVar1 == _DAT_0059ef80) << 0xe);
}


