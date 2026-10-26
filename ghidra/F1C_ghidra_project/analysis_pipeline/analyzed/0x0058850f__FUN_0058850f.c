// Function: FUN_0058850f @ 0058850f
// Size (bytes): 87


float10 FUN_0058850f(byte *param_1)

{
  uint uVar1;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 local_1c [24];
  
  while( true ) {
    if (DAT_005e6bd4 < 2) {
      uVar1 = (byte)PTR_DAT_005e69c8[(uint)*param_1 * 2] & 8;
    }
    else {
      uVar1 = FUN_0058c674(*param_1,8);
    }
    if (uVar1 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar5 = 0;
  uVar4 = 0;
  sVar2 = _strlen((char *)param_1);
  iVar3 = FUN_0058e12e(local_1c,param_1,sVar2,uVar4,uVar5);
  return (float10)*(double *)(iVar3 + 0x10);
}


