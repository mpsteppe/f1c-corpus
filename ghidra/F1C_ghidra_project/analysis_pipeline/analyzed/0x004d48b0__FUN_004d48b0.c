// Function: FUN_004d48b0 @ 004d48b0
// Size (bytes): 70


void __fastcall FUN_004d48b0(int param_1)

{
  int iVar1;
  
  if (((PTR_FUN_005d43c8 != (undefined *)0x0) && (*(int *)(param_1 + 4) != 0)) &&
     (iVar1 = *(int *)(param_1 + 8) + -1, *(int *)(param_1 + 8) = iVar1, iVar1 < 1)) {
    (*(code *)PTR_FUN_005d43c8)();
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_00587bcf(*(int *)(param_1 + 0xc));
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}


