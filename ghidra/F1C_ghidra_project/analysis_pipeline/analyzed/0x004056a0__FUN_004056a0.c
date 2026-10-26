// Function: FUN_004056a0 @ 004056a0
// Size (bytes): 322


/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_004056a0(int param_1,int param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_20 [4];
  uint local_10;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  bVar1 = *(byte *)(param_2 + 0x1b);
  if (((bVar1 & 0x20) == 0) || ((bVar1 & 4) == 0)) {
    iVar3 = *(int *)(param_2 + 4);
  }
  else {
    iVar3 = *(int *)(param_2 + 0x20);
  }
  local_20[0] = iVar3 + 0x24;
  local_10 = (uint)*(ushort *)(param_2 + 0x18);
  local_4 = CONCAT22((short)((uint)param_2 >> 0x10),(ushort)*(byte *)(param_2 + 0x1a));
  local_20[1] = 0x10;
  local_20[2] = 1;
  local_20[3] = ((bVar1 & 1) != 0) + 1;
  local_8 = (int)((uint)(ushort)*(byte *)(param_2 + 0x1a) * local_20[3]) >> 3;
  local_c = local_8 * local_10;
  param_2 = iVar3;
  uVar2 = FUN_00405670(param_1 + 0x44,&DAT_005be844,4);
  uVar2 = FUN_00405670(uVar2,local_20,4);
  uVar2 = FUN_00405670(uVar2,&DAT_005be83c,4);
  uVar2 = FUN_00405670(uVar2,&DAT_005be834,4);
  uVar2 = FUN_00405670(uVar2,local_20 + 1,4);
  uVar2 = FUN_00405670(uVar2,local_20 + 2,2);
  uVar2 = FUN_00405670(uVar2,local_20 + 3,2);
  uVar2 = FUN_00405670(uVar2,&local_10,4);
  uVar2 = FUN_00405670(uVar2,&local_c,4);
  uVar2 = FUN_00405670(uVar2,&local_8,2);
  uVar2 = FUN_00405670(uVar2,&local_4,2);
  uVar2 = FUN_00405670(uVar2,&DAT_005be82c,4);
  FUN_00405670(uVar2,&param_2,4);
  return;
}


