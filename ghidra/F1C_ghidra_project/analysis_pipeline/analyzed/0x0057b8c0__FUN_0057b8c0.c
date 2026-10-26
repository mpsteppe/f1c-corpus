// Function: FUN_0057b8c0 @ 0057b8c0
// Size (bytes): 71


undefined2 * __fastcall FUN_0057b8c0(undefined2 *param_1)

{
  u_short uVar1;
  u_long uVar2;
  
  *param_1 = 2;
  uVar2 = htonl(0);
  *(u_long *)(param_1 + 2) = uVar2;
  uVar1 = htons(0);
  param_1[1] = uVar1;
  param_1[8] = 2;
  uVar2 = htonl(0);
  *(u_long *)(param_1 + 10) = uVar2;
  uVar1 = htons(0);
  param_1[9] = uVar1;
  FUN_0057b910();
  return param_1;
}


