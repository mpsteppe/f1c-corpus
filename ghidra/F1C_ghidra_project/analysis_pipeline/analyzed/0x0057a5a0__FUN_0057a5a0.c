// Function: FUN_0057a5a0 @ 0057a5a0
// Size (bytes): 98


void __fastcall FUN_0057a5a0(undefined4 *param_1)

{
  int iVar1;
  float10 fVar2;
  undefined4 *local_4;
  
  local_4 = param_1;
  fVar2 = (float10)FUN_00584f90();
  FUN_005836e0(&local_4,(double)fVar2);
  iVar1 = (**(code **)(*(int *)*param_1 + 0x58))();
  FUN_00586800(0,0xe,0,3,500);
  *(undefined1 *)(*(int *)(iVar1 + 0x48) + 4) = 1;
  FUN_00586a00(&local_4,4);
  FUN_00585380(iVar1);
  return;
}


