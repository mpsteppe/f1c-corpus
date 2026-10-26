// Function: FUN_00568e70 @ 00568e70
// Size (bytes): 163


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00568e70(undefined4 *param_1,char *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  char cVar1;
  double dVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  double *pdVar6;
  
  uVar4 = 0xffffffff;
  pcVar3 = param_2;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = operator_new(~uVar4);
  *param_1 = pcVar3;
  do {
    cVar1 = *param_2;
    param_2 = param_2 + 1;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  dVar2 = _DAT_0059e420 / (double)CONCAT44(param_4,param_3);
  param_1[0x2b] = param_3;
  param_1[0x2c] = param_4;
  *(double *)(param_1 + 0x2d) = dVar2;
  dVar2 = _DAT_0059e420;
  pdVar6 = (double *)(param_1 + 0x2f);
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined4 *)pdVar6 = *param_5;
    param_5 = param_5 + 1;
    pdVar6 = (double *)((int)pdVar6 + 4);
  }
  *(double *)(param_1 + 0x35) = dVar2 / *(double *)(param_1 + 0x2f);
  *(double *)(param_1 + 0x37) = _DAT_0059e420 / *(double *)(param_1 + 0x31);
  *(double *)(param_1 + 0x39) = _DAT_0059e420 / *(double *)(param_1 + 0x33);
  FUN_00569410();
  return;
}


