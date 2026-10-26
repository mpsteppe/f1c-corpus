// Function: FUN_004c2a80 @ 004c2a80
// Strings:  [SeasonScoringInfo]


void __fastcall FUN_004c2a80(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  cVar1 = FUN_0042bc10();
  if ((cVar1 != '\0') && (DAT_008ab6e4 != 2)) {
    iVar2 = DAT_008ac48c * 0x18c + DAT_008ac490;
    if (iVar2 != 0) {
      param_1 = FUN_004c28d0(iVar2 + 4);
    }
    if (((param_1 != 0) &&
        (*(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + *(int *)(DAT_007c54e8 + 0x403c),
        DAT_0059e440 < *(float *)(DAT_007c54e8 + 0x409c))) &&
       ((*(float *)(DAT_007c54e8 + 0x409c) < *(float *)(param_1 + 0x14) ||
        (*(float *)(param_1 + 0x14) < DAT_0059e440 != (*(float *)(param_1 + 0x14) == DAT_0059e440)))
       )) {
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(DAT_007c54e8 + 0x409c);
    }
    FUN_004c2be0(*(undefined4 *)(DAT_007c54e8 + 0x403c));
    if (DAT_007c56a4 == 7) {
      iVar2 = *(int *)(DAT_007c54e8 + 0x4060);
      FUN_004c2cb0(iVar2);
      if (iVar2 == 1) {
        FUN_004c2c20();
      }
      iVar4 = DAT_007c54e8;
      if ((DAT_007d0410 == 4) || (DAT_007d0410 == 3)) {
        uVar5 = 0;
        if ((*(int *)(DAT_007c54e8 + 0x4064) != 3) &&
           (((iVar3 = __ftol(), iVar3 <= *(int *)(iVar4 + 0x403c) &&
             (iVar4 = FUN_00568210(s_SeasonScoringInfo_005d2804), iVar4 != 0)) &&
            (iVar2 = thunk_FUN_0059d6a9(iVar2 + -1), iVar2 != 0)))) {
          uVar5 = FUN_00567970();
          uVar5 = FUN_00587ece(uVar5);
        }
        FUN_004c2c00(uVar5);
      }
    }
  }
  return;
}


