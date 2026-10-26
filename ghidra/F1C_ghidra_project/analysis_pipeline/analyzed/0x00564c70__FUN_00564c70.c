// Function: FUN_00564c70 @ 00564c70
// Size (bytes): 349


/* WARNING: Removing unreachable block (ram,0x00564d49) */
/* WARNING: Removing unreachable block (ram,0x00564cc2) */
/* WARNING: Removing unreachable block (ram,0x00564d20) */
/* WARNING: Removing unreachable block (ram,0x00564d84) */

void FUN_00564c70(int param_1,int param_2)

{
  short sVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte local_100 [256];
  
  sVar1 = 0;
  pbVar2 = local_100;
  do {
    *pbVar2 = (byte)sVar1;
    sVar1 = sVar1 + 1;
    pbVar2 = pbVar2 + 1;
  } while (sVar1 < 0x100);
  iVar4 = 0x100;
  do {
    FUN_005622b0();
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = 0;
  sVar1 = 0;
  if (0 < param_2) {
    uVar5 = 0;
    uVar3 = 0;
    do {
      uVar5 = (uint)(byte)(*(char *)(iVar4 + param_1) + '\x01' + (char)uVar5);
      uVar3 = (uint)(byte)(local_100[uVar5] + (char)uVar3);
      FUN_005622b0();
      *(byte *)(iVar4 + param_1) =
           *(byte *)(iVar4 + param_1) ^
           local_100[(uint)local_100[uVar5] + (uint)local_100[uVar3] & 0xff];
      sVar1 = sVar1 + 1;
      iVar4 = (int)sVar1;
    } while (iVar4 < param_2);
  }
  return;
}


