// Function: FUN_0059ba1d @ 0059ba1d
// Size (bytes): 134


undefined4 FUN_0059ba1d(LPCSTR param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  BOOL BVar3;
  DWORD DVar4;
  char local_10c;
  char local_10b;
  
  BVar3 = SetCurrentDirectoryA(param_1);
  if (BVar3 != 0) {
    DVar4 = GetCurrentDirectoryA(0x105,&local_10c);
    if (DVar4 != 0) {
      if (((local_10c != '\\') && (local_10c != '/')) || (local_10c != local_10b)) {
        param_1 = (LPCSTR)CONCAT31(param_1._1_3_,0x3d);
        uVar2 = FUN_0059c0ac(local_10c);
        uVar1 = SUB41(param_1,0);
        param_1 = (LPCSTR)(uint)CONCAT12(0x3a,CONCAT11(uVar2,uVar1));
        BVar3 = SetEnvironmentVariableA((LPCSTR)&param_1,&local_10c);
        if (BVar3 == 0) goto LAB_0059ba91;
      }
      return 0;
    }
  }
LAB_0059ba91:
  DVar4 = GetLastError();
  FUN_0058af5c(DVar4);
  return 0xffffffff;
}


