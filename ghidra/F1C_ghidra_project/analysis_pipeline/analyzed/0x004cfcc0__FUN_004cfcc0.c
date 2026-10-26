// Function: FUN_004cfcc0 @ 004cfcc0
// Size (bytes): 519


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004cfcc0(int *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_20;
  float local_1c;
  float local_c;
  float local_8;
  float local_4;
  
  FUN_004c9c00();
  if ((DAT_007c56ac == '\0') || (cVar2 = FUN_004b9a00(), cVar2 != '\0')) {
    if ((DAT_0059e440 < _DAT_008afee4) && (param_1[7] != 0)) {
      iVar3 = FUN_0040c870();
      local_c = *(float *)(iVar3 + 0x24) * _DAT_0059e7f8 - *(float *)(iVar3 + 0xc);
      local_8 = *(float *)(iVar3 + 0x28) * _DAT_0059e7f8 - *(float *)(iVar3 + 0x10);
      local_4 = *(float *)(iVar3 + 0x2c) * _DAT_0059e7f8 - *(float *)(iVar3 + 0x14);
      FUN_004cc970(&local_c,_DAT_008afee4);
    }
    iVar3 = 0;
    if (0 < param_1[4]) {
      do {
        FUN_004cdb20();
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_1[4]);
    }
  }
  else {
    iVar3 = 0;
    if (0 < param_1[4]) {
      iVar4 = 0;
      do {
        iVar1 = *(int *)(param_1[5] + iVar4 + 4);
        if ((-1 < iVar1) && (iVar1 < 6)) {
          FUN_004cdb20();
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x6c;
      } while (iVar3 < param_1[4]);
    }
  }
  if (DAT_008ab6e4 == 2) {
    iVar3 = FUN_004b9e30();
    if (iVar3 == 5) {
      local_20 = 0.0;
      goto LAB_004cfe04;
    }
    fVar5 = (float10)FUN_004b9cf0();
  }
  else {
    fVar5 = (float10)_DAT_008afe98;
  }
  local_20 = (float)fVar5;
LAB_004cfe04:
  iVar3 = FUN_0040c870();
  local_c = -*(float *)(iVar3 + 0xc);
  local_8 = -*(float *)(iVar3 + 0x10);
  local_4 = -*(float *)(iVar3 + 0x14);
  local_1c = _DAT_005aced4 -
             SQRT(*(float *)(iVar3 + 0x2c) * *(float *)(iVar3 + 0x2c) +
                  *(float *)(iVar3 + 0x28) * *(float *)(iVar3 + 0x28) +
                  *(float *)(iVar3 + 0x24) * *(float *)(iVar3 + 0x24)) * _DAT_0059e46c;
  if (local_1c < DAT_0059e440) {
    local_1c = 0.0;
  }
  iVar3 = 0;
  if (0 < *param_1) {
    do {
      FUN_004ca2d0(local_20,&local_c,local_1c);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *param_1);
  }
  return;
}


