// Function: FUN_00499560 @ 00499560
// Size (bytes): 30


void __fastcall FUN_00499560(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x44);
  while (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x74))();
    piVar1 = (int *)FUN_00486320();
  }
  return;
}


