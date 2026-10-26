// Function: FUN_004b87c0 @ 004b87c0
// Size (bytes): 378


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004b87c0(int param_1)

{
  int iVar1;
  float fVar2;
  undefined2 extraout_var;
  undefined4 uVar3;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  byte *pbVar4;
  int *local_10;
  undefined4 *local_c;
  int local_4;
  
  FUN_004b7a00();
  fVar2 = *(float *)(param_1 + 0xf34) - *(float *)(param_1 + 0xf30);
  if (fVar2 < DAT_0059e440 == (fVar2 == DAT_0059e440)) {
    uVar3 = FUN_00566e20();
    *(undefined4 *)(param_1 + 0xf40) = uVar3;
    *(undefined1 *)(param_1 + 0xf81) = 1;
    local_4 = DAT_005c329c;
    if (0 < DAT_005c329c) {
      local_c = (undefined4 *)(param_1 + 0x734);
      pbVar4 = (byte *)(param_1 + 0x93c);
      local_10 = &DAT_007c54f0;
      do {
        iVar1 = *local_10;
        FUN_004e3a50(*(undefined4 *)(param_1 + 0xf30));
        FUN_004e1970();
        *local_c = *(undefined4 *)(iVar1 + 13000);
        pbVar4[-0x68] = *(byte *)(iVar1 + 0x105d);
        *pbVar4 = (byte)(*(uint *)(iVar1 + 0x48bc) >> 1) & 1;
        FUN_004ef5a0(3,0);
        local_10 = local_10 + 1;
        local_c = local_c + 1;
        pbVar4 = pbVar4 + 1;
      } while ((int)(pbVar4 + (-0x93c - param_1)) < local_4);
    }
    FUN_004b86e0((float)_DAT_008afea0);
    FUN_004d8840(0);
    *(undefined1 *)(param_1 + 0xf80) = 1;
    local_c = (undefined4 *)0x0;
    FUN_00408420(DAT_005acd1c);
    uVar3 = CONCAT22(extraout_var_00,
                     (ushort)(DAT_0059e440 < DAT_005acd1c) << 8 |
                     (ushort)(NAN(DAT_0059e440) || NAN(DAT_005acd1c)) << 10 |
                     (ushort)(DAT_0059e440 == DAT_005acd1c) << 0xe);
    if (DAT_0059e440 < DAT_005acd1c) {
      do {
        local_4 = 1;
        FUN_004b8ae0(&local_4);
        local_c = (undefined4 *)((float)_DAT_008afe90 + (float)local_c);
        uVar3 = CONCAT22(extraout_var_01,
                         (ushort)((float)local_c < DAT_005acd1c) << 8 |
                         (ushort)(NAN((float)local_c) || NAN(DAT_005acd1c)) << 10 |
                         (ushort)((float)local_c == DAT_005acd1c) << 0xe);
      } while ((float)local_c < DAT_005acd1c);
    }
    return CONCAT31((int3)((uint)uVar3 >> 8),1);
  }
  return CONCAT22(extraout_var,
                  (ushort)(fVar2 < DAT_0059e440) << 8 |
                  (ushort)(NAN(fVar2) || NAN(DAT_0059e440)) << 10 |
                  (ushort)(fVar2 == DAT_0059e440) << 0xe);
}


