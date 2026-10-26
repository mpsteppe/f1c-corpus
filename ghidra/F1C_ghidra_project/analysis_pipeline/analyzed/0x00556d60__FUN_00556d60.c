// Function: FUN_00556d60 @ 00556d60
// Size (bytes): 270


void __thiscall FUN_00556d60(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  local_4 = 0;
  if ((*(uint *)(param_2 + 0x14) & 0x2000000) == 0) {
    iVar5 = *(int *)(param_2 + 0x11c);
    iVar4 = DAT_008b8f28;
    if (0 < *(int *)(param_2 + 0x118)) {
      do {
        iVar1 = 0;
        uVar2 = *(uint *)(*(int *)(iVar5 + 4) + 0x9c) & 0x120;
        if (uVar2 == 0) {
          iVar1 = *(int *)(iVar4 + 0x1c0);
LAB_00556ddb:
          iVar1 = *(int *)(*(int *)(iVar5 + 4) + 0xa0) * 0x210 + iVar1;
        }
        else {
          if (uVar2 == 0x20) {
            iVar1 = *(int *)(iVar4 + 0x1d0);
            goto LAB_00556ddb;
          }
          if (uVar2 == 0x100) {
            iVar1 = *(int *)(iVar4 + 0x1b8);
            goto LAB_00556ddb;
          }
          if (uVar2 == 0x120) {
            iVar1 = *(int *)(iVar4 + 0x1c8);
            goto LAB_00556ddb;
          }
        }
        if (*(int *)(iVar1 + 0x208) < *(int *)(iVar1 + 0x204)) {
          puVar3 = (undefined4 *)(*(int *)(iVar1 + 0x208) * 0x10 + *(int *)(iVar1 + 0x20c));
          *puVar3 = param_1;
          puVar3[1] = param_2;
          puVar3[2] = iVar5;
          puVar3[3] = *(undefined4 *)(iVar5 + 4);
          *(int *)(iVar1 + 0x208) = *(int *)(iVar1 + 0x208) + 1;
          iVar4 = DAT_008b8f28;
        }
        if ((*(uint *)(param_2 + 0x14) & 0x1000000) == 0) {
          *(uint *)(iVar5 + 0x38) = *(uint *)(iVar5 + 0x38) & 0xfffffdff;
          iVar4 = DAT_008b8f28;
        }
        if ((*(byte *)(param_2 + 0x14) & 0x20) == 0) {
          *(uint *)(iVar5 + 0x38) = *(uint *)(iVar5 + 0x38) & 0xfffffeff;
          iVar4 = DAT_008b8f28;
        }
        iVar5 = iVar5 + 0x40;
        local_4 = local_4 + 1;
      } while (local_4 < *(int *)(param_2 + 0x118));
    }
    *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x1000020;
  }
  return;
}


