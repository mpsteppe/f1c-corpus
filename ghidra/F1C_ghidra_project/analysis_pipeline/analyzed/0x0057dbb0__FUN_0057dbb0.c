// Function: FUN_0057dbb0 @ 0057dbb0
// Size (bytes): 81


void __fastcall FUN_0057dbb0(int *param_1)

{
  undefined4 uVar1;
  float10 fVar2;
  int *piStack_4;
  
  piStack_4 = param_1;
  uVar1 = (**(code **)(*param_1 + 0x58))();
  FUN_00586800(0,0xb,0,2,0xffffffff);
  fVar2 = (float10)FUN_00584f90();
  piStack_4 = (int *)(float)fVar2;
  FUN_00586a00(&piStack_4,4);
  FUN_0057afa0(&piStack_4);
  FUN_00584c70(uVar1);
  return;
}


