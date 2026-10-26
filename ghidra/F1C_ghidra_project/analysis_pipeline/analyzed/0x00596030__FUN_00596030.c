// Function: FUN_00596030 @ 00596030
// Size (bytes): 89


undefined4 FUN_00596030(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  bool bVar2;
  
  InterlockedIncrement(&DAT_008d5a5c);
  bVar2 = DAT_008d5a58 != 0;
  if (bVar2) {
    InterlockedDecrement(&DAT_008d5a5c);
    FUN_0058dfea(0x13);
  }
  uVar1 = FUN_00596089(param_1,param_2);
  if (bVar2) {
    FUN_0058e04b(0x13);
  }
  else {
    InterlockedDecrement(&DAT_008d5a5c);
  }
  return uVar1;
}


