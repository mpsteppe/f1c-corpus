// Function: FUN_0057e6e0 @ 0057e6e0
// Size (bytes): 127


void __fastcall FUN_0057e6e0(int param_1)

{
  int *piVar1;
  int *piVar2;
  DWORD DVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(param_1 + 0xac8);
  if ((*(HANDLE *)(param_1 + 0xad8) == (HANDLE)0x0) ||
     ((DVar3 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xad8),*(DWORD *)(param_1 + 0xadc)),
      DVar3 != 0 && (DVar3 != 0x80)))) {
    puVar4 = (undefined4 *)0x0;
  }
  piVar2 = (int *)*puVar4;
  while (piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[1];
    if (((char)piVar2[2] != '\0') && ((undefined4 *)*piVar2 != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    FUN_00587bcf(piVar2);
    piVar2 = piVar1;
  }
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  puVar4[3] = 0;
  if (*(HANDLE *)(param_1 + 0xad8) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xad8));
  }
  return;
}


