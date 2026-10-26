// Function: FUN_004c02d0 @ 004c02d0
// Strings:  [Qualifying]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004c02d0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  
  if (((param_1 != 0) && (iVar1 = FUN_004c5840(0), iVar1 != 0)) &&
     (iVar1 = FUN_005679c0(s_Qualifying_005d2640), iVar1 != 0)) {
    iVar1 = 0;
    do {
      iVar2 = thunk_FUN_0059d6a9(iVar1);
      if (iVar2 != 0) {
        uVar3 = FUN_00499e20();
        iVar2 = FUN_00588410(param_1,uVar3);
        if (iVar2 == 0) {
          uVar3 = FUN_00567970();
          fVar4 = (float10)FUN_0058850f(uVar3);
          if ((float10)_DAT_0059e5fc <= fVar4) {
            return fVar4;
          }
          return (float10)_DAT_0059e670;
        }
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x68);
  }
  return (float10)_DAT_0059e670;
}


