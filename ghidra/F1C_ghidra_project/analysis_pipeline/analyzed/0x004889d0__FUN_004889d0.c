// Function: FUN_004889d0 @ 004889d0
// Size (bytes): 78


float10 __fastcall FUN_004889d0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x20))();
  iVar2 = (**(code **)(*param_1 + 0x18))();
  if ((float10)DAT_0059e440 < (float10)(iVar1 - iVar2)) {
    return (float10)param_1[0x38] / (float10)(iVar1 - iVar2);
  }
  return (float10)0.0;
}


