// Function: FUN_004c0260 @ 004c0260
// Strings:  [Qualifying]


int FUN_004c0260(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 != 0) {
    iVar1 = FUN_004c5840(0);
    if (iVar1 != 0) {
      iVar1 = FUN_005679c0(s_Qualifying_005d2640);
      if (iVar1 != 0) {
        iVar1 = 0;
        do {
          iVar2 = thunk_FUN_0059d6a9(iVar1);
          if (iVar2 != 0) {
            uVar3 = FUN_00499e20();
            iVar2 = FUN_00588410(param_1,uVar3);
            if (iVar2 == 0) {
              return iVar1 + 1;
            }
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < 0x68);
      }
    }
  }
  return 0x68;
}


