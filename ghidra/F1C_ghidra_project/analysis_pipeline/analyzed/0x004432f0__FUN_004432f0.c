// Function: FUN_004432f0 @ 004432f0
// Size (bytes): 2037


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004432f0(int param_1)

{
  double *pdVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  double local_f0;
  double local_e8;
  double local_e0;
  double local_d8;
  double local_d0;
  double local_c8;
  double local_c0;
  double local_b8;
  double local_b0;
  double local_a8;
  double local_a0;
  double local_98;
  double local_90;
  double local_88;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  undefined1 local_20 [28];
  
  local_d0 = (*(double *)(param_1 + 0x16f8) + *(double *)(param_1 + 0x16f0)) * _DAT_0059e880;
  if (_DAT_0059e430 <= local_d0) {
    if (*(double *)(param_1 + 0x1af4) < local_d0) {
      local_d0 = *(double *)(param_1 + 0x1af4);
    }
  }
  else {
    local_d0 = 0.0;
  }
  local_d8 = (*(double *)(param_1 + 0x1708) + *(double *)(param_1 + 0x1700)) * _DAT_0059e880;
  if (_DAT_0059e430 <= local_d8) {
    if (*(double *)(param_1 + 0x1af4) < local_d8) {
      local_d8 = *(double *)(param_1 + 0x1af4);
    }
  }
  else {
    local_d8 = 0.0;
  }
  iVar2 = *(int *)(param_1 + 0x1f00);
  local_f0 = *(double *)(iVar2 + 0x3a64);
  local_50 = (double)*(float *)(iVar2 + 0x3a64);
  local_e8 = (double)CONCAT44(local_e8._4_4_,*(float *)(iVar2 + 0x3a6c));
  local_48 = (double)*(float *)(iVar2 + 0x3a68);
  local_40 = (double)*(float *)(iVar2 + 0x3a6c);
  FUN_004388d0(&local_50,&local_68);
  *(double *)(param_1 + 0x1b9c) =
       (local_d8 + local_d0) * *(double *)(param_1 + 0x1ae4) * _DAT_0059e880 +
       ABS(local_d0 - local_d8) * *(double *)(param_1 + 0x1aec) + *(double *)(param_1 + 0x1adc);
  iVar2 = *(int *)(param_1 + 0x15f0);
  FUN_00435e00(param_1 + 0x1afc,&local_80);
  FUN_004388d0(iVar2 + 100,&local_f0);
  local_f0 = local_f0 - local_68;
  local_e8 = local_e8 - local_60;
  local_e0 = local_e0 - local_58;
  FUN_004388d0(iVar2 + 0x7c,local_20);
  FUN_00436230(&local_f0,local_20,&local_b0,&local_c8);
  FUN_00435e00(&local_b0,&local_38);
  FUN_00569ad0(&local_80,&local_38);
  if ((*(char *)(param_1 + 0x1bbc) != '\0') && (local_e0 < _DAT_0059e430)) {
    dVar4 = local_f0 * local_f0 + local_e0 * local_e0;
    dVar3 = _DAT_0059e420;
    if (_DAT_0059e430 < dVar4) {
      dVar4 = (local_e0 * local_e0) / dVar4;
      dVar4 = dVar4 * dVar4;
      dVar3 = _DAT_0059e420 - (_DAT_0059e420 - dVar4 * dVar4) * *(double *)(param_1 + 0x1be0);
    }
    dVar3 = dVar3 * (local_d0 * *(double *)(param_1 + 0x1bd8) +
                     local_d8 * *(double *)(param_1 + 0x1bc8) +
                     local_d8 * *(double *)(param_1 + 0x1bd0) * local_d8 +
                    *(double *)(param_1 + 0x1bc0));
    if (dVar3 < _DAT_0059e430) {
      iVar2 = *(int *)(param_1 + 0x15f0);
      local_28 = dVar3 * local_e0 * local_e0;
      local_38 = local_28 * *(double *)(iVar2 + 0x24);
      local_30 = local_28 * *(double *)(iVar2 + 0x3c);
      local_28 = local_28 * *(double *)(iVar2 + 0x54);
      FUN_00435e00(param_1 + 0x1be8,&local_80);
      FUN_00569ad0(&local_80,&local_38);
    }
  }
  FUN_00443150(param_1 + 0x1838,&local_68);
  FUN_00443150(param_1 + 0x189c,&local_68);
  if ((*(char *)(param_1 + 0x1900) != '\0') &&
     ((*(int *)(*(int *)(param_1 + 0x1f00) + 0xcd4) == 0 ||
      (*(char *)(*(int *)(param_1 + 0x1f00) + 0xd14) != '\0')))) {
    iVar2 = *(int *)(param_1 + 0x15f0);
    pdVar1 = (double *)(param_1 + 0x1918);
    local_98 = (*(double *)(param_1 + 0x1928) * *(double *)(iVar2 + 0x84) -
               *(double *)(param_1 + 0x1920) * *(double *)(iVar2 + 0x8c)) + *(double *)(iVar2 + 100)
    ;
    local_90 = (*(double *)(iVar2 + 0x8c) * *pdVar1 -
               *(double *)(param_1 + 0x1928) * *(double *)(iVar2 + 0x7c)) +
               *(double *)(iVar2 + 0x6c);
    local_88 = (*(double *)(param_1 + 0x1920) * *(double *)(iVar2 + 0x7c) -
               *(double *)(iVar2 + 0x84) * *pdVar1) + *(double *)(iVar2 + 0x74);
    FUN_004388d0(&local_98,&local_f0);
    local_f0 = local_f0 - local_68;
    local_e8 = local_e8 - local_60;
    local_e0 = local_e0 - local_58;
    if (_DAT_0059e430 <= *(double *)(param_1 + 0x1908)) {
      if (*(double *)(param_1 + 0x1910) < *(double *)(param_1 + 0x1908)) {
        *(undefined4 *)(param_1 + 0x1908) = *(undefined4 *)(param_1 + 0x1910);
        *(undefined4 *)(param_1 + 0x190c) = *(undefined4 *)(param_1 + 0x1914);
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x1908) = 0;
      *(undefined4 *)(param_1 + 0x190c) = 0;
    }
    dVar4 = local_f0 * local_f0 + local_e0 * local_e0;
    dVar3 = _DAT_0059e420;
    if (_DAT_0059e430 < dVar4) {
      dVar4 = (local_e0 * local_e0) / dVar4;
      dVar4 = dVar4 * dVar4;
      dVar3 = _DAT_0059e420 - (_DAT_0059e420 - dVar4 * dVar4) * *(double *)(param_1 + 0x1940);
    }
    *(double *)(param_1 + 0x19e0) =
         dVar3 * (*(double *)(param_1 + 0x1938) * *(double *)(param_1 + 0x1908) +
                 *(double *)(param_1 + 0x1930));
    FUN_00436230(&local_f0,local_20,&local_b0,&local_50);
    FUN_00435e00(&local_b0,&local_38);
    FUN_00569ad0(pdVar1,&local_38);
    local_c8 = local_50 + local_c8;
    local_c0 = local_c0 + local_48;
    local_b8 = local_b8 + local_40;
  }
  if ((*(char *)(param_1 + 0x1a08) != '\0') &&
     ((*(int *)(*(int *)(param_1 + 0x1f00) + 0xd18) == 0 ||
      (*(char *)(*(int *)(param_1 + 0x1f00) + 0xd58) != '\0')))) {
    iVar2 = *(int *)(param_1 + 0x15f0);
    FUN_00435e00(param_1 + 0x1a1c,&local_80);
    local_98 = (local_70 * *(double *)(iVar2 + 0x84) - local_78 * *(double *)(iVar2 + 0x8c)) +
               *(double *)(iVar2 + 100);
    local_90 = (local_80 * *(double *)(iVar2 + 0x8c) - local_70 * *(double *)(iVar2 + 0x7c)) +
               *(double *)(iVar2 + 0x6c);
    local_88 = (local_78 * *(double *)(iVar2 + 0x7c) - local_80 * *(double *)(iVar2 + 0x84)) +
               *(double *)(iVar2 + 0x74);
    FUN_004388d0(&local_98,&local_f0);
    local_f0 = local_f0 - local_68;
    local_e8 = local_e8 - local_60;
    local_e0 = local_e0 - local_58;
    dVar3 = local_f0 * local_f0 + local_e0 * local_e0;
    dVar4 = _DAT_0059e420;
    if (_DAT_0059e430 < dVar3) {
      dVar3 = (local_e0 * local_e0) / dVar3;
      dVar3 = dVar3 * dVar3;
      dVar4 = _DAT_0059e420 - (_DAT_0059e420 - dVar3 * dVar3) * *(double *)(param_1 + 0x1a14);
    }
    *(double *)(param_1 + 0x1ab4) = dVar4 * *(double *)(param_1 + 0x1a0c);
    FUN_00436230(&local_f0,local_20,&local_b0,&local_50);
    iVar2 = *(int *)(param_1 + 0x15f0);
    local_38 = local_b0 * *(double *)(iVar2 + 0x1c) +
               local_a8 * *(double *)(iVar2 + 0x24) + local_a0 * *(double *)(iVar2 + 0x2c);
    local_30 = local_b0 * *(double *)(iVar2 + 0x34) +
               local_a8 * *(double *)(iVar2 + 0x3c) + local_a0 * *(double *)(iVar2 + 0x44);
    local_28 = local_b0 * *(double *)(iVar2 + 0x4c) +
               local_a8 * *(double *)(iVar2 + 0x54) + local_a0 * *(double *)(iVar2 + 0x5c);
    FUN_00569ad0(&local_80,&local_38);
    local_c8 = local_50 + local_c8;
    local_c0 = local_c0 + local_48;
    local_b8 = local_b8 + local_40;
  }
  iVar2 = *(int *)(param_1 + 0x15f0);
  *(double *)(iVar2 + 0x14c) =
       local_c8 * *(double *)(iVar2 + 0x1c) +
       local_b8 * *(double *)(iVar2 + 0x2c) + local_c0 * *(double *)(iVar2 + 0x24) +
       *(double *)(iVar2 + 0x14c);
  *(double *)(iVar2 + 0x154) =
       local_c0 * *(double *)(iVar2 + 0x3c) +
       local_b8 * *(double *)(iVar2 + 0x44) + local_c8 * *(double *)(iVar2 + 0x34) +
       *(double *)(iVar2 + 0x154);
  *(double *)(iVar2 + 0x15c) =
       local_c0 * *(double *)(iVar2 + 0x54) +
       local_b8 * *(double *)(iVar2 + 0x5c) + local_c8 * *(double *)(iVar2 + 0x4c) +
       *(double *)(iVar2 + 0x15c);
  return;
}


