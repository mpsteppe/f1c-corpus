// Function: FUN_004b47a0 @ 004b47a0
// Size (bytes): 85


void __thiscall FUN_004b47a0(int param_1,char param_2,int param_3,uint param_4)

{
  int iVar1;
  byte bVar2;
  
  if (param_4 != 0xff) {
    param_1 = param_3 * 0xd + 1 + param_1;
    iVar1 = (int)(param_4 + ((int)param_4 >> 0x1f & 7U)) >> 3;
    param_4 = param_4 & 0x80000007;
    if ((int)param_4 < 0) {
      param_4 = (param_4 - 1 | 0xfffffff8) + 1;
    }
    bVar2 = '\x01' << ((byte)param_4 & 0x1f);
    if (param_2 != '\0') {
      *(byte *)(iVar1 + param_1) = *(byte *)(iVar1 + param_1) | bVar2;
      return;
    }
    *(byte *)(iVar1 + param_1) = *(byte *)(iVar1 + param_1) & ~bVar2;
  }
  return;
}


