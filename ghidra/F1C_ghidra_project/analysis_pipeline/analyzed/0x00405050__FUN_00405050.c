// Function: FUN_00405050 @ 00405050
// Size (bytes): 171


undefined4 FUN_00405050(char *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  pcVar5 = param_1;
  FUN_00404fe0(param_1);
  iVar2 = FUN_00407f10(pcVar5);
  if (iVar2 != -1) {
    *param_2 = iVar2;
    return 1;
  }
  if (param_1 != (char *)0x0) {
    uVar4 = 0xffffffff;
    pcVar5 = param_1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if (4 < ~uVar4 - 1) {
      iVar2 = FUN_00566810();
      if (iVar2 != 0) {
        uVar3 = FUN_00587f59(param_1 + 4);
        uVar6 = 0;
        FUN_00404fe0(0,uVar3);
        iVar2 = FUN_00407e40(uVar6,uVar3);
        if (iVar2 != 0) {
          *param_2 = *(int *)(iVar2 + 0x10);
          return 1;
        }
      }
    }
  }
  iVar2 = FUN_00595ae2(param_1,0x8000,0x100);
  if (iVar2 != -1) {
    *param_2 = iVar2;
    return 1;
  }
  return 0;
}


