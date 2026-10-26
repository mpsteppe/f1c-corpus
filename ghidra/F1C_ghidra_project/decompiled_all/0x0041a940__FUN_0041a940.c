// Function: FUN_0041a940 @ 0041a940
// Strings:  [Ignored Stop/Go Penalty, Ignored Stop/Go Penalty, Ignored Stop/Go Penalty, Ignored Stop/Go Penalty]


void FUN_0041a940(int param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined1 local_20 [32];
  
  if (DAT_007d0308 == 0) {
    return;
  }
  if (DAT_007cf3c8 == DAT_0059e440) {
    return;
  }
  if (param_1 == 0) {
    return;
  }
  if ((DAT_007c54e8 == 0) || (DAT_007c54e8 != param_1)) {
    if (param_2 == (char *)0x0) {
      return;
    }
    iVar1 = 0x18;
    bVar4 = true;
    pcVar2 = s_Ignored_Stop_Go_Penalty_005c2730;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *param_2;
      pcVar2 = pcVar2 + 1;
      param_2 = param_2 + 1;
    } while (bVar4);
    if (!bVar4) {
      return;
    }
    uVar3 = 0xf3;
  }
  else {
    if (param_2 == (char *)0x0) {
      return;
    }
    iVar1 = 0x18;
    bVar4 = true;
    pcVar2 = s_Ignored_Stop_Go_Penalty_005c2730;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *param_2;
      pcVar2 = pcVar2 + 1;
      param_2 = param_2 + 1;
    } while (bVar4);
    if (!bVar4) {
      return;
    }
    uVar3 = 0x95;
  }
  FUN_004144d0();
  FUN_004144f0(uVar3,*(undefined4 *)(param_1 + 0x489c),0xffffffff,0xffffffff,0xffffffff,0xc0000000,
               0xc0000000);
  FUN_00418560(local_20);
  return;
}


