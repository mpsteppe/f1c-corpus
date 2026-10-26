// Function: FUN_005968f6 @ 005968f6
// Size (bytes): 312


undefined4 FUN_005968f6(int param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  byte bVar1;
  bool bVar2;
  size_t sVar3;
  DWORD DVar4;
  char *_Source;
  char *_Dest;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  char local_84 [128];
  
  if (param_1 != 1) {
    if (param_1 != 0) {
      return 0xffffffff;
    }
    pbVar7 = &DAT_008d41c4;
    iVar5 = FUN_00597d3c(param_2,param_3,&DAT_008d41c4,4,0);
    if (iVar5 != 0) {
      *param_4 = '\0';
      while( true ) {
        bVar1 = *pbVar7;
        if (DAT_005e6bd4 < 2) {
          uVar6 = (byte)PTR_DAT_005e69c8[(uint)bVar1 * 2] & 4;
        }
        else {
          uVar6 = FUN_0058c674(bVar1,4);
        }
        if (uVar6 == 0) break;
        pbVar7 = pbVar7 + 2;
        *param_4 = *param_4 * '\n' + bVar1 + -0x30;
        if (0x8d41cb < (int)pbVar7) {
          return 0;
        }
      }
      return 0;
    }
    return 0xffffffff;
  }
  _Source = local_84;
  bVar2 = false;
  sVar3 = FUN_00597e4f(param_2,param_3,local_84,0x80,0);
  if (sVar3 == 0) {
    DVar4 = GetLastError();
    if (DVar4 != 0x7a) {
      return 0xffffffff;
    }
    sVar3 = FUN_00597e4f(param_2,param_3,0,0,0);
    if (sVar3 == 0) {
      return 0xffffffff;
    }
    _Source = _malloc(sVar3);
    if (_Source == (char *)0x0) {
      return 0xffffffff;
    }
    bVar2 = true;
    sVar3 = FUN_00597e4f(param_2,param_3,_Source,sVar3,0);
    if (sVar3 == 0) goto LAB_00596994;
  }
  _Dest = _malloc(sVar3);
  *(char **)param_4 = _Dest;
  if (_Dest != (char *)0x0) {
    _strncpy(_Dest,_Source,sVar3);
    if (bVar2) {
      FUN_0058aa6f(_Source);
    }
    return 0;
  }
  if (!bVar2) {
    return 0xffffffff;
  }
LAB_00596994:
  FUN_0058aa6f(_Source);
  return 0xffffffff;
}


