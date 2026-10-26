// Function: FUN_004c4cb0 @ 004c4cb0
// Size (bytes): 63


undefined1 __thiscall FUN_004c4cb0(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int *piVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  uVar2 = 0;
  *(undefined4 **)(param_1 + 0x10) = puVar1;
  if ((puVar1 != (undefined4 *)0x0) && (piVar3 = (int *)*puVar1, piVar3 != (int *)0x0)) {
    while (param_2 != *piVar3) {
      if (*(int *)(param_1 + 0x10) != 0) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x10) + 4);
      }
      if (*(undefined4 **)(param_1 + 0x10) == (undefined4 *)0x0) {
        return 0;
      }
      piVar3 = (int *)**(undefined4 **)(param_1 + 0x10);
      if (piVar3 == (int *)0x0) {
        return uVar2;
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}


