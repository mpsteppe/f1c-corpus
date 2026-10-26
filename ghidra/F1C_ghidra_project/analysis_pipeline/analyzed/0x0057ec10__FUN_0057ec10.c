// Function: FUN_0057ec10 @ 0057ec10
// Size (bytes): 293


undefined1 __thiscall FUN_0057ec10(int param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  undefined1 local_11;
  
  local_11 = 0;
  if ((*(HANDLE *)(param_1 + 0xad8) == (HANDLE)0x0) ||
     ((DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xad8),*(DWORD *)(param_1 + 0xadc)),
      DVar2 != 0 && (DVar2 != 0x80)))) {
    return 0;
  }
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xad4))) {
    piVar1 = *(int **)(param_1 + 0xac8);
    for (; 0 < param_2; param_2 = param_2 + -1) {
      if (piVar1 == (int *)0x0) goto LAB_0057ec76;
      piVar1 = (int *)piVar1[1];
    }
    if (piVar1 != (int *)0x0) {
      iVar3 = *piVar1;
      goto LAB_0057ec7c;
    }
  }
LAB_0057ec76:
  iVar3 = 0;
LAB_0057ec7c:
  iVar4 = -1;
  if (iVar3 != 0) {
    iVar3 = FUN_004b3db0();
    iVar4 = *(int *)(iVar3 + 4);
  }
  if (*(HANDLE *)(param_1 + 0xad8) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xad8));
  }
  if (((iVar4 != -1) && (*(HANDLE *)(param_1 + 0xb10) != (HANDLE)0x0)) &&
     ((DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xb10),*(DWORD *)(param_1 + 0xb14)),
      DVar2 == 0 || (DVar2 == 0x80)))) {
    for (piVar1 = *(int **)(param_1 + 0xb00); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
      if (((int *)*piVar1 != (int *)0x0) && (*(int *)*piVar1 == iVar4)) {
        if (*piVar1 != 0) {
          local_11 = 1;
          *param_3 = *(undefined4 *)(*piVar1 + 4);
        }
        break;
      }
    }
    if (*(HANDLE *)(param_1 + 0xb10) != (HANDLE)0x0) {
      ReleaseMutex(*(HANDLE *)(param_1 + 0xb10));
    }
  }
  return local_11;
}


