// Function: FUN_00538940 @ 00538940
// Size (bytes): 104


void __fastcall FUN_00538940(int param_1)

{
  int iVar1;
  
  FUN_005389b0(*(undefined4 *)(param_1 + 0xb12));
  FUN_005389b0(*(undefined4 *)(param_1 + 0xb1e));
  FUN_005383d0();
  iVar1 = 0x12;
  do {
    if (*(short *)(param_1 + 0xa74 + (uint)(byte)(&UNK_005b7dec)[iVar1] * 4) != 0) break;
    iVar1 = iVar1 + -1;
  } while (2 < iVar1);
  *(int *)(param_1 + 0x169b) = *(int *)(param_1 + 0x169b) + iVar1 * 3 + 0x11;
  return;
}


