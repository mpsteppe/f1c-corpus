// Function: FUN_00566c30 @ 00566c30
// Size (bytes): 130


bool FUN_00566c30(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char local_800 [2048];
  
  if (param_1[4] == 0) {
    FUN_0058a163(*param_1,param_2,&stack0x0000000c);
  }
  else {
    FUN_0058ac95(local_800,param_2,&stack0x0000000c);
    uVar3 = 0xffffffff;
    pcVar5 = local_800;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    iVar4 = ~uVar3 - 1;
    if (0 < iVar4) {
      iVar2 = FUN_00535220(iVar4);
      return iVar2 == iVar4;
    }
  }
  return false;
}


