// Function: FUN_004d88b0 @ 004d88b0
// Size (bytes): 32


void __fastcall FUN_004d88b0(int *param_1)

{
  int iVar1;
  
  if (*param_1 != -1) {
    iVar1 = (**(code **)(*(int *)param_1[*param_1 + 4] + 0x14))();
    if (iVar1 == 1) {
      *param_1 = -1;
    }
  }
  return;
}


