// Function: FUN_0042e320 @ 0042e320
// Size (bytes): 223


undefined1 * __fastcall FUN_0042e320(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0xffffffff;
  iVar2 = 0x2c;
  do {
    FUN_0042e1c0();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 0x37;
  do {
    FUN_0042e1c0();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_0042dc60();
  param_1[0x19a4] = 1;
  param_1[0x19a5] = 1;
  *param_1 = 0;
  param_1[0x70] = 0;
  param_1[0x1988] = 0;
  param_1[0x1989] = 0;
  *(undefined4 *)(param_1 + 0x198c) = 0;
  *(undefined4 *)(param_1 + 0x1990) = 0;
  *(undefined4 *)(param_1 + 0x1994) = 0;
  *(undefined4 *)(param_1 + 0x1998) = 0;
  *(undefined4 *)(param_1 + 0x199c) = 0;
  *(undefined4 *)(param_1 + 0x19a0) = 0;
  FUN_0042ed70();
  puVar1 = param_1 + 0x1b26;
  iVar2 = 3;
  do {
    puVar1[-0x180] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 0x80;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0x1ca8) = 0x3f000000;
  *(undefined4 *)(param_1 + 0x1cac) = 0x3f000000;
  *(undefined4 *)(param_1 + 0x1cb0) = 0x3f000000;
  *(undefined4 *)(param_1 + 0x1cb4) = 0x3f000000;
  FUN_0042e400();
  return param_1;
}


