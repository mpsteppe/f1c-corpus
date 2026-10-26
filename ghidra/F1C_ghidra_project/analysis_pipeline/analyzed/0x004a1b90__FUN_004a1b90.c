// Function: FUN_004a1b90 @ 004a1b90
// Size (bytes): 370


undefined1 __fastcall FUN_004a1b90(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  undefined1 local_185;
  undefined4 local_184;
  char local_180 [384];
  
  local_185 = 0;
  local_184 = FUN_00566e20();
  iVar6 = 0;
  local_180[0] = '\0';
  iVar2 = FUN_00566cc0(local_180,0x180);
  while (iVar2 != 0) {
    iVar2 = FUN_00596c80(local_180,&DAT_005c30b8,2);
    if (iVar2 != 0) {
      puVar3 = (undefined1 *)FUN_00587c20(local_180,&DAT_005c30b4);
      if (puVar3 != (undefined1 *)0x0) {
        *puVar3 = 0;
      }
      puVar3 = (undefined1 *)FUN_00587c20(local_180,&DAT_005c30b0);
      if (puVar3 != (undefined1 *)0x0) {
        *puVar3 = 0;
      }
      iVar2 = -1;
      pcVar7 = local_180;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      if (iVar2 != -2) {
        pcVar7 = (char *)param_1[1];
        iVar6 = iVar6 + 1;
        if (pcVar7 == (char *)0x0) {
          pcVar7 = &DAT_005ea438;
        }
        uVar4 = 0xffffffff;
        pcVar8 = pcVar7;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        iVar2 = FUN_00596c80(pcVar7,local_180,~uVar4 - 1);
        if (iVar2 == 0) {
          puVar3 = (undefined1 *)FUN_00587c20(local_180,&DAT_005c30b8);
          if (puVar3 != (undefined1 *)0x0) {
            *puVar3 = 0;
          }
          uVar4 = 0xffffffff;
          goto code_r0x004a1c9a;
        }
      }
    }
    iVar2 = FUN_00566cc0(local_180,0x180);
  }
  goto LAB_004a1ce5;
  while( true ) {
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    if (cVar1 == '\0') break;
code_r0x004a1c9a:
    if (uVar4 == 0) break;
  }
  uVar5 = 0xffffffff;
  pcVar7 = local_180;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  for (pcVar7 = local_180 + (~uVar5 - 1); local_180 + ~uVar4 + 1 <= pcVar7; pcVar7 = pcVar7 + -1) {
    if (*pcVar7 == '\"') {
      *pcVar7 = '\0';
      break;
    }
  }
  cVar1 = (**(code **)(*param_1 + 4))(local_180 + ~uVar4 + 1);
  if ((cVar1 != '\0') && (local_185 = 1, iVar6 == 1)) {
    return 1;
  }
LAB_004a1ce5:
  FUN_00566db0(local_184);
  return local_185;
}


