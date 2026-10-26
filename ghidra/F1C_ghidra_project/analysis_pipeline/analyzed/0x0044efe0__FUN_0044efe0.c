// Function: FUN_0044efe0 @ 0044efe0
// Size (bytes): 44


void __fastcall FUN_0044efe0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x278) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x20))(piVar1);
    (**(code **)(**(int **)(param_1 + 4) + 8))(*(int **)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}


