// Function: FUN_0059b092 @ 0059b092
// Size (bytes): 99


undefined4
FUN_0059b092(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  bool bVar2;
  
  InterlockedIncrement(&DAT_008d5a5c);
  bVar2 = DAT_008d5a58 != 0;
  if (bVar2) {
    InterlockedDecrement(&DAT_008d5a5c);
    FUN_0058dfea(0x13);
  }
  uVar1 = FUN_0059b0f5(param_1,param_2,param_3,param_4,param_5);
  if (bVar2) {
    FUN_0058e04b(0x13);
  }
  else {
    InterlockedDecrement(&DAT_008d5a5c);
  }
  return uVar1;
}


