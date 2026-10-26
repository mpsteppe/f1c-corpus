// Function: FUN_004c6a10 @ 004c6a10
// Strings:  [%c. %-.11s, %-.13s, %-.13s, Abbreviation]


void __fastcall FUN_004c6a10(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char local_50 [16];
  char local_40 [63];
  undefined1 local_1;
  
  pcVar3 = (char *)(param_1 + 0x4620);
  if (pcVar3 != (char *)0x0) {
    iVar2 = FUN_00568210(pcVar3);
    if ((iVar2 == 0) || (iVar2 = FUN_005679c0(s_Abbreviation_005d3214), iVar2 == 0)) {
      iVar2 = FUN_00423a00(pcVar3,&DAT_005ec4cc);
      if (iVar2 != 0) {
        if (pcVar3 == (char *)0x0) {
          DAT_005ec4cc = 0;
        }
        else {
          iVar2 = (int)&DAT_005ec4cc - (int)pcVar3;
          do {
            cVar1 = *pcVar3;
            pcVar3[iVar2] = cVar1;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
        }
      }
      _strncpy(local_40,&DAT_005ec4cc,0x3f);
      local_1 = 0;
      iVar2 = FUN_00587c20(local_40,&DAT_005c32d8);
      if (iVar2 == 0) {
        FUN_0058815f(local_50,s____13s_005d320c,local_40);
      }
      else {
        FUN_0058815f(local_50,s__c_____11s_005d3200,(int)local_40[0],iVar2 + 1);
      }
    }
    else {
      pcVar3 = (char *)FUN_00567970();
      iVar2 = FUN_00423a00(pcVar3,&DAT_005ec4cc);
      if (iVar2 != 0) {
        if (pcVar3 == (char *)0x0) {
          DAT_005ec4cc = 0;
        }
        else {
          iVar2 = (int)&DAT_005ec4cc - (int)pcVar3;
          do {
            cVar1 = *pcVar3;
            pcVar3[iVar2] = cVar1;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
        }
      }
      FUN_0058815f(local_50,s____13s_005d320c,&DAT_005ec4cc);
    }
    FUN_00589901(local_50);
    _strncpy((char *)(param_1 + 0x46f8),local_50,0xf);
    *(undefined1 *)(param_1 + 0x4707) = 0;
  }
  return;
}


