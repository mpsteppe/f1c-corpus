// Function: FUN_0042aee0 @ 0042aee0
// Size (bytes): 95


uint __fastcall FUN_0042aee0(int *param_1)

{
  if (DAT_007c56a4 != 7) {
    return param_1[param_1[0x1178] * 4 + 0x1167] & 8;
  }
  if ((((param_1[0x100f] < DAT_008acf8c) && (DAT_007c56a8 != 8)) &&
      (*(char *)((int)param_1 + 0x39fa) == '\0')) &&
     ((*(int *)(*param_1 + 0xd18) == 0 || (*(char *)(*param_1 + 0xd58) != '\0')))) {
    return 0;
  }
  return 1;
}


