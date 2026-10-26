// Function: FUN_004f9480 @ 004f9480
// Strings:  [FTIM18WHT, FTIM18WHT, loading..., FTIM28WHT, FTIM28WHT, logo_LOD.bmp, df_LOD2.bmp, _LOD_2.jpg]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004f9480(int param_1,float param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  float10 fVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined8 uVar15;
  float local_208;
  undefined4 local_204;
  char local_200 [4];
  undefined1 local_1fc [252];
  char local_100 [256];
  
  if (param_1 != 0) {
    pcVar2 = DAT_007ce5d0;
    if (DAT_007ce5d0 == (char *)0x0) {
      pcVar2 = &DAT_005ea438;
    }
    iVar6 = -(int)pcVar2;
    do {
      cVar1 = *pcVar2;
      pcVar2[(int)(local_200 + iVar6)] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uVar5 = 0xffffffff;
    pcVar2 = local_200;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = local_200 + (~uVar5 - 1);
    if (local_200 < pcVar2) {
      do {
        if (*pcVar2 == '.') {
          *pcVar2 = '\0';
          break;
        }
        pcVar2 = pcVar2 + -1;
      } while (local_200 < pcVar2);
    }
    uVar5 = 0xffffffff;
    pcVar2 = local_200;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    cVar1 = local_200[~uVar5 - 1];
    DAT_008afebc = -999;
    uVar5 = ~uVar5;
    while (cVar1 != '\\') {
      cVar1 = local_200[uVar5 - 2];
      uVar5 = uVar5 - 1;
    }
    local_1fc[uVar5] = 0;
    iVar6 = -1;
    pcVar2 = local_200;
    do {
      pcVar8 = pcVar2;
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      pcVar8 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar8;
    } while (cVar1 != '\0');
    *(undefined4 *)(pcVar8 + -1) = DAT_005d6e44;
    *(undefined4 *)(pcVar8 + 3) = DAT_005d6e48;
    pcVar8[7] = DAT_005d6e4c;
    iVar6 = FUN_0053cb20(&DAT_008afeb0,local_200,0,1);
    if ((iVar6 == 0) || (iVar6 = FUN_0053cb20(&DAT_008afeb0,s_df_LOD_bmp_005d6e38,0,1), iVar6 == 0))
    {
      if (DAT_008afeb0 != 0) {
        uVar3 = *(undefined4 *)(DAT_008afeb0 + 0x20);
        uVar11 = *(undefined4 *)(DAT_008afeb0 + 0x1c);
        uVar14 = 0;
        uVar13 = 0xffffffff;
        uVar12 = 0;
        uVar10 = 0;
        uVar4 = FUN_00495150(0,0,uVar11,uVar3,0xffffffff,0);
        FUN_00543250(0,0,uVar4,uVar10,uVar12,uVar11,uVar3,uVar13,uVar14);
        uVar12 = 0;
        uVar10 = 0x66;
        uVar4 = 800;
        uVar11 = 0;
        uVar3 = 0;
        FUN_00495150(0,0,800,0x66,0);
        FUN_00543440(uVar3,uVar11,uVar4,uVar10,uVar12);
        FUN_00495080();
        uVar3 = *(undefined4 *)(DAT_008afeb0 + 0x20);
        uVar11 = *(undefined4 *)(DAT_008afeb0 + 0x1c);
        uVar14 = 0;
        uVar13 = 0xffffffff;
        uVar12 = 0;
        uVar10 = 0;
        uVar4 = FUN_00495150(0,0,uVar11,uVar3,0xffffffff,0);
        FUN_00543250(0,0,uVar4,uVar10,uVar12,uVar11,uVar3,uVar13,uVar14);
        uVar12 = 0;
        uVar10 = 0x66;
        uVar4 = 800;
        uVar11 = 0;
        uVar3 = 0;
        FUN_00495150(0,0,800,0x66,0);
        FUN_00543440(uVar3,uVar11,uVar4,uVar10,uVar12);
      }
    }
    else {
      DAT_008afeb0 = 0;
    }
    uVar5 = 0xffffffff;
    pcVar2 = local_200;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    cVar1 = local_200[~uVar5 - 1];
    uVar5 = ~uVar5;
    while (cVar1 != '\\') {
      cVar1 = local_200[uVar5 - 2];
      uVar5 = uVar5 - 1;
    }
    local_1fc[uVar5] = 0;
    iVar6 = -1;
    pcVar2 = local_200;
    do {
      pcVar8 = pcVar2;
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      pcVar8 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar8;
    } while (cVar1 != '\0');
    *(undefined4 *)(pcVar8 + -1) = DAT_005d6e2c;
    *(undefined4 *)(pcVar8 + 3) = DAT_005d6e30;
    *(undefined2 *)(pcVar8 + 7) = DAT_005d6e34;
    pcVar8[9] = DAT_005d6e36;
    iVar6 = FUN_0053cb20(&DAT_008afeb4,local_200,0,1);
    if ((iVar6 != 0) && (iVar6 = FUN_0053cb20(&DAT_008afeb4,s_df_LOD2_bmp_005d6e20,0,1), iVar6 != 0)
       ) {
      DAT_008afeb4 = 0;
    }
    iVar6 = FUN_0053cb20(&DAT_008afeb8,s_logo_LOD_bmp_005d6e10,0,1);
    if (iVar6 != 0) {
      DAT_008afeb8 = 0;
    }
    if (DAT_007cf29c == '\x01') {
      if (DAT_005eb10c != (int *)0x0) {
        (**(code **)(*DAT_005eb10c + 0xc))();
      }
      FUN_004186a0();
      FUN_0041c4c0(1);
      FUN_004186f0();
    }
    local_204 = 0;
    local_208 = 0.0;
    FUN_004c5920(local_100,0xff);
    FUN_00589901(local_100);
    iVar6 = FUN_00423a00(local_100,&DAT_005ec4cc);
    if (iVar6 != 0) {
      iVar6 = 0;
      do {
        cVar1 = local_100[iVar6];
        (&DAT_005ec4cc)[iVar6] = cVar1;
        iVar6 = iVar6 + 1;
      } while (cVar1 != '\0');
    }
    FUN_0053d310(s_FTIM28WHT_005d6e04,&DAT_005ec4cc,&local_204,&local_208);
    iVar7 = 0x30c - local_204;
    iVar6 = FUN_00423a00(local_100,&DAT_005ec4cc);
    if (iVar6 != 0) {
      iVar6 = 0;
      do {
        cVar1 = local_100[iVar6];
        (&DAT_005ec4cc)[iVar6] = cVar1;
        iVar6 = iVar6 + 1;
      } while (cVar1 != '\0');
    }
    uVar3 = FUN_00495150();
    FUN_0053d2e0(s_FTIM28WHT_005d6e04,&DAT_005ec4cc,iVar7,0x75,uVar3);
    iVar6 = 0;
    do {
      cVar1 = s_loading____005d6df8[iVar6];
      local_100[iVar6] = cVar1;
      iVar6 = iVar6 + 1;
    } while (cVar1 != '\0');
    iVar6 = FUN_00423a00(local_100,&DAT_005ec4cc);
    if (iVar6 != 0) {
      iVar6 = 0;
      do {
        cVar1 = local_100[iVar6];
        (&DAT_005ec4cc)[iVar6] = cVar1;
        iVar6 = iVar6 + 1;
      } while (cVar1 != '\0');
    }
    FUN_0053d310(s_FTIM18WHT_005d6dec,&DAT_005ec4cc,&local_204,&local_208);
    iVar7 = 0x30c - local_204;
    iVar6 = FUN_00423a00(local_100,&DAT_005ec4cc);
    if (iVar6 != 0) {
      iVar6 = 0;
      do {
        cVar1 = local_100[iVar6];
        (&DAT_005ec4cc)[iVar6] = cVar1;
        iVar6 = iVar6 + 1;
      } while (cVar1 != '\0');
    }
    uVar3 = FUN_00495150();
    FUN_0053d2e0(s_FTIM18WHT_005d6dec,&DAT_005ec4cc,iVar7,0x203,uVar3);
  }
  fVar9 = (float10)FUN_005895a2((double)((float)DAT_005c329c * _DAT_0059e8a4 + _DAT_0059e9d4));
  if (fVar9 < (float10)param_2 == (fVar9 == (float10)param_2)) {
    FUN_0044f150();
    cVar1 = FUN_0044f460();
    if (cVar1 != '\0') {
      if (DAT_005eb10c != (int *)0x0) {
        (**(code **)(*DAT_005eb10c + 0xc))();
      }
      FUN_004186a0();
    }
    local_208 = param_2 * _DAT_005ad270;
    FUN_005895a2((double)((float)DAT_005c329c * _DAT_0059e8a4 + _DAT_0059e9d4));
    iVar6 = __ftol();
    if (DAT_008afebc + 3 <= iVar6) {
      DAT_008afebc = iVar6;
      if (DAT_008afeb0 != 0) {
        uVar15 = 0xffffffff;
        uVar10 = 0x66;
        uVar4 = 0;
        uVar11 = 0;
        iVar7 = iVar6;
        uVar3 = FUN_00495150(0,0,iVar6,0x66,0xffffffff,0);
        FUN_00543250(0,0,uVar3,uVar11,uVar4,iVar7,uVar10,uVar15);
        FUN_004a1830();
      }
      uVar15 = 0x66;
      iVar7 = 800 - iVar6;
      uVar3 = 0;
      FUN_00495150(iVar6,0,iVar7,0x66,0);
      FUN_00543440(iVar6,uVar3,iVar7,uVar15);
      if (DAT_008afeb8 != 0) {
        uVar3 = *(undefined4 *)(DAT_008afeb8 + 0x20);
        uVar11 = *(undefined4 *)(DAT_008afeb8 + 0x1c);
        uVar15 = 0;
        uVar12 = 0;
        uVar10 = 0;
        uVar4 = FUN_00495150(0,0,uVar11,uVar3,0,0);
        FUN_00543250(0,0,uVar4,uVar10,uVar12,uVar11,uVar3,uVar15);
      }
      FUN_00495080();
    }
    FUN_004c88a0();
    FUN_00556730();
    FUN_004c8650();
  }
  else {
    if (DAT_008afeb4 != 0) {
      uVar3 = *(undefined4 *)(DAT_008afeb4 + 0x20);
      uVar11 = *(undefined4 *)(DAT_008afeb4 + 0x1c);
      uVar15 = 0xffffffff;
      uVar12 = 0;
      uVar10 = 0;
      uVar4 = FUN_00495150(0,0,uVar11,uVar3,0xffffffff,0);
      FUN_00543250(0,0,uVar4,uVar10,uVar12,uVar11,uVar3,uVar15);
      FUN_00495080();
      FUN_0053cb90();
      DAT_008afeb4 = 0;
    }
    if (DAT_008afeb0 != 0) {
      FUN_0053cb90();
      DAT_008afeb0 = 0;
    }
    if (DAT_008afeb8 != 0) {
      FUN_0053cb90();
      DAT_008afeb8 = 0;
    }
    FUN_004c8d90();
  }
  FUN_004970e0();
  return 0;
}


