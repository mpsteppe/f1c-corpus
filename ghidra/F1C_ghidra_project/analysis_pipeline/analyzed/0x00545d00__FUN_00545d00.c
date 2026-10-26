// Function: FUN_00545d00 @ 00545d00
// Size (bytes): 547


void __thiscall FUN_00545d00(int param_1,uint param_2,uint *param_3)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint local_8;
  int local_4;
  
  if ((param_2 & 0x20) == 0) {
    if (((uint)param_3 & 0x20) != 0) {
      *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) | 0x800;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1b0) = 0;
  }
  for (iVar4 = *(int *)(param_1 + 0x100); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x104)) {
    if (*(int *)(iVar4 + 0xec) != 0) {
      FUN_0054bcd0(param_2,param_3,0);
    }
  }
  if (*(int *)(param_1 + 0x108) != 0) {
    FUN_0054bcd0(param_2,param_3,0);
  }
  iVar4 = *(int *)(*(int *)(param_1 + 0x110) + 0x24);
  if (iVar4 != 0) {
    uVar5 = param_2 & 0x1800;
    uVar2 = (uint)param_3 & 0x1800;
    do {
      if (uVar5 == 0x800) {
        *(uint *)(iVar4 + 0x9c) = *(uint *)(iVar4 + 0x9c) | 0x40;
      }
      else if (uVar5 == 0x1000) {
        *(uint *)(iVar4 + 0x9c) = *(uint *)(iVar4 + 0x9c) | 0x80;
      }
      else if (uVar5 == 0x1800) {
        *(byte *)(iVar4 + 0x9c) = *(byte *)(iVar4 + 0x9c) | 0xc0;
      }
      if (uVar2 == 0x800) {
        *(uint *)(iVar4 + 0x9c) = *(uint *)(iVar4 + 0x9c) & 0xffffffbf;
      }
      else if (uVar2 == 0x1000) {
        *(uint *)(iVar4 + 0x9c) = *(uint *)(iVar4 + 0x9c) & 0xffffff7f;
      }
      else if (uVar2 == 0x1800) {
        *(uint *)(iVar4 + 0x9c) = *(uint *)(iVar4 + 0x9c) & 0xffffff3f;
      }
      iVar4 = *(int *)(iVar4 + 0xc0);
    } while (iVar4 != 0);
  }
  local_4 = 0;
  puVar3 = param_3;
  do {
    switch(local_4) {
    case 0:
      puVar3 = *(uint **)(param_1 + 0x1b8);
      param_2 = *(uint *)(param_1 + 0x1b4);
      break;
    case 1:
      puVar3 = *(uint **)(param_1 + 0x1c0);
      param_2 = *(uint *)(param_1 + 0x1bc);
      break;
    case 2:
      puVar3 = *(uint **)(param_1 + 0x1c8);
      param_2 = *(uint *)(param_1 + 0x1c4);
      break;
    case 3:
      puVar3 = *(uint **)(param_1 + 0x1d0);
      param_2 = *(uint *)(param_1 + 0x1cc);
    }
    if (0 < (int)param_2) {
      uVar2 = (uint)param_3 & 0x1800;
      puVar6 = puVar3 + 9;
      local_8 = param_2;
      do {
        if (uVar2 == 0x800) {
          *puVar3 = *puVar3 & 0xfffffbff;
        }
        else if (uVar2 == 0x1000) {
          iVar4 = 8;
          puVar1 = puVar6;
          do {
            if (*puVar1 == 8) {
              *puVar1 = 0;
              puVar1[1] = 0;
              puVar1[3] = 0;
            }
            puVar1 = puVar1 + 0x10;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        else if (uVar2 == 0x1800) {
          *puVar3 = *puVar3 & 0xfffffbff;
          iVar4 = 8;
          puVar1 = puVar6;
          do {
            if (*puVar1 == 8) {
              *puVar1 = 0;
              puVar1[1] = 0;
              puVar1[3] = 0;
            }
            puVar1 = puVar1 + 0x10;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        puVar3 = puVar3 + 0x84;
        puVar6 = puVar6 + 0x84;
        local_8 = local_8 - 1;
      } while (local_8 != 0);
    }
    local_4 = local_4 + 1;
  } while (local_4 < 4);
  return;
}


