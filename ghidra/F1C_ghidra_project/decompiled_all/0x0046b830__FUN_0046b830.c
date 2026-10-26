// Function: FUN_0046b830 @ 0046b830
// Strings:  [%02.2d:%06.3f, %6.2f, --:--.---, --:--.---]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046b830(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  double dVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  float10 fVar7;
  
  iVar2 = (&DAT_007c54f0)[param_1];
  pcVar4 = &DAT_005c6a94;
  do {
    cVar1 = *pcVar4;
    pcVar4[param_2 + -0x5c6a94] = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if ((iVar2 != 0) && (-1 < DAT_007c56a4)) {
    if (DAT_007c56a4 < 7) {
      if ((*(int *)(iVar2 + 0x4064) != 3) && (iVar5 = 0, 0 < DAT_005c329c)) {
        while (*(int *)((&DAT_007c54f0)[iVar5] + 0x4060) != 1) {
          iVar5 = iVar5 + 1;
          if (DAT_005c329c <= iVar5) {
            return;
          }
        }
        if ((((&DAT_007c54f0)[iVar5] != 0) &&
            (DAT_0059e440 < *(float *)((&DAT_007c54f0)[iVar5] + 0x409c))) &&
           (DAT_0059e440 < *(float *)(iVar2 + 0x409c))) {
          fVar7 = (float10)FUN_0058957a();
          uVar6 = __ftol((double)fVar7);
          FUN_0058815f(param_2,s__02_2d__06_3f_005c6a7c,uVar6);
        }
      }
    }
    else if (((DAT_007c56a4 == 7) && (*(int *)(iVar2 + 0x4064) == 1)) &&
            (DAT_0059e440 < *(float *)(iVar2 + 0x40b8))) {
      dVar3 = _DAT_0059fb50;
      if (DAT_007d0474 != '\0') {
        dVar3 = _DAT_0059ea08;
      }
      FUN_0058815f(param_2,s__6_2f_005c6a8c,
                   (double)((((float)*(int *)(iVar2 + 0x403c) * DAT_005ea3fc) /
                            *(float *)(iVar2 + 0x40b8)) * (float)dVar3 * (float)_DAT_0059fb48));
      return;
    }
  }
  return;
}


