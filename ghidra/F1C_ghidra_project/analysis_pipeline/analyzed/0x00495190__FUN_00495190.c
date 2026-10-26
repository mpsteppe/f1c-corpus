// Function: FUN_00495190 @ 00495190
// Size (bytes): 326


undefined4 * __fastcall FUN_00495190(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0xffffffff;
  param_1[0x1c] = 0;
  param_1[0x1b] = 0;
  param_1[0x1a] = 0;
  param_1[0x19] = 0;
  param_1[0x18] = 0;
  param_1[0x17] = 0;
  param_1[0x16] = 0;
  param_1[0x1d] = 0;
  param_1[0x24] = 0;
  param_1[0x23] = 0;
  param_1[0x22] = 0;
  param_1[0x21] = 0;
  param_1[0x20] = 0;
  param_1[0x1f] = 0;
  param_1[0x1e] = 0;
  param_1[0x25] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  puVar2 = param_1 + 0x45;
  for (iVar1 = 0x500; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x556] = 0;
  param_1[0x557] = 0xffffffff;
  iVar1 = 4;
  do {
    FUN_004999e0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  puVar2 = param_1 + 0x5a3;
  for (iVar1 = 0x1a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  FUN_00493f50();
  FUN_0049a180();
  param_1[0x62b] = 0;
  param_1[0x62c] = 0;
  param_1[0x62d] = 0;
  param_1[0x62e] = 0;
  param_1[0x62f] = 0;
  param_1[0x630] = 0;
  param_1[0x631] = 0;
  param_1[0x632] = 0;
  param_1[0x633] = 0;
  param_1[0x634] = 0;
  param_1[0x635] = 0;
  param_1[0x636] = 0;
  param_1[0x637] = 0;
  param_1[0x638] = 0;
  param_1[0x639] = 0;
  param_1[0x63a] = 0;
  *param_1 = &PTR_FUN_005ac998;
  FUN_00496560();
  return param_1;
}


