// Function: FUN_0049c960 @ 0049c960
// Strings:  [ %.2d:%06.3f,  --------,  --------]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0049c960(float param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 local_4;
  
  iVar2 = (int)param_1;
  pcVar3 = s__________005cce54;
  do {
    cVar1 = *pcVar3;
    pcVar3[(int)param_1 + -0x5cce54] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if ((DAT_007c56a4 != 7) && (DAT_007d0410 != 1)) {
    param_1 = _DAT_008acf94 - (float)_DAT_008afea0;
    if ((DAT_0059e440 < param_1) && (_DAT_008acf90 < (float)_DAT_008afea0)) {
      FUN_0049b630(param_1,&local_4,&param_1);
      FUN_0058815f(iVar2,s___2d__06_3f_005cce24,local_4,(double)param_1);
      return 0;
    }
  }
  return 0;
}


