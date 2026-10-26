// Function: FUN_0044f150 @ 0044f150
// Size (bytes): 732


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0044f150(int *param_1)

{
  byte *pbVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  int *piVar5;
  float *pfVar6;
  ushort *puVar7;
  int unaff_EBX;
  byte abStack_60c [8];
  undefined4 local_604;
  char local_600 [244];
  int aiStack_50c [321];
  float fStack_8;
  
  piVar5 = (int *)param_1[1];
  if ((piVar5 != (int *)0x0) && (param_1[0x321] = 0, DAT_005cd08d != '\0')) {
    if (*param_1 == 2) {
      iVar4 = (**(code **)(*piVar5 + 0x24))(piVar5,0x100,local_600);
      if ((iVar4 == -0x7ff8fff4) || (iVar4 == -0x7ff8ffe2)) {
        iVar4 = (**(code **)(*(int *)param_1[1] + 0x1c))((int *)param_1[1]);
        if (iVar4 != 0) {
          return;
        }
        iVar4 = (**(code **)(*(int *)param_1[1] + 0x24))((int *)param_1[1],0x100,&stack0xfffff9f0);
      }
      if (iVar4 != 0) {
        return;
      }
    }
    else {
      iVar4 = 0;
      do {
        local_600[iVar4] = *(char *)((int)param_1 + iVar4 + 0x37c) << 7;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0x100);
      local_604 = 0xffffffff;
      iVar4 = (**(code **)(*piVar5 + 0x28))(piVar5,0x14,0,&local_604,1);
      if (iVar4 != 0) {
        return;
      }
      iVar4 = (**(code **)(*(int *)param_1[1] + 0x28))
                        ((int *)param_1[1],0x14,local_600 + 0xec,&stack0xfffff9e8,0);
      if (iVar4 != 0) {
        return;
      }
      if (0 < unaff_EBX) {
        piVar5 = (int *)(local_600 + 0xf4);
        do {
          pbVar1 = (byte *)(piVar5 + 1);
          iVar4 = *piVar5;
          piVar5 = piVar5 + 5;
          unaff_EBX = unaff_EBX + -1;
          abStack_60c[iVar4] = *pbVar1 & 0x80;
        } while (unaff_EBX != 0);
      }
    }
    uVar3 = 0;
    if (((local_600[0x11] & 0x80U) != 0) || ((local_600[0x91] & 0x80U) != 0)) {
      uVar3 = 0x1000;
    }
    if ((local_600[0x2c] & 0x80U) != 0) {
      uVar3 = uVar3 | 0x2000;
    }
    if ((local_600[0x1e] & 0x80U) != 0) {
      uVar3 = uVar3 | 0x8000;
    }
    if ((local_600[0x2a] & 0x80U) != 0) {
      uVar3 = uVar3 | 0x8000;
    }
    if ((local_600[0x39] & 0x80U) != 0) {
      uVar3 = uVar3 | 0x4000;
    }
    pfVar6 = (float *)(param_1 + 0x120);
    iVar4 = 1;
    do {
      if ((double)pfVar6[0x100] <= _DAT_008afea8) {
        if ((abStack_60c[iVar4] & 0x80) == 0) {
          *(undefined1 *)(iVar4 + 0x37c + (int)param_1) = 0;
        }
        else {
          if ((*(byte *)(iVar4 + 0x37c + (int)param_1) & 1) == 0) {
            *(undefined1 *)(iVar4 + 0x37c + (int)param_1) = 3;
            *pfVar6 = (float)param_1[799];
          }
          else {
            cVar2 = *(char *)(iVar4 + 0x27c + (int)param_1);
            if (cVar2 == '\0') {
              *(undefined1 *)(iVar4 + 0x37c + (int)param_1) = 1;
            }
            else if (cVar2 == '\x01') {
              *pfVar6 = fStack_8 + *pfVar6;
              *(undefined1 *)(iVar4 + 0x37c + (int)param_1) = 1;
              if (DAT_0059e440 <= *pfVar6) {
                *(undefined1 *)(iVar4 + 0x37c + (int)param_1) = 3;
                *pfVar6 = (float)param_1[800];
              }
            }
          }
          if ((*(byte *)(iVar4 + 0x37c + (int)param_1) & 2) != 0) {
            cVar2 = FUN_00404f10();
            if (((cVar2 == '\0') || (DAT_007c569c != 5)) || (iVar4 == 1)) {
              *(ushort *)((int)param_1 + param_1[0x321] * 2 + 0xc88) = uVar3 | (ushort)iVar4;
              param_1[0x321] = param_1[0x321] + 1;
            }
          }
        }
      }
      iVar4 = iVar4 + 1;
      pfVar6 = pfVar6 + 1;
    } while (iVar4 < 0x100);
    if (((local_600[0x2e] & 0x80U) != 0) && (iVar4 = 0, 0 < param_1[0x321])) {
      puVar7 = (ushort *)(param_1 + 0x322);
      do {
        uVar3 = *puVar7;
        switch(uVar3 & 0xff) {
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1e:
        case 0x1f:
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
        case 0x2c:
        case 0x2d:
        case 0x2e:
        case 0x2f:
        case 0x30:
        case 0x31:
        case 0x32:
          if ((short)uVar3 < 0) {
            uVar3 = uVar3 & 0x7fff;
          }
          else {
            uVar3 = uVar3 | 0x8000;
          }
          *puVar7 = uVar3;
        }
        iVar4 = iVar4 + 1;
        puVar7 = puVar7 + 1;
      } while (iVar4 < param_1[0x321]);
    }
  }
  return;
}


