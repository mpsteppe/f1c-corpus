// Function: FUN_005898d3 @ 005898d3
// Size (bytes): 46


undefined4 FUN_005898d3(LPCSTR param_1,LPCSTR param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = MoveFileA(param_1,param_2);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
  }
  else {
    DVar2 = 0;
  }
  if (DVar2 != 0) {
    FUN_0058af5c(DVar2);
    return 0xffffffff;
  }
  return 0;
}


