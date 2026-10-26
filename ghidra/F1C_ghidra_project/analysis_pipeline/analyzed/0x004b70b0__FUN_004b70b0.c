// Function: FUN_004b70b0 @ 004b70b0
// Size (bytes): 290


void __fastcall FUN_004b70b0(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int local_c;
  undefined4 local_8;
  undefined1 local_4 [4];
  
  FUN_004b87a0(&local_8,local_4);
  iVar5 = 0;
  iVar4 = 0;
  local_c = 0;
  do {
    iVar2 = FUN_004b72a0(local_c,local_8);
    if (iVar2 == 0) {
      FUN_004ef5a0(0xffffffff,0);
    }
    else {
      FUN_004ef5a0(3,0);
      FUN_004c7b20(iVar2 + 0x41);
      FUN_00566650(iVar2 + 0x61);
      FUN_004c6980(iVar2 + 1);
      iVar4 = iVar4 + 1;
    }
    local_c = local_c + 1;
    iVar5 = iVar5 + 0x48c0;
  } while (iVar5 < 0x1d8e00);
  uVar1 = iVar4 - 1;
  DAT_005c329c = uVar1;
  FUN_0042bc80();
  DAT_007cec90 = 0;
  DAT_007ced8c = 0;
  DAT_007cee88 = 0;
  DAT_007d0990 = ((int)uVar1 < 0) - 1 & uVar1;
  puVar3 = *(undefined1 **)(param_1 + 0x724);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  FUN_004c5690(puVar3);
  FUN_004c54f0(0);
  DAT_007c5690 = 1;
  FUN_0042cf10(*(undefined4 *)(param_1 + 0xf20));
  return;
}


