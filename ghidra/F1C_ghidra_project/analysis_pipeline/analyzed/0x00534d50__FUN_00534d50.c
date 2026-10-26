// Function: FUN_00534d50 @ 00534d50
// Size (bytes): 276


void __fastcall FUN_00534d50(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    iVar1 = FUN_00534e70();
    if (iVar1 != (&DAT_005da780)[uVar3]) {
      if (uVar3 != 0) {
        param_1[1] = param_1[1] + 1;
        *param_1 = *param_1 + -1;
      }
      if (iVar1 != -1) {
        param_1[1] = param_1[1] + 1;
        *param_1 = *param_1 + -1;
        param_1[0x16] = 1;
      }
      param_1[0xe] = (uint)(param_1[1] == 0);
      return;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 2);
  iVar1 = FUN_00534e70();
  uVar3 = FUN_00534e70();
  if ((iVar1 != 8) || ((uVar3 & 0xe0) != 0)) {
    param_1[0xe] = -3;
    return;
  }
  iVar1 = 6;
  do {
    FUN_00534e70();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((uVar3 & 4) != 0) {
    iVar1 = FUN_00534e70();
    iVar2 = FUN_00534e70();
    iVar1 = iVar1 + iVar2 * 0x100;
    do {
      if (iVar1 == 0) break;
      iVar2 = FUN_00534e70();
      iVar1 = iVar1 + -1;
    } while (iVar2 != -1);
  }
  if ((uVar3 & 8) != 0) {
    do {
      iVar1 = FUN_00534e70();
      if (iVar1 == 0) break;
    } while (iVar1 != -1);
  }
  if ((uVar3 & 0x10) != 0) {
    do {
      iVar1 = FUN_00534e70();
      if (iVar1 == 0) break;
    } while (iVar1 != -1);
  }
  if ((uVar3 & 2) != 0) {
    iVar1 = 2;
    do {
      FUN_00534e70();
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  param_1[0xe] = -(uint)(param_1[0xf] != 0) & 0xfffffffd;
  return;
}


