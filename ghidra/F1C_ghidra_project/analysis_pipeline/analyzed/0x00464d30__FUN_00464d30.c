// Function: FUN_00464d30 @ 00464d30
// Size (bytes): 343


void __thiscall FUN_00464d30(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int extraout_EDX;
  
  *param_1 = param_2;
  FUN_00568c60();
  param_1[0x19] = 0x3f800000;
  param_1[0x1a] = 0;
  param_1[0x18] = 0;
  puVar2 = (undefined4 *)param_1[0x1b];
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[1];
    if (*(char *)(puVar2 + 2) != '\0') {
      FUN_00587bcf(*puVar2);
    }
    FUN_00587bcf(puVar2);
    puVar2 = puVar1;
  }
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  puVar2 = (undefined4 *)param_1[0x1f];
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[1];
    if (*(char *)(puVar2 + 2) != '\0') {
      FUN_00587bcf(*puVar2);
    }
    FUN_00587bcf(puVar2);
    puVar2 = puVar1;
  }
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  do {
    FUN_00464a40();
  } while (extraout_EDX != 1);
  param_1[0x3903] = 0;
  puVar2 = (undefined4 *)param_1[0x396c];
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[1];
    if (*(char *)(puVar2 + 2) != '\0') {
      FUN_00587bcf(*puVar2);
    }
    FUN_00587bcf(puVar2);
    puVar2 = puVar1;
  }
  param_1[0x396c] = 0;
  param_1[0x396d] = 0;
  param_1[0x396e] = 0;
  param_1[0x396f] = 0;
  puVar2 = (undefined4 *)param_1[0x3970];
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[1];
    if (*(char *)(puVar2 + 2) != '\0') {
      FUN_00587bcf(*puVar2);
    }
    FUN_00587bcf(puVar2);
    puVar2 = puVar1;
  }
  param_1[0x3970] = 0;
  param_1[0x3971] = 0;
  param_1[0x3972] = 0;
  param_1[0x3973] = 0;
  return;
}


