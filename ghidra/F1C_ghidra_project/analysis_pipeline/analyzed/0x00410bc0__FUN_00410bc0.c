// Function: FUN_00410bc0 @ 00410bc0
// Size (bytes): 900


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00410bc0(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_34 = param_2[1];
  local_30 = (float)(*(int *)((int)param_2 + 10) << 8) * _DAT_0059e780;
  local_2c = (float)(int)(((ushort)param_2[3] & 0xff00) + *(int *)((int)param_2 + 0xe) * 0x10000) *
             _DAT_0059e780;
  uVar3 = (uint)(short)param_2[2];
  local_28 = (float)(int)((*(uint *)((int)param_2 + 0xe) >> 8 & 0xffff00) +
                         (uint)*(byte *)((int)param_2 + 0x12) * 0x1000000) * _DAT_0059e780;
  local_24 = (float)(int)*(short *)((int)param_2 + 0x13) * _DAT_0059e77c;
  local_20 = (float)(int)*(short *)((int)param_2 + 0x15) * _DAT_0059e77c;
  local_1c = (float)(int)*(short *)((int)param_2 + 0x17) * _DAT_0059e77c;
  local_18 = (float)(int)*(short *)((int)param_2 + 0x19) * _DAT_0059e778;
  local_14 = (float)(int)*(short *)((int)param_2 + 0x1b) * _DAT_0059e778;
  local_10 = (float)(int)*(short *)((int)param_2 + 0x1d) * _DAT_0059e778;
  uVar1 = *param_2 >> 0x12 & 0x3f;
  local_c = (float)(int)*(short *)((int)param_2 + 0x1f) * _DAT_0059e774;
  local_8 = (float)(int)*(short *)((int)param_2 + 0x21) * _DAT_0059e774;
  local_4 = (float)(int)*(short *)((int)param_2 + 0x23) * _DAT_0059e774;
  if (5 < uVar1 - 1) {
    return;
  }
  switch(uVar1) {
  case 1:
    if ((int)uVar3 < 0) {
      return;
    }
    iVar2 = *(int *)(param_1 + 0x24);
    break;
  case 2:
    if ((int)uVar3 < 0) {
      return;
    }
    iVar2 = *(int *)(param_1 + 0x30);
    break;
  case 3:
    if ((int)uVar3 < 0) {
      return;
    }
    iVar2 = *(int *)(param_1 + 0x3c);
    break;
  case 4:
    if ((int)uVar3 < 0) {
      return;
    }
    if (*(int *)(param_1 + 0x48) <= (int)uVar3) {
      return;
    }
    if ((int)uVar3 < 0x1a0) {
      uVar1 = uVar3 & 0x80000003;
      if ((int)uVar1 < 0) {
        uVar1 = (uVar1 - 1 | 0xfffffffc) + 1;
      }
      if (*(int *)(*(int *)(param_1 + 0x4c) + uVar3 * 0x24) == -1) {
        if ((&DAT_005ecf0c)[((int)(uVar3 + ((int)uVar3 >> 0x1f & 3U)) >> 2) * 0x1230 + uVar1 * 0x4a]
            == 0) {
          return;
        }
        FUN_0040e770((&DAT_005ecf0c)
                     [((int)(uVar3 + ((int)uVar3 >> 0x1f & 3U)) >> 2) * 0x1230 + uVar1 * 0x4a],1);
      }
      FUN_004ed250(uVar1);
    }
    FUN_0040ef70(&local_34);
    return;
  case 5:
    if ((int)uVar3 < 0) {
      return;
    }
    if (*(int *)(param_1 + 0x54) <= (int)uVar3) {
      return;
    }
    if ((int)uVar3 < 0xd0) {
      uVar1 = uVar3 & 0x80000001;
      if ((int)uVar1 < 0) {
        uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
      }
      if (*(int *)(*(int *)(param_1 + 0x58) + uVar3 * 0x24) == -1) {
        if (uVar1 == 0) {
          iVar2 = (&DAT_005ed3ac)[((int)uVar3 / 2) * 0x1230];
        }
        else {
          iVar2 = (&DAT_005ed3f0)[((int)uVar3 / 2) * 0x1230];
        }
        if (iVar2 == 0) {
          return;
        }
        FUN_0040e770(iVar2,1);
      }
      FUN_004ed250((uVar1 != 0) + '\x04');
    }
    FUN_0040ef70(&local_34);
    return;
  case 6:
    if ((int)uVar3 < 0) {
      return;
    }
    if (*(int *)(param_1 + 0x60) <= (int)uVar3) {
      return;
    }
    if ((int)uVar3 < 0x340) {
      uVar1 = uVar3 & 0x80000007;
      if ((int)uVar1 < 0) {
        uVar1 = (uVar1 - 1 | 0xfffffff8) + 1;
      }
      if (*(int *)(*(int *)(param_1 + 100) + uVar3 * 0x24) == -1) {
        if ((&DAT_005ed434)[((int)(uVar3 + ((int)uVar3 >> 0x1f & 7U)) >> 3) * 0x1230 + uVar1 * 0x11]
            == 0) {
          return;
        }
        FUN_0040e770((&DAT_005ed434)
                     [((int)(uVar3 + ((int)uVar3 >> 0x1f & 7U)) >> 3) * 0x1230 + uVar1 * 0x11],1);
      }
      FUN_004ed250(uVar1 + 6);
    }
    goto LAB_00410f2a;
  }
  if ((int)uVar3 < iVar2) {
LAB_00410f2a:
    FUN_0040ef70(&local_34);
  }
  return;
}


