// Function: FUN_0040fdd0 @ 0040fdd0
// Size (bytes): 124


undefined4 * __thiscall FUN_0040fdd0(undefined4 *param_1,byte param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((param_2 & 2) == 0) {
    *param_1 = &PTR_LAB_0059e720;
    thunk_FUN_00568f20();
    if ((param_2 & 1) != 0) {
      FUN_00587bcf(param_1);
    }
    return param_1;
  }
  iVar2 = param_1[-1];
  puVar1 = param_1 + iVar2 * 0xc6;
  if (-1 < iVar2 + -1) {
    do {
      puVar1 = puVar1 + -0xc6;
      *puVar1 = &PTR_LAB_0059e720;
      thunk_FUN_00568f20();
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1 + -1);
  }
  return param_1 + -1;
}


