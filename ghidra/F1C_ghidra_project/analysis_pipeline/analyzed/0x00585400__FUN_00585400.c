// Function: FUN_00585400 @ 00585400
// Size (bytes): 62


undefined4 __thiscall FUN_00585400(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00586d00();
  if (iVar1 == 0) {
    (**(code **)(*param_1 + 0x2c))();
    FUN_00584230(param_2);
    (**(code **)(*param_1 + 0x5c))(param_2);
    return 1;
  }
  FUN_00584dd0(param_2);
  return 1;
}


