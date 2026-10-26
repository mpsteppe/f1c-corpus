// Function: FUN_0057b5c0 @ 0057b5c0
// Size (bytes): 98


uint __thiscall FUN_0057b5c0(int param_1,int param_2,int param_3)

{
  uint in_EAX;
  int iVar1;
  uint uVar2;
  
  uVar2 = in_EAX & 0xffffff00;
  if (param_3 <= (int)(uint)*(ushort *)(param_1 + 0x1002)) {
    iVar1 = 0;
    if (0 < param_3) {
      do {
        *(undefined1 *)(iVar1 + param_2) = *(undefined1 *)(*(short *)(param_1 + 0x1000) + param_1);
        uVar2 = (int)(short)(*(short *)(param_1 + 0x1000) + 1) & 0x80000fff;
        if ((int)uVar2 < 0) {
          uVar2 = (uVar2 - 1 | 0xfffff000) + 1;
        }
        iVar1 = iVar1 + 1;
        *(short *)(param_1 + 0x1000) = (short)uVar2;
      } while (iVar1 < param_3);
    }
    *(short *)(param_1 + 0x1002) = *(short *)(param_1 + 0x1002) - (short)param_3;
    uVar2 = CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  return uVar2;
}


