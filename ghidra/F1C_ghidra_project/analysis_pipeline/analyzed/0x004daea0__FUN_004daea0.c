// Function: FUN_004daea0 @ 004daea0
// Size (bytes): 396


undefined4 * __fastcall FUN_004daea0(undefined4 param_1)

{
  undefined4 *puVar1;
  
  switch(param_1) {
  case 0:
    puVar1 = operator_new(0x18);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 2;
      *(undefined1 *)(puVar1 + 2) = 1;
      *puVar1 = &PTR_LAB_005ad050;
      puVar1[3] = 0;
      return puVar1;
    }
    break;
  case 1:
    puVar1 = operator_new(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_LAB_005ad034;
      puVar1[1] = 1;
      *(undefined1 *)(puVar1 + 2) = 1;
      puVar1[3] = 0;
      return puVar1;
    }
    break;
  case 2:
    puVar1 = operator_new(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_LAB_005ad018;
      puVar1[1] = 1;
      *(undefined1 *)(puVar1 + 2) = 1;
      puVar1[3] = 0;
      return puVar1;
    }
    break;
  case 6:
    puVar1 = operator_new(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_LAB_005acffc;
      puVar1[1] = 1;
      *(undefined1 *)(puVar1 + 2) = 1;
      puVar1[3] = 0;
      return puVar1;
    }
    break;
  case 7:
    puVar1 = operator_new(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_004db070(1,1);
      *puVar1 = &PTR_LAB_005acfe0;
      return puVar1;
    }
    break;
  case 8:
    puVar1 = operator_new(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_004db0e0();
      *puVar1 = &PTR_LAB_005acfc4;
      return puVar1;
    }
    break;
  case 0xd:
    puVar1 = operator_new(0x20);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_LAB_005acfa8;
      puVar1[1] = 1;
      *(undefined1 *)(puVar1 + 2) = 1;
      puVar1[3] = 0;
      return puVar1;
    }
    break;
  case 0x11:
    puVar1 = operator_new(0x18);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_004db070(1,1);
      *puVar1 = &PTR_LAB_005acf8c;
      return puVar1;
    }
    break;
  case 0x13:
    puVar1 = operator_new(0x2c);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_LAB_005acf70;
      puVar1[1] = 1;
      *(undefined1 *)(puVar1 + 2) = 1;
      puVar1[3] = 0;
      return puVar1;
    }
  }
  return (undefined4 *)0x0;
}


