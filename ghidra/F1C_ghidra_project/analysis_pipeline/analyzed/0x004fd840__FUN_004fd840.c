// Function: FUN_004fd840 @ 004fd840
// Size (bytes): 101


void __fastcall FUN_004fd840(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  *(undefined4 *)(param_1 + 0x38) = 0;
  while (iVar1 != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0xc);
    FUN_00587bcf(*(int *)(param_1 + 0x3c));
    *(int *)(param_1 + 0x3c) = iVar1;
  }
  puVar3 = *(undefined4 **)(param_1 + 0x54);
  while (puVar3 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)puVar3[1];
    if (*(char *)(puVar3 + 2) != '\0') {
      FUN_00587bcf(*puVar3);
    }
    FUN_00587bcf(puVar3);
    puVar3 = puVar2;
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  return;
}


