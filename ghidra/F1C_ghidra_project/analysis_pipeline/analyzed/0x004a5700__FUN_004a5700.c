// Function: FUN_004a5700 @ 004a5700
// Size (bytes): 76


int __fastcall FUN_004a5700(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = param_1 + 0x59;
  while( true ) {
    if (param_1[0x58] <= iVar1) {
      return -1;
    }
    if ((*(int *)(*param_1 + 0x403c) < *piVar2) && (*piVar2 < DAT_008acf8c)) break;
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 2;
    if (2 < iVar1) {
      return -1;
    }
  }
  return param_1[iVar1 * 2 + 0x59];
}


