// Function: FUN_0040a910 @ 0040a910
// Size (bytes): 270


uint __thiscall FUN_0040a910(int *param_1,int param_2,char param_3)

{
  uint in_EAX;
  uint uVar1;
  undefined4 uVar2;
  undefined3 uVar3;
  undefined3 extraout_var;
  int iVar4;
  int iVar5;
  
  uVar1 = in_EAX & 0xffffff00;
  if (param_2 != 0) {
    if (param_2 == param_1[4]) {
      uVar2 = FUN_00409440(0,1,1);
    }
    else if (param_2 == param_1[5]) {
      uVar2 = FUN_00409440(1,1,1);
    }
    else if (param_2 == param_1[6]) {
      uVar2 = FUN_00409440(2,1,1);
    }
    else if (param_2 == param_1[7]) {
      uVar2 = FUN_00409440(3,1,1);
    }
    else if (param_2 == param_1[9]) {
      uVar2 = FUN_00409440(5,1,1);
    }
    else if (param_2 == param_1[10]) {
      uVar2 = FUN_00409440(6,1,1);
    }
    else if (param_2 == param_1[0xb]) {
      uVar2 = FUN_00409440(7,1,1);
    }
    else if (param_2 == param_1[0xc]) {
      uVar2 = FUN_00409440(8,1,1);
    }
    else {
      iVar5 = 0;
      if (param_1[0xe] < 1) {
        return uVar1;
      }
      iVar4 = param_1[8];
      while (iVar4 != param_2) {
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 200;
        if (param_1[0xe] <= iVar5) {
          return uVar1;
        }
      }
      uVar2 = FUN_00409440(4,1,1);
      param_1[0xf] = iVar5;
    }
    uVar3 = (undefined3)((uint)uVar2 >> 8);
    if (param_3 != '\0') {
      (**(code **)(*param_1 + 0x10))();
      uVar3 = extraout_var;
    }
    uVar1 = CONCAT31(uVar3,1);
  }
  return uVar1;
}


