// Function: FUN_0041a720 @ 0041a720
// Strings:  [Ignored Blue Flags, Ignored Blue Flags, Ignored Blue Flags, Ignored Blue Flags, Jumped start, Jumped start, Jumped start, Jumped start]


void FUN_0041a720(int param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  undefined1 local_20 [32];
  
  if ((DAT_007d0308 != 0) && (DAT_007cf3c8 != DAT_0059e440)) {
    if (*(int *)(DAT_007c54e8 + 0x4894) == *(int *)(param_1 + 0x4894)) {
      if (param_2 == (char *)0x0) {
        return;
      }
      iVar1 = 0x14;
      bVar5 = true;
      pcVar3 = s_Speeding_In_Pitlane_005c271c;
      pcVar4 = param_2;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        uVar2 = 0x99;
      }
      else {
        iVar1 = 10;
        bVar5 = true;
        pcVar3 = s_Cut_Track_005c2710;
        pcVar4 = param_2;
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *pcVar3 == *pcVar4;
          pcVar3 = pcVar3 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (bVar5) {
          uVar2 = 0x97;
        }
        else {
          iVar1 = 0xd;
          bVar5 = true;
          pcVar3 = s_Jumped_start_005c2700;
          pcVar4 = param_2;
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar5 = *pcVar3 == *pcVar4;
            pcVar3 = pcVar3 + 1;
            pcVar4 = pcVar4 + 1;
          } while (bVar5);
          if (bVar5) {
            uVar2 = 0x9b;
          }
          else {
            iVar1 = 0x13;
            bVar5 = true;
            pcVar3 = s_Ignored_Blue_Flags_005c26ec;
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar5 = *pcVar3 == *param_2;
              pcVar3 = pcVar3 + 1;
              param_2 = param_2 + 1;
            } while (bVar5);
            if (!bVar5) {
              return;
            }
            uVar2 = 0x9a;
            FUN_00418a20(0x7b);
            FUN_00418a20(0x7c);
            FUN_00418a20(0x7d);
          }
        }
      }
    }
    else {
      if (param_2 == (char *)0x0) {
        return;
      }
      if (DAT_007c56a8 == 8) {
        return;
      }
      iVar1 = 0x14;
      bVar5 = true;
      pcVar3 = s_Speeding_In_Pitlane_005c271c;
      pcVar4 = param_2;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        uVar2 = 0x100;
      }
      else {
        iVar1 = 10;
        bVar5 = true;
        pcVar3 = s_Cut_Track_005c2710;
        pcVar4 = param_2;
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *pcVar3 == *pcVar4;
          pcVar3 = pcVar3 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (bVar5) {
          uVar2 = 0xfd;
        }
        else {
          iVar1 = 0xd;
          bVar5 = true;
          pcVar3 = s_Jumped_start_005c2700;
          pcVar4 = param_2;
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar5 = *pcVar3 == *pcVar4;
            pcVar3 = pcVar3 + 1;
            pcVar4 = pcVar4 + 1;
          } while (bVar5);
          if (bVar5) {
            uVar2 = 0xfe;
          }
          else {
            iVar1 = 0x13;
            bVar5 = true;
            pcVar3 = s_Ignored_Blue_Flags_005c26ec;
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar5 = *pcVar3 == *param_2;
              pcVar3 = pcVar3 + 1;
              param_2 = param_2 + 1;
            } while (bVar5);
            if (!bVar5) {
              return;
            }
            uVar2 = 0xfc;
          }
        }
      }
    }
    FUN_004144d0();
    FUN_004144f0(uVar2,*(undefined4 *)(param_1 + 0x489c),0xffffffff,0xffffffff,0xffffffff,0xc0000000
                 ,0xc0000000);
    FUN_00418560(local_20);
  }
  return;
}


