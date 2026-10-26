// Function: FUN_00548a30 @ 00548a30
// Size (bytes): 110


uint FUN_00548a30(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar5;
  uint uVar4;
  
  FUN_005884e0(param_1 % 0xa55a);
  uVar1 = _rand();
  uVar1 = uVar1 | uVar1 << 0x11;
  iVar5 = 0;
  do {
    uVar2 = uVar1 & 0xff;
    uVar4 = uVar2 % 0x4e + 0x30;
    uVar3 = (undefined1)uVar4;
    if (uVar4 < 0x30) {
      uVar3 = 0x30;
    }
    else if (0x7d < uVar4) {
      uVar3 = 0x7e;
    }
    uVar1 = (int)uVar1 >> 8;
    *(undefined1 *)(iVar5 + param_2) = uVar3;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 4);
  *(undefined1 *)(param_2 + 4) = 0;
  return uVar2 / 0x4e;
}


