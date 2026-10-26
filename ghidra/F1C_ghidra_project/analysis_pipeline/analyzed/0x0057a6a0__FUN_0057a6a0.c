// Function: FUN_0057a6a0 @ 0057a6a0
// Size (bytes): 137


undefined4 __thiscall
FUN_0057a6a0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)*param_1 + 0x58))();
  if (iVar1 == 0) {
    return 10;
  }
  if (param_4 == 0) {
    *(undefined1 *)(*(int *)(iVar1 + 0x48) + 4) = 1;
  }
  else {
    (**(code **)(**(int **)(iVar1 + 0x48) + 0x20))(param_4);
  }
  FUN_00586800(1,0,param_5,param_6,param_7);
  FUN_00586a00(param_2,param_3);
  if ((char)param_6 != '\0') {
    FUN_00585380(iVar1);
    return 0;
  }
  FUN_00585270(iVar1);
  return 0;
}


