// Function: FUN_004d15f0 @ 004d15f0
// Strings:  [PTENT%02d, PDOOR%02d]


void __fastcall FUN_004d15f0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_40 [32];
  undefined1 local_20 [32];
  
  FUN_004d1450();
  if (DAT_008afe88 != 0) {
    iVar2 = 0;
    puVar3 = (undefined4 *)(param_1 + 0x280);
    do {
      FUN_0058815f(local_40,s_PDOOR_02d_005d3c54,iVar2);
      uVar1 = FUN_005453a0(local_40,0);
      puVar3[-0x34] = uVar1;
      FUN_0058815f(local_20,s_PTENT_02d_005d3c48,iVar2);
      uVar1 = FUN_005453a0(local_20,0);
      *puVar3 = uVar1;
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 < 0x34);
  }
  return;
}


