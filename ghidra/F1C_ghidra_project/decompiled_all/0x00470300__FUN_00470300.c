// Function: FUN_00470300 @ 00470300
// Strings:  [WWWWWWWWWWWWWWWWW, WWWWWWWWWWWWWWW]


undefined4 __fastcall FUN_00470300(int param_1)

{
  switch(*(undefined4 *)(param_1 + 0x304)) {
  case 0x1af:
    DAT_007cd818 = 0;
    FUN_0048b7e0(&DAT_007cd818,0x1a);
    *(char **)(param_1 + 0x2fc) = s_WWWWWWWWWWWWWWWWW_005c6e2c;
    return 0;
  case 0x1b0:
    DAT_007cd834 = 0;
    *(undefined4 *)(param_1 + 0x2e8) = 0;
    FUN_0048b7e0(&DAT_007cd834,0x1a);
    *(char **)(param_1 + 0x2fc) = s_WWWWWWWWWWWWWWW_005c6e40;
    return 0;
  case 0x1b1:
    DAT_007cd850 = 0;
    *(undefined4 *)(param_1 + 0x2e8) = 0;
    FUN_0048b7e0(&DAT_007cd850,0xf);
    return 0;
  case 0x1b2:
    FUN_0048b7e0(&DAT_007cd860,0x20);
    *(undefined4 *)(param_1 + 0x2e8) = 2;
    return 0;
  case 0x1b3:
    *(undefined4 *)(param_1 + 0x2e8) = 0;
    FUN_0048b8f0(0xa0);
    *(undefined1 *)(param_1 + 0xe5) = 1;
    return 0;
  case 0x1b5:
    DAT_007cd880 = 0;
    FUN_0048b7e0(&DAT_007cd880,0x20);
  }
  return 0;
}


