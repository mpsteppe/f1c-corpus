// Function: FUN_0057dd40 @ 0057dd40
// Size (bytes): 232


undefined1 __thiscall FUN_0057dd40(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int *piVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 extraout_ECX;
  int *piVar4;
  int extraout_EDX;
  undefined1 uVar5;
  short sStack_1e;
  short sStack_e;
  
  piVar4 = (int *)(param_1 + 0xaac);
  uVar5 = 0;
  if ((*(HANDLE *)(param_1 + 0xabc) == (HANDLE)0x0) ||
     ((DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xabc),*(DWORD *)(param_1 + 0xac0)),
      DVar2 != 0 && (DVar2 != 0x80)))) {
    piVar4 = (int *)0x0;
  }
  piVar1 = (int *)*piVar4;
  piVar4[2] = (int)piVar1;
  if ((piVar1 != (int *)0x0) && (iVar3 = *piVar1, iVar3 != 0)) {
    while( true ) {
      if (((*(int *)(iVar3 + 4) == param_2[1]) &&
          (sStack_1e = (short)((uint)*param_2 >> 0x10), *(short *)(iVar3 + 2) == sStack_1e)) ||
         ((*(int *)(iVar3 + 0x14) == param_2[1] &&
          (sStack_e = (short)((uint)*param_2 >> 0x10), *(short *)(iVar3 + 0x12) == sStack_e)))) {
        FUN_0057b6c0(param_3);
        *(undefined4 *)(extraout_EDX + 0x1c) = extraout_ECX;
        uVar5 = 1;
        goto LAB_0057ddfd;
      }
      if (piVar4[2] == 0) break;
      piVar1 = *(int **)(piVar4[2] + 4);
      piVar4[2] = (int)piVar1;
      if ((piVar1 == (int *)0x0) || (iVar3 = *piVar1, iVar3 == 0)) break;
    }
    uVar5 = 0;
  }
LAB_0057ddfd:
  if (*(HANDLE *)(param_1 + 0xabc) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xabc));
  }
  return uVar5;
}


