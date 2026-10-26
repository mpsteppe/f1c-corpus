// Function: FUN_00545850 @ 00545850
// Size (bytes): 128


void __fastcall FUN_00545850(int param_1)

{
  int iVar1;
  int iVar2;
  
  for (iVar1 = *(int *)(param_1 + 0x100); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x104)) {
    for (iVar2 = *(int *)(iVar1 + 0xec); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4c)) {
      FUN_0054b330(0,0x20,0);
      FUN_0054b2c0(0,0x10000000,0);
    }
  }
  for (iVar1 = *(int *)(param_1 + 0x108); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x4c)) {
    FUN_0054b330(0,0x20,0);
    FUN_0054b2c0(0,0x10000000,0);
  }
  return;
}


