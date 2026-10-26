// Function: FUN_00438690 @ 00438690
// Size (bytes): 573


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00438690(int param_1,double param_2,int param_3)

{
  double dVar1;
  double dVar2;
  double dVar3;
  int iVar4;
  undefined4 *puVar5;
  double *pdVar6;
  float10 fVar7;
  undefined1 local_38 [16];
  double local_28;
  double local_20 [3];
  
  dVar2 = ABS(*(double *)(param_1 + 0xbc)) * *(double *)(param_1 + 0x3d4);
  dVar1 = *(double *)(param_1 + 0x414);
  FUN_004388d0(param_3 + 100,local_38);
  dVar3 = _DAT_0059e430;
  if (local_28 < _DAT_0059e430) {
    dVar3 = -local_28;
  }
  dVar1 = (dVar3 * *(double *)(param_1 + 0x424) + *(double *)(param_1 + 0x41c)) *
          (((double)_DAT_008afef4 + _DAT_0059eac8 + (double)_DAT_008afef0 + _DAT_0059eac8) *
           _DAT_0059e880 - *(double *)(param_1 + 0x404)) + dVar2 * dVar1;
  if (*(double *)(param_1 + 0x42c) <= *(double *)(param_1 + 0x444)) {
    dVar1 = dVar1 / *(double *)(param_1 + 0x444);
  }
  else {
    dVar2 = *(double *)(param_1 + 0x42c) -
            *(double *)(param_1 + 0x404) * *(double *)(param_1 + 0x404) *
            *(double *)(param_1 + 0x404) * *(double *)(param_1 + 0x43c) * dVar2 * param_2;
    *(double *)(param_1 + 0x42c) = dVar2;
    if (dVar2 < *(double *)(param_1 + 0x444) == (dVar2 == *(double *)(param_1 + 0x444))) {
      dVar1 = dVar1 / dVar2;
      fVar7 = ABS((float10)*(double *)(param_1 + 0x404) - (float10)*(double *)(param_1 + 0x40c));
      if (fVar7 <= (float10)*(double *)(param_1 + 0x3f4)) {
        fVar7 = (float10)fcos(fVar7 * (float10)*(double *)(param_1 + 0x3fc));
        *(double *)(param_1 + 0x3e4) =
             (double)((fVar7 * (float10)_DAT_0059eb50 + (float10)_DAT_0059ea60) *
                     (float10)*(double *)(param_1 + 0x3ec));
      }
      else {
        if (*(double *)(param_1 + 0x3ec) * _DAT_0059e880 < *(double *)(param_1 + 0x3e4)) {
          FUN_0041b200();
        }
        *(double *)(param_1 + 0x3e4) = *(double *)(param_1 + 0x3ec) * _DAT_0059e880;
      }
    }
    else {
      iVar4 = 0;
      if (0 < DAT_005c329c) {
        do {
          if (*(int *)((&DAT_007c54f0)[iVar4] + 13000) == 0) {
            if (*(int *)((&DAT_007c54f0)[iVar4] + 0x4068) == 0) {
              *(undefined4 *)((&DAT_007c54f0)[iVar4] + 0x4068) = 5;
            }
            break;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < DAT_005c329c);
      }
      dVar1 = _DAT_0059e430;
      *(undefined4 *)(param_1 + 0x42c) = 0;
      *(undefined4 *)(param_1 + 0x430) = 0;
      *(undefined4 *)(param_1 + 0x3e4) = 0;
      *(undefined4 *)(param_1 + 1000) = 0;
    }
  }
  *(double *)(param_1 + 0x404) = dVar1 * param_2 + *(double *)(param_1 + 0x404);
  puVar5 = (undefined4 *)(*(int *)(param_1 + 0x15c) + 0xbc);
  pdVar6 = local_20;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)pdVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    pdVar6 = (double *)((int)pdVar6 + 4);
  }
  dVar1 = *(double *)(param_1 + 0x434) * *(double *)(param_1 + 0x42c) + *(double *)(param_1 + 0xcc);
  local_20[0] = dVar1;
  FUN_005697a0(local_20);
  *(double *)(param_1 + 0xd4) = _DAT_0059e420 / dVar1;
  return;
}


