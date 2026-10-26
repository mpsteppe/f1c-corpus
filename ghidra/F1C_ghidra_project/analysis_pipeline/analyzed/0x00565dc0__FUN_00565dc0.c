// Function: FUN_00565dc0 @ 00565dc0
// Size (bytes): 85


undefined4 * __fastcall FUN_00565dc0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x224);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    *(undefined1 *)(puVar1 + 4) = 0;
    puVar1[0x84] = 0;
    puVar1[0x85] = 0xffffffff;
    *(undefined1 *)(puVar1 + 4) = 0;
    *(undefined1 *)(puVar1 + 0x86) = 0;
    puVar1[0x87] = 0;
    puVar1[0x88] = 0;
    *param_1 = puVar1;
    return param_1;
  }
  *param_1 = 0;
  return param_1;
}


