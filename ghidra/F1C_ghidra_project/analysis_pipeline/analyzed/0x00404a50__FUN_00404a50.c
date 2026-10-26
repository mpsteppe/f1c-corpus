// Function: FUN_00404a50 @ 00404a50
// Size (bytes): 108


undefined4 * __fastcall FUN_00404a50(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x58);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[4] = 0;
    puVar1[3] = 0;
    puVar1[2] = 0;
    puVar1[1] = 0;
    *puVar1 = 0;
    puVar1[10] = 0;
    puVar1[0xb] = 0xffffffff;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0xffffffff;
    puVar1[0xe] = 0;
    puVar1[0xf] = 0xffffffff;
    puVar1[0x10] = 0;
    puVar1[0x11] = 0;
    puVar1[0x12] = 0;
    puVar1[0x13] = 0;
    puVar1[6] = DAT_0059e48c;
    puVar1[8] = 0;
    *(undefined1 *)(puVar1 + 9) = 0;
    puVar1[0x14] = 0;
    puVar1[0x15] = 0;
    *(undefined1 *)(puVar1 + 5) = 0;
    *(undefined1 *)((int)puVar1 + 0x15) = 0;
    puVar1[7] = 0;
    *param_1 = puVar1;
    return param_1;
  }
  *param_1 = 0;
  return param_1;
}


