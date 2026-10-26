// Function: FUN_00467430 @ 00467430
// Size (bytes): 165


undefined4 __thiscall FUN_00467430(int *param_1,byte *param_2)

{
  byte bVar1;
  char cVar2;
  byte *_Dest;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  bool bVar6;
  
  if (param_2 == (byte *)0x0) {
    return 0xffffffff;
  }
  _Dest = (byte *)param_1[0xbc];
  pbVar3 = _Dest;
  pbVar5 = param_2;
  do {
    bVar1 = *pbVar3;
    bVar6 = bVar1 < *pbVar5;
    if (bVar1 != *pbVar5) {
LAB_00467475:
      iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_0046747a;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar6 = bVar1 < pbVar5[1];
    if (bVar1 != pbVar5[1]) goto LAB_00467475;
    pbVar3 = pbVar3 + 2;
    pbVar5 = pbVar5 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_0046747a:
  if (iVar4 != 0) {
    iVar4 = param_1[0xbe];
    _strncpy((char *)_Dest,(char *)param_2,iVar4 - 1U);
    _Dest[iVar4 - 1U] = 0;
    param_1[0xbd] = param_1[0xbc];
    cVar2 = *(char *)param_1[0xbc];
    while (cVar2 != '\0') {
      iVar4 = param_1[0xbd];
      param_1[0xbd] = iVar4 + 1;
      cVar2 = *(char *)(iVar4 + 1);
    }
    (**(code **)(*param_1 + 0x2c))(1);
    return 0;
  }
  return 0xffffffff;
}


