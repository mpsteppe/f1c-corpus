// Function: FUN_00564410 @ 00564410
// Strings:  [final, final, queryid, queryid]


undefined4 __fastcall FUN_00564410(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  bool bVar6;
  char *local_8 [2];
  
  local_8[0] = s_queryid_005e505c;
  local_8[1] = s_final_005e5054;
  uVar5 = 0;
  do {
    pbVar4 = (byte *)local_8[uVar5];
    pbVar2 = param_1;
    do {
      bVar1 = *pbVar2;
      bVar6 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_00564459:
        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_0056445e;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar6 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_00564459;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0056445e:
    if (iVar3 == 0) {
      return 0;
    }
    uVar5 = uVar5 + 1;
    if (1 < uVar5) {
      return 1;
    }
  } while( true );
}


