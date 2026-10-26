// Function: FUN_00498fb0 @ 00498fb0
// Size (bytes): 46


void __fastcall FUN_00498fb0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x4c);
  while (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x74))();
    piVar1 = (int *)FUN_00486320();
  }
  FUN_00499560();
  return;
}


