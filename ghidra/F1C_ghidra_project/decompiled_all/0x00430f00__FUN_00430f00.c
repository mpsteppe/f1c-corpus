// Function: FUN_00430f00 @ 00430f00
// Strings:  [%d %s, %.2f %s, %.2f %s, EST. CORNERING, EST. CORNERING, EST. TOP SPEED, EST. TOP SPEED, %s (0-%d %s)%s]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00430f00(int param_1)

{
  char *pcVar1;
  char cVar2;
  double dVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  float10 fVar7;
  float10 fVar8;
  undefined8 local_128;
  undefined4 local_118;
  undefined4 uStack_114;
  double local_110;
  char local_108 [64];
  char local_c8 [64];
  char local_88 [64];
  char local_48 [68];
  
  iVar4 = FUN_00423a00(&DAT_005c3f6c,&DAT_005ec4cc);
  if (iVar4 != 0) {
    iVar4 = 0;
    do {
      pcVar1 = &DAT_005c3f6c + iVar4;
      (&DAT_005ec4cc)[iVar4] = *pcVar1;
      iVar4 = iVar4 + 1;
    } while (*pcVar1 != '\0');
  }
  iVar4 = 0;
  do {
    cVar2 = (&DAT_005ec4cc)[iVar4];
    local_88[iVar4] = cVar2;
    iVar4 = iVar4 + 1;
  } while (cVar2 != '\0');
  iVar6 = 3;
  iVar4 = param_1 + 0x1b26;
  do {
    FUN_0058815f(iVar4,&DAT_005c3810);
    iVar4 = iVar4 + 0x80;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (DAT_007d0474 == '\0') {
    uVar5 = 100;
    local_118 = 0xac083127;
    uStack_114 = 0x40465a1c;
    iVar4 = FUN_00423a00(&DAT_005c3f64,&DAT_005ec4cc);
    if (iVar4 != 0) {
      iVar4 = 0;
      do {
        pcVar1 = &DAT_005c3f64 + iVar4;
        (&DAT_005ec4cc)[iVar4] = *pcVar1;
        iVar4 = iVar4 + 1;
      } while (*pcVar1 != '\0');
    }
    iVar4 = 0;
    do {
      cVar2 = (&DAT_005ec4cc)[iVar4];
      local_c8[iVar4] = cVar2;
      iVar4 = iVar4 + 1;
    } while (cVar2 != '\0');
  }
  else {
    uVar5 = 0x96;
    local_118 = 0x55555556;
    uStack_114 = 0x4044d555;
    iVar4 = FUN_00423a00(&DAT_005c3f68,&DAT_005ec4cc);
    if (iVar4 != 0) {
      iVar4 = 0;
      do {
        pcVar1 = &DAT_005c3f68 + iVar4;
        (&DAT_005ec4cc)[iVar4] = *pcVar1;
        iVar4 = iVar4 + 1;
      } while (*pcVar1 != '\0');
    }
    iVar4 = 0;
    do {
      cVar2 = (&DAT_005ec4cc)[iVar4];
      local_c8[iVar4] = cVar2;
      iVar4 = iVar4 + 1;
    } while (cVar2 != '\0');
  }
  iVar4 = FUN_00423a00(s_EST__ACCEL__005c3f58,&DAT_005ec4cc);
  if (iVar4 != 0) {
    iVar4 = 0;
    do {
      pcVar1 = s_EST__ACCEL__005c3f58 + iVar4;
      (&DAT_005ec4cc)[iVar4] = *pcVar1;
      iVar4 = iVar4 + 1;
    } while (*pcVar1 != '\0');
  }
  iVar4 = 0;
  do {
    cVar2 = (&DAT_005ec4cc)[iVar4];
    local_108[iVar4] = cVar2;
    iVar4 = iVar4 + 1;
  } while (cVar2 != '\0');
  iVar4 = FUN_00423a00(&DAT_005c3758,&DAT_005ec4cc);
  if (iVar4 != 0) {
    iVar4 = 0;
    do {
      pcVar1 = &DAT_005c3758 + iVar4;
      (&DAT_005ec4cc)[iVar4] = *pcVar1;
      iVar4 = iVar4 + 1;
    } while (*pcVar1 != '\0');
  }
  iVar4 = 0;
  do {
    cVar2 = (&DAT_005ec4cc)[iVar4];
    local_48[iVar4] = cVar2;
    iVar4 = iVar4 + 1;
  } while (cVar2 != '\0');
  FUN_0058815f(param_1 + 0x19a6,s__s__0__d__s__s_005c3f48,local_108,uVar5,local_c8,local_88);
  local_128 = 0.0;
  local_110 = 0.0;
  while( true ) {
    fVar7 = (float10)FUN_00430a50((undefined4)local_128,local_128._4_4_);
    if ((fVar7 < (float10)_DAT_0059e430 != (fVar7 == (float10)_DAT_0059e430)) ||
       (fVar7 = (float10)FUN_00430a50((double)(fVar7 * (float10)_DAT_0059eaa8 + (float10)local_128))
       , fVar7 < (float10)_DAT_0059e430 != (fVar7 == (float10)_DAT_0059e430))) goto LAB_0043119b;
    fVar8 = fVar7 * (float10)_DAT_0059ea68 + (float10)local_128;
    if ((float10)(double)CONCAT44(uStack_114,local_118) < fVar8) break;
    local_128 = (double)fVar8;
    local_110 = local_110 + _DAT_0059ea68;
  }
  FUN_0058815f(param_1 + 0x1b26,s___2f__s_005c3820,
               (((double)CONCAT44(uStack_114,local_118) - local_128) /
               (double)(fVar7 * (float10)_DAT_0059ea68)) * _DAT_0059ea68 + local_110,local_48);
LAB_0043119b:
  iVar4 = FUN_00423a00(s_EST__TOP_SPEED_005c3f38,&DAT_005ec4cc);
  if (iVar4 != 0) {
    iVar4 = 0;
    do {
      pcVar1 = s_EST__TOP_SPEED_005c3f38 + iVar4;
      (&DAT_005ec4cc)[iVar4] = *pcVar1;
      iVar4 = iVar4 + 1;
    } while (*pcVar1 != '\0');
  }
  iVar4 = 0;
  do {
    cVar2 = (&DAT_005ec4cc)[iVar4];
    local_108[iVar4] = cVar2;
    iVar4 = iVar4 + 1;
  } while (cVar2 != '\0');
  FUN_0058815f(param_1 + 0x1a26,&DAT_005be860,local_108,local_88);
  local_128 = 0.0;
  fVar7 = (float10)FUN_00430a50(0,0);
  if (fVar7 < (float10)_DAT_0059e430 == (fVar7 == (float10)_DAT_0059e430)) {
    do {
      local_128 = local_128 + _DAT_0059eaa0;
      fVar7 = (float10)FUN_00430a50(local_128);
    } while (fVar7 < (float10)_DAT_0059e430 == (fVar7 == (float10)_DAT_0059e430));
  }
  dVar3 = _DAT_0059ea90;
  if (DAT_007d0474 != '\0') {
    dVar3 = _DAT_0059ea98;
  }
  FUN_0058815f(param_1 + 0x1ba6,s__d__s_005c3778,(int)ROUND(local_128 * dVar3),local_c8);
  fVar7 = (float10)FUN_00430750(0,0x4052c000);
  iVar4 = FUN_00423a00(s_EST__CORNERING_005c3f28,&DAT_005ec4cc);
  if (iVar4 != 0) {
    iVar4 = 0;
    do {
      pcVar1 = s_EST__CORNERING_005c3f28 + iVar4;
      (&DAT_005ec4cc)[iVar4] = *pcVar1;
      iVar4 = iVar4 + 1;
    } while (*pcVar1 != '\0');
  }
  iVar4 = 0;
  do {
    cVar2 = (&DAT_005ec4cc)[iVar4];
    local_108[iVar4] = cVar2;
    iVar4 = iVar4 + 1;
  } while (cVar2 != '\0');
  iVar4 = FUN_00423a00(&DAT_005c3f24,&DAT_005ec4cc);
  if (iVar4 != 0) {
    iVar4 = 0;
    do {
      pcVar1 = &DAT_005c3f24 + iVar4;
      (&DAT_005ec4cc)[iVar4] = *pcVar1;
      iVar4 = iVar4 + 1;
    } while (*pcVar1 != '\0');
  }
  iVar4 = 0;
  do {
    cVar2 = (&DAT_005ec4cc)[iVar4];
    local_48[iVar4] = cVar2;
    iVar4 = iVar4 + 1;
  } while (cVar2 != '\0');
  FUN_0058815f(param_1 + 0x1aa6,&DAT_005be860,local_108,local_88);
  FUN_0058815f(param_1 + 0x1c26,s___2f__s_005c3820,(double)fVar7 * _DAT_0059ea88,local_48);
  return;
}


