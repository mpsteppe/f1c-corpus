// Function: FUN_0047bd90 @ 0047bd90
// Size (bytes): 100


void __fastcall FUN_0047bd90(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0047bc90();
  iVar1 = iVar1 + -1;
  if (iVar1 < 1) {
    *(undefined4 *)(param_1 + 0x110) = 0;
  }
  else {
    *(int *)(param_1 + 0x110) =
         (iVar1 / 2 + *(int *)(param_1 + 0x114) * *(int *)(param_1 + 0xec)) / iVar1;
  }
  if (*(int *)(param_1 + 0x110) < 0) {
    *(undefined4 *)(param_1 + 0x110) = 0;
    return;
  }
  if (*(int *)(param_1 + 0x114) < *(int *)(param_1 + 0x110)) {
    *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x114);
  }
  return;
}


