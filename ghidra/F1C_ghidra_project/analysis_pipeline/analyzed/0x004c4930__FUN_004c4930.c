// Function: FUN_004c4930 @ 004c4930
// Size (bytes): 87


void __fastcall FUN_004c4930(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  FUN_004c4cf0();
  puVar2 = (undefined4 *)param_1[2];
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[1];
    if (*(char *)(puVar2 + 2) != '\0') {
      FUN_00587bcf(*puVar2);
    }
    FUN_00587bcf(puVar2);
    puVar2 = puVar1;
  }
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (*param_1 != 0) {
    FUN_00587bcf(*param_1);
  }
  return;
}


