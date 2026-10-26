// Function: FUN_00489600 @ 00489600
// Size (bytes): 190


undefined4 __thiscall
FUN_00489600(int *param_1,int param_2,undefined1 *param_3,int param_4,int param_5,undefined4 param_6
            )

{
  void *pvVar1;
  undefined4 uVar2;
  
  if (param_2 != 0) {
    pvVar1 = operator_new(0xe8);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_00488f90();
    }
    FUN_00566650(param_2);
    if ((param_3 == (undefined1 *)0x0) &&
       (param_3 = (undefined1 *)param_1[0x2e], param_3 == (undefined1 *)0x0)) {
      param_3 = &DAT_005ea438;
    }
    FUN_00566650(param_3);
    if (param_4 != 0) {
      FUN_00566650(param_4);
    }
    if (param_5 != 0) {
      FUN_00566650(param_5);
    }
    FUN_00486340(uVar2,param_6);
    FUN_00489480();
    (**(code **)(*param_1 + 0x2c))(1);
    (**(code **)(*param_1 + 0xac))(param_2);
    return 0;
  }
  return 0xffffffff;
}


