// Function: FUN_0054ac70 @ 0054ac70
// Strings:  [Wrong MTS version, CUBE_MTS_4.01, CUBE_MTS_4.01, Error reading mesh file, Error reading mesh file, Error reading scene global matlib, Error reading scene global matlib, Error allocating mesh local matlib]


undefined4 __thiscall
FUN_0054ac70(undefined4 param_1,int param_2,int param_3,int *param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 uVar7;
  char *pcVar8;
  char *pcVar9;
  bool bVar10;
  char local_10 [16];
  
  if (param_5 == 0) {
    iVar1 = FUN_0058ace6(param_2);
    FUN_00587f64(param_2,0,2);
    iVar2 = FUN_0058ace6(param_2);
    param_5 = iVar2 - iVar1;
    FUN_00587f64(param_2,iVar1,0);
    DAT_008b8f34 = (void *)0x0;
    DAT_008b8f30 = operator_new(param_5);
    uVar6 = FUN_0058803f(DAT_008b8f30,1,param_5,param_2);
  }
  else {
    iVar1 = *(int *)(param_5 + 0x124) * 0x100;
    iVar2 = iVar1 + *(int *)(param_5 + 0x128);
    if ((*(byte *)(iVar1 + *(int *)(param_5 + 0x128)) & 0x10) != 0) {
      uVar6 = *(uint *)(iVar2 + 0xc);
      DAT_008b8f30 = operator_new(*(uint *)(iVar2 + 8));
      DAT_008b8f34 = operator_new(uVar6);
      uVar3 = FUN_0058803f(DAT_008b8f34,1,uVar6,param_2);
      if (uVar3 != uVar6) {
        FUN_00587bcf(DAT_008b8f30);
        DAT_008b8f30 = (void *)0x0;
        FUN_00587bcf(DAT_008b8f34);
        DAT_008b8f34 = (void *)0x0;
        return 0xffffffff;
      }
      FUN_0059b260(DAT_008b8f34,uVar6);
      goto LAB_0054ad25;
    }
    param_5 = *(uint *)(iVar2 + 8);
    DAT_008b8f30 = operator_new(param_5);
    uVar6 = FUN_0058803f(DAT_008b8f30,1,param_5,param_2);
  }
  if (uVar6 != param_5) {
    FUN_00587bcf(DAT_008b8f30);
    DAT_008b8f30 = (void *)0x0;
    return 0xffffffff;
  }
LAB_0054ad25:
  DAT_008b8f3c = 0;
  iVar1 = FUN_0054a5b0();
  FUN_0054a5c0(0x10);
  FUN_0054a580(0);
  iVar2 = 0xe;
  bVar10 = true;
  pcVar5 = local_10;
  pcVar8 = s_CUBE_MTS_4_10_005dbfc0;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar10 = *pcVar5 == *pcVar8;
    pcVar5 = pcVar5 + 1;
    pcVar8 = pcVar8 + 1;
  } while (bVar10);
  if (bVar10) {
    FUN_0054a5c0(0x10);
    FUN_0054a5b0();
    pvVar4 = operator_new(0x30);
    if (pvVar4 == (void *)0x0) {
      param_2 = 0;
    }
    else {
      param_2 = FUN_005473d0();
    }
    iVar1 = FUN_00548190(param_1);
    if (iVar1 != 0) {
      if (param_2 != 0) {
        FUN_00557470();
        FUN_00587bcf(param_2);
      }
      FUN_0053c590(0xffffffff,s_Error_allocating_mesh_local_matl_005dbf9c);
      return 0xffffffff;
    }
    FUN_0054a580(0);
    iVar1 = FUN_00548190(param_1);
    if (iVar1 != 0) {
      FUN_0053c590(0xffffffff,s_Error_reading_scene_global_matli_005dbf78);
      return 0xffffffff;
    }
    iVar1 = FUN_0054a5b0();
    uVar3 = param_3 - iVar1;
    pvVar4 = operator_new(uVar3);
    *param_4 = (int)pvVar4;
    FUN_0054c320(0);
    uVar6 = FUN_0054a5c0(uVar3);
    if (uVar6 != uVar3) {
      iVar1 = *param_4;
      if (iVar1 != 0) {
        FUN_00557470();
        FUN_00587bcf(iVar1);
      }
      FUN_0053c590(0xffffffff,s_Error_reading_mesh_file_005dbf60);
      return 0xffffffff;
    }
    uVar7 = 0;
  }
  else {
    pvVar4 = operator_new(0x30);
    if (pvVar4 == (void *)0x0) {
      param_2 = 0;
    }
    else {
      param_2 = FUN_005473d0();
    }
    iVar2 = FUN_00547b40(param_1);
    if (iVar2 != 0) {
      if (param_2 != 0) {
        FUN_00557470();
        FUN_00587bcf(param_2);
      }
      FUN_0053c590(0xffffffff,s_Error_allocating_mesh_local_matl_005dbf9c);
      return 0xffffffff;
    }
    FUN_0054a580(0);
    iVar2 = FUN_00547b40(param_1);
    if (iVar2 != 0) {
      FUN_0053c590(0xffffffff,s_Error_reading_scene_global_matli_005dbf78);
      return 0xffffffff;
    }
    iVar2 = FUN_0054a5b0();
    uVar3 = param_3 + (iVar1 - iVar2);
    pcVar5 = operator_new(uVar3);
    FUN_0054e9b0(0);
    uVar6 = FUN_0054a5c0(uVar3);
    if (uVar6 != uVar3) {
      FUN_0053c590(0xffffffff,s_Error_reading_mesh_file_005dbf60);
      return 0xffffffff;
    }
    iVar1 = 0xe;
    bVar10 = true;
    pcVar8 = pcVar5;
    pcVar9 = s_CUBE_MTS_4_01_005dbf50;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar10 = *pcVar8 == *pcVar9;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar10);
    if (!bVar10) {
      if (pcVar5 != (char *)0x0) {
        FUN_00557470();
        FUN_00587bcf(pcVar5);
      }
      FUN_0053c590(0xffffffff,s_Wrong_MTS_version_005dbf3c);
      return 0xffffffff;
    }
    pvVar4 = operator_new(uVar3 + 0x60);
    *param_4 = (int)pvVar4;
    FUN_0054c320(0);
    pcVar8 = pcVar5 + 0xe8;
    pcVar9 = (char *)(*param_4 + 0x148);
    for (uVar6 = uVar3 - 0xe8 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar6 = uVar3 - 0xe8 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar9 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    }
    FUN_0054b190(pcVar5,*param_4);
    FUN_00587bcf(pcVar5);
    uVar7 = 0x60;
  }
  iVar1 = FUN_0054c510(param_2,uVar7);
  if (iVar1 == 0) {
    FUN_0054b330(0x40,0x20,0);
    for (iVar1 = *(int *)(param_2 + 0x24); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc0)) {
      FUN_00547710(iVar1);
    }
    FUN_00547420();
    FUN_00557470();
    FUN_00587bcf(param_2);
    if (DAT_008b8f30 != (void *)0x0) {
      FUN_00587bcf(DAT_008b8f30);
    }
    if (DAT_008b8f34 != (void *)0x0) {
      FUN_00587bcf(DAT_008b8f34);
    }
    DAT_008b8f30 = (void *)0x0;
    DAT_008b8f34 = (void *)0x0;
    return 0;
  }
  return 0xffffffff;
}


