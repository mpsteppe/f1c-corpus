// Function: FUN_0057d8d0 @ 0057d8d0
// Size (bytes): 680


undefined1 __thiscall FUN_0057d8d0(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  char cVar4;
  DWORD DVar5;
  SOCKET *pSVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int *piVar10;
  ushort *puVar11;
  int iVar12;
  undefined1 local_632;
  short sStack_622;
  short sStack_612;
  ushort local_604;
  ushort uStack_602;
  
  local_632 = 1;
  FUN_0057d5d0(param_2,&local_604);
  iVar1 = uStack_602 + 4 + (uint)local_604;
  if (param_3 != (undefined4 *)0x0) {
    piVar10 = (int *)(param_1 + 0xaac);
    if ((*(HANDLE *)(param_1 + 0xabc) == (HANDLE)0x0) ||
       ((DVar5 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xabc),*(DWORD *)(param_1 + 0xac0)),
        DVar5 != 0 && (DVar5 != 0x80)))) {
      piVar10 = (int *)0x0;
    }
    piVar2 = (int *)*piVar10;
    piVar10[2] = (int)piVar2;
    if ((piVar2 != (int *)0x0) && (iVar7 = *piVar2, iVar7 != 0)) {
      while (((*(int *)(iVar7 + 4) != param_3[1] ||
              (sStack_622 = (short)((uint)*param_3 >> 0x10), *(short *)(iVar7 + 2) != sStack_622))
             && (cVar4 = FUN_0057db80(*param_3,param_3[1],param_3[2],param_3[3]), cVar4 == '\0'))) {
        if (piVar10[2] == 0) goto LAB_0057d9cd;
        piVar2 = *(int **)(piVar10[2] + 4);
        piVar10[2] = (int)piVar2;
        if ((piVar2 == (int *)0x0) || (iVar7 = *piVar2, iVar7 == 0)) goto LAB_0057d9cd;
      }
      iVar12 = 0;
      puVar11 = &local_604;
      iVar7 = iVar1;
      pSVar6 = (SOCKET *)FUN_0057b6b0();
      iVar7 = send(*pSVar6,(char *)puVar11,iVar7,iVar12);
      if (iVar7 != iVar1) {
        local_632 = 0;
      }
    }
LAB_0057d9cd:
    if (*(HANDLE *)(param_1 + 0xabc) == (HANDLE)0x0) {
      return local_632;
    }
    ReleaseMutex(*(HANDLE *)(param_1 + 0xabc));
    return local_632;
  }
  piVar10 = (int *)(param_1 + 0xaac);
  if ((*(HANDLE *)(param_1 + 0xabc) == (HANDLE)0x0) ||
     ((DVar5 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xabc),*(DWORD *)(param_1 + 0xac0)),
      DVar5 != 0 && (DVar5 != 0x80)))) {
    piVar10 = (int *)0x0;
  }
  piVar2 = (int *)*piVar10;
  piVar10[2] = (int)piVar2;
  if ((piVar2 != (int *)0x0) && (iVar7 = *piVar2, iVar7 != 0)) {
    do {
      iVar12 = 0;
      bVar3 = false;
      piVar2 = *(int **)(param_2 + 0x48);
      puVar8 = (undefined4 *)FUN_0057b0d0(0);
      if (puVar8 == (undefined4 *)0x0) {
LAB_0057daf0:
        iVar7 = FUN_0057b2e0();
        if (iVar7 != 0) {
          iVar7 = *piVar2;
          uVar9 = FUN_005871f0();
          cVar4 = (**(code **)(iVar7 + 0x10))(uVar9);
          if (cVar4 != '\0') goto LAB_0057db0f;
        }
      }
      else {
        do {
          if (((*(int *)(iVar7 + 4) == puVar8[1]) &&
              (sStack_622 = (short)((uint)*puVar8 >> 0x10), *(short *)(iVar7 + 2) == sStack_622)) ||
             ((*(int *)(iVar7 + 0x14) == puVar8[1] &&
              (sStack_612 = (short)((uint)*puVar8 >> 0x10), *(short *)(iVar7 + 0x12) == sStack_612))
             )) {
            bVar3 = true;
          }
          iVar12 = iVar12 + 1;
          puVar8 = (undefined4 *)FUN_0057b0d0(iVar12);
        } while (puVar8 != (undefined4 *)0x0);
        if (!bVar3) goto LAB_0057daf0;
LAB_0057db0f:
        iVar12 = 0;
        puVar11 = &local_604;
        iVar7 = iVar1;
        pSVar6 = (SOCKET *)FUN_0057b6b0();
        send(*pSVar6,(char *)puVar11,iVar7,iVar12);
      }
      if (piVar10[2] == 0) break;
      piVar2 = *(int **)(piVar10[2] + 4);
      piVar10[2] = (int)piVar2;
      if ((piVar2 == (int *)0x0) || (iVar7 = *piVar2, iVar7 == 0)) break;
    } while( true );
  }
  if (*(HANDLE *)(param_1 + 0xabc) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xabc));
  }
  return 1;
}


