// Function: FUN_0058ab58 @ 0058ab58
// Size (bytes): 289


LPVOID FUN_0058ab58(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint _Size;
  LPVOID local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_005b8d00;
  puStack_10 = &LAB_0058895c;
  local_14 = ExceptionList;
  uVar2 = param_1 * param_2;
  uVar3 = uVar2;
  ExceptionList = &local_14;
  if (uVar2 < 0xffffffe1) {
    if (uVar2 == 0) {
      uVar3 = 1;
    }
    uVar3 = uVar3 + 0xf & 0xfffffff0;
    ExceptionList = &local_14;
  }
  do {
    local_24 = (LPVOID)0x0;
    if (uVar3 < 0xffffffe1) {
      if (DAT_008d4908 == 3) {
        if (uVar2 <= DAT_008d4900) {
          FUN_0058dfea(9);
          local_8 = 0;
          local_24 = (LPVOID)FUN_0059416f(uVar2);
          local_8 = 0xffffffff;
          FUN_0058abf1();
          _Size = uVar2;
          if (local_24 == (void *)0x0) goto LAB_0058ac45;
LAB_0058ac34:
          _memset(local_24,0,_Size);
        }
LAB_0058ac40:
        if (local_24 != (LPVOID)0x0) {
          ExceptionList = local_14;
          return local_24;
        }
      }
      else {
        if ((DAT_008d4908 != 2) || (DAT_005e998c < uVar3)) goto LAB_0058ac40;
        FUN_0058dfea(9);
        local_8 = 1;
        local_24 = (LPVOID)FUN_00594c12(uVar3 >> 4);
        local_8 = 0xffffffff;
        FUN_0058ac7a();
        _Size = uVar3;
        if (local_24 != (void *)0x0) goto LAB_0058ac34;
      }
LAB_0058ac45:
      local_24 = HeapAlloc(DAT_008d4904,8,uVar3);
    }
    if (local_24 != (LPVOID)0x0) {
      ExceptionList = local_14;
      return local_24;
    }
    if (DAT_008d41b0 == 0) {
      ExceptionList = local_14;
      return (LPVOID)0x0;
    }
    iVar1 = FUN_00593db8(uVar3);
    if (iVar1 == 0) {
      ExceptionList = local_14;
      return (LPVOID)0x0;
    }
  } while( true );
}


