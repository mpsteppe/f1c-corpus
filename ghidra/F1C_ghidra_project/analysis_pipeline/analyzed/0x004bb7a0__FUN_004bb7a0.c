// Function: FUN_004bb7a0 @ 004bb7a0
// Size (bytes): 86


undefined4 * __fastcall FUN_004bb7a0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = param_1 + 0x10;
  iVar2 = 4;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *param_1 = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0xc] = 0;
  param_1[0x29] = 0;
  param_1[1] = 0xffffffff;
  param_1[9] = 0xffffffff;
  param_1[10] = 0xbf800000;
  param_1[0xb] = 0xffffffff;
  FUN_004bb950();
  return param_1;
}


