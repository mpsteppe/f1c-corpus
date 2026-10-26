// Function: FUN_00559d10 @ 00559d10
// Size (bytes): 110


bool __thiscall FUN_00559d10(int param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = (char *)(param_1 + 0xc);
  iVar3 = (param_1 + 0x18c) - (int)pcVar2;
  do {
    cVar1 = *pcVar2;
    pcVar2[iVar3] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = FUN_005897ca(param_1 + 0x18c,&DAT_005c30ac);
  *(int *)(param_1 + 0x30c) = iVar3;
  if (iVar3 != 0) {
    iVar3 = FUN_00588410(iVar3,param_2);
    if (iVar3 == 0) {
      iVar3 = FUN_005897ca(0,&DAT_005ea438);
      *(int *)(param_1 + 0x30c) = iVar3;
      return iVar3 != 0;
    }
  }
  return false;
}


