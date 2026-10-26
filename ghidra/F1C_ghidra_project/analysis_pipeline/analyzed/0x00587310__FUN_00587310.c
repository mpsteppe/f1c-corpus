// Function: FUN_00587310 @ 00587310
// Size (bytes): 96


uint __thiscall FUN_00587310(int param_1,ushort *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 in_EAX;
  int iVar4;
  uint uVar5;
  
  uVar1 = *param_2;
  param_2 = param_2 + 1;
  if (uVar1 == 0) {
    return CONCAT22((short)((uint)in_EAX >> 0x10),uVar1) & 0xffffff00;
  }
  uVar3 = (uint)uVar1;
  iVar4 = uVar3 - 0xb;
  if (0 < iVar4) {
    uVar5 = FUN_00587510(param_2,iVar4);
    if ((char)uVar5 == '\0') {
      return uVar5 & 0xffffff00;
    }
  }
  uVar2 = *(undefined4 *)((int)param_2 + iVar4);
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)((int)param_2 + (uVar3 - 7));
  *(undefined1 *)(param_1 + 0x18) = *(undefined1 *)((int)param_2 + (uVar3 - 3));
  return CONCAT31((int3)((uint)uVar2 >> 8),1);
}


