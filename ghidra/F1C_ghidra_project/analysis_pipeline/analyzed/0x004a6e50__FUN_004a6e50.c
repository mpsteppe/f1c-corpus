// Function: FUN_004a6e50 @ 004a6e50
// Size (bytes): 372


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004a6e50(int *param_1,float param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = param_1[0x61];
  if ((iVar2 == 0) || (iVar2 == 4)) {
    if (DAT_007c5698 != 0) {
      return;
    }
    if (iVar2 == 4) {
      FUN_004a6b80();
    }
  }
  if ((*(int *)(*param_1 + 13000) == 0) && (cVar1 = FUN_004a6db0(), cVar1 == '\0')) {
    if (((param_1[0x61] != 2) || (cVar1 = FUN_004a5fa0(), cVar1 == '\0')) ||
       (*(int *)(*param_1 + 13000) != 0)) goto LAB_004a6f78;
    DAT_007ce258 = 1;
    uVar3 = 4;
  }
  else {
    iVar2 = param_1[0x61];
    if (iVar2 != 1) {
      if (iVar2 == 2) {
        cVar1 = FUN_004a5fa0();
        if (cVar1 != '\0') {
          *(undefined1 *)(param_1 + 100) = 0;
          FUN_004a5c80(3);
          if (*(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894) == param_1[1]) {
            FUN_004d8840(2);
          }
          FUN_004a6200(param_2);
        }
      }
      else if (iVar2 == 3) {
        if ((char)param_1[100] == '\0') {
          FUN_004a6200(param_2);
        }
        else {
          FUN_004a68b0(param_2);
        }
      }
      goto LAB_004a6f78;
    }
    if (param_2 - (float)param_1[0x62] <= _DAT_005acb08) goto LAB_004a6f78;
    uVar3 = 0;
  }
  FUN_004a5c80(uVar3);
LAB_004a6f78:
  if (((char)param_1[0x60] != '\0') && (iVar2 = FUN_004e9630(), *(int *)(iVar2 + 300) != 1)) {
    FUN_004a5f20();
  }
  if (((char)param_1[0x6b] != '\0') && (param_1[0x61] != 3)) {
    *(undefined1 *)(param_1 + 0x6b) = 0;
    FUN_0040d410();
  }
  return;
}


