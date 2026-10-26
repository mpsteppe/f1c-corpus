// Function: FUN_00540df0 @ 00540df0
// Strings:  [Invalid parameters, Error creating vertex buffer]


undefined4 __thiscall FUN_00540df0(int *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = 0;
  uVar4 = 0;
  if (param_1[0x44e] == 0) {
    uVar3 = 0x10;
  }
  if (param_2 == (uint *)0x0) {
    FUN_0053c590(0xffffffff,s_Invalid_parameters_005dbcd0);
    return 0xffffffff;
  }
  uVar1 = *param_2;
  if ((uVar1 & 2) != 0) {
    uVar3 = uVar3 | 8;
  }
  if ((uVar1 & 0x10) != 0) {
    uVar3 = uVar3 | 8;
  }
  if ((uVar1 & 0x20) == 0) goto LAB_00540e50;
  iVar2 = param_1[0x4f8];
  if (iVar2 == 0) {
    uVar4 = 2;
  }
  else {
    if (iVar2 == 1) {
      uVar3 = uVar3 | 0x210;
      goto LAB_00540e50;
    }
    if (iVar2 != 2) goto LAB_00540e50;
  }
  uVar3 = uVar3 | 0x200;
LAB_00540e50:
  iVar2 = (**(code **)(*(int *)param_1[0x440] + 0x5c))
                    ((int *)param_1[0x440],param_2[3] * param_2[2],uVar3,param_2[1],uVar4,
                     param_2 + 8);
  *param_1 = iVar2;
  if (iVar2 == 0) {
    return 0;
  }
  FUN_0053c590(0xffffffff,s_Error_creating_vertex_buffer_005dbd40);
  return 0xffffffff;
}


