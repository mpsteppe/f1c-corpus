// Function: FUN_00540150 @ 00540150
// Size (bytes): 71


void FUN_00540150(int param_1,undefined4 param_2,uint param_3)

{
  int *piVar1;
  
  if (param_3 == 0) {
    param_3 = *(uint *)(param_1 + 0x18);
  }
  if ((param_3 & 1) == 0) {
    if ((param_3 & 2) == 0) goto LAB_0054017f;
    piVar1 = *(int **)(param_1 + 0xc);
  }
  else {
    piVar1 = *(int **)(param_1 + 8);
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x28))(piVar1);
  }
LAB_0054017f:
  if ((param_3 & 4) != 0) {
    (**(code **)(**(int **)(param_1 + 0x10) + 0x44))(*(int **)(param_1 + 0x10),param_2);
  }
  return;
}


