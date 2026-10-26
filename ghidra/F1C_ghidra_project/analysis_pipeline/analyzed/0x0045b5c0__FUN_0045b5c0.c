// Function: FUN_0045b5c0 @ 0045b5c0
// Size (bytes): 148


float10 __fastcall FUN_0045b5c0(int param_1)

{
  int iVar1;
  int iVar2;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  local_4 = FUN_0045bb00();
  iVar2 = 0;
  local_14 = 0.0;
  if (0 < local_4) {
    do {
      iVar1 = FUN_0045b580(iVar2);
      local_10 = 0.0;
      FUN_00456040(&local_8,&local_c);
      FUN_004dd400(iVar1 * 0x5c + 0x3c + param_1,local_8,local_c,&local_10,0,0);
      if (local_14 < local_10) {
        local_14 = local_10;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < local_4);
  }
  return (float10)local_14;
}


