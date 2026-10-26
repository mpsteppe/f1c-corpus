// Function: FUN_00476d70 @ 00476d70
// Size (bytes): 106


undefined4 FUN_00476d70(void)

{
  int iVar1;
  
  if (DAT_005eb10c != (int *)0x0) {
    (**(code **)(*DAT_005eb10c + 0xc))();
  }
  FUN_004186a0();
  iVar1 = FUN_0048f590();
  if ((((iVar1 != 0) && (0 < *(int *)(iVar1 + 0x48))) && (*(int **)(iVar1 + 0x3c) != (int *)0x0)) &&
     ((iVar1 = **(int **)(iVar1 + 0x3c), iVar1 != 0 && (iVar1 = *(int *)(iVar1 + 0x3c), iVar1 != 0))
     )) {
    if (DAT_005eb10c != (int *)0x0) {
      (**(code **)(*DAT_005eb10c + 0xc))();
    }
    FUN_004186a0();
    FUN_0041b980(iVar1);
  }
  return 0;
}


