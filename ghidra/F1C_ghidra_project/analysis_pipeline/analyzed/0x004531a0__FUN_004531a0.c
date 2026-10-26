// Function: FUN_004531a0 @ 004531a0
// Size (bytes): 243


undefined4 * __fastcall FUN_004531a0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  param_1[2] = 0;
  param_1[0x9f] = 0x11;
  puVar1 = param_1;
  for (iVar2 = 0x32e; puVar1 = puVar1 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
  }
  puVar1 = param_1 + 0x32f;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  param_1[0x382] = 0;
  param_1[0x41f] = 0x11;
  puVar1 = param_1 + 0x362;
  for (iVar2 = 0xff; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  param_1[0x481] = 0;
  param_1[0x51e] = 0x11;
  puVar1 = param_1 + 0x461;
  for (iVar2 = 0xff; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  puVar1 = param_1 + 0x560;
  for (iVar2 = 0x164; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  iVar2 = 0x2c;
  do {
    FUN_00452780();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = param_1 + 0x8ac;
  iVar2 = 0x2c;
  do {
    *puVar1 = 0;
    puVar1[1] = 0xffffffff;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[0x360] = 0;
  param_1[0x904] = 0;
  param_1[0x905] = 0;
  param_1[0x906] = 0;
  param_1[0x907] = 0;
  param_1[0x908] = 0;
  *(undefined1 *)(param_1 + 0x90a) = 0;
  *(undefined1 *)(param_1 + 0x35f) = 1;
  param_1[0x909] = 0xfffffffe;
  param_1[0x560] = param_1;
  return param_1;
}


