// Function: FUN_00541120 @ 00541120
// Size (bytes): 533


void __thiscall
FUN_00541120(undefined4 *param_1,int param_2,int param_3,byte param_4,char param_5,
            undefined4 param_6,int param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_retaddr;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  FUN_00553db0();
  uVar3 = 0x10002;
  if ((param_3 != 0) && (*(int *)(param_3 + 0x20) != 0)) {
    if (param_1[0x4f3] != 0) {
      param_1[0x4f3] = 0;
      uVar1 = (**(code **)(*(int *)param_1[0x440] + 0x94))
                        ((int *)param_1[0x440],0x100,param_1 + 0x503);
      *param_1 = uVar1;
    }
    uVar1 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],7,0);
    *param_1 = uVar1;
    if (param_3 == 0) {
      param_1[0x45c] = 0x100;
      if ((param_4 & 0x20) != 0) {
        param_1[0x45c] = 0x900;
        uVar3 = 0x50006;
      }
    }
    else {
      iVar2 = FUN_00554f80(uStack_8,param_3);
      if (iVar2 == 0) {
        return;
      }
      param_1[0x45c] = 0x100;
      if ((param_4 & 0x40) != 0) {
        param_1[0x45c] = 0x500;
      }
      if (param_5 < '\0') {
        param_1[0x45c] = param_1[0x45c] | 1;
      }
      if ((param_4 & 0x20) != 0) {
        param_1[0x45c] = param_1[0x45c] | 0x800;
        uVar3 = 0x60005;
      }
    }
    FUN_00554790(param_1[0x45c],uVar3,param_6);
    FUN_005546a0(&stack0xffffffb4,0);
    FUN_00553fa0(1);
    FUN_00554700(uStack_4);
    if (param_7 == 0) {
      uVar3 = (**(code **)(*(int *)param_1[0x440] + 0x118))
                        ((int *)param_1[0x440],4,unaff_retaddr,param_2 / 3);
    }
    else {
      uVar3 = (**(code **)(*(int *)param_1[0x440] + 0x118))
                        ((int *)param_1[0x440],6,unaff_retaddr,param_7);
    }
    *param_1 = uVar3;
    uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],7,param_1[0x4ee]);
    *param_1 = uVar3;
  }
  return;
}


