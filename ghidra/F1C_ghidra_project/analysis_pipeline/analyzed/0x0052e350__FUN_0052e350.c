// Function: FUN_0052e350 @ 0052e350
// Size (bytes): 391


int __thiscall FUN_0052e350(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_8;
  int local_4;
  
  iVar4 = 0;
  local_8 = 0;
  if (0 < param_3) {
    do {
      iVar1 = *(int *)(param_1 + 0x249c);
      local_4 = 0;
      if ((*(int *)(param_1 + 0x24e8) == iVar1) && (iVar1 <= param_3 - iVar4)) {
        iVar1 = FUN_0052df10((undefined4 *)(param_2 + iVar4));
        if (iVar1 == 0) {
          local_8 = local_8 + *(int *)(param_1 + 0x249c);
        }
        else {
          FUN_00588821(s_mpeg_fail_1__d_005da700,*(undefined4 *)(param_1 + 0x249c));
          uVar3 = *(uint *)(param_1 + 0x249c);
          puVar5 = (undefined4 *)(param_2 + iVar4);
          for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar5 = 0;
            puVar5 = puVar5 + 1;
          }
          for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar5 = 0;
            puVar5 = (undefined4 *)((int)puVar5 + 1);
          }
        }
        uVar3 = *(uint *)(param_1 + 0x249c);
        *(int *)(param_1 + 0x24e4) = *(int *)(param_1 + 0x24e4) + 1;
      }
      else {
        if (iVar1 <= *(int *)(param_1 + 0x24e8)) {
          local_4 = FUN_0052df10((undefined4 *)(param_1 + 0x1244));
          *(undefined4 *)(param_1 + 0x24e8) = 0;
          *(int *)(param_1 + 0x24e4) = *(int *)(param_1 + 0x24e4) + 1;
          if (local_4 != 0) {
            FUN_00588821(s_mpeg_fail_2__d_005da6f0,*(undefined4 *)(param_1 + 0x249c));
            uVar3 = *(uint *)(param_1 + 0x249c);
            puVar5 = (undefined4 *)(param_1 + 0x1244);
            for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
              *puVar5 = 0;
              puVar5 = puVar5 + 1;
            }
            for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
              *(undefined1 *)puVar5 = 0;
              puVar5 = (undefined4 *)((int)puVar5 + 1);
            }
          }
        }
        uVar3 = *(int *)(param_1 + 0x249c) - *(int *)(param_1 + 0x24e8);
        if (param_3 - iVar4 < (int)uVar3) {
          uVar3 = param_3 - iVar4;
        }
        puVar5 = (undefined4 *)(*(int *)(param_1 + 0x24e8) + 0x1244 + param_1);
        puVar6 = (undefined4 *)(param_2 + iVar4);
        for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        for (uVar2 = uVar3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
        *(uint *)(param_1 + 0x24e8) = *(int *)(param_1 + 0x24e8) + uVar3;
        if (local_4 == 0) {
          local_8 = local_8 + uVar3;
        }
      }
      iVar4 = iVar4 + uVar3;
    } while (iVar4 < param_3);
  }
  *(int *)(param_1 + 0x24b4) =
       (*(int *)(param_1 + 0x24e4) + -1) * *(int *)(param_1 + 0x248c) + *(int *)(param_1 + 0x24e8);
  return local_8;
}


