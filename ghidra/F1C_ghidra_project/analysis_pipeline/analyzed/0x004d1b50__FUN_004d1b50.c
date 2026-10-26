// Function: FUN_004d1b50 @ 004d1b50
// Size (bytes): 101


uint __thiscall FUN_004d1b50(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)*(byte *)(param_2 + 0x128 + param_1);
  if (uVar1 != 0xff) {
    if ((&DAT_005ef9a0)[uVar1 * 0x1230] != -1) {
      return uVar1;
    }
    iVar2 = 0;
    if (0 < DAT_005c329c) {
      do {
        if (*(int *)((&DAT_007c54f0)[iVar2] + 0x4060) == param_2 + 2) {
          return *(uint *)((&DAT_007c54f0)[iVar2] + 0x4038);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_005c329c);
    }
  }
  return *(uint *)(DAT_007c54f0 + 0x10);
}


