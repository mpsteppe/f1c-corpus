// Function: FUN_004b9000 @ 004b9000
// Size (bytes): 1290


void __thiscall FUN_004b9000(int param_1,float param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  float *pfVar6;
  int iVar7;
  int local_364;
  uint local_350 [108];
  int aiStack_1a0 [104];
  
  iVar7 = 0;
  do {
    iVar3 = FUN_004b72a0(iVar7,param_2);
    aiStack_1a0[iVar7] = iVar3;
    if (iVar3 != 0) {
      cVar2 = FUN_005001d0();
      if ((((cVar2 == '\0') ||
           (*(float *)(iVar3 + 0x24c) < param_2 == (*(float *)(iVar3 + 0x24c) == param_2))) ||
          (cVar2 = FUN_005001f0(), cVar2 == '\0')) || (*(float *)(iVar3 + 0x9c) < param_2)) {
        thunk_FUN_00500170();
      }
      else {
        aiStack_1a0[iVar7] = 0;
      }
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x68);
  FUN_004b5380(param_2);
  if ((*(undefined4 **)(param_1 + 0x71c) == (undefined4 *)0x0) ||
     (pfVar6 = (float *)**(undefined4 **)(param_1 + 0x71c), pfVar6 == (float *)0x0)) {
    if (param_2 <=
        (*(float *)(param_1 + 0xf34) - *(float *)(param_1 + 0xf30)) + *(float *)(param_1 + 0xf30)) {
      puVar4 = *(undefined4 **)(param_1 + 0x714);
    }
    else {
      puVar4 = *(undefined4 **)(param_1 + 0x718);
    }
    *(undefined4 **)(param_1 + 0x71c) = puVar4;
    if ((puVar4 == (undefined4 *)0x0) || (pfVar6 = (float *)*puVar4, pfVar6 == (float *)0x0))
    goto LAB_004b94eb;
  }
  if (*pfVar6 <= param_2) {
    do {
      if (*(int *)(param_1 + 0x71c) == 0) {
LAB_004b9176:
        puVar4 = *(undefined4 **)(param_1 + 0x718);
        goto LAB_004b917c;
      }
      puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x71c) + 4);
      *(undefined4 **)(param_1 + 0x71c) = puVar4;
      if ((puVar4 == (undefined4 *)0x0) || (pfVar6 = (float *)*puVar4, pfVar6 == (float *)0x0))
      goto LAB_004b9176;
    } while (*pfVar6 < param_2);
  }
  else {
    do {
      if (*(int *)(param_1 + 0x71c) == 0) {
LAB_004b913f:
        puVar4 = *(undefined4 **)(param_1 + 0x714);
LAB_004b917c:
        *(undefined4 **)(param_1 + 0x71c) = puVar4;
        if (puVar4 == (undefined4 *)0x0) {
          pfVar6 = (float *)0x0;
        }
        else {
          pfVar6 = (float *)*puVar4;
        }
        break;
      }
      puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x71c) + 8);
      *(undefined4 **)(param_1 + 0x71c) = puVar4;
      if ((puVar4 == (undefined4 *)0x0) || (pfVar6 = (float *)*puVar4, pfVar6 == (float *)0x0))
      goto LAB_004b913f;
    } while (*pfVar6 < param_2 == (*pfVar6 == param_2));
  }
  puVar4 = *(undefined4 **)(param_1 + 0x71c);
  iVar7 = -1;
  if (puVar4 != (undefined4 *)0x0) {
    iVar7 = 0;
    for (puVar1 = *(undefined4 **)(param_1 + 0x714);
        (puVar1 != (undefined4 *)0x0 && (puVar1 != puVar4)); puVar1 = (undefined4 *)puVar1[1]) {
      iVar7 = iVar7 + 1;
    }
  }
  if (iVar7 < *(int *)(param_1 + 0x720) + -1) {
    while( true ) {
      if ((pfVar6 == (float *)0x0) || (param_2 <= *pfVar6)) goto LAB_004b9207;
      if (*(int *)(param_1 + 0x71c) != 0) {
        *(undefined4 *)(param_1 + 0x71c) = *(undefined4 *)(*(int *)(param_1 + 0x71c) + 4);
      }
      if (*(undefined4 **)(param_1 + 0x71c) == (undefined4 *)0x0) break;
      pfVar6 = (float *)**(undefined4 **)(param_1 + 0x71c);
    }
    pfVar6 = (float *)0x0;
  }
