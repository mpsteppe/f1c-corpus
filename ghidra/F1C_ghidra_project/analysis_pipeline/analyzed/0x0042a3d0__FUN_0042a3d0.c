// Function: FUN_0042a3d0 @ 0042a3d0
// Size (bytes): 793


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char __fastcall FUN_0042a3d0(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char local_9;
  int local_8;
  int *local_4;
  
  iVar3 = param_1[0x1178];
  local_9 = '\x01';
  *(undefined1 *)(param_1 + 0x1152) = 1;
  *(undefined1 *)(param_1 + 0x1161) = 0;
  if (param_1[0x1162] < iVar3 + 1) {
    if (DAT_007c56a4 == 7) {
      if (DAT_007c56a8 != 8) {
        *(undefined1 *)(param_1 + 0x1161) = 1;
      }
      fVar1 = (float)(DAT_008acf8c - param_1[0x100f]) + _DAT_0059e8a4;
    }
    else {
      fVar1 = (float)param_1[(iVar3 + 0x459) * 4] - (float)param_1[0x100f];
    }
  }
  else {
    fVar1 = (float)(param_1[(iVar3 + 0x45a) * 4] - param_1[0x100f]) + _DAT_0059e8a4;
  }
  if (((*(int *)(*param_1 + 0xd18) != 0) && (*(char *)(*param_1 + 0xd58) == '\0')) &&
     (DAT_007c56a4 == 7)) {
    FUN_004efac0();
    *(undefined1 *)(param_1 + 0x1161) = 0;
    param_1[(param_1[0x1178] + 0x459) * 4] = param_1[0x100f];
    param_1[param_1[0x1178] * 4 + 0x1167] = 8;
  }
  if ((*(char *)((int)param_1 + 0x39fa) != '\0') && (DAT_007c56a4 == 7)) {
    FUN_004efac0();
    *(undefined1 *)(param_1 + 0x1161) = 0;
    param_1[(param_1[0x1178] + 0x459) * 4] = param_1[0x100f];
    param_1[param_1[0x1178] * 4 + 0x1167] = 8;
  }
  iVar3 = FUN_0042aee0();
  if ((iVar3 != 0) || (DAT_007c56a4 != 7)) {
    local_9 = '\0';
    FUN_004c6d90(0);
    param_1[0x114d] = (int)((float)_DAT_008afea0 + _DAT_0059e808);
    if (DAT_007c56a4 == 7) {
      *(undefined1 *)(param_1 + 0x1104) = 1;
      *(undefined1 *)(param_1 + 0x117d) = 0;
      FUN_004bc060(1);
    }
  }
  if (fVar1 < _DAT_0059e478) {
    fVar1 = _DAT_0059e478;
  }
  fVar1 = fVar1 * (float)param_1[0x117a];
  if ((float)param_1[0xe62] < fVar1) {
    fVar1 = (float)param_1[0xe62];
  }
  param_1[param_1[0x1178] * 4 + 0x1165] = (int)fVar1;
  FUN_004a5bd0(fVar1);
  if (local_9 == '\0') {
    FUN_004f1890(fVar1);
    FUN_0042a6f0();
  }
  iVar3 = *param_1;
  if (((*(int *)(iVar3 + 0xcd4) != 0) && (*(char *)(iVar3 + 0xd14) == '\0')) ||
     ((*(int *)(iVar3 + 0xd18) != 0 && (*(char *)(iVar3 + 0xd58) == '\0')))) {
    FUN_004a56b0(1);
  }
  if (_DAT_0059e444 <= _DAT_008afee8) {
    if (_DAT_0059e978 <= _DAT_008afee8) {
      local_8 = 5;
      if (_DAT_0059e974 <= _DAT_008afee8) {
        local_8 = 6;
      }
    }
    else {
      local_8 = 4;
    }
  }
  else {
    local_8 = param_1[0x1163];
  }
  local_4 = param_1 + 0x1180;
  iVar3 = 0;
  do {
    if (*local_4 == local_8) {
      iVar4 = 0;
      iVar2 = param_1[0xcde];
      while (iVar2 != iVar3) {
        if (iVar2 < iVar3) {
          FUN_004a5750(2);
        }
        else {
          FUN_004a57a0(2);
        }
        iVar4 = iVar4 + 1;
        if (7 < iVar4) break;
        iVar2 = param_1[0xcde];
      }
    }
    iVar3 = iVar3 + 1;
    local_4 = local_4 + 1;
    if (6 < iVar3) {
      return local_9;
    }
  } while( true );
}


