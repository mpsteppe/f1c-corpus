// Function: FUN_00411330 @ 00411330
// Size (bytes): 266


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00411330(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,float *param_6)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 3) {
    iVar1 = *(int *)(param_1 + 0x4c);
    iVar2 = param_5 + param_4 * 4;
    param_5 = (&DAT_005ecf0c)[param_4 * 0x1230 + param_5 * 0x4a];
    *(float *)(*(int *)(iVar1 + 0x20 + iVar2 * 0x24) + 0x1c) = _DAT_007d0ad4 + *param_6;
    iVar2 = iVar1 + iVar2 * 0x24;
  }
  else if (param_2 == 4) {
    iVar2 = *(int *)(param_1 + 0x58) + (param_5 + param_4 * 2) * 0x24;
    if (param_5 == 0) {
      param_5 = (&DAT_005ed3ac)[param_4 * 0x1230];
      *(float *)(*(int *)(iVar2 + 0x20) + 0x1c) = _DAT_007d0ad4 + *param_6;
    }
    else {
      param_5 = (&DAT_005ed3f0)[param_4 * 0x1230];
      *(float *)(*(int *)(iVar2 + 0x20) + 0x1c) = _DAT_007d0ad4 + *param_6;
    }
  }
  else {
    iVar2 = param_5;
    if (param_2 == 5) {
      iVar1 = *(int *)(param_1 + 100);
      iVar2 = param_5 + param_4 * 8;
      param_5 = (&DAT_005ed434)[param_4 * 0x1230 + param_5 * 0x11];
      *(float *)(*(int *)(iVar1 + 0x20 + iVar2 * 0x24) + 0x1c) = _DAT_007d0ad4 + *param_6;
      iVar2 = iVar1 + iVar2 * 0x24;
    }
  }
  FUN_0040e770(param_5,1);
  FUN_0040eec0(param_3);
  FUN_0040ef70(param_6);
  *(undefined1 *)(iVar2 + 10) = 1;
  return;
}


