// Function: FUN_00584230 @ 00584230
// Strings:  [Ping Request from %s, Added Node, Added Node, Unknown Address, Unknown Address, Unknown Address, --FAILED, Unknown Node]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_00584230(int *param_1,int param_2)

{
  byte bVar1;
  void **ppvVar2;
  char cVar3;
  char extraout_var;
  byte *pbVar4;
  DWORD DVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  int *unaff_EBX;
  byte *pbVar10;
  int unaff_ESI;
  char *pcVar11;
  bool bVar12;
  float10 fVar13;
  undefined4 uStack_6d8;
  uint local_6d4;
  uint local_6d0;
  int local_6c4;
  undefined1 local_6bd;
  char local_6bc [8];
  byte local_6b4 [16];
  undefined1 local_6a4;
  undefined4 local_674;
  undefined4 local_670;
  undefined4 local_66c;
  uint local_668;
  undefined1 uStack_578;
  uint local_518;
  undefined4 local_514;
  undefined4 local_510;
  undefined1 local_50c;
  undefined3 local_50b;
  undefined1 uStack_414;
  undefined1 uStack_410;
  undefined1 local_40c;
  undefined1 uStack_28;
  undefined4 uStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059d0d3;
  local_c = ExceptionList;
  local_6bd = 1;
  local_6d0 = 0;
  local_6d4 = 0;
  uVar9 = (uint)*(ushort *)(*(int *)(param_2 + 0x1c) + *(int *)(param_2 + 0x38) * 4 + 2);
  ExceptionList = &local_c;
  ppvVar2 = &local_c;
  if (uVar9 != 0) {
    do {
      FUN_00585e80();
      if ((*(byte *)(local_6c4 + *(int *)(param_2 + 0x14)) & uStack_6d8._3_1_) != 0) {
        local_6d0 = local_6d0 | 1 << ((byte)local_6d4 & 0x1f);
      }
      local_6d4 = local_6d4 + 1;
      ppvVar2 = ExceptionList;
    } while (local_6d4 < uVar9);
  }
  ExceptionList = ppvVar2;
  switch(local_6d0 - 1) {
  case 0:
    cVar3 = (**(code **)(*param_1 + 0x40))();
    if ((cVar3 != '\0') && (cVar3 = FUN_00585220(), cVar3 != '\0')) {
      iVar7 = FUN_00586a90();
      cVar3 = FUN_0057a0c0();
      if (cVar3 != '\0') {
        uStack_6d8 = (int *)((uint)uStack_6d8 & 0xffffff);
        cVar3 = (**(code **)(*param_1 + 0x78))();
        if (cVar3 != '\0') {
          (**(code **)(*param_1 + 0xc4))();
          uStack_6d8[1] = *(int *)(iVar7 + 0x30);
          (**(code **)(*param_1 + 0x58))();
          FUN_00586800();
          (**(code **)(*uStack_6d8 + 0xc))();
          uStack_410 = 0;
          puStack_8 = (undefined1 *)0x0;
          (**(code **)(*uStack_6d8 + 0x10))();
          FUN_00586a00();
          (**(code **)*param_1)();
          (**(code **)(*param_1 + 0x7c))();
          (**(code **)(*param_1 + 0x5c))();
          uStack_28 = 1;
          cVar3 = (**(code **)(*param_1 + 4))();
          if (cVar3 == '\0') {
            pcVar6 = s_Unknown_Node_005e638c;
            do {
              cVar3 = *pcVar6;
              (&stack0xffa19594)[(int)pcVar6] = cVar3;
              pcVar6 = pcVar6 + 1;
            } while (cVar3 != '\0');
          }
          if (extraout_var == '\0') {
            iVar7 = -1;
            pcVar6 = &stack0xfffff920;
            do {
              pcVar11 = pcVar6;
              if (iVar7 == 0) break;
              iVar7 = iVar7 + -1;
              pcVar11 = pcVar6 + 1;
              cVar3 = *pcVar6;
              pcVar6 = pcVar11;
            } while (cVar3 != '\0');
            *(undefined4 *)(pcVar11 + -1) = s___FAILED_005e6380._0_4_;
            *(undefined4 *)(pcVar11 + 3) = s___FAILED_005e6380._4_4_;
            pcVar11[7] = s___FAILED_005e6380[8];
          }
          piVar8 = (int *)FUN_00585cc0();
          (**(code **)(*piVar8 + 0x1c))();
          FUN_004b0170();
        }
      }
    }
    break;
  case 1:
    (**(code **)(*param_1 + 0x84))();
    (**(code **)(*param_1 + 0x78))();
    FUN_00586a80();
    uStack_414 = 0;
    local_c = (void *)0x2;
    FUN_00586a10();
    (**(code **)(*unaff_EBX + 0x14))();
    fVar13 = (float10)FUN_00584f90();
    *(float *)(unaff_ESI + 4) =
         (float)((fVar13 - (float10)*(float *)(unaff_ESI + 4)) * (float10)_DAT_0059e450);
    pcVar6 = s_Unknown_Address_005e6370;
    uStack_14 = CONCAT31(uStack_14._1_3_,3);
    do {
      cVar3 = *pcVar6;
      pcVar6[(int)&stack0xffa195cc] = cVar3;
      pcVar6 = pcVar6 + 1;
    } while (cVar3 != '\0');
    (**(code **)(*param_1 + 4))();
    piVar8 = (int *)FUN_00585cc0();
    (**(code **)(*piVar8 + 0xc))();
    FUN_004b0170();
    (**(code **)(*param_1 + 0x34))();
    break;
  case 2:
    cVar3 = FUN_00585220();
    if (cVar3 == '\0') {
LAB_00584580:
      (**(code **)(*param_1 + 0x58))();
      FUN_00586800();
      FUN_00586a00();
      (**(code **)*param_1)();
    }
    else {
      pbVar4 = (byte *)FUN_00585020();
      iVar7 = -1;
      pbVar10 = pbVar4;
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar1 = *pbVar10;
        pbVar10 = pbVar10 + 1;
      } while (bVar1 != 0);
      if (iVar7 != -2) {
        _strncpy((char *)local_6b4,&DAT_005ea438,0x10);
        local_6a4 = 0;
        FUN_00586a10();
        pbVar10 = local_6b4;
        do {
          bVar1 = *pbVar4;
          bVar12 = bVar1 < *pbVar10;
          if (bVar1 != *pbVar10) {
LAB_00584631:
            iVar7 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
            goto LAB_00584636;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar12 = bVar1 < pbVar10[1];
          if (bVar1 != pbVar10[1]) goto LAB_00584631;
          pbVar4 = pbVar4 + 2;
          pbVar10 = pbVar10 + 2;
        } while (bVar1 != 0);
        iVar7 = 0;
LAB_00584636:
        if (iVar7 != 0) goto LAB_00584580;
      }
      iVar7 = (**(code **)(*param_1 + 0x58))();
      FUN_00586800();
      (**(code **)(*param_1 + 0x90))();
      FUN_00585870();
      (**(code **)(*param_1 + 0x8c))();
      FUN_00586a00();
      (**(code **)(**(int **)(iVar7 + 0x48) + 0xc))();
      FUN_00585380();
    }
    break;
  case 3:
    iVar7 = FUN_00586a10();
    if (iVar7 == 0) {
      FUN_005857c0();
      (**(code **)(*param_1 + 0x98))();
    }
    local_6b4[0] = 0;
    pcVar6 = s_Added_Node_005e6364;
    local_4 = 4;
    do {
      cVar3 = *pcVar6;
      (&stack0xffa195e8)[(int)pcVar6] = cVar3;
      pcVar6 = pcVar6 + 1;
    } while (cVar3 != '\0');
    cVar3 = (**(code **)(*param_1 + 4))();
    if (cVar3 == '\0') {
      pcVar6 = s_Unknown_Node_005e638c;
      do {
        cVar3 = *pcVar6;
        (&stack0xffa195b8)[(int)pcVar6] = cVar3;
        pcVar6 = pcVar6 + 1;
      } while (cVar3 != '\0');
    }
    piVar8 = (int *)FUN_00585cc0();
    (**(code **)(*piVar8 + 0x10))();
    FUN_004b0170();
    FUN_00585cd0();
    break;
  case 4:
    FUN_00585cd0();
    iVar7 = FUN_00586a10();
    local_6d0 = (uint)(iVar7 != 0);
    DVar5 = WaitForSingleObject((HANDLE)param_1[0x186],5);
    if ((DVar5 != 0x102) && (DVar5 != 0xffffffff)) {
      param_1[0x171] = local_6d0;
    }
    if ((HANDLE)param_1[0x186] != (HANDLE)0x0) {
      ReleaseMutex((HANDLE)param_1[0x186]);
    }
    local_6b4[0] = 0;
    pcVar6 = &DAT_005e6360;
    local_4 = 5;
    do {
      cVar3 = *pcVar6;
      (&stack0xffa195ec)[(int)pcVar6] = cVar3;
      pcVar6 = pcVar6 + 1;
    } while (cVar3 != '\0');
    cVar3 = (**(code **)(*param_1 + 4))();
    if (cVar3 == '\0') {
      pcVar6 = s_Unknown_Node_005e638c;
      do {
        cVar3 = *pcVar6;
        (&stack0xffa195b8)[(int)pcVar6] = cVar3;
        pcVar6 = pcVar6 + 1;
      } while (cVar3 != '\0');
    }
    piVar8 = (int *)FUN_00585cc0();
    (**(code **)(*piVar8 + 0x10))();
    FUN_004b0170();
    break;
  case 5:
    break;
  case 6:
    cVar3 = (**(code **)(*param_1 + 8))();
    if (cVar3 != '\0') {
      (**(code **)(*param_1 + 0x94))();
    }
    break;
  case 7:
    local_40c = 0;
    local_4 = 6;
    do {
      iVar7 = FUN_00586a10();
      if (iVar7 == 0) {
        FUN_00585d20();
        (**(code **)(*param_1 + 0xb0))();
        ExceptionList = local_c;
        return 1;
      }
    } while (iVar7 == 4);
    break;
  case 8:
    iVar7 = FUN_00586a10();
    if (iVar7 == 0) {
      (**(code **)(*param_1 + 0x94))();
    }
    break;
  case 9:
    cVar3 = (**(code **)(*param_1 + 0x78))();
    if (cVar3 != '\0') {
      FUN_00586a90();
      (**(code **)(iRam00000000 + 0x14))();
      (**(code **)(*param_1 + 0xc0))();
      piVar8 = (int *)FUN_00585cc0();
      (**(code **)(*piVar8 + 0x28))();
      FUN_004b0170();
      (**(code **)(*param_1 + 0x7c))();
    }
    break;
  case 10:
    (**(code **)(*param_1 + 0x58))();
    FUN_00586800();
    FUN_00586a10();
    FUN_00586a00();
    (**(code **)*param_1)();
    (**(code **)(*param_1 + 0x5c))();
    uStack_578 = 0;
    uStack_14 = 8;
    (**(code **)(*param_1 + 4))();
    FUN_0058815f();
    piVar8 = (int *)FUN_00585cc0();
    (**(code **)(*piVar8 + 0x18))();
    FUN_004b0170();
    break;
  case 0xb:
    FUN_00586a10();
    FUN_00584f90();
    iVar7 = *param_1;
    __ftol();
    (**(code **)(iVar7 + 0x14))();
    break;
  case 0xc:
    FUN_00586a80();
    FUN_00586a90();
    FUN_00587930();
    break;
  case 0xd:
    FUN_00586a10();
    local_514 = 0x20000000;
    local_510 = 0xc7d2ced3;
    local_50c = 0xff;
    local_518 = uVar9;
    piVar8 = (int *)FUN_00585cc0();
    cVar3 = (**(code **)(*piVar8 + 8))();
    FUN_004b0170();
    if (cVar3 != '\0') {
      _local_50c = CONCAT31(local_50b,(undefined1)local_6c4);
      (**(code **)(*param_1 + 0x58))();
      FUN_00586800();
      FUN_00586a00();
      (**(code **)*param_1)();
      (**(code **)(*param_1 + 0x5c))();
    }
    break;
  case 0xe:
    local_674 = 0xffffffff;
    local_670 = 0x20000000;
    local_66c = 0xc7d2ced3;
    local_668 = local_668 & 0xffffff00;
    FUN_00586a10();
    FUN_00584f90();
    FUN_00583700();
    break;
  default:
    local_6bd = 0;
  }
  ExceptionList = local_c;
  return local_6bd;
}


