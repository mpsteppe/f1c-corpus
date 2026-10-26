// Function: FUN_00596773 @ 00596773
// Size (bytes): 201


uint FUN_00596773(LPWSTR param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_2 != (byte *)0x0) && (param_3 != 0)) {
    bVar1 = *param_2;
    if (bVar1 != 0) {
      if (DAT_008d3f38 == 0) {
        if (param_1 != (LPWSTR)0x0) {
          *param_1 = (ushort)bVar1;
        }
        return 1;
      }
      if ((PTR_DAT_005e69c8[(uint)bVar1 * 2 + 1] & 0x80) == 0) {
        iVar2 = MultiByteToWideChar(DAT_008d3f48,9,(LPCSTR)param_2,1,param_1,
                                    (uint)(param_1 != (LPWSTR)0x0));
        if (iVar2 != 0) {
          return 1;
        }
      }
      else {
        if (1 < (int)DAT_005e6bd4) {
          if ((int)param_3 < (int)DAT_005e6bd4) goto LAB_00596805;
          iVar2 = MultiByteToWideChar(DAT_008d3f48,9,(LPCSTR)param_2,DAT_005e6bd4,param_1,
                                      (uint)(param_1 != (LPWSTR)0x0));
          if (iVar2 != 0) {
            return DAT_005e6bd4;
          }
        }
        if ((DAT_005e6bd4 <= param_3) && (param_2[1] != 0)) {
          return DAT_005e6bd4;
        }
      }
LAB_00596805:
      puVar3 = (undefined4 *)FUN_0058afcf();
      *puVar3 = 0x2a;
      return 0xffffffff;
    }
    if (param_1 != (LPWSTR)0x0) {
      *param_1 = L'\0';
    }
  }
  return 0;
}


