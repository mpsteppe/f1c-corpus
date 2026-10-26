// Function: FUN_0057dff0 @ 0057dff0
// Size (bytes): 171


uint __thiscall
FUN_0057dff0(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int *piVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = 0;
  piVar5 = (int *)(param_1 + 0xaac);
  if ((*(HANDLE *)(param_1 + 0xabc) == (HANDLE)0x0) ||
     ((DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xabc),*(DWORD *)(param_1 + 0xac0)),
      DVar2 != 0 && (DVar2 != 0x80)))) {
    piVar5 = (int *)0x0;
  }
  piVar1 = (int *)*piVar5;
  piVar5[2] = (int)piVar1;
  iVar7 = iVar6;
  if ((piVar1 != (int *)0x0) && (iVar3 = *piVar1, iVar3 != 0)) {
    while (((iVar7 = iVar3, *(int *)(iVar3 + 4) != param_3 ||
            (*(short *)(iVar3 + 2) != param_2._2_2_)) &&
           (((*(int *)(iVar3 + 0x14) != param_3 || (*(short *)(iVar3 + 0x12) != param_2._2_2_)) &&
            (iVar7 = iVar6, piVar5[2] != 0))))) {
      piVar1 = *(int **)(piVar5[2] + 4);
      piVar5[2] = (int)piVar1;
      if ((piVar1 == (int *)0x0) || (iVar3 = *piVar1, iVar3 == 0)) break;
    }
  }
  uVar4 = 0;
  if (*(HANDLE *)(param_1 + 0xabc) != (HANDLE)0x0) {
    uVar4 = ReleaseMutex(*(HANDLE *)(param_1 + 0xabc));
  }
  if (iVar7 == 0) {
    return uVar4 & 0xffffff00;
  }
  uVar4 = FUN_0057de30(iVar7,param_6);
  return uVar4;
}


