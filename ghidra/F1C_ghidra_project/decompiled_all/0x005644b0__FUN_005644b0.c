// Function: FUN_005644b0 @ 005644b0
// Strings:  [hostaddr, hostaddr]


undefined4 __fastcall FUN_005644b0(undefined4 param_1,char *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  
  iVar2 = 9;
  bVar4 = true;
  pcVar3 = s_hostaddr_005e5064;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar4 = *param_2 == *pcVar3;
    param_2 = param_2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    uVar1 = FUN_00564490();
    return uVar1;
  }
  iVar2 = FUN_005644f0();
  if (iVar2 == 0) {
    return param_3;
  }
  return *(undefined4 *)(iVar2 + 4);
}


