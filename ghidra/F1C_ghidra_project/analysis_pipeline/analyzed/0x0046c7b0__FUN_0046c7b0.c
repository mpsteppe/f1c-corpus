// Function: FUN_0046c7b0 @ 0046c7b0
// Size (bytes): 105


undefined4 FUN_0046c7b0(char param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_007cd2b8;
  if (param_1 == '\0') {
    puVar3 = &DAT_007cd470;
  }
  iVar2 = 0;
  iVar1 = 0;
  do {
    if (puVar3[iVar1] == -1) break;
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x68);
  if (param_3 < 0) {
    puVar3[iVar2] = param_2;
  }
  else {
    if (iVar2 < param_3) {
      param_3 = iVar2;
    }
    iVar1 = puVar3[param_3];
    puVar3[param_3] = param_2;
    do {
      param_3 = param_3 + 1;
      if (0x67 < param_3) {
        return 0;
      }
      iVar2 = puVar3[param_3];
      puVar3[param_3] = iVar1;
      iVar1 = iVar2;
    } while (iVar2 != -1);
  }
  return 1;
}


