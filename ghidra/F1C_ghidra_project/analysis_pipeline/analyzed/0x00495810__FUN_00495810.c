// Function: FUN_00495810 @ 00495810
// Size (bytes): 123


undefined4 FUN_00495810(char *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char local_50 [80];
  
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  iVar2 = -(int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)(local_50 + iVar2)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  FUN_00589901(local_50);
  iVar2 = FUN_00587c20(local_50,&DAT_005cc79c);
  if (iVar2 == 0) {
    iVar2 = -1;
    pcVar4 = local_50;
    do {
      pcVar5 = pcVar4;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar5 = pcVar4 + 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar5;
    } while (cVar1 != '\0');
    *(undefined4 *)(pcVar5 + -1) = DAT_005cc79c;
    pcVar5[3] = DAT_005cc7a0;
  }
  uVar3 = FUN_00494de0(local_50);
  return uVar3;
}


