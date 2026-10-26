// Function: FUN_00554790 @ 00554790
// Size (bytes): 899


void __thiscall FUN_00554790(undefined4 *param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint local_200 [64];
  undefined4 local_100 [64];
  
  uVar1 = param_1[0x45d];
  iVar4 = 0;
  if (uVar1 != param_2) {
    if ((param_2 & 4) != (uVar1 & 4)) {
      local_100[0] = 0x16;
      if ((param_2 & 4) == 0) {
        local_200[0] = param_1[0x4e9];
      }
      else {
        local_200[0] = 1;
      }
      iVar4 = 1;
    }
    if ((param_2 & 0x400) != (uVar1 & 0x400)) {
      local_100[iVar4] = 0x1d;
      if ((param_2 & 0x400) == 0) {
        local_200[iVar4] = 0;
      }
      else {
        local_200[iVar4] = 1;
      }
      iVar4 = iVar4 + 1;
    }
    iVar5 = iVar4;
    if ((param_2 & 0x800) != (uVar1 & 0x800)) {
      uVar2 = param_1[0x4ef];
      local_100[iVar4] = 0x1b;
      if ((param_2 & 0x800) == 0) {
        local_200[iVar4] = 0;
        iVar5 = iVar4 + 1;
        if (uVar2 != 0x10002) {
          if (*(short *)(param_1 + 0x4ef) != 2) {
            local_100[iVar5] = 0x13;
            local_200[iVar5] = 2;
            iVar5 = iVar4 + 2;
          }
          if (*(short *)((int)param_1 + 0x13be) != 1) {
            local_100[iVar5] = 0x14;
            local_200[iVar5] = 1;
            iVar5 = iVar5 + 1;
          }
          param_1[0x4ef] = 0x10002;
          param_3 = 0x10002;
        }
      }
      else {
        local_200[iVar4] = 1;
        iVar5 = iVar4 + 1;
        if (param_3 != uVar2) {
          if ((short)param_3 != (short)uVar2) {
            local_100[iVar5] = 0x13;
            iVar5 = iVar4 + 2;
            local_200[iVar4 + 1] = param_3 & 0xffff;
          }
          if (param_3._2_2_ != *(ushort *)((int)param_1 + 0x13be)) {
            local_100[iVar5] = 0x14;
            local_200[iVar5] = (uint)param_3._2_2_;
            iVar5 = iVar5 + 1;
          }
          param_1[0x4ef] = param_3;
        }
      }
    }
    iVar4 = iVar5;
    if (((param_2 & 0x1000) != (uVar1 & 0x1000)) && ((param_2 & 0x1000) != 0)) {
      local_100[iVar5] = 0x1b;
      local_200[iVar5] = 1;
      iVar4 = iVar5 + 1;
      if (param_3 != 0x20002) {
        if (*(short *)(param_1 + 0x4ef) != 2) {
          local_100[iVar4] = 0x13;
          local_200[iVar4] = 2;
          iVar4 = iVar5 + 2;
        }
        if (*(short *)((int)param_1 + 0x13be) != 2) {
          local_100[iVar4] = 0x14;
          local_200[iVar4] = 2;
          iVar4 = iVar4 + 1;
        }
        param_1[0x4ef] = 0x20002;
        param_3 = 0x20002;
      }
    }
    if (((param_2 & 0x10) != (uVar1 & 0x10)) && ((param_2 & 0x10) != 0)) {
      local_100[iVar4] = 9;
      local_200[iVar4] = 1;
      iVar4 = iVar4 + 1;
    }
    if (((param_2 & 0x20) != (uVar1 & 0x20)) && ((param_2 & 0x20) != 0)) {
      local_100[iVar4] = 9;
      local_200[iVar4] = 1;
      iVar4 = iVar4 + 1;
    }
    if (((param_2 & 0x100) != (uVar1 & 0x100)) && ((param_2 & 0x100) != 0)) {
      local_100[iVar4] = 9;
      local_200[iVar4] = 2;
      iVar4 = iVar4 + 1;
    }
    if ((param_2 & 1) != (uVar1 & 1)) {
      local_100[iVar4] = 0xf;
      if ((param_2 & 1) == 0) {
        local_200[iVar4] = 0;
      }
      else {
        local_200[iVar4] = 1;
      }
      iVar4 = iVar4 + 1;
    }
  }
  if (((param_2 & 0x800) != 0) && (param_3 != param_1[0x4ef])) {
    if ((short)param_3 != (short)param_1[0x4ef]) {
      local_100[iVar4] = 0x13;
      local_200[iVar4] = param_3 & 0xffff;
      iVar4 = iVar4 + 1;
    }
    if (param_3._2_2_ != *(ushort *)((int)param_1 + 0x13be)) {
      local_100[iVar4] = 0x14;
      local_200[iVar4] = (uint)param_3._2_2_;
      iVar4 = iVar4 + 1;
    }
    param_1[0x4ef] = param_3;
  }
  if (((param_2 & 1) != 0) && (param_4 != param_1[0x4f0])) {
    local_100[iVar4] = 0x18;
    local_200[iVar4] = param_4;
    iVar4 = iVar4 + 1;
    param_1[0x4f0] = param_4;
  }
  if ((iVar4 != 0) && (iVar4 != 0)) {
    iVar5 = 0;
    do {
      uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))
                        ((int *)param_1[0x440],local_100[iVar5],local_200[iVar5]);
      iVar5 = iVar5 + 1;
      *param_1 = uVar3;
    } while (iVar5 < iVar4);
  }
  param_1[0x45d] = param_2;
  return;
}


