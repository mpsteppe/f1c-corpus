// Function: FUN_00406cc0 @ 00406cc0
// Size (bytes): 219


undefined4 __fastcall FUN_00406cc0(int *param_1)

{
  int iVar1;
  undefined4 unaff_retaddr;
  
  (**(code **)(*param_1 + 0xc))();
  FUN_00534ac0();
  _AIL_startup_0();
  _AIL_set_preference_8(0x1f,0);
  if (param_1[0x15] == 0) {
    iVar1 = 0x2b11;
  }
  else {
    iVar1 = (-(uint)(param_1[0x15] != 1) & 0x5622) + 0x5622;
  }
  iVar1 = _AIL_open_digital_driver_16(iVar1,0x10,2,0);
  param_1[0x24] = iVar1;
  if (iVar1 == 0) {
    param_1[0x24] = 0;
    (**(code **)(*param_1 + 0x34))(0);
    _AIL_shutdown_0();
    param_1[0x22] = 0;
    return 1;
  }
  (**(code **)(*param_1 + 0x34))(0xc);
  _AIL_set_DirectSound_HWND_8(param_1[0x24],unaff_retaddr);
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  _AIL_set_file_callbacks_16(FUN_00405050,&LAB_00405100,FUN_00405160,&LAB_00405280);
  param_1[0x22] = 1;
  return 0;
}


