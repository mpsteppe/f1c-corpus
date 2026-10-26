// Function: FUN_0058b92a @ 0058b92a
// Size (bytes): 213


undefined4 FUN_0058b92a(uint param_1,void *param_2,size_t param_3)

{
  int iVar1;
  undefined4 *puVar2;
  DWORD DVar3;
  uint uVar4;
  void *pvVar5;
  undefined4 uVar6;
  CHAR local_10c [260];
  LPSTR local_8;
  
  uVar4 = param_1;
  if (param_1 == 0) {
    DVar3 = GetCurrentDirectoryA(0x104,local_10c);
  }
  else {
    iVar1 = FUN_0058b9ff(param_1);
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)FUN_0058afd8();
      *puVar2 = 0xf;
      puVar2 = (undefined4 *)FUN_0058afcf();
      *puVar2 = 0xd;
      return 0;
    }
    param_1 = (uint)CONCAT12(0x2e,CONCAT11(0x3a,(char)uVar4 + '@'));
    DVar3 = GetFullPathNameA((LPCSTR)&param_1,0x104,local_10c,&local_8);
  }
  if ((DVar3 != 0) && (uVar4 = DVar3 + 1, uVar4 < 0x105)) {
    if (param_2 == (void *)0x0) {
      if ((int)uVar4 <= (int)param_3) {
        uVar4 = param_3;
      }
      pvVar5 = _malloc(uVar4);
      if (pvVar5 != (void *)0x0) {
LAB_0058b9eb:
        uVar6 = FUN_0058fca0(pvVar5,local_10c);
        return uVar6;
      }
      puVar2 = (undefined4 *)FUN_0058afcf();
      *puVar2 = 0xc;
    }
    else {
      pvVar5 = param_2;
      if ((int)uVar4 <= (int)param_3) goto LAB_0058b9eb;
      puVar2 = (undefined4 *)FUN_0058afcf();
      *puVar2 = 0x22;
    }
  }
  return 0;
}


