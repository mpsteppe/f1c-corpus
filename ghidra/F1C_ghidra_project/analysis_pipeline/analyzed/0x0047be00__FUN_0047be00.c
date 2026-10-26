// Function: FUN_0047be00 @ 0047be00
// Size (bytes): 110


void __fastcall FUN_0047be00(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_0047bc90();
  iVar1 = *(int *)(param_1 + 0x114);
  iVar2 = iVar2 + -1;
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0xec) = 0;
  }
  else {
    *(int *)(param_1 + 0xec) = (iVar1 / 2 + *(int *)(param_1 + 0x110) * iVar2) / iVar1;
  }
  if (*(int *)(param_1 + 0xec) < 0) {
    *(undefined4 *)(param_1 + 0xec) = 0;
  }
  else if (iVar2 < *(int *)(param_1 + 0xec)) {
    *(int *)(param_1 + 0xec) = iVar2;
  }
  if (iVar2 < *(int *)(param_1 + 0x114)) {
    FUN_0047bd90();
    return;
  }
  return;
}


