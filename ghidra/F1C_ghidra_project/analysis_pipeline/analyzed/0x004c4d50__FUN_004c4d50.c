// Function: FUN_004c4d50 @ 004c4d50
// Size (bytes): 668


int __thiscall FUN_004c4d50(int param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  byte *pbVar9;
  bool bVar10;
  int local_384;
  int local_380;
  int local_37c;
  int local_378;
  undefined4 local_374;
  undefined1 local_370;
  undefined4 local_36c;
  undefined1 local_368;
  undefined4 local_364;
  undefined1 local_360;
  undefined4 local_35c;
  int local_358 [50];
  int local_290 [50];
  int local_1c8 [50];
  byte local_100 [256];
  
  iVar8 = 0;
  local_384 = 0;
  FUN_004c4cf0();
  if (param_2 != (byte *)0x0) {
    pbVar9 = &DAT_005ea438;
    pbVar2 = param_2;
    do {
      bVar1 = *pbVar2;
      bVar10 = bVar1 < *pbVar9;
      if (bVar1 != *pbVar9) {
LAB_004c4da4:
        iVar3 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_004c4da9;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar10 = bVar1 < pbVar9[1];
      if (bVar1 != pbVar9[1]) goto LAB_004c4da4;
      pbVar2 = pbVar2 + 2;
      pbVar9 = pbVar9 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_004c4da9:
    if ((iVar3 != 0) && ((DAT_007d0398 == 0 || (DAT_007d0410 == 5)))) {
      FUN_00566650(param_2);
      local_370 = DAT_005d30d8;
      local_368 = DAT_005d30d0;
      local_36c = DAT_005d30cc;
      local_374 = DAT_005d30d4;
      local_364 = DAT_005d30c4;
      local_35c = DAT_005d30c0;
      local_378 = 0;
      local_384 = 0;
      local_380 = 0;
      local_37c = 0;
      local_360 = DAT_005d30c8;
      iVar3 = -(int)param_2;
      do {
        bVar1 = *param_2;
        param_2[(int)(local_100 + iVar3)] = bVar1;
        param_2 = param_2 + 1;
      } while (bVar1 != 0);
      piVar6 = local_290;
      for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar6 = 0;
        piVar6 = piVar6 + 1;
      }
      piVar6 = local_358;
      for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar6 = 0;
        piVar6 = piVar6 + 1;
      }
      iVar3 = FUN_005897ca(local_100,&local_374);
      while (iVar3 != 0) {
        iVar4 = FUN_00588410(iVar3,&local_36c);
        if (iVar4 == 0) {
          local_380 = 0;
        }
        else {
          iVar4 = FUN_00588410(iVar3,&local_35c);
          if (iVar4 == 0) {
            local_380 = 1;
          }
          else {
            iVar4 = FUN_00588410(iVar3,&local_364);
            if (iVar4 == 0) {
              local_380 = 2;
            }
            else {
              if (local_380 == 0) {
LAB_004c4ef9:
                piVar5 = &local_37c;
                piVar6 = local_358 + iVar8;
              }
              else if (local_380 == 1) {
                piVar5 = &local_378;
                piVar6 = local_290 + local_378;
              }
              else {
                if (local_380 != 2) goto LAB_004c4ef9;
                piVar5 = &local_384;
                piVar6 = local_1c8 + local_384;
              }
              if (*piVar5 < 0x31) {
                *piVar5 = *piVar5 + 1;
                *piVar6 = iVar3;
                iVar8 = local_37c;
              }
            }
          }
        }
        iVar3 = FUN_005897ca(0,&local_374);
      }
      FUN_004c4990(local_358,iVar8);
      FUN_004c4aa0(local_290,local_378);
      local_384 = FUN_004c4bb0(local_1c8,local_384);
      goto LAB_004c4fce;
    }
  }
  FUN_00566650(&DAT_005ea438);
  iVar8 = DAT_008ac390;
  iVar3 = 0;
  if (0 < DAT_008ac390) {
    local_384 = DAT_008ac390;
    do {
      piVar6 = operator_new(4);
      *piVar6 = iVar3;
      puVar7 = operator_new(0xc);
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        *puVar7 = piVar6;
        puVar7[1] = 0;
        *(undefined1 *)(puVar7 + 2) = 1;
      }
      if (*(int *)(param_1 + 8) == 0) {
        *(undefined4 **)(param_1 + 8) = puVar7;
        *(undefined4 **)(param_1 + 0x10) = puVar7;
      }
      else {
        *(undefined4 **)(*(int *)(param_1 + 0xc) + 4) = puVar7;
      }
      iVar3 = iVar3 + 1;
      *(undefined4 **)(param_1 + 0xc) = puVar7;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    } while (iVar3 < iVar8);
  }
LAB_004c4fce:
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x18) = 0;
  return local_384;
}


