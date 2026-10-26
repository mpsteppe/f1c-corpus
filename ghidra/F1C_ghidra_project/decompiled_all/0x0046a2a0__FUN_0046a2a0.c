// Function: FUN_0046a2a0 @ 0046a2a0
// Strings:  [%4.4sICON.bmp, _TSBIcon.bmp]


void FUN_0046a2a0(void)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int local_118;
  char local_110 [14];
  char acStack_102 [258];
  
  FUN_0048d230();
  if (0 < DAT_008ac488) {
    iVar6 = 0;
    local_118 = DAT_008ac488;
    do {
      pcVar7 = (char *)(DAT_008ac490 + 4 + iVar6);
      pcVar2 = pcVar7;
      do {
        cVar1 = *pcVar2;
        pcVar2[(int)(acStack_102 + (2 - (int)pcVar7))] = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      uVar3 = 0xffffffff;
      pcVar2 = acStack_102 + 2;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      if ((0 < (int)(~uVar3 - 1)) && (pcVar2 = acStack_102 + ~uVar3, acStack_102 + 2 <= pcVar2)) {
        do {
          if (*pcVar2 == '\\') break;
          *pcVar2 = '\0';
          pcVar2 = pcVar2 + -1;
        } while (acStack_102 + 2 <= pcVar2);
      }
      uVar3 = 0xffffffff;
      pcVar2 = pcVar7;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      for (pcVar2 = pcVar7 + (~uVar3 - 1); pcVar7 < pcVar2; pcVar2 = pcVar2 + -1) {
        if (*pcVar2 == '\\') {
          pcVar2 = pcVar2 + 1;
          break;
        }
      }
      FUN_0058815f(local_110,PTR_s__4_4sICON_bmp_005c6660,pcVar2);
      uVar3 = 0xffffffff;
      pcVar7 = local_110;
      do {
        pcVar2 = pcVar7;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar2 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar2;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar4 = -1;
      pcVar7 = acStack_102 + 2;
      do {
        pcVar8 = pcVar7;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar8 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar8;
      } while (cVar1 != '\0');
      pcVar7 = pcVar2 + -uVar3;
      pcVar2 = pcVar8 + -1;
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar2 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar2 = pcVar2 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar2 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar2 = pcVar2 + 1;
      }
      iVar4 = FUN_00497ad0(acStack_102 + 2,0);
      if (iVar4 == 0) {
        iVar4 = FUN_00497ad0(PTR_s__TSBIcon_bmp_005c665c,0);
      }
      FUN_0048d2b0(iVar4);
      iVar6 = iVar6 + 0x18c;
      local_118 = local_118 + -1;
    } while (local_118 != 0);
  }
  return;
}


