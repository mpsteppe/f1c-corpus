// Function: FUN_004a3390 @ 004a3390
// Size (bytes): 163


void __thiscall FUN_004a3390(uint *param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*param_1 & 1) == 0) {
    if (0 < (int)param_1[3]) {
      iVar2 = 0;
      iVar1 = 0;
      do {
        iVar3 = param_1[4] + iVar2;
        if (*(int *)(param_1[4] + 100 + iVar2) != 0) {
          FUN_004a2840(0);
          if ((param_2 == '\0') || (*(char *)(iVar3 + 3) != '\0')) {
            if (*(char *)(iVar3 + 2) == '\0') {
              FUN_0054c1a0();
            }
            else {
              FUN_0054c190();
            }
          }
          if ((*(int *)(iVar3 + 0x48) != -1) && (*(int *)(iVar3 + 100) != 0)) {
            FUN_005506a0(0,0,0);
          }
        }
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 0x78;
      } while (iVar1 < (int)param_1[3]);
    }
    if ((1 < DAT_007cf884) && (param_1[5] != 0)) {
      FUN_0054c1b0(1,0,0);
    }
    *param_1 = *param_1 | 1;
  }
  return;
}


