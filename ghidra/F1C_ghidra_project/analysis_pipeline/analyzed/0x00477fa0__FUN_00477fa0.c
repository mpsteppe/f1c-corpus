// Function: FUN_00477fa0 @ 00477fa0
// Size (bytes): 110


undefined4 __fastcall FUN_00477fa0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)param_1[0x10] + 0x1c))(3);
  if (iVar1 != 0) {
    iVar1 = FUN_0048d360();
    if (param_1[0x47] != iVar1) {
      iVar1 = FUN_0048d360();
      param_1[0x47] = iVar1;
      (**(code **)(*param_1 + 0xa0))();
    }
  }
  iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x12);
  if ((iVar1 != 0) && (param_1[0x48] != *(int *)(iVar1 + 0x174))) {
    param_1[0x48] = *(int *)(iVar1 + 0x174);
    (**(code **)(*param_1 + 0xa0))();
  }
  return 0;
}


