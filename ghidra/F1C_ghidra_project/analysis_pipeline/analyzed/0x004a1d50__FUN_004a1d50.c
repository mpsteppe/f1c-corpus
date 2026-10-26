// Function: FUN_004a1d50 @ 004a1d50
// Size (bytes): 72


void __thiscall FUN_004a1d50(int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  
  if (param_3 != 0) {
    FUN_00566cf0(param_3);
  }
  piVar1 = (int *)*param_1;
  param_1[2] = (int)piVar1;
  if ((piVar1 != (int *)0x0) && (puVar2 = (undefined4 *)*piVar1, puVar2 != (undefined4 *)0x0)) {
    while( true ) {
      (**(code **)*puVar2)(param_2);
      if (param_1[2] == 0) break;
      puVar2 = *(undefined4 **)(param_1[2] + 4);
      param_1[2] = (int)puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        return;
      }
      puVar2 = (undefined4 *)*puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        return;
      }
    }
  }
  return;
}


