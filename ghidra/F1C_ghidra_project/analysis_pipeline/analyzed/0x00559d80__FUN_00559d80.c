// Function: FUN_00559d80 @ 00559d80
// Size (bytes): 153


bool __thiscall FUN_00559d80(int param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  
  pcVar2 = (char *)(param_1 + 0xc);
  iVar4 = (param_1 + 0x18c) - (int)pcVar2;
  do {
    cVar1 = *pcVar2;
    pcVar2[iVar4] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar4 = FUN_005897ca(param_1 + 0x18c,&DAT_005c30ac);
  *(int *)(param_1 + 0x30c) = iVar4;
  while( true ) {
    if (iVar4 == 0) {
      return false;
    }
    iVar4 = FUN_00588410(*(undefined4 *)(param_1 + 0x30c),param_2);
    if (iVar4 == 0) break;
    uVar3 = FUN_005897ca(0,&DAT_005c32d8);
    *(undefined4 *)(param_1 + 0x30c) = uVar3;
    iVar4 = FUN_005897ca(0,&DAT_005c30ac);
    *(int *)(param_1 + 0x30c) = iVar4;
  }
  iVar4 = FUN_005897ca(0,&DAT_005c32d8);
  *(int *)(param_1 + 0x30c) = iVar4;
  return iVar4 != 0;
}


