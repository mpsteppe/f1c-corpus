// Function: FUN_00466650 @ 00466650
// Size (bytes): 652


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00466650(int *param_1)

{
  float fVar1;
  float fVar2;
  int unaff_ESI;
  bool bVar3;
  float10 fVar4;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  undefined1 local_4 [4];
  
  if (param_1[0x3c] == 0) {
    return;
  }
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  local_28 = 0.0;
  local_1c = 0;
  FUN_00498880(&local_8,local_4);
  fVar4 = (float10)FUN_00498730();
  local_24 = (float)fVar4;
  fVar1 = (float)param_1[0x43];
  param_1[0x43] = (int)(float)(fVar4 + (float10)fVar1);
  if ((float10)_DAT_0059e478 < fVar4 + (float10)fVar1) {
    param_1[0x43] = 0x40400000;
  }
  FUN_0054b530(&local_c,&local_10,&local_14,&local_18,&local_28,&local_1c);
  local_28 = (float)param_1[0x45];
  if ((char)param_1[0x3d] != '\0') {
    FUN_004988a0(3);
    bVar3 = local_24 != DAT_0059e440;
    param_1[0x43] = 0;
    if (bVar3) {
      local_20 = (float)(local_8 - param_1[0x41]);
      param_1[0x44] = (int)(((float)(int)local_20 / local_24) * _DAT_0059e450);
    }
    bVar3 = local_8 - param_1[0x41] < 0;
    fVar1 = SQRT((float)param_1[0x44] * (float)param_1[0x44]) * _DAT_0059f20c;
    if (local_8 == param_1[0x41] || bVar3) {
      if (bVar3) {
        local_28 = fVar1 + local_28;
        (**(code **)(*param_1 + 0x2c))(1);
        goto LAB_00466890;
      }
    }
    else {
      local_28 = local_28 - fVar1;
    }
    (**(code **)(*param_1 + 0x2c))(1);
    goto LAB_00466890;
  }
  local_20 = (_DAT_0059e43c - (float)param_1[0x43] * _DAT_0059e98c) *
             SQRT((float)param_1[0x44] * (float)param_1[0x44]) * _DAT_0059f208;
  fVar1 = local_24 * _DAT_0059e450;
  if (((float)param_1[0x44] <= _DAT_0059e8ec) || (_DAT_0059e478 <= (float)param_1[0x43])) {
    fVar2 = fVar1;
    if (DAT_0059e440 < (float)param_1[0x44]) goto LAB_00466830;
  }
  else {
    fVar2 = local_20 + fVar1;
LAB_00466830:
    local_28 = local_28 - fVar2;
  }
  if ((_DAT_0059f204 <= (float)param_1[0x44]) || (_DAT_0059e478 <= (float)param_1[0x43])) {
    if ((float)param_1[0x44] < DAT_0059e440) {
      local_28 = fVar1 + local_28;
    }
  }
  else {
    local_28 = fVar1 + local_20 + local_28;
  }
  (**(code **)(*param_1 + 0x2c))(1);
LAB_00466890:
  FUN_0054b4d0(local_10,local_14,local_18,local_1c,unaff_ESI,local_20);
  param_1[0x45] = unaff_ESI;
  param_1[0x41] = local_c;
  param_1[0x42] = local_8;
  return;
}


