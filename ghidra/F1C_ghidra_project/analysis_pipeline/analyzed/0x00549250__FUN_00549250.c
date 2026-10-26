// Function: FUN_00549250 @ 00549250
// Size (bytes): 86


void __thiscall FUN_00549250(int *param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  
  pbVar3 = param_2;
  if ((*param_2 & 4) != 0) {
    pbVar3 = (byte *)(*param_1 + 0x128);
  }
  iVar1 = *(int *)pbVar3;
  if (param_1[0x3d] == 0) {
    param_1[0x3d] = iVar1;
    param_2[0x68] = 0;
    param_2[0x69] = 0;
    param_2[0x6a] = 0;
    param_2[0x6b] = 0;
    param_2[0x6c] = 0;
    param_2[0x6d] = 0;
    param_2[0x6e] = 0;
    param_2[0x6f] = 0;
    return;
  }
  for (iVar2 = *(int *)(iVar1 + 0x6c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x6c)) {
    iVar1 = iVar2;
  }
  *(byte **)(iVar1 + 0x6c) = param_2;
  param_2[0x6c] = 0;
  param_2[0x6d] = 0;
  param_2[0x6e] = 0;
  param_2[0x6f] = 0;
  *(int *)(param_2 + 0x68) = iVar1;
  return;
}


