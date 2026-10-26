// Function: FUN_0059b260 @ 0059b260
// Strings:  [1.1.3]


int __fastcall FUN_0059b260(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_24;
  
  iVar1 = FUN_005357c0(0x38);
  if (iVar1 == 0) {
    iVar2 = FUN_005357e0();
    if (iVar2 == 1) {
      *param_2 = local_24;
      iVar1 = FUN_00535660();
    }
    else {
      FUN_00535660();
      iVar1 = -5;
      if (iVar2 != 0) {
        return iVar2;
      }
    }
  }
  return iVar1;
}


