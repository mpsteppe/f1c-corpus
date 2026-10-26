// Function: FUN_0042ecc0 @ 0042ecc0
// Size (bytes): 63


void __thiscall FUN_0042ecc0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_0042de10(param_2);
  *(undefined4 *)(param_1 + 0x1640) = *(undefined4 *)(param_1 + 0x1978);
  puVar1 = (undefined4 *)(param_1 + 0x1680);
  iVar2 = 8;
  do {
    *puVar1 = *(undefined4 *)(param_1 + 0x1970);
    puVar1 = puVar1 + 0x10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


