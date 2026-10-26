// Function: FUN_0054a870 @ 0054a870
// Strings:  [%s\%s, Illegal mesh file name %s, Could not locate mesh file %s,  for file %s,  for file %s]


undefined4 __thiscall FUN_0054a870(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  undefined1 *puVar10;
  char *pcVar11;
  char *pcVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int local_408;
  undefined4 local_404;
  char local_400 [256];
  char local_300 [256];
  char local_200 [256];
  undefined1 local_100 [256];
  
  iVar2 = -(int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)(local_300 + iVar2)] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_00589901(local_300);
  if ((local_300[0] == '\0') || (iVar2 = FUN_00587c20(local_300,&DAT_005d359c), iVar2 == 0)) {
    FUN_0058815f(local_400,s_Illegal_mesh_file_name__s_005dbef0,local_300);
    goto LAB_0054abc0;
  }
  iVar2 = FUN_00587db0(local_300,&DAT_005be828);
  if (iVar2 == 0) {
    iVar2 = 0;
    if (0 < DAT_008b8e30) {
      puVar10 = &DAT_008b5a3c;
      do {
        FUN_0058815f(local_100,s__s__s_005c2d64,puVar10,local_300);
        iVar5 = FUN_00587db0(local_100,&DAT_005be828);
        if (iVar5 != 0) {
          uVar3 = FUN_0058ace6(iVar5);
          FUN_00587f64(iVar5,0,2);
          local_404 = FUN_0058ace6(iVar5);
          FUN_00587f64(iVar5,uVar3,0);
          iVar6 = FUN_0054ac70(iVar5,local_404,&local_408,0);
          if (iVar6 != 0) {
            FUN_00587d02(iVar5);
            goto LAB_0054aa57;
          }
          FUN_00587d02(iVar5);
          break;
        }
        iVar2 = iVar2 + 1;
        puVar10 = puVar10 + 0x84;
      } while (iVar2 < DAT_008b8e30);
    }
    if (iVar2 == DAT_008b8e30) {
      iVar2 = 0;
      for (iVar5 = DAT_008b8f14; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x130)) {
        iVar6 = FUN_00560230(local_300);
        if (iVar6 == 0) {
          iVar6 = FUN_0054ac70(*(undefined4 *)(iVar5 + 0x10),
                               *(undefined4 *)
                                (*(int *)(iVar5 + 0x124) * 0x100 + 8 + *(int *)(iVar5 + 0x128)),
                               &local_408,iVar5);
          if (iVar6 == 0) break;
          if (iVar6 == -1) goto LAB_0054aa57;
        }
        iVar2 = iVar2 + 1;
      }
    }
    else {
      iVar2 = -1;
    }
    if (iVar2 != DAT_008b6ac0) goto LAB_0054a968;
    FUN_0058815f(local_400,s_Could_not_locate_mesh_file__s_005dbf0c,local_300);
    goto LAB_0054abc0;
  }
  uVar3 = FUN_0058ace6(iVar2);
  FUN_00587f64(iVar2,0,2);
  uVar4 = FUN_0058ace6(iVar2);
  FUN_00587f64(iVar2,uVar3,0);
  iVar5 = FUN_0054ac70(iVar2,uVar4,&local_408,0);
  if (iVar5 == 0) {
    FUN_00587d02(iVar2);
LAB_0054a968:
    *(int *)(local_408 + 0x138) = param_1;
    if ((*(byte *)(param_1 + 0x3c) & 0x10) == 0) {
      uVar3 = 0;
      uVar4 = 0;
      uVar16 = 0;
      uVar15 = 0;
      uVar14 = 0;
      uVar13 = 0;
    }
    else {
      uVar3 = *(undefined4 *)(local_408 + 0x114);
      uVar4 = *(undefined4 *)(local_408 + 0x110);
      uVar16 = *(undefined4 *)(local_408 + 0x10c);
      uVar15 = *(undefined4 *)(local_408 + 0x108);
      uVar14 = *(undefined4 *)(local_408 + 0x104);
      uVar13 = *(undefined4 *)(local_408 + 0x100);
    }
    FUN_0054b4d0(uVar13,uVar14,uVar15,uVar16,uVar4,uVar3);
    FUN_0054b570(0,local_408);
    FUN_0054abe0(local_408);
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xffff7fff;
    return 0;
  }
  FUN_00587d02(iVar2);
  FUN_0053c5b0(0,local_400);
LAB_0054aa7a:
  FUN_0058815f(local_200,s_for_file__s_005dbf2c,local_300);
  uVar7 = 0xffffffff;
  pcVar9 = local_200;
  do {
    pcVar12 = pcVar9;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    pcVar12 = pcVar9 + 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar12;
  } while (cVar1 != '\0');
  uVar7 = ~uVar7;
  iVar2 = -1;
  pcVar9 = local_400;
  do {
    pcVar11 = pcVar9;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar11 = pcVar9 + 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar11;
  } while (cVar1 != '\0');
  pcVar9 = pcVar12 + -uVar7;
  pcVar12 = pcVar11 + -1;
  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar12 = *(undefined4 *)pcVar9;
    pcVar9 = pcVar9 + 4;
    pcVar12 = pcVar12 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar12 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    pcVar12 = pcVar12 + 1;
  }
LAB_0054abc0:
  FUN_0053c590(0xffffffff,local_400);
  return 0xffffffff;
LAB_0054aa57:
  FUN_0053c5b0(0,local_400);
  goto LAB_0054aa7a;
}


