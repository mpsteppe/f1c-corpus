// Function: FUN_00487010 @ 00487010
// Size (bytes): 68


undefined1 * __thiscall FUN_00487010(int param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x50) + -1 < param_2) goto LAB_0048704c;
  if ((param_2 < 0) || (*(int *)(param_1 + 0x50) <= param_2)) {
LAB_00487040:
    piVar2 = (int *)0x0;
  }
  else {
    puVar1 = *(undefined4 **)(param_1 + 0x44);
    for (; 0 < param_2; param_2 = param_2 + -1) {
      if (puVar1 == (undefined4 *)0x0) goto LAB_00487040;
      puVar1 = (undefined4 *)puVar1[1];
    }
    if (puVar1 == (undefined4 *)0x0) goto LAB_00487040;
    piVar2 = (int *)*puVar1;
  }
  if ((undefined1 *)*piVar2 != (undefined1 *)0x0) {
    return (undefined1 *)*piVar2;
  }
LAB_0048704c:
  return &DAT_005ea438;
}


