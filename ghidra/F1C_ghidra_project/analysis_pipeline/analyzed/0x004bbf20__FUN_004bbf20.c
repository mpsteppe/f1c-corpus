// Function: FUN_004bbf20 @ 004bbf20
// Size (bytes): 78


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004bbf20(int param_1)

{
  if (DAT_0083ee60 < 0x3ff) {
    DAT_0083ee60 = DAT_0083ee60 + 1;
    DAT_008aae64 = DAT_008aae64 + 0x1b0;
  }
  FUN_004b33b0(4,0x18,0,*(undefined4 *)(param_1 + 4),(float)_DAT_008afea0,0);
  return *(undefined4 *)(param_1 + 0x44);
}


