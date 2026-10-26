// Function: FUN_00587260 @ 00587260
// Size (bytes): 166


undefined4 __thiscall FUN_00587260(int param_1,ushort *param_2,int *param_3)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  ushort *puVar5;
  uint local_8;
  undefined4 *local_4;
  
  uVar2 = FUN_00587250();
  if (*param_3 < (int)(uint)uVar2) {
    return 0;
  }
  local_4 = (undefined4 *)0x0;
  *param_2 = uVar2;
  local_8 = *param_3 - 2;
  puVar4 = param_2 + 1;
  cVar1 = FUN_00587580(&local_4,&local_8);
  if (cVar1 != '\0') {
    puVar5 = puVar4;
    for (uVar3 = local_8 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)puVar5 = *local_4;
      local_4 = local_4 + 1;
      puVar5 = puVar5 + 2;
    }
    puVar4 = (ushort *)((int)puVar4 + local_8);
    for (local_8 = local_8 & 3; local_8 != 0; local_8 = local_8 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)local_4;
      local_4 = (undefined4 *)((int)local_4 + 1);
      puVar5 = (ushort *)((int)puVar5 + 1);
    }
  }
  *(undefined4 *)puVar4 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(puVar4 + 2) = *(undefined4 *)(param_1 + 0x14);
  *(undefined1 *)(puVar4 + 4) = *(undefined1 *)(param_1 + 0x18);
  *param_3 = (int)((int)(puVar4 + 4) + (1 - (int)param_2));
  return 1;
}


