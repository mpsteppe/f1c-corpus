// Function: FUN_004a3440 @ 004a3440
// Size (bytes): 85


void __fastcall FUN_004a3440(uint *param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*param_1 & 1) != 0) {
    iVar1 = 0;
    if (0 < (int)param_1[3]) {
      iVar2 = 0;
      do {
        if (*(int *)(param_1[4] + iVar2 + 100) != 0) {
          FUN_0054c1a0();
        }
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 0x78;
      } while (iVar1 < (int)param_1[3]);
    }
    if ((1 < DAT_007cf884) && (param_1[5] != 0)) {
      FUN_0054c1b0(0,0,0);
    }
  }
  *param_1 = *param_1 & 0xfffffffc;
  return;
}


