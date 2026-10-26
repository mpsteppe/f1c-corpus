// Function: FUN_004e09e0 @ 004e09e0
// Size (bytes): 685


void __fastcall FUN_004e09e0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int extraout_EDX;
  int iVar3;
  
  if ((DAT_008afe88 != 0) && (param_1[1] != 0)) {
    FUN_004e0db0();
    FUN_00545150(param_1[1]);
    FUN_00411570(*(undefined4 *)(*param_1 + 0x4894),0);
  }
  FUN_004e38d0();
  FUN_004e3050();
  FUN_004dfa50();
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  FUN_00566650(&DAT_005ea438);
  iVar3 = 4;
  do {
    FUN_004dfb60();
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_004dfa50();
  FUN_004dfa50();
  iVar3 = 8;
  do {
    FUN_004dfa50();
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  param_1[0x223] = 0;
  param_1[0x224] = 0;
  param_1[0x225] = 0;
  param_1[0x226] = 0;
  param_1[0x227] = 0;
  param_1[0x228] = 0;
  param_1[0x229] = 0;
  param_1[0x22a] = 0;
  param_1[0x22b] = 0;
  param_1[0x22c] = 0;
  param_1[0x22d] = 0;
  param_1[0x230] = 0;
  piVar1 = param_1 + 0x22e;
  iVar3 = 2;
  piVar2 = param_1 + 0x231;
  do {
    *piVar1 = 0;
    *piVar2 = 0;
    piVar2[1] = 0;
    piVar2[2] = 0;
    piVar1 = piVar1 + 1;
    iVar3 = iVar3 + -1;
    piVar2[3] = 0;
    piVar2 = piVar2 + 4;
  } while (iVar3 != 0);
  param_1[0x239] = 0;
  param_1[0x23d] = 0;
  param_1[0x23e] = 0;
  param_1[0x23f] = 0;
  param_1[0x240] = 0;
  param_1[0x241] = 0;
  param_1[0x242] = 0;
  param_1[0x243] = 0;
  param_1[0x244] = 0;
  param_1[0x245] = 0;
  param_1[0x24d] = 0;
  param_1[0x24e] = 0;
  param_1[0x24f] = 0;
  param_1[0x250] = 0;
  param_1[0x251] = 0;
  *(undefined2 *)(param_1 + 0x252) = 0;
  param_1[0x253] = 0;
  param_1[0x254] = 0;
  param_1[0x255] = 0;
  param_1[0x259] = 0;
  param_1[0x25a] = 0;
  *(undefined1 *)(param_1 + 0x25b) = 0;
  *(undefined1 *)((int)param_1 + 0x96d) = 0;
  param_1[0x25c] = 0;
  *(undefined1 *)(param_1 + 0x25d) = 0;
  *(undefined1 *)((int)param_1 + 0x975) = 0;
  *(undefined1 *)((int)param_1 + 0x976) = 0;
  *(undefined1 *)((int)param_1 + 0x977) = 0;
  *(undefined1 *)(param_1 + 0x25e) = 0;
  *(undefined1 *)((int)param_1 + 0x979) = 0;
  param_1[0x25f] = 0;
  param_1[0x261] = -0x800001;
  param_1[0x260] = -1;
  param_1[0x262] = 0x3f800000;
  param_1[0x2db] = 0;
  piVar1 = param_1 + 0x2dc;
  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar1 = 0;
    piVar1 = piVar1 + 1;
  }
  param_1[0x2ea] = 0;
  iVar3 = 0xb;
  do {
    FUN_004ded20();
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined1 *)(param_1 + 0x263) = 0;
  do {
    FUN_004dfb90();
  } while (extraout_EDX != 1);
  param_1[0xaf4] = 0;
  if (param_1[0xaf5] != 0) {
    FUN_00587bcf(param_1[0xaf5]);
    param_1[0xaf5] = 0;
  }
  return;
}


