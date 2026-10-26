// Function: FUN_00534e70 @ 00534e70
// Size (bytes): 112


uint __fastcall FUN_00534e70(undefined4 *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_1[0xf] != 0) {
    return 0xffffffff;
  }
  if (param_1[1] == 0) {
    puVar2 = (undefined4 *)FUN_0058afcf();
    *puVar2 = 0;
    iVar3 = FUN_0058803f(param_1[0x11],1,0x4000,param_1[0x10]);
    param_1[1] = iVar3;
    if (iVar3 == 0) {
      param_1[0xf] = 1;
      if ((*(byte *)(param_1[0x10] + 0xc) & 0x20) == 0) {
        return 0xffffffff;
      }
      param_1[0xe] = 0xffffffff;
      return 0xffffffff;
    }
    *param_1 = param_1[0x11];
  }
  param_1[1] = param_1[1] + -1;
  bVar1 = *(byte *)*param_1;
  *param_1 = (byte *)*param_1 + 1;
  return (uint)bVar1;
}


