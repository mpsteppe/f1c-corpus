// Function: FUN_004b3400 @ 004b3400
// Size (bytes): 1512


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004b3400(uint *param_1)

{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  uVar7 = *param_1;
  switch(uVar7 >> 0x1d) {
  case 1:
    switch(uVar7 >> 0x12 & 0x3f) {
    case 0:
    case 7:
      uVar7 = uVar7 & 0xff;
      if ((uVar7 < 0x68) && ((&DAT_005ef9a0)[uVar7 * 0x1230] == 2)) {
        FUN_00463d10(uVar7,param_1);
        uVar3 = FUN_004b2b00();
        FUN_004c7bf0(uVar3);
        return;
      }
      break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      if ((&DAT_005ef9a0)[(uVar7 & 0xff) * 0x1230] == 2) {
        FUN_00410bc0(param_1);
        return;
      }
    }
    break;
  case 2:
    switch(uVar7 >> 0x12 & 0x3f) {
    case 0:
      if ((uVar7 & 0xff) < 0x68) {
        FUN_004e2c70();
        FUN_004f8a70();
        return;
      }
      break;
    case 2:
      uVar6 = uVar7 & 0xff;
      if (uVar6 < 0x68) {
        iVar4 = uVar6 * 0x48c0;
        if (((&DAT_005ef9a0)[uVar6 * 0x1230] != 1) && ((&DAT_005ef9a0)[uVar6 * 0x1230] != 0)) {
          if ((uVar7 & 0x3ff00) == 0x600) {
            *(undefined1 *)((int)param_1 + 0xe) = 0;
            param_1[4] = 0;
          }
          *(uint *)(&DAT_005ed700 + iVar4) = param_1[2];
          *(uint *)(&DAT_005ed704 + iVar4) = param_1[3];
          *(uint *)(&DAT_005ed708 + iVar4) = param_1[4];
          *(uint *)(&DAT_005ed70c + iVar4) = param_1[5];
          *(short *)(&DAT_005ed710 + iVar4) = (short)param_1[6];
          return;
        }
      }
      break;
    case 4:
      FUN_004fe060(param_1);
      return;
    case 5:
      FUN_004fc700(param_1);
      return;
    case 6:
      _DAT_008afedc = (float)(byte)param_1[2] * _DAT_0059e460;
      return;
    case 7:
      if ((uVar7 & 0xff) < 0x68) {
        local_c = (float)(int)(char)param_1[2] * _DAT_005accec;
        local_c = local_c + local_c;
        local_8 = (float)(int)*(char *)((int)param_1 + 9) * _DAT_005accec * _DAT_0059e8a4;
        local_4 = (float)(int)*(char *)((int)param_1 + 10) * _DAT_005accec * _DAT_005acce8;
        local_18 = (float)(int)*(char *)((int)param_1 + 0xb) * _DAT_005accec;
        local_14 = (float)(int)(char)param_1[3] * _DAT_005accec;
        local_10 = (float)(int)*(char *)((int)param_1 + 0xd) * _DAT_005accec;
        FUN_004e3940(*(undefined4 *)((int)param_1 + 0xe),&local_c,&local_18);
        return;
      }
      break;
    case 8:
      if ((uVar7 & 0xff) < 0x68) {
        FUN_004e3a10(param_1[2]);
        return;
      }
    }
    break;
  case 3:
    uVar7 = uVar7 >> 0x12 & 0x3f;
    if (uVar7 == 6) {
      if (DAT_007ce254 == '\0') {
        fVar2 = (float)(byte)param_1[2] * _DAT_0059e460;
        iVar4 = _rand();
        FUN_004c8de0(iVar4 % 3 + 5,fVar2);
        return;
      }
    }
    else if (uVar7 == 7) {
      FUN_004c81a0();
      _DAT_008ac4b0 = param_1[1];
      return;
    }
    break;
  case 4:
    switch(uVar7 >> 0x12 & 0x3f) {
    case 7:
      uVar7 = uVar7 >> 8 & 0x3ff;
      iVar8 = uVar7 - 0xc;
      iVar4 = 0;
      if (0 < iVar8) {
        do {
          iVar10 = (uint)*(byte *)(iVar4 + 0x14 + (int)param_1) * 0x48c0;
          iVar1 = iVar4 + 1;
          FUN_004bc2f0(iVar1);
          if (iVar4 < 1) {
            *(undefined4 *)(&DAT_005f07a8 + iVar10) = 0;
          }
          else {
            *(undefined **)(&DAT_005f07a8 + iVar10) =
                 &DAT_005ec6d8 + (uint)*(byte *)(iVar4 + 0x13 + (int)param_1) * 0x48c0;
          }
          if (iVar4 < (int)(uVar7 - 0xd)) {
            *(undefined **)(&DAT_005f07ac + iVar10) =
                 &DAT_005ec6d8 + (uint)*(byte *)(iVar4 + 0x15 + (int)param_1) * 0x48c0;
          }
          else {
            *(undefined4 *)(&DAT_005f07ac + iVar10) = 0;
          }
          if ((iVar4 == 0) && (puVar5 = param_1 + 2, DAT_0059e440 < (float)param_1[2])) {
            puVar9 = (uint *)(&DAT_005f0780 + iVar10);
            iVar10 = 3;
            do {
              uVar6 = *puVar5;
              puVar5 = puVar5 + 1;
              *puVar9 = uVar6;
              puVar9 = puVar9 + 1;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
          }
          (&DAT_008ad008)[iVar4] = *(undefined1 *)(iVar4 + 0x14 + (int)param_1);
          iVar4 = iVar1;
        } while (iVar1 < iVar8);
        return;
      }
      break;
    case 8:
      if (((uVar7 & 0xff) < 0x68) &&
         (((&DAT_005ef9a0)[(uVar7 & 0xff) * 0x1230] == 2 ||
          ((&DAT_005ef9a0)[(uVar7 & 0xff) * 0x1230] == 3)))) {
        FUN_004bc4e0(param_1[2],param_1[1],(int)(short)param_1[3],
                     (int)*(short *)((int)param_1 + 0xe));
        return;
      }
      break;
    case 10:
    case 0xb:
      FUN_004d1a50(param_1);
      return;
    case 0x14:
      if (DAT_008ab6e4 != 2) {
        FUN_004d23d0(param_1);
        return;
      }
      break;
    case 0x15:
      FUN_004d22c0(param_1);
      return;
    case 0x17:
      FUN_004bbed0(param_1);
      return;
    case 0x18:
      FUN_004bbf70();
      return;
    case 0x1a:
    case 0x1b:
      FUN_004bbfc0(param_1);
      return;
    case 0x1c:
      *(undefined4 *)(&DAT_005f073c + (uVar7 & 0xff) * 0x48c0) = 3;
      return;
    case 0x21:
      DAT_008acfe4 = 1;
      return;
    case 0x22:
      DAT_008acfe4 = 0;
      return;
    }
    break;
  case 6:
    uVar6 = uVar7 >> 0x12 & 0x3f;
    if (uVar6 == 0) {
      if ((uVar7 & 0xff) < 0x68) {
        FUN_004ed030();
        FUN_004e39d0(param_1[2]);
      }
    }
    else if ((uVar6 == 1) && ((&DAT_005ef9a0)[(uVar7 & 0xff) * 0x1230] == 2)) {
      FUN_004a5d10(param_1);
      return;
    }
  }
  return;
}


