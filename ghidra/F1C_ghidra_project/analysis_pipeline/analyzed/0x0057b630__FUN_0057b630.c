// Function: FUN_0057b630 @ 0057b630
// Size (bytes): 75


uint __thiscall FUN_0057b630(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  uint in_EAX;
  uint uVar2;
  int iVar3;
  
  uVar2 = in_EAX & 0xffffff00;
  if (param_3 <= (int)(uint)*(ushort *)(param_1 + 0x1002)) {
    uVar2 = (uint)*(short *)(param_1 + 0x1000);
    iVar3 = 0;
    if (0 < param_3) {
      do {
        puVar1 = (undefined1 *)(uVar2 + param_1);
        uVar2 = uVar2 + 1 & 0x80000fff;
        *(undefined1 *)(iVar3 + param_2) = *puVar1;
        if ((int)uVar2 < 0) {
          uVar2 = (uVar2 - 1 | 0xfffff000) + 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_3);
    }
    uVar2 = CONCAT31((int3)(uVar2 >> 8),1);
  }
  return uVar2;
}


