// Function: FUN_00467f90 @ 00467f90
// Strings:  [<HEADER2>, <HEADER>]


void __fastcall FUN_00467f90(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 0xf8);
  *(undefined4 **)(param_1 + 0x100) = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)*puVar3;
  }
  iVar2 = *(int *)(param_1 + 0x44);
  while (iVar2 != 0) {
    iVar2 = *(int *)(iVar2 + 4);
    FUN_00418d60(1);
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  do {
    if (puVar3 == (undefined4 *)0x0) {
      return;
    }
    puVar1 = (undefined1 *)*puVar3;
    if (puVar1 == (undefined1 *)0x0) {
      puVar1 = &DAT_005ea438;
    }
    iVar2 = FUN_00588410(puVar1,s_<HEADER>_005c6720);
    if (iVar2 == 0) {
      if (*(int *)(param_1 + 0x100) != 0) {
        *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(*(int *)(param_1 + 0x100) + 4);
      }
      if ((*(undefined4 **)(param_1 + 0x100) != (undefined4 *)0x0) &&
         (puVar3 = (undefined4 *)**(undefined4 **)(param_1 + 0x100), puVar3 != (undefined4 *)0x0)) {
        puVar1 = (undefined1 *)*puVar3;
        if (puVar1 == (undefined1 *)0x0) {
          puVar1 = &DAT_005ea438;
        }
LAB_0046805b:
        FUN_00486f30(puVar1,0xffffffff);
      }
    }
    else {
      puVar1 = (undefined1 *)*puVar3;
      if (puVar1 == (undefined1 *)0x0) {
        puVar1 = &DAT_005ea438;
      }
      iVar2 = FUN_00588410(puVar1,s_<HEADER2>_005c6714);
      if (iVar2 == 0) {
        puVar1 = (undefined1 *)*puVar3;
        if (puVar1 == (undefined1 *)0x0) {
          puVar1 = &DAT_005ea438;
        }
        goto LAB_0046805b;
      }
    }
    if (*(int *)(param_1 + 0x100) != 0) {
      *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(*(int *)(param_1 + 0x100) + 4);
    }
    if (*(undefined4 **)(param_1 + 0x100) == (undefined4 *)0x0) {
      return;
    }
    puVar3 = (undefined4 *)**(undefined4 **)(param_1 + 0x100);
  } while( true );
}


