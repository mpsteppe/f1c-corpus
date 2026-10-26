// Function: FUN_0055fbc0 @ 0055fbc0
// Size (bytes): 24


void FUN_0055fbc0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_008b8f04;
  for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


