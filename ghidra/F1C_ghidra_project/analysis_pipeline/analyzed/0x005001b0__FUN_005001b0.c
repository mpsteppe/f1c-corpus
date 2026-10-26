// Function: FUN_005001b0 @ 005001b0
// Size (bytes): 26


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005001b0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 8);
  for (iVar1 = 0x6c; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(param_1 + 0xc) = _DAT_005ad34c;
  return;
}


