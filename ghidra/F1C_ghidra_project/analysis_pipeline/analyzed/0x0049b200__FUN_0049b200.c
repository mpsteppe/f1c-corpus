// Function: FUN_0049b200 @ 0049b200
// Size (bytes): 360


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0049b200(void)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  undefined3 uVar4;
  
  FUN_0058957a((float)_DAT_008afea0);
  uVar4 = __ftol();
  uVar1 = __ftol();
  bVar2 = __ftol();
  bVar3 = __ftol();
  return ((CONCAT31(uVar4,uVar1) & 0xffff) << 8 | (uint)bVar2) << 8 | (uint)bVar3;
}


