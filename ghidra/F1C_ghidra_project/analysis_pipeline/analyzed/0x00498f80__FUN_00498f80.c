// Function: FUN_00498f80 @ 00498f80
// Size (bytes): 46


void __fastcall FUN_00498f80(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x4c);
  while (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x70))();
    piVar1 = (int *)FUN_00486320();
  }
  FUN_00499540();
  return;
}


