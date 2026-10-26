// Function: FUN_0049c770 @ 0049c770
// Strings:  [ %d%s,  %.1f%s]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0049c770(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  float fVar4;
  char local_10 [16];
  
  fVar4 = *(float *)(DAT_007c54e0 + 0x3984);
  if (*(float *)(DAT_007c54e0 + 0x3448) <= DAT_0059e440) {
    iVar3 = 0;
    do {
      cVar1 = (&DAT_005ccea0)[iVar3];
      local_10[iVar3] = cVar1;
      iVar3 = iVar3 + 1;
    } while (cVar1 != '\0');
  }
  else {
    uVar2 = __ftol(fVar4);
    FUN_0058815f(local_10,&PTR_DAT_005ccea4,uVar2);
  }
  if (DAT_007d0450 == 1) {
    FUN_0058815f(param_1,s___1f_s_005cce98,(double)(fVar4 * _DAT_005acaf8),local_10);
    return 0;
  }
  uVar2 = __ftol(local_10);
  FUN_0058815f(param_1,s__d_s_005cce90,uVar2);
  return 0;
}


