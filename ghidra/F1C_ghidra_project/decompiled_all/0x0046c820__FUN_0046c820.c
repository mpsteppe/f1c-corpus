// Function: FUN_0046c820 @ 0046c820
// Strings:  [Q_Order0000.bmp]


void __fastcall FUN_0046c820(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = DAT_005c329c;
  if (*(char *)(param_1 + 0x174) == '\0') {
    FUN_00497ad0(PTR_s_Q_Order0000_bmp_005c6674,0);
    puVar3 = &DAT_007cd470;
    for (iVar2 = 0x68; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0xffffffff;
      puVar3 = puVar3 + 1;
    }
    *(undefined4 *)(param_1 + 0x178) = 0xffffffff;
    return;
  }
  iVar1 = 0;
  if (0 < DAT_005c329c) {
    do {
      (&DAT_007cd2b8)[iVar1] = *(undefined4 *)((&DAT_007c54f0)[iVar1] + 0x4894);
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
    if (0x67 < iVar1) {
      *(undefined4 *)(param_1 + 0x178) = 0xffffffff;
      return;
    }
  }
  puVar3 = &DAT_007cd2b8 + iVar1;
  for (iVar2 = 0x68 - iVar1; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xffffffff;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(param_1 + 0x178) = 0xffffffff;
  return;
}


