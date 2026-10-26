// Function: FUN_00543540 @ 00543540
// Size (bytes): 114


void __thiscall FUN_00543540(int param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  
  if (*param_2 < 0) {
    *param_4 = *param_4 + *param_2;
    *param_2 = 0;
  }
  if (*(int *)(param_1 + 0x1c) < *param_4 + *param_2) {
    *param_4 = *(int *)(param_1 + 0x1c) - *param_2;
  }
  iVar1 = *param_4;
  if (*(int *)(param_1 + 0x1c) <= *param_4) {
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  *param_4 = iVar1;
  if (*param_3 < 0) {
    *param_5 = *param_5 + *param_3;
    *param_3 = 0;
  }
  if (*(int *)(param_1 + 0x20) < *param_5 + *param_3) {
    *param_5 = *(int *)(param_1 + 0x20) - *param_3;
  }
  if (*param_5 < *(int *)(param_1 + 0x20)) {
    *param_5 = *param_5;
    return;
  }
  *param_5 = *(int *)(param_1 + 0x20);
  return;
}


