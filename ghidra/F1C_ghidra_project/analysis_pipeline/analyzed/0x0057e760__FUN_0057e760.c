// Function: FUN_0057e760 @ 0057e760
// Size (bytes): 128


void __fastcall FUN_0057e760(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  DWORD DVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(param_1 + 0xb00);
  if ((*(HANDLE *)(param_1 + 0xb10) == (HANDLE)0x0) ||
     ((DVar3 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xb10),*(DWORD *)(param_1 + 0xb14)),
      DVar3 != 0 && (DVar3 != 0x80)))) {
    puVar4 = (undefined4 *)0x0;
  }
  puVar4[2] = (undefined4 *)*puVar4;
  puVar2 = (undefined4 *)*puVar4;
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[1];
    if (*(char *)(puVar2 + 2) != '\0') {
      FUN_00587bcf(*puVar2);
    }
    FUN_00587bcf(puVar2);
    puVar2 = puVar1;
  }
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  puVar4[3] = 0;
  if (*(HANDLE *)(param_1 + 0xb10) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xb10));
  }
  return;
}


