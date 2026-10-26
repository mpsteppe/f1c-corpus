// Function: FUN_00406790 @ 00406790
// Strings:  [%s%d,%d.mp3, %s%d,%d.mp3]


void __fastcall FUN_00406790(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  char cVar3;
  byte *pbVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  bool bVar11;
  undefined1 local_20;
  undefined4 local_1f;
  
  uVar8 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x90);
  pbVar4 = *(byte **)(param_1 + 0x10);
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (pbVar4 == (byte *)0x0) {
      pbVar4 = &DAT_005ea438;
    }
    pbVar10 = &DAT_005ea438;
    do {
      bVar1 = *pbVar4;
      bVar11 = bVar1 < *pbVar10;
      if (bVar1 != *pbVar10) {
LAB_00406899:
        iVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_0040689e;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar11 = bVar1 < pbVar10[1];
      if (bVar1 != pbVar10[1]) goto LAB_00406899;
      pbVar4 = pbVar4 + 2;
      pbVar10 = pbVar10 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_0040689e:
    if (iVar5 == 0) {
      iVar5 = FUN_004080b0(*(undefined4 *)(param_1 + 0x1c));
      if ((iVar5 == 0) || (iVar7 = FUN_004054e0(*(undefined4 *)(param_1 + 0x18)), iVar7 != 0))
      goto LAB_00406963;
      local_20 = DAT_005ea438;
      iVar7 = 7;
      if (*(int *)(iVar5 + 0x2c) == 2) {
        uVar2 = *(undefined4 *)(iVar5 + 0x24);
        puVar9 = &local_1f;
        for (; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar9 = 0;
          puVar9 = puVar9 + 1;
        }
        *(undefined2 *)puVar9 = 0;
        *(undefined1 *)((int)puVar9 + 2) = 0;
        FUN_0058815f(&local_20,s__s_d__d_mp3_005be854,&DAT_005be820,*(undefined4 *)(iVar5 + 0x10),
                     uVar2);
        puVar6 = &local_20;
      }
      else {
        uVar2 = *(undefined4 *)(iVar5 + 0x10);
        puVar9 = &local_1f;
        for (; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar9 = 0;
          puVar9 = puVar9 + 1;
        }
        *(undefined2 *)puVar9 = 0;
        *(undefined1 *)((int)puVar9 + 2) = 0;
        FUN_0058815f(&local_20,&DAT_005be84c,&DAT_005be820,uVar2);
        puVar6 = &local_20;
      }
    }
    else {
      puVar6 = *(undefined1 **)(param_1 + 0x10);
      if (puVar6 == (undefined1 *)0x0) {
        puVar6 = &DAT_005ea438;
      }
    }
  }
  else {
    if (pbVar4 == (byte *)0x0) {
      pbVar4 = &DAT_005ea438;
    }
    pbVar10 = &DAT_005ea438;
    do {
      bVar1 = *pbVar4;
      bVar11 = bVar1 < *pbVar10;
      if (bVar1 != *pbVar10) {
LAB_004067e5:
        iVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_004067ea;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar11 = bVar1 < pbVar10[1];
      if (bVar1 != pbVar10[1]) goto LAB_004067e5;
      pbVar4 = pbVar4 + 2;
      pbVar10 = pbVar10 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_004067ea:
    if ((iVar5 == 0) || (*(int *)(param_1 + 0x1c) < 1)) goto LAB_00406963;
    puVar6 = *(undefined1 **)(param_1 + 0x10);
    if (puVar6 == (undefined1 *)0x0) {
      puVar6 = &DAT_005ea438;
    }
    cVar3 = FUN_004069f0(puVar6,*(undefined4 *)(param_1 + 0x18));
    if (cVar3 == '\0') goto LAB_00406963;
    local_20 = DAT_005ea438;
    puVar9 = &local_1f;
    for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    uVar2 = *(undefined4 *)(param_1 + 0x5c);
    *(undefined2 *)puVar9 = 0;
    *(undefined1 *)((int)puVar9 + 2) = 0;
    FUN_0058815f(&local_20,s__s_d__d_mp3_005be854,&DAT_005be820,uVar2,
                 *(undefined4 *)(param_1 + 0x1c));
    puVar6 = &local_20;
  }
  uVar8 = _AIL_open_stream_12(uVar8,puVar6,0);
  *(undefined4 *)(param_1 + 0xc) = uVar8;
LAB_00406963:
  if (*(int *)(param_1 + 0xc) == 0) {
    FUN_00406700(0);
    puVar9 = (undefined4 *)(param_1 + 0x1c);
    iVar5 = 3;
    do {
      FUN_00566650(&DAT_005ea438);
      puVar9[-1] = 0xffffffff;
      *puVar9 = 0xffffffff;
      *(undefined1 *)(puVar9 + 1) = 0;
      puVar9 = puVar9 + 5;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    return;
  }
  _AIL_register_stream_callback_8(*(int *)(param_1 + 0xc),&LAB_00405030);
  _AIL_start_stream_4(*(undefined4 *)(param_1 + 0xc));
  _AIL_set_stream_volume_levels_12
            (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 4),
             *(undefined4 *)(param_1 + 4));
  FUN_00406700(2);
  return;
}


