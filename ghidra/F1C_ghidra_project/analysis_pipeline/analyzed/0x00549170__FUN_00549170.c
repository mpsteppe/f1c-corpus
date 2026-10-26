// Function: FUN_00549170 @ 00549170
// Size (bytes): 82


void __fastcall FUN_00549170(int param_1)

{
  int iVar1;
  int local_4;
  
  for (iVar1 = *(int *)(param_1 + 0xe8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
    local_4 = 0;
    FUN_0054bc60(iVar1,&local_4);
    if (local_4 != 0) {
      FUN_005452b0(local_4);
      FUN_005490b0(local_4);
    }
  }
  return;
}


