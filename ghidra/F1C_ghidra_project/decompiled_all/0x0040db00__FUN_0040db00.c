// Function: FUN_0040db00 @ 0040db00
// Strings:  [<none>, <any trackside>, <last>, <original>, <player>]


undefined4 __thiscall FUN_0040db00(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 != 0) {
    iVar1 = FUN_00588410(s_<player>_005beb3c,param_2);
    if (iVar1 == 0) {
      uVar2 = FUN_0040d0b0();
      return uVar2;
    }
    iVar1 = FUN_00588410(s_<original>_005beb30,param_2);
    if (iVar1 == 0) {
      return *(undefined4 *)(param_1 + 0x8c);
    }
    iVar1 = FUN_00588410(s_<last>_005beb28,param_2);
    if (iVar1 == 0) {
      return *(undefined4 *)(param_1 + 0x90);
    }
    iVar1 = FUN_00588410(s_<any_trackside>_005beb18,param_2);
    if (iVar1 != 0) {
      iVar1 = FUN_00588410(s_<none>_005beb10,param_2);
      if (iVar1 == 0) {
        return 0;
      }
      uVar2 = FUN_0040c890(param_2);
      return uVar2;
    }
  }
  return 0;
}


