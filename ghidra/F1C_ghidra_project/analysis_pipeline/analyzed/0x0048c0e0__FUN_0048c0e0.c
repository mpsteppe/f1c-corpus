// Function: FUN_0048c0e0 @ 0048c0e0
// Size (bytes): 132


undefined4 __fastcall FUN_0048c0e0(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined1 **)(param_1 + 0xb8);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  iVar2 = FUN_00588410(puVar1,&DAT_005cc21c);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0x30c) = 0;
  }
  puVar1 = *(undefined1 **)(param_1 + 0xb8);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  iVar2 = FUN_00588410(puVar1,&DAT_005c36f0);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0x30c) = 1;
  }
  puVar1 = *(undefined1 **)(param_1 + 0xb8);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  iVar2 = FUN_00588410(puVar1,&DAT_005cc210);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0x30c) = 2;
  }
  return 0;
}


