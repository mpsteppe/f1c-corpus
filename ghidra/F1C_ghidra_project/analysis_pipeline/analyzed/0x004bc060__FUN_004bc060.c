// Function: FUN_004bc060 @ 004bc060
// Size (bytes): 127


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004bc060(int param_1,char param_2)

{
  int iVar1;
  
  iVar1 = DAT_008aae64;
  if (DAT_007c56a4 == 7) {
    if (DAT_0083ee60 < 0x3ff) {
      DAT_0083ee60 = DAT_0083ee60 + 1;
      DAT_008aae64 = DAT_008aae64 + 0x1b0;
    }
    if (param_2 != '\0') {
      FUN_004b33b0(4,0x1a,1,*(undefined4 *)(param_1 + 4),(float)_DAT_008afea0,0);
      *(undefined1 *)(iVar1 + 8) = *(undefined1 *)(param_1 + 0x34);
      return;
    }
    FUN_004b33b0(4,0x1b,0,*(undefined4 *)(param_1 + 4),(float)_DAT_008afea0,0);
  }
  return;
}


