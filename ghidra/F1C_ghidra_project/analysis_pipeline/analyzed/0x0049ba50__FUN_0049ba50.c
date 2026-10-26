// Function: FUN_0049ba50 @ 0049ba50
// Size (bytes): 56


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0049ba50(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  uint in_EAX;
  uint3 uVar4;
  
  uVar1 = in_EAX >> 8;
  if (0 < DAT_007d0b64) {
    fVar2 = *(float *)(DAT_007c54e0 + 0x398c) * *(float *)(DAT_007c54e0 + 0x3984);
    fVar3 = (float)DAT_007d0b64 * _DAT_0059e448;
    uVar4 = (uint3)(CONCAT22((short)((uint)DAT_007c54e0 >> 0x10),
                             (ushort)(fVar3 < fVar2) << 8 | (ushort)(NAN(fVar3) || NAN(fVar2)) << 10
                             | (ushort)(fVar3 == fVar2) << 0xe) >> 8);
    if (fVar3 >= fVar2 && (fVar3 == fVar2) == 0) {
      return CONCAT31(uVar4,1);
    }
    uVar1 = (uint)uVar4;
  }
  return uVar1 << 8;
}


