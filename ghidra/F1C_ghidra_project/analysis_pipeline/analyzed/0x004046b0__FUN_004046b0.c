// Function: FUN_004046b0 @ 004046b0
// Size (bytes): 221


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004046b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  local_4 = 0;
  if (0 < *(int *)(param_1 + 0x130)) {
    iVar4 = 0;
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x134) + 0x114 + iVar4);
      if (iVar1 != 0) {
        if (*(int *)(iVar1 + 300) < *(int *)(param_1 + 0x10)) {
          if ((*(int *)(iVar1 + 300) == 1) &&
             (*(int *)(*(int *)(param_1 + 0x134) + iVar4 + 300) == 0)) {
            *(undefined4 *)(iVar1 + 0x4c) = 0;
            iVar3 = *(int *)(iVar1 + 0x110);
            while ((((iVar3 != 0 && (iVar2 = *(int *)(iVar3 + 0x110), iVar2 != 0)) &&
                    (iVar3 != iVar1)) && (*(int *)(iVar2 + 0x10c) == iVar3))) {
              *(float *)(iVar3 + 0x4c) =
                   *(float *)(*(int *)(iVar3 + 0x10c) + 0x4c) +
                   *(float *)(*(int *)(iVar3 + 0x10c) + 0x3c);
              iVar3 = iVar2;
            }
          }
        }
        else {
          iVar3 = FUN_004038e0(iVar1,1);
          if ((iVar3 != 0) && (*(int *)(iVar3 + 0x10c) != 0)) {
            *(float *)(iVar1 + 0x4c) =
                 (*(float *)(*(int *)(iVar3 + 0x10c) + 0x4c) + *(float *)(iVar3 + 0x4c)) *
                 _DAT_0059e450;
          }
        }
      }
      local_4 = local_4 + 1;
      iVar4 = iVar4 + 0x13c;
    } while (local_4 < *(int *)(param_1 + 0x130));
  }
  return;
}


