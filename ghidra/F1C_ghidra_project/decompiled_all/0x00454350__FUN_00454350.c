// Function: FUN_00454350 @ 00454350
// Strings:  [JOY2 B16, JOY2 P0L, JOY2 P1L, JOY2 P2L, JOY2 P3D, JOY2 P3L, JOY2 P3L]


uint __thiscall FUN_00454350(int param_1,char *param_2,int *param_3,int param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar7;
  undefined3 uVar6;
  
  if (param_4 != 0) {
    iVar5 = 0x60;
    do {
      iVar2 = iVar5 + 4;
      *(float *)((int)&DAT_007cd108 + iVar5) =
           (*(float *)(iVar5 + 0x10c0 + param_1) - *(float *)(iVar5 + 0xd88 + param_1)) *
           *(float *)(iVar5 + 0xd68 + param_1);
      iVar5 = iVar2;
    } while (iVar2 < 0x80);
    iVar5 = 0x60;
    do {
      iVar2 = iVar5 + 4;
      *(float *)((int)&DAT_007cca2c + iVar5) =
           (*(float *)(iVar5 + 0x14bc + param_1) - *(float *)(iVar5 + 0x1184 + param_1)) *
           *(float *)(iVar5 + 0x1164 + param_1);
      iVar5 = iVar2;
    } while (iVar2 < 0x80);
  }
  *param_3 = -1;
  cVar1 = FUN_00454250(0,0,&DAT_007cd168);
  if (cVar1 != '\0') {
    *param_3 = 1;
  }
  cVar1 = FUN_004542d0(0,0,&DAT_007cd168);
  if (cVar1 != '\0') {
    *param_3 = 2;
  }
  cVar1 = FUN_00454250(1,0,&DAT_007cd168);
  if (cVar1 != '\0') {
    *param_3 = 3;
  }
  cVar1 = FUN_004542d0(1,0,&DAT_007cd168);
  if (cVar1 != '\0') {
    *param_3 = 4;
  }
  cVar1 = FUN_00454250(2,0,&DAT_007cd168);
  if (cVar1 != '\0') {
    *param_3 = 5;
  }
  cVar1 = FUN_004542d0(2,0,&DAT_007cd168);
  if (cVar1 != '\0') {
    *param_3 = 6;
  }
  cVar1 = FUN_00454250(3,0,&DAT_007cd168);
  if (cVar1 != '\0') {
    *param_3 = 7;
  }
  cVar1 = FUN_004542d0(3,0,&DAT_007cd168);
  if (cVar1 != '\0') {
    *param_3 = 8;
  }
  cVar1 = FUN_00454250(4,0,&DAT_007cd168);
  if (cVar1 != '\0') {
    *param_3 = 9;
  }
  cVar1 = FUN_004542d0(4,0,&DAT_007cd168);
  if (cVar1 != '\0') {
    *param_3 = 10;
  }
  cVar1 = FUN_00454250(5,0,&DAT_007cd168);
  if (cVar1 != '\0') {
    *param_3 = 0xb;
  }
  cVar1 = FUN_004542d0(5,0,&DAT_007cd168);
  if (cVar1 != '\0') {
    *param_3 = 0xc;
  }
  cVar1 = FUN_00454250(6,0,&DAT_007cd168);
  if (cVar1 != '\0') {
    *param_3 = 0x66;
  }
  cVar1 = FUN_004542d0(6,0,&DAT_007cd168);
  if (cVar1 != '\0') {
    *param_3 = 0x67;
  }
  cVar1 = FUN_00454250(7,0,&DAT_007cd168);
  if (cVar1 != '\0') {
    *param_3 = 0x68;
  }
  cVar1 = FUN_004542d0(7,0,&DAT_007cd168);
  if (cVar1 != '\0') {
    *param_3 = 0x69;
  }
  if (*(char *)(param_1 + 0x1160) != '\0') {
    *param_3 = 0xd;
  }
  if (*(char *)(param_1 + 0x1161) != '\0') {
    *param_3 = 0xe;
  }
  if (*(char *)(param_1 + 0x1162) != '\0') {
    *param_3 = 0xf;
  }
  if (*(char *)(param_1 + 0x1163) != '\0') {
    *param_3 = 0x10;
  }
  if (*(char *)(param_1 + 0x1164) != '\0') {
    *param_3 = 0x11;
  }
  if (*(char *)(param_1 + 0x1165) != '\0') {
    *param_3 = 0x12;
  }
  if (*(char *)(param_1 + 0x1166) != '\0') {
    *param_3 = 0x13;
  }
  if (*(char *)(param_1 + 0x1167) != '\0') {
    *param_3 = 0x14;
  }
  if (*(char *)(param_1 + 0x1168) != '\0') {
    *param_3 = 0x15;
  }
  if (*(char *)(param_1 + 0x1169) != '\0') {
    *param_3 = 0x16;
  }
  if (*(char *)(param_1 + 0x116a) != '\0') {
    *param_3 = 0x17;
  }
  if (*(char *)(param_1 + 0x116b) != '\0') {
    *param_3 = 0x18;
  }
  if (*(char *)(param_1 + 0x116c) != '\0') {
    *param_3 = 0x19;
  }
  if (*(char *)(param_1 + 0x116d) != '\0') {
    *param_3 = 0x1a;
  }
  if (*(char *)(param_1 + 0x116e) != '\0') {
    *param_3 = 0x1b;
  }
  if (*(char *)(param_1 + 0x116f) != '\0') {
    *param_3 = 0x1c;
  }
  if (*(char *)(param_1 + 0x1180) < '\0') {
    if (*(int *)(param_1 + 0x1170) == DAT_007cd1bc) {
      *param_3 = 0x46;
    }
    if (*(int *)(param_1 + 0x1170) == DAT_007cd1d4) {
      *param_3 = 0x47;
    }
    if (*(int *)(param_1 + 0x1170) == DAT_007ccf5c) {
      *param_3 = 0x48;
    }
    if (*(int *)(param_1 + 0x1170) == DAT_007cd1ec) {
      *param_3 = 0x49;
    }
    if ((*(uint *)(param_1 + 0x1180) & 0x100) != 0) {
      if (*(int *)(param_1 + 0x1174) == DAT_007cd0ac) {
        *param_3 = 0x4a;
      }
      if (*(int *)(param_1 + 0x1174) == DAT_007cd0c4) {
        *param_3 = 0x4b;
      }
      if (*(int *)(param_1 + 0x1174) == DAT_007cd12c) {
        *param_3 = 0x4c;
      }
      if (*(int *)(param_1 + 0x1174) == DAT_007cd144) {
        *param_3 = 0x4d;
      }
      if ((*(uint *)(param_1 + 0x1180) & 0x200) != 0) {
        if (*(int *)(param_1 + 0x1178) == DAT_007cd018) {
          *param_3 = 0x4e;
        }
        if (*(int *)(param_1 + 0x1178) == DAT_007cd048) {
          *param_3 = 0x4f;
        }
        if (*(int *)(param_1 + 0x1178) == DAT_007cd0dc) {
          *param_3 = 0x50;
        }
        if (*(int *)(param_1 + 0x1178) == DAT_007cd0f4) {
          *param_3 = 0x51;
        }
        if ((*(uint *)(param_1 + 0x1180) & 0x400) != 0) {
          if (*(int *)(param_1 + 0x117c) == DAT_007cca10) {
            *param_3 = 0x52;
          }
          if (*(int *)(param_1 + 0x117c) == DAT_007cca40) {
            *param_3 = 0x53;
          }
          if (*(int *)(param_1 + 0x117c) == DAT_007cd060) {
            *param_3 = 0x54;
          }
          if (*(int *)(param_1 + 0x117c) == DAT_007cd078) {
            *param_3 = 0x55;
          }
        }
      }
    }
  }
  cVar1 = FUN_00454250(0,1,&DAT_007cca8c);
  if (cVar1 != '\0') {
    *param_3 = 0x1e;
  }
  cVar1 = FUN_004542d0(0,1,&DAT_007cca8c);
  if (cVar1 != '\0') {
    *param_3 = 0x1f;
  }
  cVar1 = FUN_00454250(1,1,&DAT_007cca8c);
  if (cVar1 != '\0') {
    *param_3 = 0x20;
  }
  cVar1 = FUN_004542d0(1,1,&DAT_007cca8c);
  if (cVar1 != '\0') {
    *param_3 = 0x21;
  }
  cVar1 = FUN_00454250(2,1,&DAT_007cca8c);
  if (cVar1 != '\0') {
    *param_3 = 0x22;
  }
  cVar1 = FUN_004542d0(2,1,&DAT_007cca8c);
  if (cVar1 != '\0') {
    *param_3 = 0x23;
  }
  cVar1 = FUN_00454250(3,1,&DAT_007cca8c);
  if (cVar1 != '\0') {
    *param_3 = 0x24;
  }
  cVar1 = FUN_004542d0(3,1,&DAT_007cca8c);
  if (cVar1 != '\0') {
    *param_3 = 0x25;
  }
  cVar1 = FUN_00454250(4,1,&DAT_007cca8c);
  if (cVar1 != '\0') {
    *param_3 = 0x26;
  }
  cVar1 = FUN_004542d0(4,1,&DAT_007cca8c);
  if (cVar1 != '\0') {
    *param_3 = 0x27;
  }
  cVar1 = FUN_00454250(5,1,&DAT_007cca8c);
  if (cVar1 != '\0') {
    *param_3 = 0x28;
  }
  cVar1 = FUN_004542d0(5,1,&DAT_007cca8c);
  if (cVar1 != '\0') {
    *param_3 = 0x29;
  }
  cVar1 = FUN_00454250(6,1,&DAT_007cca8c);
  if (cVar1 != '\0') {
    *param_3 = 0x6a;
  }
  cVar1 = FUN_004542d0(6,1,&DAT_007cca8c);
  if (cVar1 != '\0') {
    *param_3 = 0x6b;
  }
  cVar1 = FUN_00454250(7,1,&DAT_007cca8c);
  if (cVar1 != '\0') {
    *param_3 = 0x6c;
  }
  uVar3 = FUN_004542d0(7,1,&DAT_007cca8c);
  if ((char)uVar3 != '\0') {
    *param_3 = 0x6d;
  }
  if (*(char *)(param_1 + 0x155c) != '\0') {
    *param_3 = 0x2a;
  }
  if (*(char *)(param_1 + 0x155d) != '\0') {
    *param_3 = 0x2b;
  }
  if (*(char *)(param_1 + 0x155e) != '\0') {
    *param_3 = 0x2c;
  }
  if (*(char *)(param_1 + 0x155f) != '\0') {
    *param_3 = 0x2d;
  }
  if (*(char *)(param_1 + 0x1560) != '\0') {
    *param_3 = 0x2e;
  }
  if (*(char *)(param_1 + 0x1561) != '\0') {
    *param_3 = 0x2f;
  }
  if (*(char *)(param_1 + 0x1562) != '\0') {
    *param_3 = 0x30;
  }
  if (*(char *)(param_1 + 0x1563) != '\0') {
    *param_3 = 0x31;
  }
  if (*(char *)(param_1 + 0x1564) != '\0') {
    *param_3 = 0x32;
  }
  if (*(char *)(param_1 + 0x1565) != '\0') {
    *param_3 = 0x33;
  }
  if (*(char *)(param_1 + 0x1566) != '\0') {
    *param_3 = 0x34;
  }
  if (*(char *)(param_1 + 0x1567) != '\0') {
    *param_3 = 0x35;
  }
  if (*(char *)(param_1 + 0x1568) != '\0') {
    *param_3 = 0x36;
  }
  if (*(char *)(param_1 + 0x1569) != '\0') {
    *param_3 = 0x37;
  }
  if (*(char *)(param_1 + 0x156a) != '\0') {
    *param_3 = 0x38;
  }
  if (*(char *)(param_1 + 0x156b) != '\0') {
    *param_3 = 0x39;
  }
  uVar4 = CONCAT31((int3)((uint)uVar3 >> 8),*(char *)(param_1 + 0x157c));
  if (*(char *)(param_1 + 0x157c) < '\0') {
    if (*(int *)(param_1 + 0x156c) == DAT_007ccfd8) {
      *param_3 = 0x56;
    }
    if (*(int *)(param_1 + 0x156c) == DAT_007cd000) {
      *param_3 = 0x57;
    }
    if (*(int *)(param_1 + 0x156c) == DAT_007cd094) {
      *param_3 = 0x58;
    }
    if (*(int *)(param_1 + 0x156c) == DAT_007cd030) {
      *param_3 = 0x59;
    }
    uVar4 = *(uint *)(param_1 + 0x157c);
    if ((uVar4 & 0x100) != 0) {
      if (*(int *)(param_1 + 0x1570) == DAT_007ca548) {
        *param_3 = 0x5a;
      }
      if (*(int *)(param_1 + 0x1570) == DAT_007ca578) {
        *param_3 = 0x5b;
      }
      if (*(int *)(param_1 + 0x1570) == DAT_007cca28) {
        *param_3 = 0x5c;
      }
      if (*(int *)(param_1 + 0x1570) == DAT_007cca68) {
        *param_3 = 0x5d;
      }
      uVar4 = *(uint *)(param_1 + 0x157c);
      if ((uVar4 & 0x200) != 0) {
        if (*(int *)(param_1 + 0x1574) == DAT_007ca4cc) {
          *param_3 = 0x5e;
        }
        if (*(int *)(param_1 + 0x1574) == DAT_007ca4f4) {
          *param_3 = 0x5f;
        }
        if (*(int *)(param_1 + 0x1574) == DAT_007ca560) {
          *param_3 = 0x60;
        }
        if (*(int *)(param_1 + 0x1574) == DAT_007ca530) {
          *param_3 = 0x61;
        }
        uVar4 = *(uint *)(param_1 + 0x157c);
        if ((uVar4 & 0x400) != 0) {
          if (*(int *)(param_1 + 0x1578) == DAT_007ca434) {
            *param_3 = 0x62;
          }
          if (*(int *)(param_1 + 0x1578) == DAT_007ca40c) {
            *param_3 = 99;
          }
          uVar4 = *(uint *)(param_1 + 0x1578);
          if (uVar4 == DAT_007ca4b4) {
            *param_3 = 100;
          }
          if (*(int *)(param_1 + 0x1578) == DAT_007ca46c) {
            *param_3 = 0x65;
            goto LAB_00454bf9;
          }
        }
      }
    }
  }
  if (*param_3 == -1) {
    return uVar4 & 0xffffff00;
  }
LAB_00454bf9:
  iVar5 = *param_3;
  pcVar7 = s__EMPTY__005c44b0 + iVar5 * 9;
  do {
    cVar1 = *pcVar7;
    uVar6 = (undefined3)((uint)iVar5 >> 8);
    iVar5 = CONCAT31(uVar6,cVar1);
    pcVar7 = pcVar7 + 1;
    *param_2 = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  return CONCAT31(uVar6,1);
}


