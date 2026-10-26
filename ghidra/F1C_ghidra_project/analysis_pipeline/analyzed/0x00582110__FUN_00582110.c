// Function: FUN_00582110 @ 00582110
// Size (bytes): 124


undefined4 * __fastcall FUN_00582110(undefined4 *param_1)

{
  u_short uVar1;
  u_long uVar2;
  
  *(undefined2 *)param_1 = 2;
  uVar2 = htonl(0);
  param_1[1] = uVar2;
  uVar1 = htons(0);
  *(u_short *)((int)param_1 + 2) = uVar1;
  *(undefined2 *)(param_1 + 4) = 2;
  uVar2 = htonl(0);
  param_1[5] = uVar2;
  uVar1 = htons(0);
  *(u_short *)((int)param_1 + 0x12) = uVar1;
  FUN_0057b530();
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0xffffffff;
  param_1[9] = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  *(undefined2 *)(param_1 + 0xd) = 0;
  return param_1;
}