LAB_004b9207:
  local_364 = 0;
  if (pfVar6 != (float *)0x0) {
    while( true ) {
      FUN_00566db0(pfVar6[1]);
      FUN_004b4450();
      FUN_004b44a0(param_1 + 0x6e4);
      local_364 = local_364 + 1;
      if (0x40 < local_364) break;
      iVar7 = 0;
      if (*(short *)(pfVar6 + 2) != 0) {
        do {
          FUN_004b4360(param_1 + 0x6e4,*pfVar6,local_350);
          if ((local_350[0] & 0xe0000000) == 0x20000000) {
            uVar5 = local_350[0] >> 0x12 & 0x3f;
            if (uVar5 == 0) {
              if (((local_350[0] & 0xff) < 0x68) && (aiStack_1a0[local_350[0] & 0xff] != 0)) {
                FUN_004fffb0(param_2,local_350);
              }
            }
            else if ((uVar5 != 0) && (uVar5 < 7)) {
              FUN_004b54e0(local_350);
            }
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < (int)(uint)*(ushort *)(pfVar6 + 2));
      }
      iVar7 = 0;
      do {
        if ((aiStack_1a0[iVar7] != 0) && (cVar2 = FUN_005001d0(), cVar2 == '\0')) goto LAB_004b9314;
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x68);
      if ((0x3f < local_364) || (cVar2 = FUN_004b5460(), cVar2 != '\0')) break;
LAB_004b9314:
      if (*(int *)(param_1 + 0x71c) != 0) {
        *(undefined4 *)(param_1 + 0x71c) = *(undefined4 *)(*(int *)(param_1 + 0x71c) + 8);
      }
      if ((*(undefined4 **)(param_1 + 0x71c) == (undefined4 *)0x0) ||
         (pfVar6 = (float *)**(undefined4 **)(param_1 + 0x71c), pfVar6 == (float *)0x0)) break;
    }
  }
  *(undefined4 **)(param_1 + 0x71c) = puVar4;
  if (puVar4 == (undefined4 *)0x0) {
    pfVar6 = (float *)0x0;
  }
  else {
    pfVar6 = (float *)*puVar4;
  }
  if (*(int *)(param_1 + 0x71c) != 0) {
    iVar7 = *(int *)(param_1 + 0x714);
    iVar3 = 0;
    if (iVar7 != 0) {
      do {
        if (iVar7 == *(int *)(param_1 + 0x71c)) break;
        iVar7 = *(int *)(iVar7 + 4);
        iVar3 = iVar3 + 1;
      } while (iVar7 != 0);
      if (0 < iVar3) {
        while( true ) {
          if ((pfVar6 == (float *)0x0) || (*pfVar6 <= param_2)) goto LAB_004b93b7;
          if (*(int *)(param_1 + 0x71c) != 0) {
            *(undefined4 *)(param_1 + 0x71c) = *(undefined4 *)(*(int *)(param_1 + 0x71c) + 8);
          }
          if (*(undefined4 **)(param_1 + 0x71c) == (undefined4 *)0x0) break;
          pfVar6 = (float *)**(undefined4 **)(param_1 + 0x71c);
        }
        pfVar6 = (float *)0x0;
      }
    }
  }
LAB_004b93b7:
  local_364 = 0;
  if (pfVar6 != (float *)0x0) {
    while( true ) {
      FUN_00566db0(pfVar6[1]);
      FUN_004b4450();
      FUN_004b44a0(param_1 + 0x6e4);
      local_364 = local_364 + 1;
      if (0x40 < local_364) break;
      iVar7 = 0;
      if (*(short *)(pfVar6 + 2) != 0) {
        do {
          FUN_004b4360(param_1 + 0x6e4,*pfVar6,local_350);
          if ((local_350[0] & 0xe0000000) == 0x20000000) {
            uVar5 = local_350[0] >> 0x12 & 0x3f;
            if (uVar5 == 0) {
              if (((local_350[0] & 0xff) < 0x68) && (aiStack_1a0[local_350[0] & 0xff] != 0)) {
                FUN_004fffb0(param_2,local_350);
              }
            }
            else if ((uVar5 != 0) && (uVar5 < 7)) {
              FUN_004b54e0(local_350);
            }
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < (int)(uint)*(ushort *)(pfVar6 + 2));
      }
      iVar7 = 0;
      do {
        if ((aiStack_1a0[iVar7] != 0) && (cVar2 = FUN_005001f0(), cVar2 == '\0')) goto LAB_004b94c4;
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x68);
      if ((0x3f < local_364) || (cVar2 = FUN_004b54a0(), cVar2 != '\0')) break;
LAB_004b94c4:
      if (*(int *)(param_1 + 0x71c) != 0) {
        *(undefined4 *)(param_1 + 0x71c) = *(undefined4 *)(*(int *)(param_1 + 0x71c) + 4);
      }
      if ((*(undefined4 **)(param_1 + 0x71c) == (undefined4 *)0x0) ||
         (pfVar6 = (float *)**(undefined4 **)(param_1 + 0x71c), pfVar6 == (float *)0x0)) break;
    }
  }
LAB_004b94eb:
  FUN_004b5630();
  FUN_004b5760();
  return;
}


