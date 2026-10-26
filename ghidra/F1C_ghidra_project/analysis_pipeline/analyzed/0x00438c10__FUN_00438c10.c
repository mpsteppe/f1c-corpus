// Function: FUN_00438c10 @ 00438c10
// Size (bytes): 143


undefined4 * __fastcall FUN_00438c10(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_004353f0();
  FUN_0042e1c0();
  FUN_0056d3e0();
  FUN_004363d0();
  FUN_004363d0();
  puVar1 = param_1;
  for (iVar2 = 0x7ce; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  iVar2 = 4;
  puVar1 = param_1 + 0x176;
  do {
    *puVar1 = 0x8f5c28f6;
    puVar1[1] = 0x40767dc2;
    puVar1[2] = *puVar1;
    puVar1[3] = puVar1[1];
    puVar1[4] = puVar1[2];
    iVar2 = iVar2 + -1;
    puVar1[5] = puVar1[3];
    puVar1 = puVar1 + 0x119;
  } while (iVar2 != 0);
  FUN_0043e230();
  return param_1;
}


