// Function: FUN_0049e5b0 @ 0049e5b0
// Size (bytes): 179


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0049e5b0(float param_1)

{
  uint uVar1;
  int iVar2;
  
  if (_DAT_0059e468 <= param_1) {
    if (param_1 <= _DAT_005acb08) {
      if (param_1 < _DAT_005acb00) goto LAB_0049e60f;
      if (param_1 < _DAT_005acb04) {
        uVar1 = __ftol();
        return uVar1 | 0xffff0000;
      }
    }
    uVar1 = __ftol();
    return (uVar1 | 0xffffff00) << 8;
  }
LAB_0049e60f:
  iVar2 = __ftol();
  return iVar2 << 0x10 | 0xff0000ff;
}


