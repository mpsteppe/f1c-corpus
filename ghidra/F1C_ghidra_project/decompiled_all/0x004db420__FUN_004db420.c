// Function: FUN_004db420 @ 004db420
// Strings:  [INSTANT REPLAY]


undefined4 * __fastcall FUN_004db420(int param_1)

{
  undefined4 *puVar1;
  
  if (param_1 == 0) {
    puVar1 = operator_new(0x18);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 0;
      *(undefined1 *)(puVar1 + 2) = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0xffffffff;
      *puVar1 = &PTR_FUN_005ad088;
      FUN_00566650(s_INSTANT_REPLAY_005d4b88);
      return puVar1;
    }
  }
  else if (param_1 == 1) {
    puVar1 = operator_new(0x18);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 0;
      *(undefined1 *)(puVar1 + 2) = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0xffffffff;
      *puVar1 = &PTR_FUN_005ad0a4;
      return puVar1;
    }
  }
  else if ((param_1 == 2) && (puVar1 = operator_new(0x18), puVar1 != (undefined4 *)0x0)) {
    puVar1[1] = 0;
    *(undefined1 *)(puVar1 + 2) = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0xffffffff;
    *puVar1 = &PTR_FUN_005ad0c0;
    return puVar1;
  }
  return (undefined4 *)0x0;
}


