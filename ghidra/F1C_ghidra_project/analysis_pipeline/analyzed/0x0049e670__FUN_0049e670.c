// Function: FUN_0049e670 @ 0049e670
// Size (bytes): 232


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049e670(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894) !=
      *(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894)) {
    FUN_00543440(param_2,param_3,param_4,param_5,0xff00ff00);
    return;
  }
  iVar3 = 0;
  do {
    iVar4 = (param_5 / 3) * iVar3 + param_3;
    iVar1 = param_5;
    if (iVar3 == 2) {
      iVar1 = (param_5 / 3) * 3;
    }
    uVar2 = FUN_0049e5b0((float)((float10)*(double *)(&DAT_007c7a00 + iVar3 * 8 + param_1 * 0x464) -
                                (float10)_DAT_0059eac8));
    FUN_00543440(param_2,iVar4,param_4,(param_3 + iVar1) - iVar4,uVar2);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return;
}


