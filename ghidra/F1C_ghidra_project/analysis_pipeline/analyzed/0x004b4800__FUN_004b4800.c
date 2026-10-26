// Function: FUN_004b4800 @ 004b4800
// Size (bytes): 51


void __thiscall FUN_004b4800(int param_1,int param_2,uint param_3)

{
  byte *pbVar1;
  uint uVar2;
  
  uVar2 = param_3 & 0x80000007;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
  }
  pbVar1 = (byte *)(((int)(param_3 + ((int)param_3 >> 0x1f & 7U)) >> 3) +
                   param_2 * 0xd + 0x35 + param_1);
  *pbVar1 = *pbVar1 | '\x01' << ((byte)uVar2 & 0x1f);
  return;
}


