// Function: FUN_0054bdc0 @ 0054bdc0
// Size (bytes): 322


void __thiscall FUN_0054bdc0(int param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int local_8;
  
  for (iVar2 = *(int *)(param_1 + 0x204); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {
    puVar6 = *(uint **)(iVar2 + 0x11c);
    local_8 = 0;
    if (0 < *(int *)(iVar2 + 0x118)) {
      do {
        uVar3 = *puVar6 & ~param_3 | param_2;
        *puVar6 = uVar3;
        if ((param_2 & 0x20) == 0) {
          if ((param_3 & 0x20) != 0) {
            if ((uVar3 & 3) == 0) {
              FUN_0055d900(0);
            }
            else {
              if ((uVar3 & 1) == 0) {
                FUN_0055e320(0);
              }
              else {
                FUN_0055da50(0);
              }
              if ((*(uint *)(iVar2 + 0x14) & 0x400000) != 0) {
                FUN_0055eb30();
              }
            }
          }
        }
        else {
          uVar3 = *(uint *)(DAT_008b8f28 + 0x1b0);
          FUN_0054e0e0(puVar6,6);
          iVar5 = 0;
          if (0 < (int)puVar6[2]) {
            iVar4 = 0;
            do {
              puVar1 = (uint *)(iVar4 + 0x18 + puVar6[8]);
              *puVar1 = *puVar1 & 0xff000000;
              puVar1 = (uint *)(iVar4 + 0x18 + puVar6[8]);
              *puVar1 = *puVar1 | (((uVar3 & 3) * 0x100 + ((int)uVar3 >> 2 & 3U)) * 0x100 +
                                  ((int)uVar3 >> 4 & 3U)) * 0x40;
              iVar5 = iVar5 + 1;
              iVar4 = iVar4 + 0x40;
            } while (iVar5 < (int)puVar6[2]);
          }
          *(int *)(DAT_008b8f28 + 0x1b0) = *(int *)(DAT_008b8f28 + 0x1b0) + 1;
          FUN_0054e0f0(puVar6,4);
        }
        puVar6 = puVar6 + 0x10;
        local_8 = local_8 + 1;
      } while (local_8 < *(int *)(iVar2 + 0x118));
    }
  }
  return;
}


