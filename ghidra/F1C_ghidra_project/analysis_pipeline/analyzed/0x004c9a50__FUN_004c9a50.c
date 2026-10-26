// Function: FUN_004c9a50 @ 004c9a50
// Size (bytes): 265


undefined4 * __fastcall FUN_004c9a50(undefined4 param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 *extraout_ECX;
  undefined4 *extraout_ECX_00;
  undefined4 *extraout_ECX_01;
  undefined4 *extraout_ECX_02;
  
  switch(param_1) {
  case 1:
    pvVar2 = operator_new(0x2c);
    if (pvVar2 != (void *)0x0) {
      FUN_004c8f10(DAT_005ace14);
      extraout_ECX[7] = 0;
      extraout_ECX[8] = 0;
      extraout_ECX[9] = 0;
      extraout_ECX[10] = 0;
      *extraout_ECX = &PTR_FUN_005ace3c;
      return extraout_ECX;
    }
    break;
  case 2:
    pvVar2 = operator_new(0x28);
    if (pvVar2 != (void *)0x0) {
      FUN_004c8f10(DAT_005ace14);
      *extraout_ECX_00 = &PTR_FUN_005ace4c;
      extraout_ECX_00[7] = 0;
      extraout_ECX_00[8] = 0;
      extraout_ECX_00[9] = 0;
      return extraout_ECX_00;
    }
    break;
  case 3:
  case 4:
    break;
  case 5:
    pvVar2 = operator_new(0x1c);
    if (pvVar2 != (void *)0x0) {
      FUN_004c8f10(DAT_005ace18);
      *extraout_ECX_01 = &PTR_LAB_005ace7c;
      return extraout_ECX_01;
    }
    break;
  case 6:
    puVar1 = operator_new(0x24);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_004c8f10(DAT_005ace1c);
      *puVar1 = &PTR_FUN_005ace5c;
      _rand();
      puVar1[7] = 0;
      puVar1[8] = 0;
      return puVar1;
    }
    break;
  case 7:
    pvVar2 = operator_new(0x20);
    if (pvVar2 != (void *)0x0) {
      FUN_004c8f10(0x7effffff);
      *extraout_ECX_02 = &PTR_LAB_005ace6c;
      extraout_ECX_02[7] = 0;
      return extraout_ECX_02;
    }
    break;
  default:
    goto switchD_004c9a5c_default;
  }
switchD_004c9a5c_default:
  return (undefined4 *)0x0;
}


