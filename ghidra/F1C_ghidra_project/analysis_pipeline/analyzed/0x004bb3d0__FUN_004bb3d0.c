// Function: FUN_004bb3d0 @ 004bb3d0
// Size (bytes): 41


void __fastcall FUN_004bb3d0(int *param_1)

{
  int iVar1;
  
  if (((char)param_1[3] != '\0') && (iVar1 = *param_1, iVar1 != 0)) {
    if (*(int *)(iVar1 + 4) != 0) {
      FUN_00587bcf(*(int *)(iVar1 + 4));
    }
    FUN_00587bcf(iVar1);
  }
  return;
}


