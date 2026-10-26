// Function: FUN_0057a3f0 @ 0057a3f0
// Size (bytes): 43


undefined4 * __fastcall FUN_0057a3f0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  *param_1 = 1;
  param_1[1] = 0;
  *(undefined2 *)(param_1 + 2) = 0xd45;
  *(undefined2 *)((int)param_1 + 10) = 0x1d8;
  param_1[3] = 0;
  puVar2 = param_1 + 4;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}


