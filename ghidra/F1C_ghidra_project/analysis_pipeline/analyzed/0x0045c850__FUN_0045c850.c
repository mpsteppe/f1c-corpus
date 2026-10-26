// Function: FUN_0045c850 @ 0045c850
// Size (bytes): 82


void __thiscall FUN_0045c850(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(param_1 + 0x14 + param_2 * 4) = 0;
  *(undefined4 *)(param_1 + 0x1b4 + param_2 * 4) = 0;
  *(undefined1 *)(param_2 + 0x354 + param_1) = 0;
  *(undefined1 *)(param_2 + 0x3bc + param_1) = 0;
  puVar2 = (undefined4 *)(param_2 * 0x20 + 0x424 + param_1);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)(param_1 + 0x12c4 + param_2 * 2) = 0;
  *(undefined4 *)(param_1 + 0x1124 + param_2 * 4) = 0xbf800000;
  return;
}


