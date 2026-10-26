// Function: FUN_0049e760 @ 0049e760
// Size (bytes): 68


void FUN_0049e760(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = __ftol();
  uVar1 = uVar1 & 0x80000001;
  bVar2 = uVar1 == 0;
  if ((int)uVar1 < 0) {
    bVar2 = (uVar1 - 1 | 0xfffffffe) == 0xffffffff;
  }
  if (bVar2) {
    FUN_00543440(param_2,param_3,param_4,param_5,0xffff0000);
  }
  return;
}


