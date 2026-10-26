// Function: FUN_0055c860 @ 0055c860
// Size (bytes): 320


void __thiscall
FUN_0055c860(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piStack_4c;
  
  piStack_4c = (int *)0x55c870;
  FUN_00553db0();
  piStack_4c = (int *)0x2;
  puVar1 = (undefined4 *)FUN_00540f00(param_1[0x450],0x40,0);
  *puVar1 = *param_3;
  puVar1[1] = param_3[1];
  puVar1[4] = param_5;
  puVar1[7] = *param_4;
  uVar2 = param_4[1];
  puVar1[0xb] = param_5;
  puVar1[8] = uVar2;
  piStack_4c = (int *)param_1[0x450];
  FUN_00540f90();
  if (param_1[0x554] == 0) {
    piStack_4c = (int *)param_1[0x440];
    uVar2 = (**(code **)(*piStack_4c + 0x88))();
    *param_1 = uVar2;
  }
  piStack_4c = (int *)0x0;
  uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],7);
  *param_1 = uVar2;
  FUN_005546a0(&piStack_4c,0);
  FUN_00554790(0x100,0,0);
  if (param_1[0x4f1] != 1) {
    param_1[0x4f1] = 1;
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x88,1);
    *param_1 = uVar2;
  }
  FUN_00554700(param_1[0x450]);
  uVar2 = (**(code **)(*(int *)param_1[0x440] + 0x118))((int *)param_1[0x440],2,0,1);
  *param_1 = uVar2;
  uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],7,param_1[0x4ee]);
  *param_1 = uVar2;
  if (param_1[0x554] == 0) {
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 0x8c))((int *)param_1[0x440]);
    *param_1 = uVar2;
  }
  return;
}


