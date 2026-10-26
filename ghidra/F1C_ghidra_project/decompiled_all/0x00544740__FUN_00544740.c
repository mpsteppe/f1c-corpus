// Function: FUN_00544740 @ 00544740
// Strings:  [SHADOWTEX%.3d]


undefined4 __fastcall FUN_00544740(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int local_24;
  undefined1 auStack_20 [32];
  
  iVar1 = FUN_0055c9b0();
  if ((iVar1 != 0) && ((*(uint *)(param_1 + 0xec) & 0x100000) != 0)) {
    if (0 < *(int *)(param_1 + 0x160)) {
      iVar1 = 0;
      if (0 < *(int *)(param_1 + 0x160)) {
        do {
          FUN_005502c0();
          iVar1 = iVar1 + 1;
        } while (iVar1 < *(int *)(param_1 + 0x160));
      }
      FUN_005478b0(*(undefined4 *)(param_1 + 0x164));
      *(undefined4 *)(param_1 + 0x160) = 0;
      *(undefined4 *)(param_1 + 0x164) = 0;
      FUN_00541420();
    }
    *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) & 0xffefffff;
  }
  FUN_0055c440(param_1);
  if ((*(uint *)(param_1 + 0xec) & 0x100000) == 0) {
    iVar1 = FUN_0055c9b0();
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 0x158) < 1) goto LAB_00544a53;
      local_24 = 1;
    }
    else {
      local_24 = *(int *)(param_1 + 0x158);
      if (local_24 < 1) goto LAB_00544a53;
    }
    if (DAT_008b8dbc == 0) {
      if (DAT_008b8dc0 != 0) {
        FUN_00542e50();
        iVar1 = DAT_008b8dc0;
        if (DAT_008b8dc0 != 0) {
          FUN_00557470();
          FUN_00587bcf(iVar1);
        }
        DAT_008b8dc0 = 0;
      }
    }
    else {
      FUN_00542e50();
      iVar1 = DAT_008b8dbc;
      if (DAT_008b8dbc != 0) {
        FUN_00557470();
        FUN_00587bcf(iVar1);
      }
      DAT_008b8dbc = 0;
    }
    piVar2 = operator_new(local_24 * 0x60 + 4);
    if (piVar2 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = piVar2 + 1;
      *piVar2 = local_24;
      iVar1 = local_24;
      if (-1 < local_24 + -1) {
        do {
          FUN_0054fe10();
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
    }
    iVar1 = 0;
    *(int **)(param_1 + 0x164) = piVar3;
    piVar3[0x13] = local_24;
    if (0 < local_24) {
      do {
        FUN_0058815f(auStack_20,s_SHADOWTEX__3d_005dbe0c,iVar1);
        iVar4 = FUN_0054fe50(auStack_20);
        if (iVar4 != 0) {
          if (-1 < iVar1) {
            iVar1 = iVar1 + 1;
            do {
              FUN_005502c0();
              iVar1 = iVar1 + -1;
            } while (iVar1 != 0);
          }
          iVar1 = *(int *)(param_1 + 0x164);
          if (iVar1 != 0) {
            iVar4 = *(int *)(iVar1 + -4);
            if (-1 < iVar4 + -1) {
              do {
                FUN_00557470();
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            FUN_00587bcf(iVar1 + -4);
          }
LAB_005449c8:
          *(undefined4 *)(param_1 + 0x164) = 0;
          break;
        }
        iVar4 = FUN_00542950(DAT_008b8df4,DAT_008b8df4,DAT_008b8df8,0x40008);
        if (iVar4 != 0) {
          if (-1 < iVar1) {
            iVar1 = iVar1 + 1;
            do {
              FUN_005502c0();
              iVar1 = iVar1 + -1;
            } while (iVar1 != 0);
          }
          FUN_005478b0(*(undefined4 *)(param_1 + 0x164));
          goto LAB_005449c8;
        }
        FUN_005435c0(0xff00ff);
        iVar1 = iVar1 + 1;
      } while (iVar1 < local_24);
    }
    if (*(int *)(param_1 + 0x164) != 0) {
      FUN_00547860(*(int *)(param_1 + 0x164));
      iVar1 = FUN_00541340(0x800);
      if (iVar1 != 0) {
        iVar1 = local_24;
        if (0 < local_24) {
          do {
            FUN_005502c0();
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
        }
        FUN_005478b0(*(undefined4 *)(param_1 + 0x164));
        *(undefined4 *)(param_1 + 0x164) = 0;
      }
    }
    if (*(int *)(param_1 + 0x164) != 0) {
      *(int *)(param_1 + 0x160) = local_24;
      *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) | 0x100000;
    }
  }
LAB_00544a53:
  for (iVar1 = *(int *)(param_1 + 0x100); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x104)) {
    for (iVar4 = *(int *)(iVar1 + 0xec); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x4c)) {
      iVar5 = FUN_00544db0(iVar4,0);
      if (iVar5 != 0) {
        return 0xffffffff;
      }
    }
  }
  iVar1 = *(int *)(param_1 + 0x108);
  while( true ) {
    if (iVar1 == 0) {
      for (iVar1 = *(int *)(param_1 + 0x148); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x68)) {
        FUN_005575f0();
      }
      return 0;
    }
    iVar4 = FUN_00544db0(iVar1,0);
    if (iVar4 != 0) break;
    iVar1 = *(int *)(iVar1 + 0x4c);
  }
  return 0xffffffff;
}


