// Function: FUN_004d59b0 @ 004d59b0
// Size (bytes): 305


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d59b0(void)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined1 local_9;
  float local_8;
  int local_4;
  
  local_9 = 4;
  FUN_004d5be0(&local_9,1);
  iVar5 = 0;
  iVar4 = 0;
  bVar1 = 0;
  do {
    bVar3 = bVar1;
    uVar2 = (uint)(byte)(&DAT_007c749a)[iVar4];
    if ((iVar4 == 5) && (DAT_007cea5c == 0)) {
      uVar2 = 1;
    }
    iVar5 = iVar5 + (uVar2 << (bVar3 & 0x1f));
    iVar4 = iVar4 + 1;
    bVar1 = bVar3 + 2;
  } while (iVar4 < 0xb);
  iVar4 = iVar5 + (DAT_007ce6d0 << (bVar3 + 2 & 0x1f)) + (DAT_007ce958 << (bVar3 + 4 & 0x1f));
  if (*(int *)(DAT_007c54e8 + 0x1054) == 1) {
    iVar4 = iVar4 + (1 << (bVar3 + 5 & 0x1f));
  }
  local_4 = iVar4 + ((uint)DAT_007ce874 << (bVar3 + 6 & 0x1f)) +
            ((uint)DAT_007ce88c << (bVar3 + 7 & 0x1f));
  FUN_004d5be0(&local_4,4);
  local_8 = _DAT_008afee4;
  FUN_004d5be0(&local_8,4);
  local_8 = _DAT_008afee8;
  FUN_004d5be0(&local_8,4);
  local_8 = _DAT_008afeec;
  FUN_004d5be0(&local_8,4);
  local_8 = _DAT_008afef0 + _DAT_005acafc;
  FUN_004d5be0(&local_8,4);
  local_8 = _DAT_008afef4 + _DAT_005acafc;
  FUN_004d5be0(&local_8,4);
  return;
}


