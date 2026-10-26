// Function: FUN_0045f710 @ 0045f710
// Size (bytes): 568


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0045f710(int param_1)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  int local_244;
  int iStack_240;
  uint local_23c [107];
  int local_90 [36];
  
  cVar3 = FUN_00461440();
  if (cVar3 != '\0') {
    FUN_004651c0();
    iVar7 = 0;
    piVar8 = &DAT_005ef9a0;
    do {
      if (*piVar8 != -1) {
        FUN_004652d0(iVar7);
      }
      piVar8 = piVar8 + 0x1230;
      iVar7 = iVar7 + 1;
    } while ((int)piVar8 < 0x7c87a0);
  }
  if ((*(int *)(param_1 + 0x3fc4) == 2) || (*(int *)(param_1 + 0x3fc4) == 1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  while( true ) {
    local_244 = 0x1b0;
    iVar7 = FUN_0057a760(local_23c,&local_244,local_90);
    if (iVar7 != 0) break;
    *(undefined4 *)(param_1 + 0x388) = 0;
    if (bVar2) {
      uVar4 = FUN_00460c30(local_90[0]);
      local_23c[0] = local_23c[0] & 0xffffff00 | uVar4;
    }
    FUN_0045c8f0(local_23c,(float)_DAT_008afea0);
    FUN_0045d890(local_23c);
  }
  if (bVar2) {
    cVar3 = FUN_00461440();
    if (cVar3 == '\0') {
      FUN_00461470();
      iStack_240 = FUN_00462300();
      iVar7 = 0;
      local_244 = 0;
      if (0 < *(int *)(param_1 + 0x3e14)) {
        pcVar6 = (char *)(param_1 + 0x410);
        do {
          cVar3 = FUN_004614c0();
          if ((cVar3 != '\0') &&
             (iVar1 = *(int *)(param_1 + 0x3e18 + *pcVar6 * 4), iVar1 != iStack_240)) {
            FUN_004b3b30();
            iVar5 = FUN_004b3af0(local_23c);
            while (iVar5 != 0) {
              if (iVar1 != local_90[0]) {
                FUN_00462250(local_23c,1,iVar1,1000);
                iVar7 = iVar7 + 1;
              }
              iVar5 = FUN_004b3af0(local_23c);
            }
          }
          local_244 = local_244 + 1;
          pcVar6 = pcVar6 + 0x8c;
        } while (local_244 < *(int *)(param_1 + 0x3e14));
      }
      if (((DAT_007d0f04 == 0) && (8 < DAT_007d0e98)) && (0 < iVar7)) {
        FUN_0057a730(0);
      }
      FUN_004b0170();
    }
    else {
      FUN_004b3b30();
      iVar7 = FUN_004b3af0(local_23c);
      if (iVar7 != 0) {
        do {
          FUN_00465300(local_23c);
          iVar7 = FUN_004b3af0(local_23c);
        } while (iVar7 != 0);
        return;
      }
    }
  }
  return;
}


