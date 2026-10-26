// Function: FUN_0048f590 @ 0048f590
// Size (bytes): 54


undefined4 __fastcall FUN_0048f590(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x174);
  if ((-1 < iVar2) && (iVar2 < *(int *)(param_1 + 0xfc))) {
    puVar1 = *(undefined4 **)(param_1 + 0xf0);
    for (; 0 < iVar2; iVar2 = iVar2 + -1) {
      if (puVar1 == (undefined4 *)0x0) {
        return 0;
      }
      puVar1 = (undefined4 *)puVar1[1];
    }
    if (puVar1 != (undefined4 *)0x0) {
      return *puVar1;
    }
  }
  return 0;
}


