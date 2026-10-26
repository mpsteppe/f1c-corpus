// Function: FUN_0057dc10 @ 0057dc10
// Strings:  [Duplicate connection]


uint __thiscall FUN_0057dc10(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  DWORD DVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  float10 fVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  short sStack_1e;
  short sStack_e;
  
  fVar7 = (float10)FUN_00584f90();
  uVar9 = 1;
  *(float *)(param_2 + 0x30) = (float)fVar7;
  *(float *)(param_2 + 0x2c) = (float)fVar7;
  puVar2 = (undefined4 *)FUN_0057b6b0(1);
  FUN_0057c860(*puVar2,uVar9);
  piVar6 = (int *)(param_1 + 0xaac);
  if ((*(HANDLE *)(param_1 + 0xabc) == (HANDLE)0x0) ||
     ((DVar3 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xabc),*(DWORD *)(param_1 + 0xac0)),
      DVar3 != 0 && (DVar3 != 0x80)))) {
    piVar6 = (int *)0x0;
  }
  while( true ) {
    piVar1 = (int *)*piVar6;
    piVar6[2] = (int)piVar1;
    if ((piVar1 == (int *)0x0) || (*piVar1 == 0)) break;
    uVar8 = FUN_0057b6a0();
    iVar5 = (int)((ulonglong)uVar8 >> 0x20);
    puVar2 = (undefined4 *)uVar8;
    while (((*(int *)(iVar5 + 4) != puVar2[1] ||
            (sStack_1e = (short)((uint)*puVar2 >> 0x10), *(short *)(iVar5 + 2) != sStack_1e)) &&
           ((*(int *)(iVar5 + 0x14) != puVar2[1] ||
            (sStack_e = (short)((uint)*puVar2 >> 0x10), *(short *)(iVar5 + 0x12) != sStack_e))))) {
      if (piVar6[2] == 0) goto LAB_0057dcfc;
      piVar1 = *(int **)(piVar6[2] + 4);
      piVar6[2] = (int)piVar1;
      if ((piVar1 == (int *)0x0) || (iVar5 = *piVar1, iVar5 == 0)) goto LAB_0057dcfc;
    }
    FUN_0057de30(iVar5,s_Duplicate_connection_005e62c8);
  }
LAB_0057dcfc:
  FUN_00586000(param_2,0);
  uVar4 = 0;
  if (*(HANDLE *)(param_1 + 0xabc) != (HANDLE)0x0) {
    uVar4 = ReleaseMutex(*(HANDLE *)(param_1 + 0xabc));
  }
  return uVar4 & 0xffffff00;
}


