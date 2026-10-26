// Function: FUN_0045b360 @ 0045b360
// Size (bytes): 125


undefined4 * __fastcall FUN_0045b360(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_004dcb70();
  param_1[0xb] = 0;
  param_1[0xc] = 0xffffffff;
  FUN_004dcf80();
  puVar1 = param_1 + 0xf;
  iVar2 = 8;
  do {
    *(undefined1 *)puVar1 = 0;
    puVar1[0x14] = 0xffffffff;
    puVar1[0x15] = 0xbf800000;
    puVar1[0x16] = 3;
    puVar1 = puVar1 + 0x17;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *param_1 = &PTR_FUN_0059f080;
  param_1[199] = 0;
  iVar2 = 0;
  do {
    FUN_0045b430(iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  *(undefined1 *)(param_1 + 200) = 0;
  param_1[0xc9] = 0;
  param_1[0xca] = 0;
  return param_1;
}


