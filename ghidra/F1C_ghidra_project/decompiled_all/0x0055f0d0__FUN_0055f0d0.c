// Function: FUN_0055f0d0 @ 0055f0d0
// Strings:  [Unknown, Unknown, Cyrix MediaGX, Cyrix 6x86, Cyrix MediaGX MMX, Cyrix 6x86MX, CyrixInstead, AMD K6-III MMX]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0055f0d0(undefined4 *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  HANDLE pvVar5;
  DWORD dwPriorityClass;
  int iVar6;
  uint uVar7;
  uint uVar8;
  float10 fVar9;
  DWORD dwPriorityClass_00;
  int local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 local_98 [4];
  undefined1 local_94 [4];
  _MEMORYSTATUS local_90 [3];
  _SYSTEM_INFO local_24;
  
  pcVar4 = (char *)(param_1 + 1);
  pcVar2 = s_Unknown_005c307c;
  *param_1 = 0;
  param_1[0x27] = 0;
  do {
    cVar1 = *pcVar2;
    *(char *)((int)(param_1 + -0x170c1e) + (int)pcVar2) = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  GetSystemInfo(&local_24);
  if ((local_24.dwProcessorType != 0x1e6) && (local_24.dwProcessorType != 0x24a)) goto LAB_0055f981;
  iVar3 = FUN_005567f5(&local_9c,&local_a0,pcVar4);
  if (iVar3 == 0) {
    pcVar4 = s_Non_compatible_CPU_005dc5d0;
    local_a8 = 0;
    *param_1 = 0;
    param_1[9] = 0;
    do {
      cVar1 = *pcVar4;
      *(char *)((int)(param_1 + -0x177173) + (int)pcVar4) = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    goto LAB_0055f981;
  }
  Sleep(0);
  pvVar5 = GetCurrentProcess();
  dwPriorityClass = GetPriorityClass(pvVar5);
  dwPriorityClass_00 = 0x80;
  pvVar5 = GetCurrentProcess();
  SetPriorityClass(pvVar5,dwPriorityClass_00);
  local_a0 = 0;
  local_9c = 0;
  FUN_005567f5(&local_9c,&local_a0,pcVar4);
  FUN_00556220();
  FUN_00556260(1);
  FUN_00556440();
  FUN_0055687b(local_98,local_94);
  do {
    fVar9 = (float10)FUN_00556650();
  } while (fVar9 < (float10)_DAT_0059eb50);
  FUN_0055687b(&local_9c,&local_a0);
  pvVar5 = GetCurrentProcess();
  SetPriorityClass(pvVar5,dwPriorityClass);
  FUN_0053ac70(2,0);
  iVar3 = __ftol();
  FUN_0053ac70(1,0);
  iVar6 = ((iVar3 * 4 + 0x19) / 0x32) * 0x32;
  uVar8 = (((iVar3 * 3 + 100) / 200) * 200) / 3 - iVar3;
  uVar7 = ((int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2) - iVar3;
  if ((int)((uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f)) <
      (int)((uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f))) {
    uVar8 = uVar7;
  }
  local_a8 = iVar3 + uVar8;
  uVar8 = FUN_005567f5(&local_9c,&local_a0,pcVar4);
  uVar7 = uVar8 & 0x3000;
  if (uVar7 != 0) {
    if (uVar7 == 0x1000) {
      if (((uVar8 & 0xf00) == 0x500) || ((uVar8 & 0xf00) == 0x600)) goto LAB_0055f965;
    }
    else if (uVar7 == 0x2000) goto LAB_0055f32e;
    goto switchD_0055f413_caseD_20;
  }
LAB_0055f32e:
  iVar3 = FUN_00588410(pcVar4,s_GenuineIntel_005dc5c0);
  if (iVar3 == 0) {
    if (uVar7 == 0x2000) {
      pcVar2 = s_Dual_005dc5b8;
      do {
        cVar1 = *pcVar2;
        *(char *)((int)(param_1 + -0x17716d) + (int)pcVar2) = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
    }
    else {
      pcVar2 = &DAT_005ea438;
      do {
        cVar1 = *pcVar2;
        *(char *)((int)(param_1 + -0x17a90d) + (int)pcVar2) = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
    }
    uVar7 = uVar8 & 0xf00;
    if (uVar7 == 0x500) {
      uVar8 = uVar8 & 0xf0;
      if (uVar8 == 0x10) {
        iVar3 = -1;
        do {
          pcVar2 = pcVar4;
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          pcVar2 = pcVar4 + 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar2;
        } while (cVar1 != '\0');
        *(undefined4 *)(pcVar2 + -1) = s_Intel_Pentium_005dc538._0_4_;
        *(undefined4 *)(pcVar2 + 3) = s_Intel_Pentium_005dc538._4_4_;
        *(undefined4 *)(pcVar2 + 7) = s_Intel_Pentium_005dc538._8_4_;
        *(undefined2 *)(pcVar2 + 0xb) = s_Intel_Pentium_005dc538._12_2_;
      }
      else if (uVar8 == 0x20) {
        iVar3 = -1;
        do {
          pcVar2 = pcVar4;
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          pcVar2 = pcVar4 + 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar2;
        } while (cVar1 != '\0');
        *(undefined4 *)(pcVar2 + -1) = s_Intel_Pentium_005dc538._0_4_;
        *(undefined4 *)(pcVar2 + 3) = s_Intel_Pentium_005dc538._4_4_;
        *(undefined4 *)(pcVar2 + 7) = s_Intel_Pentium_005dc538._8_4_;
        *(undefined2 *)(pcVar2 + 0xb) = s_Intel_Pentium_005dc538._12_2_;
      }
      else {
        if (uVar8 != 0x40) goto switchD_0055f413_caseD_20;
        iVar3 = -1;
        do {
          pcVar2 = pcVar4;
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          pcVar2 = pcVar4 + 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar2;
        } while (cVar1 != '\0');
        *(undefined4 *)(pcVar2 + -1) = s_Intel_Pentium_MMX_005dc548._0_4_;
        *(undefined4 *)(pcVar2 + 3) = s_Intel_Pentium_MMX_005dc548._4_4_;
        *(undefined4 *)(pcVar2 + 7) = s_Intel_Pentium_MMX_005dc548._8_4_;
        *(undefined4 *)(pcVar2 + 0xb) = s_Intel_Pentium_MMX_005dc548._12_4_;
        *(undefined2 *)(pcVar2 + 0xf) = s_Intel_Pentium_MMX_005dc548._16_2_;
        param_1[0x27] = param_1[0x27] | 1;
      }
      goto LAB_0055f965;
    }
    if (uVar7 != 0x600) {
      if (uVar7 == 0xf00) {
        iVar3 = -1;
        do {
          pcVar2 = pcVar4;
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          pcVar2 = pcVar4 + 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar2;
        } while (cVar1 != '\0');
        *(undefined4 *)(pcVar2 + -1) = s_Intel_Pentium_4_005dc5a8._0_4_;
        *(undefined4 *)(pcVar2 + 3) = s_Intel_Pentium_4_005dc5a8._4_4_;
        *(undefined4 *)(pcVar2 + 7) = s_Intel_Pentium_4_005dc5a8._8_4_;
        *(undefined4 *)(pcVar2 + 0xb) = s_Intel_Pentium_4_005dc5a8._12_4_;
        param_1[0x27] = param_1[0x27] | 3;
        *param_1 = 3;
      }
      goto switchD_0055f413_caseD_20;
    }
    switch(uVar8 & 0xf0) {
    case 0x10:
      iVar3 = -1;
      do {
        pcVar2 = pcVar4;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar2 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar2;
      } while (cVar1 != '\0');
      *(undefined4 *)(pcVar2 + -1) = s_Intel_Pentium_Pro_005dc594._0_4_;
      *(undefined4 *)(pcVar2 + 3) = s_Intel_Pentium_Pro_005dc594._4_4_;
      *(undefined4 *)(pcVar2 + 7) = s_Intel_Pentium_Pro_005dc594._8_4_;
      *(undefined4 *)(pcVar2 + 0xb) = s_Intel_Pentium_Pro_005dc594._12_4_;
      *(undefined2 *)(pcVar2 + 0xf) = s_Intel_Pentium_Pro_005dc594._16_2_;
      goto LAB_0055f965;
    case 0x30:
    case 0x50:
      iVar3 = -1;
      do {
        pcVar2 = pcVar4;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar2 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar2;
      } while (cVar1 != '\0');
      *(undefined4 *)(pcVar2 + -1) = s_Intel_Pentium_II_005dc580._0_4_;
      *(undefined4 *)(pcVar2 + 3) = s_Intel_Pentium_II_005dc580._4_4_;
      *(undefined4 *)(pcVar2 + 7) = s_Intel_Pentium_II_005dc580._8_4_;
      *(undefined4 *)(pcVar2 + 0xb) = s_Intel_Pentium_II_005dc580._12_4_;
      pcVar2[0xf] = s_Intel_Pentium_II_005dc580[0x10];
      goto LAB_0055f4b4;
    case 0x60:
      iVar3 = -1;
      do {
        pcVar2 = pcVar4;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar2 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar2;
      } while (cVar1 != '\0');
      *(undefined4 *)(pcVar2 + -1) = s_Intel_Celeron_005dc570._0_4_;
      *(undefined4 *)(pcVar2 + 3) = s_Intel_Celeron_005dc570._4_4_;
      *(undefined4 *)(pcVar2 + 7) = s_Intel_Celeron_005dc570._8_4_;
      *(undefined2 *)(pcVar2 + 0xb) = s_Intel_Celeron_005dc570._12_2_;
LAB_0055f4b4:
      param_1[0x27] = param_1[0x27] | 1;
      *param_1 = 1;
      break;
    case 0x70:
    case 0x80:
      iVar3 = -1;
      do {
        pcVar2 = pcVar4;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar2 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar2;
      } while (cVar1 != '\0');
      *(undefined4 *)(pcVar2 + -1) = s_Intel_Pentium_III_005dc55c._0_4_;
      *(undefined4 *)(pcVar2 + 3) = s_Intel_Pentium_III_005dc55c._4_4_;
      *(undefined4 *)(pcVar2 + 7) = s_Intel_Pentium_III_005dc55c._8_4_;
      *(undefined4 *)(pcVar2 + 0xb) = s_Intel_Pentium_III_005dc55c._12_4_;
      *(undefined2 *)(pcVar2 + 0xf) = s_Intel_Pentium_III_005dc55c._16_2_;
      param_1[0x27] = param_1[0x27] | 3;
      *param_1 = 2;
      if (local_a8 < 0x191) {
        *param_1 = 1;
      }
    }
    goto switchD_0055f413_caseD_20;
  }
  iVar3 = FUN_00588410(pcVar4,s_AuthenticAMD_005dc528);
  if (iVar3 != 0) {
    iVar3 = FUN_00588410(pcVar4,s_CyrixInstead_005dc4bc);
    if (iVar3 == 0) {
      if (uVar7 == 0x2000) {
        pcVar2 = s_Dual_005dc5b8;
        do {
          cVar1 = *pcVar2;
          *(char *)((int)(param_1 + -0x17716d) + (int)pcVar2) = cVar1;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
      }
      else {
        pcVar2 = &DAT_005ea438;
        do {
          cVar1 = *pcVar2;
          *(char *)((int)(param_1 + -0x17a90d) + (int)pcVar2) = cVar1;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
      }
      uVar7 = uVar8 & 0xf00;
      if (uVar7 == 0x400) {
        if (((byte)uVar8 & 0xf0) != 0x40) goto switchD_0055f413_caseD_20;
        iVar3 = -1;
        do {
          pcVar2 = pcVar4;
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          pcVar2 = pcVar4 + 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar2;
        } while (cVar1 != '\0');
        *(undefined4 *)(pcVar2 + -1) = s_Cyrix_MediaGX_005dc47c._0_4_;
        *(undefined4 *)(pcVar2 + 3) = s_Cyrix_MediaGX_005dc47c._4_4_;
        *(undefined4 *)(pcVar2 + 7) = s_Cyrix_MediaGX_005dc47c._8_4_;
        *(undefined2 *)(pcVar2 + 0xb) = s_Cyrix_MediaGX_005dc47c._12_2_;
      }
      else if (uVar7 == 0x500) {
        iVar3 = -1;
        do {
          pcVar2 = pcVar4;
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          pcVar2 = pcVar4 + 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar2;
        } while (cVar1 != '\0');
        if (((byte)uVar8 & 0xf0) == 0x20) {
          *(undefined4 *)(pcVar2 + -1) = DAT_005dc48c;
          *(undefined4 *)(pcVar2 + 3) = DAT_005dc490;
          *(undefined2 *)(pcVar2 + 7) = DAT_005dc494;
          pcVar2[9] = DAT_005dc496;
        }
        else {
          *(undefined4 *)(pcVar2 + -1) = s_Cyrix_MediaGX_MMX_005dc498._0_4_;
          *(undefined4 *)(pcVar2 + 3) = s_Cyrix_MediaGX_MMX_005dc498._4_4_;
          *(undefined4 *)(pcVar2 + 7) = s_Cyrix_MediaGX_MMX_005dc498._8_4_;
          *(undefined4 *)(pcVar2 + 0xb) = s_Cyrix_MediaGX_MMX_005dc498._12_4_;
          *(undefined2 *)(pcVar2 + 0xf) = s_Cyrix_MediaGX_MMX_005dc498._16_2_;
          param_1[0x27] = param_1[0x27] | 1;
        }
      }
      else {
        if (uVar7 != 0x600) goto switchD_0055f413_caseD_20;
        iVar3 = -1;
        do {
          pcVar2 = pcVar4;
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          pcVar2 = pcVar4 + 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar2;
        } while (cVar1 != '\0');
        *(undefined4 *)(pcVar2 + -1) = DAT_005dc4ac;
        *(undefined4 *)(pcVar2 + 3) = DAT_005dc4b0;
        *(undefined4 *)(pcVar2 + 7) = DAT_005dc4b4;
        pcVar2[0xb] = DAT_005dc4b8;
      }
      goto LAB_0055f965;
    }
    goto switchD_0055f413_caseD_20;
  }
  if (uVar7 == 0x2000) {
    pcVar2 = s_Dual_005dc5b8;
    do {
      cVar1 = *pcVar2;
      *(char *)((int)(param_1 + -0x17716d) + (int)pcVar2) = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
  }
  else {
    pcVar2 = &DAT_005ea438;
    do {
      cVar1 = *pcVar2;
      *(char *)((int)(param_1 + -0x17a90d) + (int)pcVar2) = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
  }
  if ((uVar8 & 0xf00) != 0x500) {
    if ((uVar8 & 0xf00) != 0x600) goto switchD_0055f413_caseD_20;
    switch(uVar8 & 0xf0) {
    case 0x10:
    case 0x20:
    case 0x40:
      iVar3 = -1;
      do {
        pcVar2 = pcVar4;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar2 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar2;
      } while (cVar1 != '\0');
      *(undefined4 *)(pcVar2 + -1) = s_AMD_Athlon_005dc51c._0_4_;
      *(undefined4 *)(pcVar2 + 3) = s_AMD_Athlon_005dc51c._4_4_;
      *(undefined2 *)(pcVar2 + 7) = s_AMD_Athlon_005dc51c._8_2_;
      pcVar2[9] = s_AMD_Athlon_005dc51c[10];
      goto LAB_0055f6bb;
    case 0x30:
    case 0x70:
      iVar3 = -1;
      do {
        pcVar2 = pcVar4;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar2 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar2;
      } while (cVar1 != '\0');
      *(undefined4 *)(pcVar2 + -1) = s_AMD_Duron_005dc510._0_4_;
      *(undefined4 *)(pcVar2 + 3) = s_AMD_Duron_005dc510._4_4_;
      *(undefined2 *)(pcVar2 + 7) = s_AMD_Duron_005dc510._8_2_;
LAB_0055f6bb:
      param_1[0x27] = param_1[0x27] | 5;
      *param_1 = 2;
      break;
    case 0x60:
      iVar3 = -1;
      do {
        pcVar2 = pcVar4;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar2 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar2;
      } while (cVar1 != '\0');
      *(undefined4 *)(pcVar2 + -1) = s_AMD_Athlon_4_005dc500._0_4_;
      *(undefined4 *)(pcVar2 + 3) = s_AMD_Athlon_4_005dc500._4_4_;
      *(undefined4 *)(pcVar2 + 7) = s_AMD_Athlon_4_005dc500._8_4_;
      pcVar2[0xb] = s_AMD_Athlon_4_005dc500[0xc];
      param_1[0x27] = param_1[0x27] | 5;
      *param_1 = 3;
      if (local_a8 < 0x4b1) {
        *param_1 = 2;
      }
    }
    goto switchD_0055f413_caseD_20;
  }
  switch(uVar8 & 0xf0) {
  case 0:
  case 0x10:
  case 0x20:
  case 0x30:
    iVar3 = -1;
    do {
      pcVar2 = pcVar4;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar2 = pcVar4 + 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar2;
    } while (cVar1 != '\0');
    *(undefined4 *)(pcVar2 + -1) = DAT_005dc4f8;
    *(undefined2 *)(pcVar2 + 3) = DAT_005dc4fc;
    pcVar2[5] = DAT_005dc4fe;
    break;
  default:
    goto switchD_0055f413_caseD_20;
  case 0x60:
  case 0x70:
    iVar3 = -1;
    do {
      pcVar2 = pcVar4;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar2 = pcVar4 + 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar2;
    } while (cVar1 != '\0');
    *(undefined4 *)(pcVar2 + -1) = DAT_005dc4ec;
    *(undefined4 *)(pcVar2 + 3) = DAT_005dc4f0;
    *(undefined2 *)(pcVar2 + 7) = DAT_005dc4f4;
    pcVar2[9] = DAT_005dc4f6;
    param_1[0x27] = param_1[0x27] | 1;
    break;
  case 0x80:
    iVar3 = -1;
    do {
      pcVar2 = pcVar4;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar2 = pcVar4 + 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar2;
    } while (cVar1 != '\0');
    *(undefined4 *)(pcVar2 + -1) = DAT_005dc4dc;
    *(undefined4 *)(pcVar2 + 3) = DAT_005dc4e0;
    *(undefined4 *)(pcVar2 + 7) = DAT_005dc4e4;
    pcVar2[0xb] = DAT_005dc4e8;
    param_1[0x27] = param_1[0x27] | 1;
    break;
  case 0x90:
    iVar3 = -1;
    do {
      pcVar2 = pcVar4;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar2 = pcVar4 + 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar2;
    } while (cVar1 != '\0');
    *(undefined4 *)(pcVar2 + -1) = s_AMD_K6_III_MMX_005dc4cc._0_4_;
    *(undefined4 *)(pcVar2 + 3) = s_AMD_K6_III_MMX_005dc4cc._4_4_;
    *(undefined4 *)(pcVar2 + 7) = s_AMD_K6_III_MMX_005dc4cc._8_4_;
    *(undefined2 *)(pcVar2 + 0xb) = s_AMD_K6_III_MMX_005dc4cc._12_2_;
    pcVar2[0xd] = s_AMD_K6_III_MMX_005dc4cc[0xe];
    *param_1 = 1;
    param_1[0x27] = param_1[0x27] | 1;
    goto switchD_0055f413_caseD_20;
  }
LAB_0055f965:
  *param_1 = 0;
switchD_0055f413_caseD_20:
  param_1[9] = 1;
  FUN_00557470();
LAB_0055f981:
  local_90[0].dwLength = 0x20;
  GlobalMemoryStatus(local_90);
  if (0x5db < local_a8) {
    *param_1 = 4;
  }
  param_1[0x23] = local_90[0].dwTotalPhys;
  param_1[0x1f] = local_90[0].dwTotalPhys;
  param_1[0x24] = local_90[0].dwAvailPhys;
  param_1[0x20] = local_90[0].dwAvailPhys;
  param_1[10] = local_a8;
  param_1[0x21] = local_90[0].dwTotalPageFile;
  param_1[0x22] = local_90[0].dwAvailPageFile;
  if ((param_2 != 0) && (iVar3 = FUN_0055bfc0(), 0 < iVar3)) {
    FUN_0055bfd0(0);
    FUN_0055be20(param_1 + 0x15,param_1 + 0x25,param_1 + 0x26);
  }
  return;
}


