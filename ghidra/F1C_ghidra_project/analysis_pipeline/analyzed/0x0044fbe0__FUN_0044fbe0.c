// Function: FUN_0044fbe0 @ 0044fbe0
// Size (bytes): 53


void __fastcall FUN_0044fbe0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x2f4) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x20))(piVar1);
    (**(code **)(**(int **)(param_1 + 0x80) + 8))(*(int **)(param_1 + 0x80));
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  return;
}


