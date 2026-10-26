// Function: FUN_00554be0 @ 00554be0
// Size (bytes): 69


void __thiscall FUN_00554be0(undefined4 *param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_2 != param_1[0x4e8]) {
    param_1[0x4e8] = param_2;
    piVar1 = (int *)param_1[0x440];
    if (param_2 != 0) {
      uVar2 = (**(code **)(*piVar1 + 200))(piVar1,0xe,1);
      *param_1 = uVar2;
      return;
    }
    uVar2 = (**(code **)(*piVar1 + 200))(piVar1,0xe,0);
    *param_1 = uVar2;
  }
  return;
}


