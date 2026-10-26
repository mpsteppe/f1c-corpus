// Function: FUN_004562f0 @ 004562f0
// Strings:  [RADIUS, ORIENTATIONOFFSET, POSITIONOFFSET, ORIENTATIONRATE, RADIUSLIMITS, FALSE, FALSE, CLEAR]


undefined4 __thiscall FUN_004562f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  char *pcVar4;
  bool bVar5;
  undefined1 local_4d5;
  undefined4 local_4d4;
  undefined4 local_4d0;
  undefined4 local_4cc;
  undefined4 local_4c8;
  undefined4 local_4c4;
  undefined4 local_4c0;
  undefined4 local_4bc;
  undefined4 local_4b8;
  undefined4 local_4b4;
  undefined4 local_4b0;
  undefined4 local_4ac;
  undefined4 local_4a8;
  undefined4 local_4a4;
  undefined4 local_4a0;
  undefined4 local_49c [97];
  undefined4 local_318;
  undefined1 local_314;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_300 [96];
  char local_180 [384];
  
  puVar3 = local_300;
  for (iVar1 = 0x60; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_4b0 = 0;
  local_4cc = 0;
  local_4b8 = 0;
  local_4a8 = 0;
  local_4a0 = 0;
  local_49c[0] = 0;
  local_4d0 = 0;
  local_4d4 = 0;
  local_4c8 = 0;
  local_318 = 0;
  local_304 = 0;
  local_30c = 0;
  local_308 = 0;
  local_314 = 1;
  local_4d5 = 1;
  local_4a4 = 0;
  local_4ac = 0;
  local_4b4 = 0;
  local_4bc = 0;
  local_4c4 = 0;
  local_4c0 = 0x3f800000;
  iVar1 = FUN_00566cc0(local_300,0x180);
  while (iVar1 != 0) {
    iVar1 = FUN_005651b0();
    if (iVar1 == 0) {
      FUN_00565870(&DAT_005c57fc,&local_4d4,&local_4d0,0,0,0,0,0,0);
      FUN_00565760(s_COLOR_005c57f4,&local_4c4,&local_4bc,&local_4b4,0);
      FUN_00565870(s_CLIPPLANES_005c57e8,local_49c,&local_4a0,0,0,0,0,0,0);
      FUN_00565870(s_LODMULTIPLIER_005c57d8,&local_4c0,0,0,0,0,0,0,0);
      FUN_00565870(&DAT_005c57d0,&local_4a8,&local_4b8,0,0,0,0,0,0);
      FUN_00565870(s_CENTER_005c57c8,&local_4cc,&local_4b0,0,0,0,0,0,0);
      FUN_00565870(s_MIPMAPLODBIAS_005c57b8,&local_4c8,0,0,0,0,0,0,0);
      FUN_00565760(s_FLAGS1_005c57b0,&local_4ac,0,0,0);
      FUN_00565760(s_FLAGS2_005c57a8,&local_4a4,0,0,0);
      iVar1 = FUN_00565520(s_CLEAR_005c57a0,local_180,0);
      if (iVar1 != 0) {
        iVar1 = 6;
        bVar5 = true;
        pcVar2 = local_180;
        pcVar4 = s_FALSE_005c5798;
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *pcVar2 == *pcVar4;
          pcVar2 = pcVar2 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (bVar5) {
          local_4d5 = 0;
        }
      }
      FUN_00565870(s_RADIUSLIMITS_005c5788,param_1 + 0x80,param_1 + 0x84,0,0,0,0,0,0);
      FUN_00565870(s_ORIENTATIONRATE_005c5778,param_1 + 0x88,param_1 + 0x8c,param_1 + 0x90,0,0,0,0,0
                  );
      FUN_00565870(s_POSITIONOFFSET_005c5768,param_1 + 0x94,param_1 + 0x98,param_1 + 0x9c,0,0,0,0,0)
      ;
      FUN_00565870(s_ORIENTATIONOFFSET_005c5754,param_1 + 0xa0,param_1 + 0xa4,param_1 + 0xa8,0,0,0,0
                   ,0);
      FUN_00565870(s_RADIUS_005c574c,param_1 + 0xac,0,0,0,0,0,0,0);
    }
    else {
      if (iVar1 == 2) break;
      if (iVar1 == 4) {
        return 1;
      }
    }
    iVar1 = FUN_00566cc0(local_300,0x180);
  }
  FUN_00566650(param_3);
  *(undefined4 *)(param_1 + 0x30) = local_4d4;
  *(undefined4 *)(param_1 + 0x34) = local_4d0;
  *(undefined4 *)(param_1 + 0x38) = local_4d4;
  *(undefined4 *)(param_1 + 100) = local_4c4;
  *(undefined4 *)(param_1 + 0x3c) = local_4d0;
  *(undefined4 *)(param_1 + 0x40) = local_49c[0];
  *(undefined1 *)(param_1 + 0x60) = local_4d5;
  *(undefined4 *)(param_1 + 0x44) = local_4a0;
  *(undefined4 *)(param_1 + 0x68) = local_4bc;
  *(undefined4 *)(param_1 + 0x48) = local_4c0;
  *(undefined4 *)(param_1 + 0x4c) = local_4a8;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x50) = local_4b8;
  *(undefined4 *)(param_1 + 0x74) = local_4ac;
  *(undefined4 *)(param_1 + 0x54) = local_4cc;
  *(undefined4 *)(param_1 + 0x6c) = local_4b4;
  *(undefined4 *)(param_1 + 0x58) = local_4b0;
  *(undefined4 *)(param_1 + 0x78) = local_4a4;
  *(undefined4 *)(param_1 + 0x5c) = local_4c8;
  return 0;
}


