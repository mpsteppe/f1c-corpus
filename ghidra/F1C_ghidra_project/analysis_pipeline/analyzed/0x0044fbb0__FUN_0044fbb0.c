// Function: FUN_0044fbb0 @ 0044fbb0
// Size (bytes): 34


void __thiscall FUN_0044fbb0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)(param_1 + 0x2f4) = param_2;
  puVar2 = (undefined4 *)&stack0x00000008;
  puVar3 = (undefined4 *)(param_1 + 0x84);
  for (iVar1 = 0x91; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


