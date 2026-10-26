// Function: FUN_0042ec60 @ 0042ec60
// Size (bytes): 93


void __fastcall FUN_0042ec60(undefined1 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(param_1 + 0xc4);
  iVar3 = 4;
  do {
    iVar2 = 0xb;
    do {
      *puVar1 = puVar1[1];
      puVar1 = puVar1 + 0x10;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar1 = (undefined4 *)(param_1 + 0xbc4);
  iVar3 = 0x37;
  do {
    *puVar1 = puVar1[1];
    puVar1 = puVar1 + 0x10;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(param_1 + 0x1ca8) = 0x3f000000;
  *(undefined4 *)(param_1 + 0x1cac) = 0x3f000000;
  *(undefined4 *)(param_1 + 0x1cb0) = 0x3f000000;
  *(undefined4 *)(param_1 + 0x1cb4) = 0x3f000000;
  *param_1 = 1;
  return;
}


