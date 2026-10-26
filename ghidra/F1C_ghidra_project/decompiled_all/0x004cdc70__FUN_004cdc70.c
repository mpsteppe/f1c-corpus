// Function: FUN_004cdc70 @ 004cdc70
// Strings:  [D:\dev\F1_1999_2002\Source\specialfx.cpp, Could not find track variable "%s" referenced with keyword "%s" in terrain.ini]


int FUN_004cdc70(undefined4 param_1,undefined4 param_2,float *param_3,byte *param_4)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  bool bVar7;
  float10 fVar8;
  byte local_80 [128];
  
  iVar3 = FUN_00565520(param_2,local_80,0);
  if (iVar3 != 0) {
    if ((((char)local_80[0] < '0') || ('9' < (char)local_80[0])) && (local_80[0] != 0x2e)) {
      do {
        if (param_4 == (byte *)0x0) {
          cVar2 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_speci_005d3624,0x8b7);
          if (cVar2 != '\0') {
            FUN_004d7aa0(&DAT_008ad25c,s_Could_not_find_track_variable____005d37e8,local_80,param_2)
            ;
          }
          return 0;
        }
        pbVar4 = local_80;
        pbVar6 = param_4;
        do {
          bVar1 = *pbVar4;
          bVar7 = bVar1 < *pbVar6;
          if (bVar1 != *pbVar6) {
LAB_004cdd0a:
            iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
            goto LAB_004cdd0f;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar7 = bVar1 < pbVar6[1];
          if (bVar1 != pbVar6[1]) goto LAB_004cdd0a;
          pbVar4 = pbVar4 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_004cdd0f:
        if (iVar5 == 0) {
          *param_3 = *(float *)(param_4 + 0x20);
          return iVar3;
        }
        param_4 = *(byte **)(param_4 + 0x24);
      } while( true );
    }
    fVar8 = (float10)FUN_0058850f(local_80);
    *param_3 = (float)fVar8;
  }
  return iVar3;
}


