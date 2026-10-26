// Function: FUN_004bf640 @ 004bf640
// Size (bytes): 85


void __fastcall FUN_004bf640(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  FUN_004bf730();
  puVar2 = (undefined4 *)*param_1;
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[1];
    if (*(char *)(puVar2 + 2) != '\0') {
      FUN_00587bcf(*puVar2);
    }
    FUN_00587bcf(puVar2);
    puVar2 = puVar1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


