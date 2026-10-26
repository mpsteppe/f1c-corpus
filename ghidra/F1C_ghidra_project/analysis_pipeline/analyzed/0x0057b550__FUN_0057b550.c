// Function: FUN_0057b550 @ 0057b550
// Size (bytes): 98


uint __thiscall FUN_0057b550(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = (uint)*(ushort *)(param_1 + 0x1002) + param_3;
  if ((int)uVar2 < 0x1001) {
    uVar2 = (int)*(short *)(param_1 + 0x1000) + (uint)*(ushort *)(param_1 + 0x1002);
    if (0 < param_3) {
      param_2 = param_2 - uVar2;
      iVar4 = param_3;
      do {
        uVar3 = uVar2 & 0x80000fff;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xfffff000) + 1;
        }
        puVar1 = (undefined1 *)(param_2 + uVar2);
        uVar2 = uVar2 + 1;
        iVar4 = iVar4 + -1;
        *(undefined1 *)(uVar3 + param_1) = *puVar1;
      } while (iVar4 != 0);
    }
    *(short *)(param_1 + 0x1002) = *(short *)(param_1 + 0x1002) + (short)param_3;
    return CONCAT31((int3)(uVar2 >> 8),1);
  }
  return uVar2 & 0xffffff00;
}


