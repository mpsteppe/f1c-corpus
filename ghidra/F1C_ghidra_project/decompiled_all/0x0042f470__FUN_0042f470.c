// Function: FUN_0042f470 @ 0042f470
// Strings:  [Unknown, Unknown, bevel, bevel, %.1f %s, %.1f %s, %d %s, %.3f %s]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0042f470(int param_1,int param_2)

{
  double *pdVar1;
  char cVar2;
  double dVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  float10 fVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  char *pcVar13;
  undefined *puVar14;
  undefined1 *puVar15;
  undefined1 local_48 [68];
  
  pdVar1 = (double *)(param_2 * 0x40 + 0xbb0 + param_1);
  switch(param_2) {
  case 0:
    iVar5 = FUN_00423a00(s_Unknown_005c307c,&DAT_005ec4cc);
    if (iVar5 != 0) {
      iVar5 = 0;
      do {
        pcVar13 = s_Unknown_005c307c + iVar5;
        (&DAT_005ec4cc)[iVar5] = *pcVar13;
        iVar5 = iVar5 + 1;
      } while (*pcVar13 != '\0');
    }
    iVar5 = (int)pdVar1 + 0x1e;
    FUN_0058815f(iVar5,&DAT_005ec4cc);
    iVar6 = FUN_004d7880(param_1 + 0x70);
    if (iVar6 == 0) {
      return;
    }
    puVar4 = (undefined4 *)FUN_004d7570(*(undefined4 *)((int)pdVar1 + 0x14));
    if (puVar4 == (undefined4 *)0x0) {
      return;
    }
    pcVar13 = (char *)*puVar4;
    if (pcVar13 == (char *)0x0) {
      pcVar13 = &DAT_005ea438;
    }
    iVar6 = FUN_00423a00(pcVar13,&DAT_005ec4cc);
    if (iVar6 != 0) {
      if (pcVar13 != (char *)0x0) {
        iVar6 = (int)&DAT_005ec4cc - (int)pcVar13;
        do {
          cVar2 = *pcVar13;
          pcVar13[iVar6] = cVar2;
          pcVar13 = pcVar13 + 1;
        } while (cVar2 != '\0');
        FUN_0058815f(iVar5,&DAT_005ec4cc);
        return;
      }
      DAT_005ec4cc = 0;
    }
    FUN_0058815f(iVar5,&DAT_005ec4cc);
    return;
  case 1:
  case 2:
  case 0x1f:
    dVar3 = ((double)*(int *)((int)pdVar1 + 0x14) * pdVar1[1] + *pdVar1) * _DAT_0059ea20;
    FUN_0058815f((int)pdVar1 + 0x1e,s__4_1f__4_1f_005c3814,_DAT_0059ea20 - dVar3,dVar3);
    return;
  case 3:
    dVar3 = (double)*(int *)((int)pdVar1 + 0x14) * pdVar1[1] + *pdVar1;
    iVar5 = FUN_00423a00(s_turns_005c3828,&DAT_005ec4cc);
    if (iVar5 != 0) {
      iVar5 = 0;
      do {
        pcVar13 = s_turns_005c3828 + iVar5;
        (&DAT_005ec4cc)[iVar5] = *pcVar13;
        iVar5 = iVar5 + 1;
      } while (*pcVar13 != '\0');
    }
    puVar15 = &DAT_005ec4cc;
    goto LAB_0042f5c5;
  case 4:
  case 0x34:
  case 0x35:
  case 0x36:
    if (param_2 == 0x34) {
      bVar9 = SBORROW4(*(int *)(param_1 + 0x1884),1);
      iVar5 = *(int *)(param_1 + 0x1884) + -1;
LAB_0042f632:
      if (bVar9 == iVar5 < 0) {
LAB_0042f638:
        dVar3 = (double)*(int *)((int)pdVar1 + 0x14) * pdVar1[1] + *pdVar1;
        if (*(double *)(param_1 + 0x1994) == _DAT_0059e430) {
          iVar5 = FUN_00423a00(&DAT_005c3810,&DAT_005ec4cc);
          if (iVar5 != 0) {
            iVar5 = 0;
            do {
              pcVar13 = &DAT_005c3810 + iVar5;
              (&DAT_005ec4cc)[iVar5] = *pcVar13;
              iVar5 = iVar5 + 1;
            } while (*pcVar13 != '\0');
          }
          FUN_0058815f(local_48,&DAT_005c3808,&DAT_005ec4cc);
        }
        else {
          iVar5 = __ftol();
          if (iVar5 == 1) {
            iVar5 = FUN_00423a00(&DAT_005c3804,&DAT_005ec4cc);
            if (iVar5 != 0) {
              iVar5 = 0;
              do {
                pcVar13 = &DAT_005c3804 + iVar5;
                (&DAT_005ec4cc)[iVar5] = *pcVar13;
                iVar5 = iVar5 + 1;
              } while (*pcVar13 != '\0');
            }
            FUN_0058815f(local_48,s__1__s__005c37fc,&DAT_005ec4cc);
          }
          else {
            iVar6 = FUN_00423a00(&DAT_005c37f4,&DAT_005ec4cc);
            if (iVar6 != 0) {
              iVar6 = 0;
              do {
                pcVar13 = &DAT_005c37f4 + iVar6;
                (&DAT_005ec4cc)[iVar6] = *pcVar13;
                iVar6 = iVar6 + 1;
              } while (*pcVar13 != '\0');
            }
            FUN_0058815f(local_48,s___d__s__005c37ec,iVar5,&DAT_005ec4cc);
          }
        }
        if (*(int *)(param_1 + 4) == 1) {
          FUN_0058815f((int)pdVar1 + 0x1e,s__4_1f__s__s_005c37e0,dVar3 * _DAT_0059ea40,
                       param_1 + 0x58,local_48);
          return;
        }
        FUN_0058815f((int)pdVar1 + 0x1e,s__d__s__s_005c37d4,(int)ROUND(dVar3),param_1 + 0x58,
                     local_48);
        return;
      }
    }
    else {
      if (param_2 == 0x35) {
        bVar9 = SBORROW4(*(int *)(param_1 + 0x1884),2);
        iVar5 = *(int *)(param_1 + 0x1884) + -2;
        goto LAB_0042f632;
      }
      if ((param_2 != 0x36) || (2 < *(int *)(param_1 + 0x1884))) goto LAB_0042f638;
    }
    iVar5 = FUN_00423a00(&DAT_005c3810,&DAT_005ec4cc);
    if (iVar5 != 0) {
      iVar5 = 0;
      do {
        pcVar13 = &DAT_005c3810 + iVar5;
        (&DAT_005ec4cc)[iVar5] = *pcVar13;
        iVar5 = iVar5 + 1;
      } while (*pcVar13 != '\0');
    }
    goto LAB_0042fc54;
  case 5:
  case 6:
    if (*(char *)(param_1 + 0x1989) == '\0') {
      dVar3 = ((double)*(int *)((int)pdVar1 + 0x14) * pdVar1[1] + *pdVar1) * _DAT_0059ea20;
      if (*(int *)(param_1 + 4) == 0) {
        FUN_0058815f((int)pdVar1 + 0x1e,s___2f__s_005c3820,dVar3,param_1 + 0x18);
        return;
      }
      FUN_0058815f((int)pdVar1 + 0x1e,s___3f__s_005c3780,dVar3 * _DAT_0059ea18,param_1 + 0x18);
      return;
    }
  case 0x10:
  case 0x16:
    FUN_0042f180(pdVar1);
    return;
  case 7:
  case 8:
    puVar15 = (undefined1 *)(param_1 + 0x28);
    dVar3 = ((double)*(int *)((int)pdVar1 + 0x14) * pdVar1[1] + *pdVar1) * _DAT_0059ea30;
LAB_0042f5c5:
    pcVar13 = s___2f__s_005c3820;
LAB_0042f5ca:
    FUN_0058815f((int)pdVar1 + 0x1e,pcVar13,dVar3,puVar15);
    return;
  case 9:
  case 10:
    dVar3 = ((double)*(int *)((int)pdVar1 + 0x14) * pdVar1[1] + *pdVar1) * _DAT_0059ea20;
    if (*(int *)(param_1 + 4) == 0) {
      FUN_0058815f((int)pdVar1 + 0x1e,s___1f__s_005c36f4,dVar3,param_1 + 0x18);
      return;
    }
    FUN_0058815f((int)pdVar1 + 0x1e,s___2f__s_005c3820,dVar3 * _DAT_0059ea18,param_1 + 0x18);
    return;
  case 0xb:
  case 0xc:
  case 0x22:
    puVar15 = (undefined1 *)(param_1 + 0x28);
    dVar3 = ((double)*(int *)((int)pdVar1 + 0x14) * pdVar1[1] + *pdVar1) * _DAT_0059ea30;
    pcVar13 = s___1f__s_005c36f4;
    goto LAB_0042f5ca;
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x15:
    FUN_0042f260(pdVar1,0,0);
    return;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
    FUN_0042f1e0(pdVar1);
    return;
  case 0x1b:
  case 0x1c:
    if ((*(byte *)(param_1 + 0x198c) & 1) == 0) {
      FUN_0058815f((int)pdVar1 + 0x1e,s__d__s_005c3778,
                   (int)ROUND((double)*(int *)((int)pdVar1 + 0x14) * pdVar1[1] + *pdVar1),
                   param_1 + 0x28);
      return;
    }
    puVar15 = (undefined1 *)(*(int *)((int)pdVar1 + 0x14) + 1);
    puVar14 = &DAT_005c3280;
    break;
  case 0x1d:
    if ((*(byte *)(param_1 + 0x198c) & 2) == 0) {
      puVar15 = (undefined1 *)
                (int)ROUND(_DAT_0059ea20 -
                           ((double)*(int *)((int)pdVar1 + 0x14) * pdVar1[1] + *pdVar1));
      puVar14 = &DAT_005c37cc;
    }
    else {
      puVar15 = (undefined1 *)(*(int *)((int)pdVar1 + 0x14) + 1);
      puVar14 = &DAT_005c3280;
    }
    break;
  case 0x1e:
  case 0x26:
  case 0x28:
    puVar15 = (undefined1 *)(*(int *)((int)pdVar1 + 0x14) + 1);
    puVar14 = &DAT_005c3280;
    break;
  case 0x20:
  case 0x21:
    puVar15 = (undefined1 *)
              (int)ROUND(((double)*(int *)((int)pdVar1 + 0x14) * pdVar1[1] + *pdVar1) *
                         _DAT_0059ea20);
    puVar14 = &DAT_005c37cc;
    break;
  case 0x23:
  case 0x24:
  case 0x25:
    puVar15 = (undefined1 *)
              (int)ROUND(((double)*(int *)((int)pdVar1 + 0x14) * pdVar1[1] + *pdVar1) *
                         _DAT_0059ea20);
    puVar14 = &DAT_005c37cc;
    break;
  case 0x27:
    iVar5 = (int)ROUND(((double)*(int *)((int)pdVar1 + 0x14) * pdVar1[1] + *pdVar1) * _DAT_0059ea38)
    ;
    FUN_0058815f((int)pdVar1 + 0x1e,s__d_03d_005c37c4,iVar5 / 1000,iVar5 % 1000);
    return;
  case 0x29:
  case 0x33:
    puVar15 = *(undefined1 **)((int)pdVar1 + 0x14);
    puVar14 = &DAT_005c3280;
    break;
  case 0x2a:
    uVar11 = FUN_0042dcc0(*(undefined4 *)((int)pdVar1 + 0x14));
    iVar7 = FUN_0042dce0((int)((ulonglong)uVar11 >> 0x20));
    iVar5 = *(int *)(param_1 + 0x1984);
    iVar6 = *(int *)(param_1 + 0x1980);
    iVar8 = FUN_00423a00(s_bevel_005c36c0,&DAT_005ec4cc);
    if (iVar8 != 0) {
      iVar8 = 0;
      do {
        pcVar13 = s_bevel_005c36c0 + iVar8;
        (&DAT_005ec4cc)[iVar8] = *pcVar13;
        iVar8 = iVar8 + 1;
      } while (*pcVar13 != '\0');
    }
    if ((*(byte *)(param_1 + 0x198c) & 4) != 0) {
      FUN_0058815f((int)pdVar1 + 0x1e,s__2d__2d___s__2d__2d__005c37ac,(int)uVar11,iVar7,
                   &DAT_005ec4cc,iVar6,iVar5);
      return;
    }
    FUN_0058815f((int)pdVar1 + 0x1e,s___2f_1_005c37a4,
                 (double)(iVar5 * iVar7) / (double)(iVar6 * (int)uVar11));
    return;
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
    if (*(char *)((int)pdVar1 + 0x1c) != '\0') {
      uVar11 = FUN_0042dc80(*(undefined4 *)((int)pdVar1 + 0x14));
      uVar12 = FUN_0042dca0((int)((ulonglong)uVar11 >> 0x20));
      fVar10 = (float10)FUN_0042dd00((int)((ulonglong)uVar12 >> 0x20),
                                     *(undefined4 *)(param_1 + 0x1644));
      if ((*(byte *)(param_1 + 0x198c) & 4) != 0) {
        FUN_0058815f((int)pdVar1 + 0x1e,s__2d__2d____3f__005c3794,(int)uVar11,(int)uVar12,
                     (double)fVar10);
        return;
      }
      FUN_0058815f((int)pdVar1 + 0x1e,s___2f____2f__005c3788,
                   (double)(int)uVar12 / (double)(int)uVar11,(double)fVar10);
      return;
    }
    iVar5 = FUN_00423a00(&DAT_005c3810,&DAT_005ec4cc);
    if (iVar5 != 0) {
      iVar5 = 0;
      do {
        pcVar13 = &DAT_005c3810 + iVar5;
        (&DAT_005ec4cc)[iVar5] = *pcVar13;
        iVar5 = iVar5 + 1;
      } while (*pcVar13 != '\0');
    }
LAB_0042fc54:
    puVar15 = &DAT_005ec4cc;
    puVar14 = &DAT_005c2c18;
    break;
  default:
    goto switchD_0042f49d_default;
  }
  FUN_0058815f((int)pdVar1 + 0x1e,puVar14,puVar15);
switchD_0042f49d_default:
  return;
}


