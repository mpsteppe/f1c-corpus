// Function: FUN_004b7a00 @ 004b7a00
// Size (bytes): 131


uint __fastcall FUN_004b7a00(int param_1)

{
  uint *puVar1;
  char cVar2;
  undefined4 *puVar3;
  
  FUN_00566d70();
  do {
    cVar2 = FUN_004b7860(1);
  } while (cVar2 != '\0');
  if (0 < (int)*(uint *)(param_1 + 0x720)) {
    puVar3 = *(undefined4 **)(param_1 + 0x714);
    *(undefined4 **)(param_1 + 0x71c) = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = (undefined4 *)*puVar3;
    }
    *(undefined4 *)(param_1 + 0xf30) = *puVar3;
    puVar1 = *(uint **)(param_1 + 0x718);
    *(uint **)(param_1 + 0x71c) = puVar1;
    if (puVar1 != (uint *)0x0) {
      puVar3 = (undefined4 *)*puVar1;
      *(undefined4 *)(param_1 + 0xf34) = *puVar3;
      return (uint)puVar3 & 0xffffff00;
    }
    *(undefined4 *)(param_1 + 0xf34) = uRam00000000;
    return 0;
  }
  *(undefined4 *)(param_1 + 0xf30) = 0;
  *(undefined4 *)(param_1 + 0xf34) = 0;
  return *(uint *)(param_1 + 0x720) & 0xffffff00;
}


