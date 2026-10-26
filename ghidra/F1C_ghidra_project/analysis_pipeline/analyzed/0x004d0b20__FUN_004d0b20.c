// Function: FUN_004d0b20 @ 004d0b20
// Size (bytes): 255


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004d0b20(int *param_1,float param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar2 = FUN_0040c870();
  local_c = -*(float *)(iVar2 + 0xc);
  iVar3 = 0;
  local_8 = -*(float *)(iVar2 + 0x10);
  local_4 = -*(float *)(iVar2 + 0x14);
  if (0 < *param_1) {
    iVar2 = 0;
    do {
      iVar4 = param_1[1] + iVar2;
      if (*(int *)(param_1[1] + 0x68 + iVar2) != 0) {
        FUN_0054b420(&local_18,&local_14,&local_10);
        local_18 = local_18 - local_c;
        local_14 = local_14 - local_8;
        local_10 = local_10 - local_4;
        if (local_18 * local_18 + local_14 * local_14 + local_10 * local_10 < _DAT_005acee4) {
          fVar1 = param_2 + *(float *)(iVar4 + 0x80);
          *(float *)(iVar4 + 0x80) = fVar1;
          if (*(float *)(iVar4 + 0x7c) < fVar1) {
            *(float *)(iVar4 + 0x80) = fVar1 - *(float *)(iVar4 + 0x7c);
          }
          FUN_004a2840(*(undefined4 *)(iVar4 + 0x80));
        }
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x84;
    } while (iVar3 < *param_1);
  }
  return;
}


