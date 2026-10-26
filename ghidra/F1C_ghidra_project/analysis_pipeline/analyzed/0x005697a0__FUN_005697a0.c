// Function: FUN_005697a0 @ 005697a0
// Size (bytes): 79


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005697a0(int param_1,double *param_2)

{
  double dVar1;
  int iVar2;
  double *pdVar3;
  undefined4 *puVar4;
  
  dVar1 = _DAT_0059e420;
  pdVar3 = param_2;
  puVar4 = (undefined4 *)(param_1 + 0xbc);
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *(undefined4 *)pdVar3;
    pdVar3 = (double *)((int)pdVar3 + 4);
    puVar4 = puVar4 + 1;
  }
  *(double *)(param_1 + 0xd4) = dVar1 / *param_2;
  *(double *)(param_1 + 0xdc) = _DAT_0059e420 / param_2[1];
  *(double *)(param_1 + 0xe4) = _DAT_0059e420 / param_2[2];
  FUN_00569410();
  return;
}


