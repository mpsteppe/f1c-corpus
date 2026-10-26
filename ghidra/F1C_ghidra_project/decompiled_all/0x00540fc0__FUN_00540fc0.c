// Function: FUN_00540fc0 @ 00540fc0
// Strings:  [Invalid parameters, Error creating index buffer]


undefined4 __thiscall FUN_00540fc0(int *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_2 == (uint *)0x0) {
    FUN_0053c590(0xffffffff,s_Invalid_parameters_005dbcd0);
    return 0xffffffff;
  }
  uVar1 = *param_2;
  if ((uVar1 & 2) != 0) {
    uVar3 = 8;
  }
  if ((uVar1 & 0x10) != 0) {
    uVar3 = 8;
  }
  if ((uVar1 & 0x20) != 0) {
    uVar3 = uVar3 | 0x200;
  }
  iVar2 = (**(code **)(*(int *)param_1[0x440] + 0x60))
                    ((int *)param_1[0x440],param_2[1] << 1,uVar3,0x65,0,param_2 + 6);
  *param_1 = iVar2;
  if (iVar2 != 0) {
    FUN_0053c590(0xffffffff,s_Error_creating_index_buffer_005dbd60);
    return 0xffffffff;
  }
  return 0;
}


