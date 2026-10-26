// Function: FUN_00496880 @ 00496880
// Strings:  [CURRENT_LAYER, CURRENT_PAGE]


undefined4 __fastcall FUN_00496880(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  
  for (piVar1 = *(int **)(param_1 + 0x1c); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x23]) {
    (**(code **)(*piVar1 + 0xa4))();
  }
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 0x38))
              (*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x60));
  }
  piVar1 = *(int **)(param_1 + 0x18);
  if (piVar1 != (int *)0x0) {
    iVar2 = FUN_00498e40();
    if (iVar2 != 0) {
      iVar2 = FUN_00498e40();
      puVar3 = *(undefined1 **)(iVar2 + 0x34);
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_005ea438;
      }
      FUN_0049a490(s_CURRENT_PAGE_005cca20,puVar3);
    }
    iVar2 = FUN_00498e40();
    if (iVar2 != 0) {
      puVar3 = (undefined1 *)piVar1[0xd];
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_005ea438;
      }
      FUN_0049a490(s_CURRENT_LAYER_005cca10,puVar3);
    }
    (**(code **)(*piVar1 + 0x40))();
  }
  return 0;
}


