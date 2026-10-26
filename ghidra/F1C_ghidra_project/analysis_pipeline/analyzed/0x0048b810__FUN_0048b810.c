// Function: FUN_0048b810 @ 0048b810
// Size (bytes): 213


undefined4 __thiscall FUN_0048b810(int *param_1,byte *param_2)

{
  byte bVar1;
  byte *_Dest;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  char *pcVar6;
  bool bVar7;
  
  if (param_2 == (byte *)0x0) {
    return 0xffffffff;
  }
  _Dest = (byte *)param_1[0xbc];
  pbVar3 = _Dest;
  pbVar5 = param_2;
  do {
    bVar1 = *pbVar3;
    bVar7 = bVar1 < *pbVar5;
    if (bVar1 != *pbVar5) {
LAB_0048b855:
      iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      goto LAB_0048b85a;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar7 = bVar1 < pbVar5[1];
    if (bVar1 != pbVar5[1]) goto LAB_0048b855;
    pbVar3 = pbVar3 + 2;
    pbVar5 = pbVar5 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_0048b85a:
  if (iVar4 == 0) {
    return 0xffffffff;
  }
  iVar4 = param_1[0xbe];
  _strncpy((char *)_Dest,(char *)param_2,iVar4 - 1U);
  _Dest[iVar4 - 1U] = 0;
  pcVar6 = (char *)param_1[0xbc];
  cVar2 = *pcVar6;
  do {
    if (cVar2 == '\0') {
LAB_0048b8a9:
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
    cVar2 = FUN_0048b560(cVar2);
    if (cVar2 == '\0') {
      *pcVar6 = '\0';
      goto LAB_0048b8a9;
    }
    cVar2 = pcVar6[1];
    pcVar6 = pcVar6 + 1;
  } while( true );
}


