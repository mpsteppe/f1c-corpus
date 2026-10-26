// Function: FUN_00512093 @ 00512093
// Size (bytes): 129


void FUN_00512093(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = 0;
  local_8 = 0;
  local_c = 0;
  if (param_1 != (int *)0x0) {
    local_8 = *param_1;
  }
  if (param_2 != (int *)0x0) {
    iVar1 = *param_2;
  }
  if (param_3 != (int *)0x0) {
    local_c = *param_3;
  }
  if (local_8 != 0) {
    FUN_00511f70(local_8,iVar1,local_c);
  }
  if (iVar1 != 0) {
    FUN_00517e85(iVar1);
    *param_2 = 0;
  }
  if (local_c != 0) {
    FUN_00517e85(local_c);
    *param_3 = 0;
  }
  if (local_8 != 0) {
    FUN_00517e85(local_8);
    *param_1 = 0;
  }
  return;
}


