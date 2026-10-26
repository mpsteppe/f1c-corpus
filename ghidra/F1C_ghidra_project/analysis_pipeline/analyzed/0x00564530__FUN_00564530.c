// Function: FUN_00564530 @ 00564530
// Size (bytes): 67


undefined4 __fastcall FUN_00564530(undefined4 param_1,char *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  
  iVar2 = 5;
  bVar4 = true;
  pcVar3 = &DAT_005c61ec;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar4 = *param_2 == *pcVar3;
    param_2 = param_2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    uVar1 = FUN_00564480();
    return uVar1;
  }
  iVar2 = FUN_005644f0();
  if (iVar2 == 0) {
    return param_3;
  }
  uVar1 = FUN_00587f59(*(undefined4 *)(iVar2 + 4));
  return uVar1;
}


