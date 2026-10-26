// Function: FUN_0057e3a0 @ 0057e3a0
// Size (bytes): 110


void __fastcall FUN_0057e3a0(int param_1)

{
  int *piVar1;
  DWORD DVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0xac8);
  if ((*(HANDLE *)(param_1 + 0xad8) == (HANDLE)0x0) ||
     ((DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xad8),*(DWORD *)(param_1 + 0xadc)),
      DVar2 != 0 && (DVar2 != 0x80)))) {
    piVar3 = (int *)0x0;
  }
  piVar1 = (int *)*piVar3;
  piVar3[2] = (int)piVar1;
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    while( true ) {
      FUN_00587230(0);
      if (piVar3[2] == 0) break;
      piVar1 = *(int **)(piVar3[2] + 4);
      piVar3[2] = (int)piVar1;
      if ((piVar1 == (int *)0x0) || (*piVar1 == 0)) break;
    }
  }
  if (*(HANDLE *)(param_1 + 0xad8) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xad8));
  }
  return;
}


