// Function: FUN_004da080 @ 004da080
// Size (bytes): 65


uint __fastcall FUN_004da080(int param_1)

{
  float fVar1;
  undefined4 in_EAX;
  undefined3 uVar3;
  uint uVar2;
  bool bVar4;
  
  fVar1 = *(float *)(param_1 + 0x14);
  uVar2 = CONCAT22((short)((uint)in_EAX >> 0x10),
                   (ushort)(fVar1 < DAT_0059e440) << 8 |
                   (ushort)(NAN(fVar1) || NAN(DAT_0059e440)) << 10 |
                   (ushort)(fVar1 == DAT_0059e440) << 0xe);
  if ((fVar1 < DAT_0059e440 == 0) && (uVar2 = *(uint *)(param_1 + 0x1c), uVar2 != 0)) {
    uVar3 = (undefined3)(uVar2 >> 8);
    if (*(char *)(param_1 + 0x18) == '\0') {
      bVar4 = uVar2 == *(uint *)(DAT_007c54e0 + 0x40d4);
      uVar2 = CONCAT31(uVar3,1);
      if (bVar4) {
        return uVar2;
      }
    }
    else if (uVar2 == *(uint *)(DAT_007c54e0 + 0x40d0)) {
      return CONCAT31(uVar3,1);
    }
  }
  return uVar2 & 0xffffff00;
}


