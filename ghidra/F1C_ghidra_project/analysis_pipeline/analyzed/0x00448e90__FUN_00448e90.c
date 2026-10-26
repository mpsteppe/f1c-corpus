// Function: FUN_00448e90 @ 00448e90
// Size (bytes): 34


undefined4 * __fastcall FUN_00448e90(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[7] = 0;
  *(undefined1 *)((int)param_1 + 0x19) = 0;
  *(undefined2 *)((int)param_1 + 0x1a) = 0xffff;
  *(undefined1 *)(param_1 + 6) = 1;
  return param_1;
}


