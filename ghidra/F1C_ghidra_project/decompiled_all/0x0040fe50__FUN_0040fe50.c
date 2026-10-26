// Function: FUN_0040fe50 @ 0040fe50
// Strings:  [WHEEL, DSCONE, DSINDICATOR, DSINDICATOR, DSPOLY, DSPOLY]


void FUN_0040fe50(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *extraout_ECX;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  
  FUN_005881c0();
  iVar9 = 0x68;
  extraout_ECX[3] = 0x68;
  puVar1 = operator_new(0xea4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar7 = (undefined4 *)0x0;
  }
  else {
    puVar7 = puVar1 + 1;
    *puVar1 = 0x68;
    do {
      FUN_0040e6d0();
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  iVar9 = 0;
  extraout_ECX[4] = puVar7;
  if (0 < (int)extraout_ECX[3]) {
    do {
      FUN_0040e860();
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)extraout_ECX[3]);
  }
  iVar9 = FUN_005452f0();
  iVar8 = 0;
  extraout_ECX[0x18] = 0;
  extraout_ECX[0x15] = 0;
  extraout_ECX[0x12] = 0;
  extraout_ECX[0xf] = 0;
  extraout_ECX[0xc] = 0;
  extraout_ECX[9] = 0;
  extraout_ECX[5] = 0;
  extraout_ECX[7] = 0;
  pvVar2 = operator_new(iVar9 * 4 + 4);
  if (0 < iVar9) {
    do {
      iVar3 = FUN_00545340();
      if (((byte)*(undefined4 *)(iVar3 + 0x3c) & 0x10) == 0x10) {
        FUN_0054bda0();
        iVar4 = _strncmp(&stack0x00000004,s_DSPOLY_005beba4,6);
        if (iVar4 == 0) {
          iVar4 = extraout_ECX[5];
          *(int *)(&stack0x00000084 + iVar4 * 4) = iVar3;
          extraout_ECX[5] = iVar4 + 1;
        }
        iVar4 = _strncmp(&stack0x00000004,s_DSINDICATOR_005beb98,0xb);
        if (iVar4 == 0) {
          iVar4 = extraout_ECX[5];
          *(int *)(&stack0x00000084 + iVar4 * 4) = iVar3;
          extraout_ECX[5] = iVar4 + 1;
        }
        iVar4 = _strncmp(&stack0x00000004,s_DSCONE_005beb90,6);
        if (iVar4 == 0) {
          iVar4 = extraout_ECX[9];
          *(int *)(&stack0x00000484 + iVar4 * 4) = iVar3;
          extraout_ECX[9] = iVar4 + 1;
        }
        iVar4 = _strncmp(&stack0x00000004,&DAT_005beb88,4);
        if (iVar4 == 0) {
          iVar4 = extraout_ECX[9];
          *(int *)(&stack0x00000484 + iVar4 * 4) = iVar3;
          extraout_ECX[9] = iVar4 + 1;
        }
        iVar4 = _strncmp(&stack0x00000004,&DAT_005beb80,4);
        if (iVar4 == 0) {
          iVar4 = extraout_ECX[0xc];
          *(int *)(&stack0x00000c84 + iVar4 * 4) = iVar3;
          extraout_ECX[0xc] = iVar4 + 1;
        }
        iVar4 = _strncmp(&stack0x00000004,&DAT_005beb78,4);
        if (iVar4 == 0) {
          iVar4 = extraout_ECX[0xf];
          *(int *)(&stack0x00001484 + iVar4 * 4) = iVar3;
          extraout_ECX[0xf] = iVar4 + 1;
        }
        iVar4 = _strncmp(&stack0x00000004,s_WHEEL_005beb70,5);
        if (iVar4 == 0) {
          iVar4 = extraout_ECX[0x12];
          *(int *)(&stack0x00000884 + iVar4 * 4) = iVar3;
          extraout_ECX[0x12] = iVar4 + 1;
        }
        iVar4 = _strncmp(&stack0x00000004,&DAT_005beb68,4);
        if (iVar4 == 0) {
          iVar4 = extraout_ECX[0x15];
          *(int *)(&stack0x00001084 + iVar4 * 4) = iVar3;
          extraout_ECX[0x15] = iVar4 + 1;
        }
        iVar4 = _strncmp(&stack0x00000004,&DAT_005beb60,4);
        if (iVar4 == 0) {
          iVar4 = extraout_ECX[0x18];
          *(int *)(&stack0x00001884 + iVar4 * 4) = iVar3;
          extraout_ECX[0x18] = iVar4 + 1;
        }
        FUN_0054fb40();
      }
      else {
        FUN_0054bda0();
        iVar4 = _strncmp(&stack0x00000044,s_DSPOLY_005beba4,6);
        if (iVar4 == 0) {
          iVar4 = extraout_ECX[5];
          *(int *)(&stack0x00000084 + iVar4 * 4) = iVar3;
          extraout_ECX[5] = iVar4 + 1;
        }
        else {
          iVar4 = _strncmp(&stack0x00000044,s_DSINDICATOR_005beb98,0xb);
          if (iVar4 == 0) {
            iVar4 = extraout_ECX[5];
            *(int *)(&stack0x00000084 + iVar4 * 4) = iVar3;
            extraout_ECX[5] = iVar4 + 1;
          }
          else {
            iVar4 = FUN_0054fb70();
            if ((((iVar4 != 0) && (iVar3 != DAT_008ad074)) && (iVar3 != DAT_008ad078)) &&
               (((iVar3 != DAT_008ad07c && (iVar3 != DAT_008ad080)) && (iVar3 != DAT_008ad084)))) {
              *(int *)((int)pvVar2 + extraout_ECX[7] * 4) = iVar3;
              extraout_ECX[7] = extraout_ECX[7] + 1;
            }
          }
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar9);
  }
  extraout_ECX[0x12] = extraout_ECX[0x12] + 0x1a0;
  extraout_ECX[0x15] = extraout_ECX[0x15] + 0xd0;
  extraout_ECX[0x18] = extraout_ECX[0x18] + 0x340;
  if (DAT_008ad074 != 0) {
    iVar9 = extraout_ECX[5];
    *(int *)(&stack0x00000084 + iVar9 * 4) = DAT_008ad074;
    extraout_ECX[5] = iVar9 + 1;
  }
  if (DAT_008ad078 != 0) {
    iVar9 = extraout_ECX[5];
    *(int *)(&stack0x00000084 + iVar9 * 4) = DAT_008ad078;
    extraout_ECX[5] = iVar9 + 1;
  }
  if (DAT_008ad07c != 0) {
    iVar9 = extraout_ECX[5];
    *(int *)(&stack0x00000084 + iVar9 * 4) = DAT_008ad07c;
    extraout_ECX[5] = iVar9 + 1;
  }
  if (DAT_008ad080 != 0) {
    iVar9 = extraout_ECX[5];
    *(int *)(&stack0x00000084 + iVar9 * 4) = DAT_008ad080;
    extraout_ECX[5] = iVar9 + 1;
  }
  if (DAT_008ad084 != 0) {
    iVar9 = extraout_ECX[5];
    *(int *)(&stack0x00000084 + iVar9 * 4) = DAT_008ad084;
    extraout_ECX[5] = iVar9 + 1;
  }
  iVar9 = extraout_ECX[5];
  piVar5 = operator_new(iVar9 * 0x24 + 4);
  if (piVar5 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = piVar5 + 1;
    *piVar5 = iVar9;
    if (-1 < iVar9 + -1) {
      do {
        FUN_0040e6d0();
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  iVar9 = 0;
  extraout_ECX[6] = piVar6;
  if (0 < (int)extraout_ECX[5]) {
    do {
      FUN_0040e880();
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)extraout_ECX[5]);
  }
  iVar9 = extraout_ECX[7];
  piVar5 = operator_new(iVar9 * 0x24 + 4);
  if (piVar5 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = piVar5 + 1;
    *piVar5 = iVar9;
    if (-1 < iVar9 + -1) {
      do {
        FUN_0040e6d0();
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  iVar9 = 0;
  extraout_ECX[8] = piVar6;
  if (0 < (int)extraout_ECX[7]) {
    do {
      FUN_0040e8b0();
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)extraout_ECX[7]);
  }
  FUN_00587bcf();
  iVar9 = extraout_ECX[9];
  piVar5 = operator_new(iVar9 * 0x24 + 4);
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    *piVar5 = iVar9;
    piVar5 = piVar5 + 1;
    if (-1 < iVar9 + -1) {
      do {
        FUN_0040e6d0();
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  iVar9 = extraout_ECX[9];
  extraout_ECX[10] = piVar5;
  piVar5 = operator_new(iVar9 * 0x318 + 4);
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    *piVar5 = iVar9;
    piVar5 = piVar5 + 1;
    piVar6 = piVar5;
    if (-1 < iVar9 + -1) {
      do {
        FUN_00568e30();
        *piVar6 = (int)&PTR_LAB_0059e720;
        FUN_004594d0();
        *piVar6 = (int)&PTR_LAB_0059e768;
        iVar9 = iVar9 + -1;
        piVar6 = piVar6 + 0xc6;
      } while (iVar9 != 0);
    }
  }
  extraout_ECX[0xb] = piVar5;
  iVar9 = 0;
  if (0 < (int)extraout_ECX[9]) {
    do {
      FUN_0040e8f0();
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)extraout_ECX[9]);
  }
  iVar9 = extraout_ECX[0xc];
  piVar5 = operator_new(iVar9 * 0x24 + 4);
  if (piVar5 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = piVar5 + 1;
    *piVar5 = iVar9;
    if (-1 < iVar9 + -1) {
      do {
        FUN_0040e6d0();
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  iVar9 = extraout_ECX[0xc];
  extraout_ECX[0xd] = piVar6;
  piVar5 = operator_new(iVar9 * 0x318 + 4);
  if (piVar5 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = piVar5 + 1;
    *piVar5 = iVar9;
    piVar5 = piVar6;
    if (-1 < iVar9 + -1) {
      do {
        FUN_00568e30();
        *piVar5 = (int)&PTR_LAB_0059e720;
        FUN_004594d0();
        *piVar5 = (int)&PTR_LAB_0059e75c;
        iVar9 = iVar9 + -1;
        piVar5 = piVar5 + 0xc6;
      } while (iVar9 != 0);
    }
  }
  extraout_ECX[0xe] = piVar6;
  iVar9 = 0;
  if (0 < (int)extraout_ECX[0xc]) {
    do {
      FUN_0040e990();
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)extraout_ECX[0xc]);
  }
  iVar9 = extraout_ECX[0xf];
  piVar5 = operator_new(iVar9 * 0x24 + 4);
  if (piVar5 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = piVar5 + 1;
    *piVar5 = iVar9;
    if (-1 < iVar9 + -1) {
      do {
        FUN_0040e6d0();
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  iVar9 = extraout_ECX[0xf];
  extraout_ECX[0x10] = piVar6;
  piVar5 = operator_new(iVar9 * 0x318 + 4);
  if (piVar5 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = piVar5 + 1;
    *piVar5 = iVar9;
    piVar5 = piVar6;
    if (-1 < iVar9 + -1) {
      do {
        FUN_00568e30();
        *piVar5 = (int)&PTR_LAB_0059e720;
        FUN_004594d0();
        *piVar5 = (int)&PTR_LAB_0059e750;
        iVar9 = iVar9 + -1;
        piVar5 = piVar5 + 0xc6;
      } while (iVar9 != 0);
    }
  }
  extraout_ECX[0x11] = piVar6;
  iVar9 = 0;
  if (0 < (int)extraout_ECX[0xf]) {
    do {
      FUN_0040ea30();
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)extraout_ECX[0xf]);
  }
  iVar9 = extraout_ECX[0x12];
  piVar5 = operator_new(iVar9 * 0x24 + 4);
  if (piVar5 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = piVar5 + 1;
    *piVar5 = iVar9;
    if (-1 < iVar9 + -1) {
      do {
        FUN_0040e6d0();
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  iVar9 = extraout_ECX[0x12];
  extraout_ECX[0x13] = piVar6;
  piVar5 = operator_new(iVar9 * 0x328 + 4);
  if (piVar5 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = piVar5 + 1;
    *piVar5 = iVar9;
    piVar5 = piVar6;
    if (-1 < iVar9 + -1) {
      do {
        FUN_00568e30();
        *piVar5 = (int)&PTR_LAB_0059e720;
        FUN_004594d0();
        *piVar5 = (int)&PTR_LAB_0059e744;
        iVar9 = iVar9 + -1;
        piVar5 = piVar5 + 0xca;
      } while (iVar9 != 0);
    }
  }
  extraout_ECX[0x14] = piVar6;
  iVar9 = 0;
  if (0 < (int)extraout_ECX[0x12]) {
    do {
      FUN_0040eb30();
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)extraout_ECX[0x12]);
  }
  iVar9 = extraout_ECX[0x15];
  piVar5 = operator_new(iVar9 * 0x24 + 4);
  if (piVar5 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = piVar5 + 1;
    *piVar5 = iVar9;
    if (-1 < iVar9 + -1) {
      do {
        FUN_0040e6d0();
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  iVar9 = extraout_ECX[0x15];
  extraout_ECX[0x16] = piVar6;
  piVar5 = operator_new(iVar9 * 0x318 + 4);
  if (piVar5 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = piVar5 + 1;
    *piVar5 = iVar9;
    piVar5 = piVar6;
    if (-1 < iVar9 + -1) {
      do {
        FUN_00568e30();
        *piVar5 = (int)&PTR_LAB_0059e720;
        FUN_004594d0();
        *piVar5 = (int)&PTR_LAB_0059e738;
        iVar9 = iVar9 + -1;
        piVar5 = piVar5 + 0xc6;
      } while (iVar9 != 0);
    }
  }
  extraout_ECX[0x17] = piVar6;
  iVar9 = 0;
  if (0 < (int)extraout_ECX[0x15]) {
    do {
      FUN_0040ebd0();
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)extraout_ECX[0x15]);
  }
  iVar9 = extraout_ECX[0x18];
  piVar5 = operator_new(iVar9 * 0x24 + 4);
  if (piVar5 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = piVar5 + 1;
    *piVar5 = iVar9;
    if (-1 < iVar9 + -1) {
      do {
        FUN_0040e6d0();
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  iVar9 = extraout_ECX[0x18];
  extraout_ECX[0x19] = piVar6;
  piVar5 = operator_new(iVar9 * 0x318 + 4);
  if (piVar5 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = piVar5 + 1;
    *piVar5 = iVar9;
    piVar5 = piVar6;
    if (-1 < iVar9 + -1) {
      do {
        FUN_00568e30();
        *piVar5 = (int)&PTR_LAB_0059e720;
        FUN_004594d0();
        *piVar5 = (int)&PTR_LAB_0059e72c;
        iVar9 = iVar9 + -1;
        piVar5 = piVar5 + 0xc6;
      } while (iVar9 != 0);
    }
  }
  extraout_ECX[0x1a] = piVar6;
  iVar9 = 0;
  if (0 < (int)extraout_ECX[0x18]) {
    do {
      FUN_0040ec70();
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)extraout_ECX[0x18]);
  }
  iVar9 = extraout_ECX[3] +
          extraout_ECX[0x18] + extraout_ECX[0x12] + extraout_ECX[0xc] + extraout_ECX[5] +
          extraout_ECX[0x15] + extraout_ECX[0xf] + extraout_ECX[9];
  *extraout_ECX = 0;
  extraout_ECX[1] = iVar9;
  pvVar2 = operator_new(iVar9 * 4);
  extraout_ECX[2] = pvVar2;
  return;
}


