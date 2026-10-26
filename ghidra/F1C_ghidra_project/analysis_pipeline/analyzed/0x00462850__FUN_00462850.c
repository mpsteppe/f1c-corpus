// Function: FUN_00462850 @ 00462850
// Size (bytes): 65


undefined4 __fastcall FUN_00462850(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_004a0590();
  if (iVar1 == 0) {
    if (DAT_007c56a4 == 7) {
      FUN_004613e0();
    }
    FUN_00460710();
    FUN_0045f2b0(0xffffffff);
    *(undefined1 *)(*param_1 + 0x374) = 1;
    return 1;
  }
  return 0;
}


