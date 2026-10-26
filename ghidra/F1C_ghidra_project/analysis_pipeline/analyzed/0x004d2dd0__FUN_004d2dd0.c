// Function: FUN_004d2dd0 @ 004d2dd0
// Size (bytes): 66


void __fastcall FUN_004d2dd0(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0xa4) != 0) {
    return;
  }
  pvVar1 = operator_new(8);
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004d0060();
    *(undefined4 *)(param_1 + 0xa4) = uVar2;
    FUN_004d0110();
    return;
  }
  *(undefined4 *)(param_1 + 0xa4) = 0;
  FUN_004d0110();
  return;
}


