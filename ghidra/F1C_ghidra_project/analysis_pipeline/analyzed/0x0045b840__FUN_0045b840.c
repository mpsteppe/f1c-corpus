// Function: FUN_0045b840 @ 0045b840
// Size (bytes): 270


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0045b840(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  int local_14;
  int local_10;
  int local_8;
  int local_4;
  
  FUN_0045bb00();
  iVar2 = *(int *)(param_1 + 0x31c);
  iVar4 = 0;
  local_14 = 0;
  *(undefined1 *)(param_1 + 800) = 0;
  FUN_0045b660();
  FUN_004dcf30(&local_8,0);
  local_4 = __ftol();
  local_10 = 0;
  do {
    uVar5 = local_10 + iVar2 & 0x80000007;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
    }
    iVar1 = uVar5 * 0x5c + param_1;
    if (DAT_0059e440 < *(float *)(uVar5 * 0x5c + 0x90 + param_1)) {
      FUN_004dd030(iVar1 + 0x3c,local_8 / 2,iVar4,*(undefined4 *)(iVar1 + 0x8c),2,0xbf800000,
                   0xbf800000,0);
      fVar3 = *(float *)(iVar1 + 0x90) - (float)_DAT_008afe90;
      *(float *)(iVar1 + 0x90) = fVar3;
      if (fVar3 < DAT_0059e440 == (fVar3 == DAT_0059e440)) {
        *(undefined1 *)(param_1 + 800) = 1;
      }
      else {
        FUN_0045b430(uVar5);
      }
      local_14 = local_14 + 1;
      iVar4 = iVar4 + local_4;
      if (3 < local_14) {
        return;
      }
    }
    local_10 = local_10 + 1;
    if (7 < local_10) {
      return;
    }
  } while( true );
}


