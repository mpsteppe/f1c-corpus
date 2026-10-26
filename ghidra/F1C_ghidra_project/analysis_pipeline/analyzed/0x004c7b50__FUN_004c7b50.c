// Function: FUN_004c7b50 @ 004c7b50
// Size (bytes): 118


void __fastcall FUN_004c7b50(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  
  iVar1 = FUN_00415230(param_1 + 0x4620,param_1 + 0x4714);
  *(int *)(param_1 + 0x489c) = iVar1;
  if ((iVar1 < 0) &&
     (puVar2 = (undefined4 *)(*(int *)(param_1 + 0x4898) * 0x424 + DAT_008ac394),
     puVar2 != (undefined4 *)0x0)) {
    puVar4 = (undefined1 *)*puVar2;
    if (puVar4 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    uVar3 = FUN_00415230(puVar2 + 0x2f,puVar4);
    *(undefined4 *)(param_1 + 0x489c) = uVar3;
  }
  uVar3 = FUN_00415550(param_1 + 0x46b8);
  *(undefined4 *)(param_1 + 0x48a0) = uVar3;
  return;
}


