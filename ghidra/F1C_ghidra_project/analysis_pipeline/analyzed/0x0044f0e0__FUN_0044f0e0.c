// Function: FUN_0044f0e0 @ 0044f0e0
// Size (bytes): 106


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0044f0e0(int param_1,uint param_2,float param_3)

{
  uint uVar1;
  ushort *puVar2;
  
  *(undefined1 *)(param_2 + 0x37c + param_1) = 0;
  uVar1 = 0;
  puVar2 = (ushort *)(param_1 + 0xc88);
  do {
    if (*puVar2 == param_2) {
      *(undefined2 *)(param_1 + 0xc88 + uVar1 * 2) = 0;
      break;
    }
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar1 < 0x100);
  if (param_3 <= DAT_0059e440) {
    *(undefined4 *)(param_1 + 0x87c + param_2 * 4) = 0;
    return;
  }
  *(float *)(param_1 + 0x87c + param_2 * 4) = (float)_DAT_008afea8 + param_3;
  return;
}


