// Function: FUN_004a5c80 @ 004a5c80
// Size (bytes): 138


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004a5c80(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != *(int *)(param_1 + 0x184)) {
    if ((param_2 == 1) || ((*(int *)(param_1 + 0x184) != 1 && (param_2 == 2)))) {
      *(float *)(param_1 + 0x18c) = (float)_DAT_008afea0;
    }
    iVar1 = DAT_008aae64;
    if (DAT_0083ee60 < 0x3ff) {
      DAT_0083ee60 = DAT_0083ee60 + 1;
      DAT_008aae64 = DAT_008aae64 + 0x1b0;
    }
    FUN_004b33b0(6,1,1,*(undefined4 *)(param_1 + 4),(float)_DAT_008afea0,0);
    *(char *)(iVar1 + 8) = (char)param_2;
    FUN_004a5d10(iVar1);
  }
  return;
}


