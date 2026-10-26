// Function: FUN_00556040 @ 00556040
// Size (bytes): 465


undefined4 __thiscall FUN_00556040(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if ((*(uint *)(param_2 + 0x19c) & 0xe0000) == 0) {
    param_2 = 0;
    param_1[0x53c] = 0;
    uVar4 = 0x1c;
  }
  else {
    param_1[0x53c] = 1;
    uVar3 = ((int)*(short *)(param_2 + 0x18c) << 8 | (int)*(short *)(param_2 + 0x18a)) << 8 |
            (int)*(short *)(param_2 + 0x188);
    if (uVar3 != param_1[0x53d]) {
      param_1[0x53d] = uVar3;
      uVar4 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x22,uVar3);
      *param_1 = uVar4;
    }
    if ((float)param_1[0x53f] != *(float *)(param_2 + 0x194)) {
      param_1[0x53f] = *(undefined4 *)(param_2 + 0x194);
      uVar4 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x24,param_1[0x53f])
      ;
      *param_1 = uVar4;
    }
    if ((float)param_1[0x540] != *(float *)(param_2 + 0x198)) {
      param_1[0x540] = *(undefined4 *)(param_2 + 0x198);
      uVar4 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x25,param_1[0x540])
      ;
      *param_1 = uVar4;
    }
    if ((float)param_1[0x53e] != *(float *)(param_2 + 400)) {
      param_1[0x53e] = *(undefined4 *)(param_2 + 400);
      uVar4 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x26,param_1[0x53e])
      ;
      *param_1 = uVar4;
    }
    iVar1 = *(int *)(param_2 + 0x19c);
    if (param_1[0x541] == iVar1) {
      return 0;
    }
    param_1[0x541] = iVar1;
    if (iVar1 == 0x20000) {
      param_2 = 3;
    }
    else if (iVar1 == 0x40000) {
      param_2 = 1;
    }
    else if (iVar1 == 0x80000) {
      param_2 = 2;
    }
    if ((param_1[0x4ea] & 0x4000) == 0) {
      piVar2 = (int *)param_1[0x440];
      if ((char)((uint)param_1[0x4ea] >> 8) < '\0') {
        uVar4 = (**(code **)(*piVar2 + 200))(piVar2,0x8c,param_2);
        *param_1 = uVar4;
        return 0;
      }
      param_1[0x53c] = 0;
      uVar4 = (**(code **)(*piVar2 + 200))(piVar2,0x1c,0);
      *param_1 = uVar4;
      return 0;
    }
    uVar4 = 0x23;
  }
  uVar4 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],uVar4,param_2);
  *param_1 = uVar4;
  return 0;
}


