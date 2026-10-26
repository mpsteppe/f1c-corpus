// Function: FUN_00467dc0 @ 00467dc0
// Size (bytes): 72


undefined4 __fastcall FUN_00467dc0(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  FUN_00467e40();
  FUN_00467f90();
  *(int *)(param_1 + 0xec) =
       (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 2 + *(int *)(param_1 + 4);
  puVar1 = *(undefined1 **)(param_1 + 0xb8);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  uVar2 = FUN_00497ad0(puVar1,0);
  *(undefined4 *)(param_1 + 0x108) = uVar2;
  return 0;
}


