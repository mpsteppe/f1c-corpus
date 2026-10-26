// Function: FUN_005895a2 @ 005895a2
// Size (bytes): 207


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005895a2(double param_1)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  undefined4 uVar5;
  
  uVar2 = FUN_00591e66(DAT_005e65a0,0xffff);
  if ((param_1._6_2_ & 0x7ff0) == 0x7ff0) {
    iVar3 = FUN_00591d2e();
    if (0 < iVar3) {
      if (iVar3 < 3) {
        FUN_00591e66(uVar2,0xffff);
        return (float10)param_1;
      }
      if (iVar3 == 3) {
        fVar4 = (float10)FUN_0059163b();
        return fVar4;
      }
    }
    dVar1 = param_1 + _DAT_005b8c80;
    uVar5 = 8;
  }
  else {
    fVar4 = (float10)__frnd(SUB84(param_1,0),(int)((ulonglong)param_1 >> 0x20));
    dVar1 = (double)fVar4;
    if ((dVar1 == param_1) || ((uVar2 & 0x20) != 0)) {
      FUN_00591e66(uVar2,0xffff);
      return (float10)dVar1;
    }
    uVar5 = 0x10;
  }
  fVar4 = (float10)FUN_0059168f(uVar5,0xb,param_1,dVar1,uVar2);
  return fVar4;
}


