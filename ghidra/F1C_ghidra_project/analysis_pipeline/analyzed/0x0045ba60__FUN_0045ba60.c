// Function: FUN_0045ba60 @ 0045ba60
// Size (bytes): 145


void __thiscall FUN_0045ba60(int param_1,byte *param_2,char param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  
  if (param_2 != (byte *)0x0) {
    iVar4 = -1;
    pbVar6 = param_2;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar1 = *pbVar6;
      pbVar6 = pbVar6 + 1;
    } while (bVar1 != 0);
    if (iVar4 != -2) {
      iVar4 = 0;
      pbVar6 = (byte *)(param_1 + 0x3c);
      do {
        pbVar3 = pbVar6;
        pbVar5 = param_2;
        if (param_3 == '\0') {
          do {
            bVar1 = *pbVar3;
            bVar7 = bVar1 < *pbVar5;
            if (bVar1 != *pbVar5) {
LAB_0045bac6:
              iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
              goto LAB_0045bacb;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar7 = bVar1 < pbVar5[1];
            if (bVar1 != pbVar5[1]) goto LAB_0045bac6;
            pbVar3 = pbVar3 + 2;
            pbVar5 = pbVar5 + 2;
          } while (bVar1 != 0);
          iVar2 = 0;
LAB_0045bacb:
          bVar7 = iVar2 == 0;
        }
        else {
          iVar2 = FUN_00566810();
          bVar7 = iVar2 != 0;
        }
        if (bVar7) {
          FUN_0045b430(iVar4);
        }
        iVar4 = iVar4 + 1;
        pbVar6 = pbVar6 + 0x5c;
      } while (iVar4 < 8);
    }
  }
  return;
}


