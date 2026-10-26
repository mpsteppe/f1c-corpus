// Function: FUN_00499520 @ 00499520
// Size (bytes): 32


undefined4 __fastcall FUN_00499520(int param_1)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 0x44); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x23]) {
    (**(code **)(*piVar1 + 0xa4))();
  }
  return 0;
}


