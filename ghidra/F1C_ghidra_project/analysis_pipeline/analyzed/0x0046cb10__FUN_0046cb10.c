// Function: FUN_0046cb10 @ 0046cb10
// Size (bytes): 51


uint FUN_0046cb10(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = FUN_0046cb00();
  if ((char)uVar2 == '\0') {
    return uVar2 & 0xffffff00;
  }
  iVar4 = 0;
  do {
    iVar1 = (&DAT_007cd470)[iVar4];
    iVar3 = iVar1;
    if (iVar1 < 0) break;
    iVar3 = iVar1 * 0x48c0;
    iVar4 = iVar4 + 1;
    (&DAT_005f0730)[iVar1 * 0x1230] = iVar4;
  } while (iVar4 < 0x68);
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


