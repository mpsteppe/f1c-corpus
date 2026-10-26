// Function: FUN_00553980 @ 00553980
// Size (bytes): 104


undefined4
FUN_00553980(undefined4 *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x24);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005532a0();
  }
  if (param_2 != 0) {
    FUN_00553370(param_2);
  }
  if (param_3 != 0) {
    FUN_00553620(param_3);
  }
  FUN_00553630(param_4,param_5);
  FUN_0055c2a0(uVar2);
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = uVar2;
  }
  return 0;
}


