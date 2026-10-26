// Function: FUN_00410f60 @ 00410f60
// Size (bytes): 413


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00410f60(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (int)(short)param_2[2];
  switch(*param_2 >> 0x12 & 0x3f) {
  case 1:
    if (iVar2 < 0) {
      return;
    }
    if (*(int *)(param_1 + 0x24) <= iVar2) {
      return;
    }
    iVar2 = *(int *)(iVar2 * 0x318 + 0xd0 + *(int *)(param_1 + 0x2c));
    break;
  case 2:
    if (iVar2 < 0) {
      return;
    }
    if (*(int *)(param_1 + 0x30) <= iVar2) {
      return;
    }
    iVar3 = *(int *)(param_1 + 0x38);
    goto LAB_00411034;
  case 3:
    if (iVar2 < 0) {
      return;
    }
    if (*(int *)(param_1 + 0x3c) <= iVar2) {
      return;
    }
    iVar2 = *(int *)(iVar2 * 0x318 + 0xd0 + *(int *)(param_1 + 0x44));
    break;
  case 4:
    if (iVar2 < 0) {
      return;
    }
    if (*(int *)(param_1 + 0x48) <= iVar2) {
      return;
    }
    iVar3 = *(int *)(param_1 + 0x50);
    iVar1 = 0x328;
    goto LAB_0041103a;
  case 5:
    if (iVar2 < 0) {
      return;
    }
    if (*(int *)(param_1 + 0x54) <= iVar2) {
      return;
    }
    iVar2 = *(int *)(iVar2 * 0x318 + 0xd0 + *(int *)(param_1 + 0x5c));
    break;
  case 6:
    if (iVar2 < 0) {
      return;
    }
    if (*(int *)(param_1 + 0x60) <= iVar2) {
      return;
    }
    iVar3 = *(int *)(param_1 + 0x68);
LAB_00411034:
    iVar1 = 0x318;
LAB_0041103a:
    iVar2 = *(int *)(iVar2 * iVar1 + 0xd0 + iVar3);
    break;
  default:
    goto switchD_00410f7b_default;
  }
  if (iVar2 != 0) {
    FUN_0054b4d0((float)(*(int *)((int)param_2 + 10) << 8) * _DAT_0059e780,
                 (float)(int)(((ushort)param_2[3] & 0xff00) + *(int *)((int)param_2 + 0xe) * 0x10000
                             ) * _DAT_0059e780,
                 (float)(int)((*(uint *)((int)param_2 + 0xe) >> 8 & 0xffff00) +
                             (uint)*(byte *)((int)param_2 + 0x12) * 0x1000000) * _DAT_0059e780,
                 (float)(int)*(short *)((int)param_2 + 0x13) * _DAT_0059e77c,
                 (float)(int)*(short *)((int)param_2 + 0x15) * _DAT_0059e77c,
                 (float)(int)*(short *)((int)param_2 + 0x17) * _DAT_0059e77c);
  }
switchD_00410f7b_default:
  return;
}


