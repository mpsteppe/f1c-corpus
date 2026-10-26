// Function: FUN_0049c370 @ 0049c370
// Strings:  [-%.2d:%06.3f,  --------,  --------,  -%d %s]


undefined4 FUN_0049c370(float param_1)

{
  char cVar1;
  float fVar2;
  char *pcVar3;
  int iVar4;
  int local_4;
  
  fVar2 = param_1;
  pcVar3 = s__________005cce54;
  do {
    cVar1 = *pcVar3;
    pcVar3[(int)param_1 + -0x5cce54] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if ((((*(int *)(DAT_007c54e0 + 0x4064) == 0) &&
       (iVar4 = *(int *)(DAT_007c54e0 + 0x40d0), iVar4 != 0)) && (*(int *)(iVar4 + 0x4064) == 0)) &&
     (iVar4 = FUN_0049b6d0(iVar4,DAT_007c54e0,&param_1,&local_4), iVar4 == 0)) {
    if (0 < local_4) {
      pcVar3 = &DAT_005cce74;
      if (local_4 != 1) {
        pcVar3 = &DAT_005cce6c;
      }
      iVar4 = FUN_00423a00(pcVar3,&DAT_005ec4cc);
      if (iVar4 != 0) {
        if (pcVar3 == (char *)0x0) {
          DAT_005ec4cc = 0;
        }
        else {
          iVar4 = (int)&DAT_005ec4cc - (int)pcVar3;
          do {
            cVar1 = *pcVar3;
            pcVar3[iVar4] = cVar1;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
        }
      }
      FUN_0058815f(fVar2,s___d__s_005cce64,local_4,&DAT_005ec4cc);
      return 0;
    }
    param_1 = ABS(param_1);
    FUN_0049b630(param_1,&local_4,&param_1);
    FUN_0058815f(fVar2,s____2d__06_3f_005cce34,local_4,(double)param_1);
  }
  return 0;
}


