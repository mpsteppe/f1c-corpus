// Function: FUN_0057c950 @ 0057c950
// Size (bytes): 183


undefined1 __thiscall FUN_0057c950(int param_1,undefined4 *param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  DWORD DVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 uVar5;
  
  uVar5 = 0;
  if (param_4 == (int *)0x0) {
    *(undefined2 *)((int)param_2 + 2) = *(undefined2 *)(param_1 + 0x910);
    param_2[1] = 0xffffffff;
    return 1;
  }
  puVar3 = (undefined4 *)(param_1 + 0xac8);
  if ((*(HANDLE *)(param_1 + 0xad8) == (HANDLE)0x0) ||
     ((DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xad8),*(DWORD *)(param_1 + 0xadc)),
      DVar2 != 0 && (DVar2 != 0x80)))) {
    puVar3 = (undefined4 *)0x0;
  }
  iVar4 = *param_4;
  if ((-1 < iVar4) && (iVar4 < (int)puVar3[3])) {
    piVar1 = (int *)*puVar3;
    for (; 0 < iVar4; iVar4 = iVar4 + -1) {
      if (piVar1 == (int *)0x0) goto LAB_0057c9f1;
      piVar1 = (int *)piVar1[1];
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
      puVar3 = (undefined4 *)FUN_004b3db0();
      uVar5 = 1;
      *param_2 = *puVar3;
      param_2[1] = puVar3[1];
      param_2[2] = puVar3[2];
      param_2[3] = puVar3[3];
    }
  }
LAB_0057c9f1:
  if (*(HANDLE *)(param_1 + 0xad8) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xad8));
  }
  return uVar5;
}


