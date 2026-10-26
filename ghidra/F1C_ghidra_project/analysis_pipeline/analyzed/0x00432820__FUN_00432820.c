// Function: FUN_00432820 @ 00432820
// Size (bytes): 65


undefined1 * __thiscall FUN_00432820(int *param_1,int param_2)

{
  int *piVar1;
  undefined1 *puVar2;
  
  if ((-1 < param_2) && (param_2 < *(int *)(*param_1 + 0x2c))) {
    piVar1 = *(int **)(*param_1 + 0x20);
    for (; 0 < param_2; param_2 = param_2 + -1) {
      if (piVar1 == (int *)0x0) {
        return (undefined1 *)0x0;
      }
      piVar1 = (int *)piVar1[1];
    }
    if ((piVar1 != (int *)0x0) && ((int *)*piVar1 != (int *)0x0)) {
      puVar2 = *(undefined1 **)*piVar1;
      if (puVar2 == (undefined1 *)0x0) {
        return &DAT_005ea438;
      }
      return puVar2;
    }
  }
  return (undefined1 *)0x0;
}


