// Function: FUN_00549440 @ 00549440
// Size (bytes): 37


void __fastcall FUN_00549440(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  for (iVar1 = *(int *)(param_1 + 0xfc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
    uVar2 = FUN_0054a2d0(iVar1);
    *(undefined4 *)(iVar1 + 0x10) = uVar2;
  }
  return;
}


