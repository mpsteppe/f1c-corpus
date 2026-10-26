// Function: FUN_00563e00 @ 00563e00
// Size (bytes): 109


undefined4 __fastcall FUN_00563e00(int *param_1)

{
  int iVar1;
  
  if (*param_1 != 0) {
    return 4;
  }
  FUN_00564860();
  iVar1 = FUN_00564810(&LAB_005640f0);
  param_1[1] = iVar1;
  FUN_00564740();
  iVar1 = FUN_005646d0(4,&LAB_005645a0,&LAB_00564600,&LAB_00564630);
  param_1[0x25] = iVar1;
  param_1[0x26] = 0;
  return 0;
}


