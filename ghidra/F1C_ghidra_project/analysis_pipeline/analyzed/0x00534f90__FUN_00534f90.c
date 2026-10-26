// Function: FUN_00534f90 @ 00534f90
// Size (bytes): 563


int __fastcall FUN_00534f90(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int local_8;
  
  if ((param_1 == (int *)0x0) || ((char)param_1[0x17] != 'r')) {
    return -2;
  }
  iVar4 = param_1[0xe];
  if ((iVar4 == -3) || (iVar4 == -1)) {
    return -1;
  }
  if (iVar4 == 1) {
    return 0;
  }
  param_1[3] = param_2;
  param_1[4] = param_3;
  iVar4 = param_2;
  iVar3 = param_3;
  do {
    if (iVar3 == 0) {
LAB_005350e0:
      iVar4 = FUN_00536e90(param_1[3] - iVar4);
      param_1[0x13] = iVar4;
      return param_3 - param_1[4];
    }
    uVar5 = param_1[1];
    if (param_1[0x16] != 0) {
      if ((uint)param_1[4] < uVar5) {
        uVar5 = param_1[4];
      }
      local_8 = param_2;
      if (uVar5 != 0) {
        puVar2 = (undefined4 *)*param_1;
        puVar7 = (undefined4 *)param_1[3];
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar7 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar7 = puVar7 + 1;
        }
        for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)puVar7 = *(undefined1 *)puVar2;
          puVar2 = (undefined4 *)((int)puVar2 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        local_8 = param_2 + uVar5;
        param_1[3] = local_8;
        *param_1 = *param_1 + uVar5;
        param_1[4] = param_1[4] - uVar5;
        param_1[1] = param_1[1] - uVar5;
      }
      if (param_1[4] != 0) {
        iVar4 = FUN_0058803f(local_8,1,param_1[4],param_1[0x10]);
        param_1[4] = param_1[4] - iVar4;
      }
      param_3 = param_3 - param_1[4];
      param_1[2] = param_1[2] + param_3;
      param_1[5] = param_1[5] + param_3;
      if (param_3 == 0) {
        param_1[0xf] = 1;
      }
      return param_3;
    }
    if ((uVar5 == 0) && (param_1[0xf] == 0)) {
      puVar2 = (undefined4 *)FUN_0058afcf();
      *puVar2 = 0;
      iVar3 = FUN_0058803f(param_1[0x11],1,0x4000,param_1[0x10]);
      param_1[1] = iVar3;
      if ((iVar3 == 0) && (param_1[0xf] = 1, (*(byte *)(param_1[0x10] + 0xc) & 0x20) != 0)) {
        param_1[0xe] = -1;
        goto LAB_005350e0;
      }
      *param_1 = param_1[0x11];
    }
    iVar3 = FUN_005357e0();
    param_1[0xe] = iVar3;
    if (iVar3 == 1) {
      iVar3 = FUN_00536e90(param_1[3] - iVar4);
      iVar4 = param_1[3];
      param_1[0x13] = iVar3;
      iVar3 = FUN_00535560();
      if (iVar3 != param_1[0x13]) {
        param_1[0xe] = -3;
        goto LAB_005350e0;
      }
      FUN_00535560();
      FUN_00534d50();
      if (param_1[0xe] != 0) goto LAB_005350e0;
      iVar3 = param_1[2];
      iVar1 = param_1[5];
      FUN_00535620();
      param_1[2] = iVar3;
      param_1[5] = iVar1;
      iVar3 = FUN_00536e90(0);
      param_1[0x13] = iVar3;
    }
    if ((param_1[0xe] != 0) || (param_1[0xf] != 0)) goto LAB_005350e0;
    iVar3 = param_1[4];
  } while( true );
}


