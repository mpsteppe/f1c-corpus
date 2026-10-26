// Function: FUN_0040e170 @ 0040e170
// Size (bytes): 62


void __fastcall FUN_0040e170(int param_1)

{
  int *piVar1;
  
  if ((*(int *)(param_1 + 0x88) != 0) && (*(int *)(*(int *)(param_1 + 0x88) + 0x24) == 10)) {
    FUN_004347c0();
  }
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 0xaf4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))();
  }
  FUN_004186a0();
  FUN_0040da30();
  return;
}


