// Function: FUN_00447d00 @ 00447d00
// Strings:  [%s %4.1f:%4.1f, BRAKE BIAS, BRAKE BIAS]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00447d00(int param_1,int param_2)

{
  int *piVar1;
  char *pcVar2;
  double dVar3;
  int iVar4;
  undefined1 local_80 [128];
  
  FUN_0045bdf0();
  if (param_2 < 1) {
    if (param_2 < 0) {
      piVar1 = (int *)(param_1 + 0x1580);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 < 0) {
        *(undefined4 *)(param_1 + 0x1580) = 0;
      }
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 0x1580) + 1;
    *(int *)(param_1 + 0x1580) = iVar4;
    if (*(int *)(param_1 + 0x157c) <= iVar4) {
      *(int *)(param_1 + 0x1580) = *(int *)(param_1 + 0x157c) + -1;
    }
  }
  dVar3 = (double)*(int *)(param_1 + 0x1580) * *(double *)(param_1 + 0x1574) +
          *(double *)(param_1 + 0x156c);
  *(double *)(param_1 + 0x1564) = dVar3;
  dVar3 = dVar3 * _DAT_0059ea20;
  iVar4 = FUN_00423a00();
  if (iVar4 != 0) {
    iVar4 = 0;
    do {
      pcVar2 = s_BRAKE_BIAS_005c43a4 + iVar4;
      (&DAT_005ec4cc)[iVar4] = *pcVar2;
      iVar4 = iVar4 + 1;
    } while (*pcVar2 != '\0');
  }
  FUN_0058815f(local_80,s__s__4_1f__4_1f_005c4394,&DAT_005ec4cc,_DAT_0059ea20 - dVar3,dVar3);
  FUN_0045bd10();
  return;
}


