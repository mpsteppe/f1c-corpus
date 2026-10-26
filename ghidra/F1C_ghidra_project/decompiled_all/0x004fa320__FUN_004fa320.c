// Function: FUN_004fa320 @ 004fa320
// Strings:  [CUBE error loading scene file %s: %s, D:\dev\F1_1999_2002\Source\vidman.cpp, D:\dev\F1_1999_2002\Source\vidman.cpp, Entered VidMan::Init()]


undefined4 FUN_004fa320(void)

{
  char cVar1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  char local_400 [510];
  char acStack_202 [514];
  
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_vidma_005d6dc4,0x3fb);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_VidMan__Init___005d6e9c);
  }
  DAT_008afe70 = 0;
  FUN_0053d400(3 - DAT_007cf65c);
  FUN_0053d430(DAT_007cfbfc);
  FUN_0053d410(DAT_007cfc20);
  FUN_00551fb0(DAT_007d032c);
  if (DAT_007cfb90 == 1) {
    FUN_0054a1c0(1,0);
    uVar7 = 0;
  }
  else if (DAT_007cfb90 == 2) {
    FUN_0054a1c0(1,0);
    uVar7 = 1;
  }
  else {
    if (DAT_007cfb90 != 3) {
      FUN_0054a1c0(1,0);
      FUN_0054a1c0(2,0);
      FUN_0054a1c0(4,0);
      FUN_0054a1c0(8,0);
      uVar7 = 1;
      goto LAB_004fa447;
    }
    FUN_0054a1c0(1,1);
    uVar7 = 1;
  }
  FUN_0054a1c0(2,uVar7);
  FUN_0054a1c0(4,1);
  FUN_0054a1c0(8,1);
  uVar7 = 0;
LAB_004fa447:
  FUN_0054a1c0(0x10,uVar7);
  puVar2 = DAT_007ce5ec;
  if (DAT_007ce5ec == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_004c55b0(puVar2);
  iVar5 = DAT_008ac48c * 0x18c + DAT_008ac490;
  if (iVar5 != 0) {
    pcVar3 = (char *)(iVar5 + 4);
    iVar5 = -(int)pcVar3;
    do {
      cVar1 = *pcVar3;
      pcVar3[(int)(local_400 + iVar5)] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    uVar6 = 0xffffffff;
    pcVar3 = local_400;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if ((0 < (int)(~uVar6 - 1)) && (pcVar3 = local_400 + (~uVar6 - 2), local_400 <= pcVar3)) {
      do {
        if (*pcVar3 == '\\') break;
        *pcVar3 = '\0';
        pcVar3 = pcVar3 + -1;
      } while (local_400 <= pcVar3);
    }
    uVar6 = 0xffffffff;
    pcVar3 = local_400;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if ((0 < (int)(~uVar6 - 1)) && (local_400[~uVar6 - 2] == '\\')) {
      local_400[~uVar6 - 2] = '\0';
    }
    FUN_0053c800(local_400);
  }
  puVar2 = DAT_005ec428;
  if (DAT_005ec428 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  puVar4 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar4 = &DAT_005ea438;
  }
  FUN_0058815f(acStack_202 + 2,&DAT_005be860,puVar4,puVar2);
  uVar6 = 0xffffffff;
  pcVar3 = acStack_202 + 2;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if ((0 < (int)(~uVar6 - 1)) && (acStack_202[~uVar6] == '\\')) {
    acStack_202[~uVar6] = '\0';
  }
  FUN_0053c800(acStack_202 + 2);
  FUN_00546230(FUN_004f9480,0x41000000);
  puVar2 = DAT_007ce5d0;
  if (DAT_007ce5d0 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  iVar5 = FUN_00546010(&DAT_008afe88,puVar2,0);
  if (iVar5 == 0) {
    FUN_00546230(0,0);
    FUN_004d15f0();
    FUN_004f9480(0x42ca0000);
    FUN_005458d0(2);
    return 0;
  }
  FUN_0053c5b0(0,local_400);
  cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vidma_005d6dc4,0x45a);
  if (cVar1 != '\0') {
    puVar2 = DAT_007ce5d0;
    if (DAT_007ce5d0 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    FUN_004d7aa0(&DAT_008ad25c,s_CUBE_error_loading_scene_file__s_005cc220,puVar2,local_400);
  }
  return 1;
}


