// Function: FUN_00434460 @ 00434460
// Size (bytes): 861


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00434460(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  float local_20;
  undefined4 local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  uVar4 = 0;
  local_1c = 0;
  if (*param_1 == '\0') {
    local_1c = FUN_00434820();
    local_20 = (float)((uint)local_20 & 0xffffff00);
    uVar4 = local_1c;
  }
  else {
    iVar2 = *(int *)(param_1 + 4);
    if (iVar2 == 0) {
      FUN_004d8760(2,1);
      param_1[4] = '\x01';
      param_1[5] = '\0';
      param_1[6] = '\0';
      param_1[7] = '\0';
      param_1[0x28] = '\0';
      param_1[0x29] = '\0';
      param_1[0x2a] = '\0';
      param_1[0x2b] = '\0';
      local_20 = (float)((uint)local_20 & 0xffffff00);
      param_1[0x24] = '\0';
      param_1[0x25] = '\0';
      param_1[0x26] = '@';
      param_1[0x27] = '@';
    }
    else {
      if (iVar2 == 1) {
        local_20 = (float)((uint)local_20._1_3_ << 8);
        if (*(float *)(param_1 + 0x24) <= DAT_0059e440) {
          param_1[4] = '\x02';
          param_1[5] = '\0';
          param_1[6] = '\0';
          param_1[7] = '\0';
          param_1[0x24] = '\0';
          param_1[0x25] = '\0';
          param_1[0x26] = '\0';
          param_1[0x27] = '@';
        }
        else {
          *(float *)(param_1 + 0x24) = *(float *)(param_1 + 0x24) - (float)_DAT_008afe98;
        }
      }
      else {
        local_20 = (float)CONCAT31(local_20._1_3_,1);
        if (iVar2 == 2) {
          param_1[0x2c] = '\x01';
          param_1[0x2d] = '\0';
          param_1[0x2e] = '\0';
          param_1[0x2f] = '\0';
          cVar1 = FUN_00435240();
          if (cVar1 != '\0') {
            param_1[4] = '\x04';
            param_1[5] = '\0';
            param_1[6] = '\0';
            param_1[7] = '\0';
            FUN_004d8760(0,1);
          }
          goto LAB_0043469b;
        }
        if (iVar2 == 5) {
          if (*(float *)(param_1 + 0x24) <= DAT_0059e440) {
            uVar4 = 1;
            local_1c = 1;
          }
          else {
            *(float *)(param_1 + 0x24) = *(float *)(param_1 + 0x24) - (float)_DAT_008afe98;
          }
          goto LAB_0043469b;
        }
        cVar1 = FUN_00418b90(0x208);
        if (cVar1 == '\0') {
          if (*(float *)(param_1 + 0x34) < DAT_0059e440 ==
              (*(float *)(param_1 + 0x34) == DAT_0059e440)) {
            *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x34) - (float)_DAT_008afe98;
          }
          else {
            iVar2 = *(int *)(param_1 + 0x18);
            param_1[0x34] = '\0';
            param_1[0x35] = '\0';
            param_1[0x36] = '\x10';
            param_1[0x37] = '@';
            *(int *)(param_1 + 0x18) = iVar2 + 1;
            *(int *)(param_1 + 0x2c) = iVar2 + 3;
            if (iVar2 + 1 < DAT_005c329c) {
              iVar3 = 0;
              if (DAT_005c329c < 1) {
LAB_00434673:
                FUN_004d88b0();
              }
              else {
                do {
                  param_1[0x1c] = '\0';
                  param_1[0x1d] = '\0';
                  param_1[0x1e] = '\0';
                  param_1[0x1f] = '\0';
                  if (*(int *)((&DAT_007c54f0)[iVar3] + 0x4060) == iVar2 + 2) {
                    *(int *)(param_1 + 0x1c) = iVar3;
                    goto LAB_00434673;
                  }
                  iVar3 = iVar3 + 1;
                } while (iVar3 < DAT_005c329c);
                FUN_004d88b0();
              }
            }
            else {
              param_1[4] = '\x05';
              param_1[5] = '\0';
              param_1[6] = '\0';
              param_1[7] = '\0';
              *(int *)(param_1 + 0x18) = iVar2;
              param_1[0x24] = '\0';
              param_1[0x25] = '\0';
              param_1[0x26] = '@';
              param_1[0x27] = '@';
            }
          }
        }
        else {
          cVar1 = FUN_00435240();
          if (cVar1 != '\0') {
            iVar2 = *(int *)(param_1 + 0x18);
            *(int *)(param_1 + 0x18) = iVar2 + 1;
            *(int *)(param_1 + 0x2c) = iVar2 + 3;
            if (iVar2 + 1 < DAT_005c329c) {
              iVar3 = 0;
              if (0 < DAT_005c329c) {
                do {
                  param_1[0x1c] = '\0';
                  param_1[0x1d] = '\0';
                  param_1[0x1e] = '\0';
                  param_1[0x1f] = '\0';
                  if (*(int *)((&DAT_007c54f0)[iVar3] + 0x4060) == iVar2 + 2) {
                    *(int *)(param_1 + 0x1c) = iVar3;
                    break;
                  }
                  iVar3 = iVar3 + 1;
                } while (iVar3 < DAT_005c329c);
              }
              FUN_004d88b0();
              FUN_0041c0f0(*(undefined4 *)(param_1 + 0x18));
            }
            else {
              param_1[4] = '\x05';
              param_1[5] = '\0';
              param_1[6] = '\0';
              param_1[7] = '\0';
              *(int *)(param_1 + 0x18) = iVar2;
              param_1[0x24] = '\0';
              param_1[0x25] = '\0';
              param_1[0x26] = '@';
              param_1[0x27] = '@';
            }
          }
        }
      }
      *(float *)(param_1 + 0x28) = (float)_DAT_008afe98 + *(float *)(param_1 + 0x28);
      uVar4 = local_1c;
    }
  }
LAB_0043469b:
  iVar2 = *(int *)(param_1 + 0xc);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0xb0) != 0)) {
    local_18 = *(float *)(iVar2 + 0xbc);
    iVar2 = FUN_004582a0(*(undefined4 *)(param_1 + 0x2c));
    if ((iVar2 != 0) && (local_18 < *(float *)(iVar2 + 0x18))) {
      FUN_00434d60(local_20);
    }
    FUN_0040c910();
    iVar2 = *(int *)(param_1 + 0xc);
    if (iVar2 != 0) {
      DAT_005ea535 = 1;
      local_c = *(undefined4 *)(iVar2 + 0x18);
      _DAT_005ea538 = iVar2;
      FUN_00541cd0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 0x10),
                   *(undefined4 *)(iVar2 + 0x14),local_c,*(undefined4 *)(iVar2 + 0x1c),
                   *(undefined4 *)(iVar2 + 0x20));
      FUN_00456060(&local_20,&local_18);
      FUN_00456080(&local_10,&local_14);
      FUN_00542050(local_20 * _DAT_0059e65c,local_18 * _DAT_0059e65c,0);
      FUN_005423c0(local_10,local_14);
      FUN_00542680(*(undefined4 *)(iVar2 + 0x48));
      return local_1c;
    }
  }
  return uVar4;
}


