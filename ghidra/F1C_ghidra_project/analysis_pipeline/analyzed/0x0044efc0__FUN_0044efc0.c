// Function: FUN_0044efc0 @ 0044efc0
// Size (bytes): 31


void __thiscall FUN_0044efc0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)(param_1 + 0x278) = param_2;
  puVar2 = (undefined4 *)&stack0x00000008;
  puVar3 = (undefined4 *)(param_1 + 8);
  for (iVar1 = 0x91; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


