// Function: FUN_004c6f10 @ 004c6f10
// Size (bytes): 676


void __fastcall FUN_004c6f10(int param_1)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int local_4c;
  uint local_48;
  int local_3c [3];
  undefined1 local_30 [12];
  undefined1 local_24 [12];
  float local_18;
  float local_14;
  float local_10;
  float local_c [2];
  float local_4;
  
  iVar7 = 0;
  *(int *)(param_1 + 0x48a4) = *(int *)(param_1 + 0x4894) % 0x34;
  do {
    iVar4 = FUN_004d1410(iVar7);
    if (iVar4 == 0) break;
    iVar4 = FUN_00588410(param_1 + 0x46b8,iVar4);
    if (iVar4 == 0) {
      *(int *)(param_1 + 0x48a4) = iVar7;
      break;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x34);
  uVar6 = DAT_007d0b40;
  local_3c[0] = 0;
  local_3c[1] = 2;
  local_3c[2] = 1;
  if ((uint)((int)*(uint *)(param_1 + 0x4710) < 0xd) != (*(uint *)(param_1 + 0x4710) & 1)) {
    local_3c[0] = 2;
    local_3c[1] = 0;
  }
  local_48 = DAT_007d0b40;
  if (2 < (int)DAT_007d0b40) {
    local_48 = 3;
  }
  FUN_00403f70(*(undefined4 *)(param_1 + 0x48a4),local_24,local_30);
  cVar3 = FUN_00404030(local_24,local_30);
  if ((cVar3 != '\0') && (iVar7 = 0, 0 < (int)uVar6)) {
    do {
      iVar4 = local_3c[iVar7];
      *(int *)(param_1 + 0x48a8) = iVar4;
      iVar5 = 0;
      if (0 < DAT_005c329c) {
        do {
          iVar1 = (&DAT_007c54f0)[iVar5];
          if (((iVar1 != param_1) && (*(int *)(iVar1 + 0x48a4) == *(int *)(param_1 + 0x48a4))) &&
             (*(int *)(iVar1 + 0x48a8) == iVar4)) break;
          iVar5 = iVar5 + 1;
        } while (iVar5 < DAT_005c329c);
      }
      if (iVar5 == DAT_005c329c) {
        return;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)uVar6);
  }
  local_4c = 0;
  do {
    uVar6 = local_48;
    if (local_4c != 0) {
      uVar6 = 3;
    }
    *(undefined4 *)(param_1 + 0x48a4) = 0;
    do {
      FUN_00403f70(*(undefined4 *)(param_1 + 0x48a4),local_24,local_30);
      cVar3 = FUN_00404030(local_24,local_30);
      uVar2 = -(uint)(local_4c != 0) & local_48;
      if (cVar3 != '\0') {
        for (; (int)uVar2 < (int)uVar6; uVar2 = uVar2 + 1) {
          FUN_00403fc0(*(undefined4 *)(param_1 + 0x48a4),uVar2,local_c,&local_18);
          if (((local_c[0] != DAT_0059e440) || (local_4 != DAT_0059e440)) ||
             ((local_18 != DAT_0059e440 ||
              ((local_14 != DAT_0059e440 || (local_10 != DAT_0059e440)))))) {
            iVar7 = local_3c[uVar2];
            *(int *)(param_1 + 0x48a8) = iVar7;
            iVar4 = 0;
            if (0 < DAT_005c329c) {
              do {
                iVar5 = (&DAT_007c54f0)[iVar4];
                if (((iVar5 != param_1) && (*(int *)(iVar5 + 0x48a4) == *(int *)(param_1 + 0x48a4)))
                   && (*(int *)(iVar5 + 0x48a8) == iVar7)) break;
                iVar4 = iVar4 + 1;
              } while (iVar4 < DAT_005c329c);
            }
            if (iVar4 == DAT_005c329c) {
              return;
            }
          }
        }
      }
      iVar7 = *(int *)(param_1 + 0x48a4) + 1;
      *(int *)(param_1 + 0x48a4) = iVar7;
    } while (iVar7 < 0x34);
    local_4c = local_4c + 1;
    if (1 < local_4c) {
      *(undefined4 *)(param_1 + 0x48a4) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x48a8) = 0xffffffff;
      return;
    }
  } while( true );
}


