// Function: FUN_00586f70 @ 00586f70
// Size (bytes): 47


void __thiscall FUN_00586f70(int *param_1,uint param_2,char param_3)

{
  byte bVar1;
  byte *pbVar2;
  
  bVar1 = '\x01' << ((byte)param_2 & 7);
  if (param_3 != '\0') {
    pbVar2 = (byte *)(*param_1 + (param_2 >> 3));
    *pbVar2 = *pbVar2 | bVar1;
    return;
  }
  pbVar2 = (byte *)(*param_1 + (param_2 >> 3));
  *pbVar2 = *pbVar2 & ~bVar1;
  return;
}


