// Function: FUN_0049c0b0 @ 0049c0b0
// Strings:  [ --------,  --------]


undefined4 FUN_0049c0b0(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined *puVar4;
  
  pcVar2 = s__________005cce54;
  do {
    cVar1 = *pcVar2;
    pcVar2[param_1 + -0x5cce54] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  puVar4 = DAT_007c54e0;
  if ((DAT_007cfff0 & 1) != 0) {
    iVar3 = FUN_004d1b50(0);
    if (iVar3 == 0xff) {
      return 0;
    }
    puVar4 = &DAT_005ec6d8 + iVar3 * 0x48c0;
  }
  if ((puVar4 != (undefined *)0x0) &&
     (DAT_0059e440 < *(float *)(puVar4 + *(int *)(DAT_007c54e0 + 0x4040) * 4 + 0x40a8))) {
    FUN_0058815f(param_1,&PTR_DAT_005c3730,puVar4 + 0x46f8);
    FUN_00589901(param_1);
  }
  return 0;
}


