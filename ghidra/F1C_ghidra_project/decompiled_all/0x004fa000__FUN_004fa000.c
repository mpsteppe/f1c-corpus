// Function: FUN_004fa000 @ 004fa000
// Strings:  [D:\dev\F1_1999_2002\Source\vidman.cpp, 3DCONFIG.EXE , No Device, Entered VidMan::Enter()]


undefined4 FUN_004fa000(void)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  _STARTUPINFOA *p_Var9;
  char *pcVar10;
  char *pcVar11;
  bool bVar12;
  int local_564;
  undefined4 local_560;
  undefined4 local_55c;
  undefined4 local_558;
  _PROCESS_INFORMATION local_554;
  _STARTUPINFOA local_544;
  byte local_500 [256];
  char local_400 [1024];
  
  cVar2 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_vidma_005d6dc4,0x3a0);
  if (cVar2 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_VidMan__Enter___005d6e6c);
  }
  FUN_00568be0(1);
  iVar3 = FUN_0053d470(0,0,0);
  if (iVar3 != 0) {
    return 1;
  }
  iVar3 = FUN_0053d890(DAT_005ec488);
  if (iVar3 == 0) {
    iVar3 = 0;
    do {
      bVar1 = s_No_Device_005d6e60[iVar3];
      local_500[iVar3] = bVar1;
      iVar3 = iVar3 + 1;
    } while (bVar1 != 0);
  }
  else {
    FUN_0053d8e0(iVar3 + 8,local_500);
  }
  pbVar8 = DAT_005ec480;
  if (DAT_005ec480 == (byte *)0x0) {
    pbVar8 = &DAT_005ea438;
  }
  pbVar4 = local_500;
  do {
    bVar1 = *pbVar4;
    bVar12 = bVar1 < *pbVar8;
    if (bVar1 != *pbVar8) {
LAB_004fa0de:
      iVar3 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      goto LAB_004fa0e3;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar4[1];
    bVar12 = bVar1 < pbVar8[1];
    if (bVar1 != pbVar8[1]) goto LAB_004fa0de;
    pbVar4 = pbVar4 + 2;
    pbVar8 = pbVar8 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004fa0e3:
  if (iVar3 == 0) {
    FUN_004f9160(DAT_005ec488);
    FUN_004f91b0(DAT_005ec48c,&local_55c,&local_558,&local_564,&local_560);
    iVar3 = local_564;
    if (DAT_005ec4a4 != '\0') {
      FUN_0055c330(0,0,&local_564);
      if (local_564 != iVar3) {
        DAT_005ec4a4 = '\0';
      }
    }
    iVar5 = FUN_004a1200(local_55c,local_558,DAT_005ec4a4);
    if (iVar5 == 0) {
      FUN_0053c680(DAT_007ce2dc,DAT_007ce2dc,DAT_007ce2a0);
      FUN_005408f0(DAT_005ec4b4);
      FUN_004f9420(local_55c,local_558,iVar3,local_560);
      iVar3 = FUN_004f9310(DAT_008afe74);
      if (iVar3 != 0) {
        return 1;
      }
      FUN_004f9f00();
      FUN_005434a0(0,0,0x3f800000,0x3f800000,0);
      FUN_0055c060(0);
      FUN_005434a0(0,0,0x3f800000,0x3f800000,0);
      FUN_004f9f30();
      FUN_00494690();
    }
    return 0;
  }
  FUN_00422be0(0);
  GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_500,0x100);
  iVar3 = 0;
  p_Var9 = &local_544;
  for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {
    p_Var9->cb = 0;
    p_Var9 = (_STARTUPINFOA *)&p_Var9->lpReserved;
  }
  local_544.cb = 0x44;
  do {
    cVar2 = s_3DCONFIG_EXE_005d6e50[iVar3];
    local_400[iVar3] = cVar2;
    iVar3 = iVar3 + 1;
  } while (cVar2 != '\0');
  uVar6 = 0xffffffff;
  pbVar8 = local_500;
  do {
    pbVar4 = pbVar8;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pbVar4 = pbVar8 + 1;
    bVar1 = *pbVar8;
    pbVar8 = pbVar4;
  } while (bVar1 != 0);
  uVar6 = ~uVar6;
  iVar3 = -1;
  pcVar10 = local_400;
  do {
    pcVar11 = pcVar10;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar11 = pcVar10 + 1;
    cVar2 = *pcVar10;
    pcVar10 = pcVar11;
  } while (cVar2 != '\0');
  pbVar8 = pbVar4 + -uVar6;
  pbVar4 = (byte *)(pcVar11 + -1);
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pbVar4 = *(undefined4 *)pbVar8;
    pbVar8 = pbVar8 + 4;
    pbVar4 = pbVar4 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pbVar4 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    pbVar4 = pbVar4 + 1;
  }
  CreateProcessA((LPCSTR)0x0,local_400,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0x20,
                 (LPVOID)0x0,(LPCSTR)0x0,&local_544,&local_554);
  return 1;
}


