// Function: FUN_0052dc90 @ 0052dc90
// Size (bytes): 184


undefined4 __fastcall FUN_0052dc90(uint param_1)

{
  int iVar1;
  uint local_8;
  
  local_8 = param_1;
  if (*(char *)(param_1 + 0x2d3c) != '\0') {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x2d34) + 8))(&local_8,4,0);
    if (iVar1 != 4) {
      FUN_00588821(s_waiting_for_cd_access_005da65c);
      return 0xffffffff;
    }
    iVar1 = FUN_0052da30(local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
  }
  iVar1 = *(int *)(param_1 + 0x2498);
  if (iVar1 < 4) {
    FUN_00588821(s_CMpegFilePlayer__DecodeHeader___r_005da5fc,local_8,iVar1);
  }
  else {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x2d34) + 8))
                      (*(undefined4 *)(param_1 + 0x24a4),iVar1,0);
    if (iVar1 != *(int *)(param_1 + 0x2498)) {
      *(undefined1 *)(param_1 + 0x2d3c) = 0;
      return 0xffffffff;
    }
  }
  *(undefined4 *)(param_1 + 0x24a8) = 0;
  *(undefined1 *)(param_1 + 0x2d3c) = 1;
  return 0;
}


