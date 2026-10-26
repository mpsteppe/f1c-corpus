// Function: FUN_00548c20 @ 00548c20
// Size (bytes): 280


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00548c20(undefined4 *param_1,int param_2)

{
  int iVar1;
  float local_18;
  float local_14;
  float local_10;
  float local_c [3];
  
  local_10 = 0.0;
  local_14 = 0.0;
  local_18 = 0.0;
  local_c[2] = 0.0;
  local_c[0] = 0.0;
  local_c[1] = 0.0;
  if (param_1[2] != 0) {
    FUN_0054b530(&local_10,&local_14,&local_18,local_c + 2,local_c,local_c + 1);
  }
  FUN_00541d10(-local_10,-local_14 - _DAT_0059e8a4,-local_18);
  FUN_00541db0(0x3fc90fdb,-local_c[0],0);
  if (0 < *(int *)(param_2 + 0x174)) {
    FUN_005572b0();
    FUN_00541a70();
    FUN_00541b70(0xe);
    iVar1 = 0;
    if (0 < *(int *)(param_2 + 0x174)) {
      do {
        FUN_00556930(*param_1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_2 + 0x174));
    }
    FUN_005550e0(param_2,*param_1);
  }
  return;
}


