// Function: FUN_004a6200 @ 004a6200
// Size (bytes): 317


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004a6200(int *param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  float10 fVar3;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  iVar1 = *param_1;
  *(undefined1 *)(param_1 + 100) = 1;
  local_18 = *(float *)(iVar1 + 0x34f8);
  local_14 = *(float *)(iVar1 + 0x34fc);
  local_10 = *(float *)(iVar1 + 0x3500);
  if (_DAT_005acb50 < local_18 * local_18 + local_10 * local_10 + local_14 * local_14) {
    *(undefined1 *)(param_1 + 100) = 0;
  }
  FUN_004f1b50(1);
  if (*(int *)(*param_1 + 13000) == 1) {
    FUN_004ef930(0);
    uVar2 = FUN_0042a3d0();
    *(undefined1 *)(param_1 + 100) = uVar2;
  }
  else if (DAT_007ce048 == 1) {
    *(undefined1 *)(param_1 + 100) = 0;
  }
  if ((char)param_1[100] != '\0') {
    param_1[0x68] = param_2;
    fVar3 = (float10)FUN_004a6340();
    param_1[0x69] = (int)(float)(fVar3 + (float10)(float)param_1[0x68]);
    if (param_1[2] != 0) {
      FUN_004efb20(local_c,&local_18);
      FUN_004a3320(local_c,&local_18);
    }
    if (((*param_1 == DAT_007c54e8) && ((char)param_1[0x6b] == '\0')) && (DAT_007ce814 == 0)) {
      *(undefined1 *)(param_1 + 0x6b) = 1;
      if (DAT_005ea3ec != '\0') {
        FUN_0040d3c0(10);
        return;
      }
      FUN_0040d3c0(9);
    }
  }
  return;
}


