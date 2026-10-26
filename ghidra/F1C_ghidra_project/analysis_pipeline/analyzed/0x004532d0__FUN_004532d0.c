// Function: FUN_004532d0 @ 004532d0
// Size (bytes): 146


void __fastcall FUN_004532d0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int local_4;
  
  local_4 = 0;
  if (0 < *(int *)(param_1 + 0xd80)) {
    do {
      iVar2 = 0;
      puVar1 = &DAT_007d1448 + (uint)(local_4 != 0) * 0xd8;
      do {
        FUN_0044fc20(iVar2,(float)puVar1[9] + (float)puVar1[9],*puVar1,puVar1[0x12]);
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 0x1b;
      } while (iVar2 < 8);
      local_4 = local_4 + 1;
    } while (local_4 < *(int *)(param_1 + 0xd80));
  }
  return;
}


