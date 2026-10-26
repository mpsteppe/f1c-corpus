// Function: FUN_0040c540 @ 0040c540
// Size (bytes): 107


undefined4 FUN_0040c540(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  iVar2 = (&DAT_005f0738)[param_1 * 0x1230] + -1;
  if (-1 < param_2) {
    iVar2 = (&DAT_005f0738)[param_1 * 0x1230] + 1;
  }
  iVar3 = DAT_005c329c;
  if ((0 < iVar2) && (iVar3 = iVar2, DAT_005c329c < iVar2)) {
    iVar3 = 1;
  }
  iVar2 = 0;
  if (0 < DAT_005c329c) {
    while (iVar3 != *(int *)((&DAT_007c54f0)[iVar2] + 0x4060)) {
      iVar2 = iVar2 + 1;
      if (DAT_005c329c <= iVar2) {
        return uVar1;
      }
    }
    uVar1 = *(undefined4 *)((&DAT_007c54f0)[iVar2] + 0x4894);
  }
  return uVar1;
}


