// Function: FUN_00431aa0 @ 00431aa0
// Strings:  [%3d/%3d/%3d %s]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00431aa0(int param_1,int param_2,undefined4 param_3,int param_4)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  undefined1 *puVar4;
  int local_18 [2];
  float local_10 [4];
  
  iVar2 = 0;
  pfVar3 = (float *)(param_1 + (param_2 * 3 + 0x73b) * 4);
  do {
    fVar1 = *pfVar3;
    iVar2 = iVar2 + 1;
    pfVar3 = pfVar3 + 1;
    local_10[iVar2] = fVar1 - (float)_DAT_0059eac8;
  } while (iVar2 < 3);
  if (*(int *)(param_1 + 4) == 1) {
    puVar4 = &DAT_005c3738;
    iVar2 = 0;
    do {
      *(int *)((int)local_18 + iVar2) =
           (int)ROUND((*(float *)((int)local_10 + iVar2 + 4) - (float)_DAT_0059eac0) *
                      (float)_DAT_0059eab8 - (float)_DAT_0059eab0);
      iVar2 = iVar2 + 4;
    } while (iVar2 < 0xc);
  }
  else {
    puVar4 = &DAT_005c3734;
    iVar2 = 0;
    do {
      *(int *)((int)local_18 + iVar2) = (int)ROUND(*(float *)((int)local_10 + iVar2 + 4));
      iVar2 = iVar2 + 4;
    } while (iVar2 < 0xc);
  }
  if (param_4 != 3) {
    FUN_0058815f(param_3,&PTR_DAT_005c3f70,local_18[param_4]);
    *(undefined1 *)(param_2 + 0x1ce8 + param_1) = 0;
    return;
  }
  FUN_0058815f(param_3,s__3d__3d__3d__s_005c3f74,local_18[0],local_18[1],local_10[0],puVar4);
  *(undefined1 *)(param_2 + 0x1ce8 + param_1) = 0;
  return;
}


