// Function: FUN_004d98a0 @ 004d98a0
// Size (bytes): 316


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004d98a0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char local_80 [128];
  
  if (*(float *)(param_1 + 0x10) < DAT_0059e440) {
    return 1;
  }
  *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x10) - (float)_DAT_008afe98;
  iVar2 = DAT_007c54e0;
  if (DAT_007c54e0 != 0) {
    iVar3 = *(int *)(DAT_007c54e0 + 0x4060) + -1;
    if ((-1 < iVar3) && (iVar3 < 0x19)) {
      FUN_0058815f(local_80,&DAT_005ccef0,(int)(char)(DAT_005d4ae8 + (char)iVar3));
      FUN_004d7e40(local_80,100,0x332,0xffffff,0,3,DAT_005acf60,DAT_005acf60);
    }
    pcVar4 = (char *)(iVar2 + 0x46f8);
    iVar3 = -(int)pcVar4;
    do {
      cVar1 = *pcVar4;
      pcVar4[(int)(local_80 + iVar3)] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00589901(local_80);
    FUN_004d7e40(local_80,0xd2,0x332,0xffffff,0,0,0x3f800000,0x3f800000);
    pcVar4 = (char *)(iVar2 + 0x46b8);
    iVar2 = -(int)pcVar4;
    do {
      cVar1 = *pcVar4;
      pcVar4[(int)(local_80 + iVar2)] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00589901(local_80);
    FUN_004d7e40(local_80,0xd2,0x35a,0x48aab3,0,0,0x3f800000,0x3f800000);
  }
  return 0;
}


