// Function: FUN_004a6d50 @ 004a6d50
// Size (bytes): 96


void __fastcall FUN_004a6d50(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (DAT_007c56a4 == 7) {
    iVar1 = *(int *)(*param_1 + 0x4040);
    if ((iVar1 == 2) || (iVar1 != 0)) {
      iVar1 = *(int *)(*param_1 + 0x403c);
      iVar3 = 0;
      if (0 < param_1[0x58]) {
        piVar2 = param_1 + 0x59;
        do {
          if (*piVar2 == iVar1 + 1) {
            FUN_004a5c80(1);
          }
          iVar3 = iVar3 + 1;
          piVar2 = piVar2 + 2;
        } while (iVar3 < param_1[0x58]);
      }
    }
  }
  return;
}


