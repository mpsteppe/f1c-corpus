// Function: FUN_00429fd0 @ 00429fd0
// Size (bytes): 311


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_00429fd0(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  if (_DAT_0059e868 <= _DAT_008afee8) {
    if (_DAT_0059e7e8 <= _DAT_008afee8) {
      if (_DAT_0059e450 <= _DAT_008afee8) {
        if (_DAT_0059e970 <= _DAT_008afee8) {
          if (_DAT_0059e8cc <= _DAT_008afee8) {
            if (_DAT_0059e908 <= _DAT_008afee8) {
              iVar5 = 6;
            }
            else {
              uVar1 = _rand();
              uVar1 = uVar1 & 0x80000001;
              if ((int)uVar1 < 0) {
                uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
              }
              iVar5 = 6 - (uint)(uVar1 != 0);
            }
          }
          else {
            iVar5 = 5;
          }
        }
        else {
          uVar1 = _rand();
          uVar1 = uVar1 & 0x80000001;
          if ((int)uVar1 < 0) {
            uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
          }
          iVar5 = (uVar1 != 0) + 4;
        }
        goto LAB_0042a0c3;
      }
    }
    else {
      uVar1 = _rand();
      uVar1 = uVar1 & 0x80000001;
      bVar6 = uVar1 == 0;
      if ((int)uVar1 < 0) {
        bVar6 = (uVar1 - 1 | 0xfffffffe) == 0xffffffff;
      }
      if (!bVar6) {
        iVar5 = *(int *)(param_1 + 0x458c);
        goto LAB_0042a0c3;
      }
    }
    iVar5 = 4;
  }
  else {
    iVar5 = *(int *)(param_1 + 0x458c);
  }
LAB_0042a0c3:
  iVar3 = 0;
  iVar4 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 0x3978) + 0x10)) {
    do {
      FUN_004d7570(iVar4);
      iVar2 = FUN_004a4830();
      if (iVar5 == iVar2) {
        iVar3 = iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(*(int *)(param_1 + 0x3978) + 0x10));
  }
  return iVar3;
}


