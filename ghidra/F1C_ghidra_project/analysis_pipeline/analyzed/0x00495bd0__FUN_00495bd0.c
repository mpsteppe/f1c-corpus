// Function: FUN_00495bd0 @ 00495bd0
// Size (bytes): 485


void __fastcall FUN_00495bd0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined1 *puVar8;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  undefined1 local_4 [4];
  
  local_24 = 2;
  local_18 = 2;
  local_1c = 0;
  local_20 = 0;
  local_28 = 0;
  uVar2 = FUN_00495150();
  FUN_00498550();
  local_10 = 4;
  do {
    cVar1 = FUN_00499a50();
    if (cVar1 != '\0') {
      uVar11 = 1;
      piVar9 = &local_c;
      piVar6 = &local_8;
      uVar3 = FUN_0049a2b0(piVar6,piVar9,1);
      FUN_004983b0(uVar3,piVar6,piVar9,uVar11);
      local_20 = local_20 + local_c;
      if (local_1c < local_8) {
        local_1c = local_8;
      }
      local_28 = local_28 + 1;
    }
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  if (0 < local_28) {
    iVar10 = local_1c + 6;
    if (800 < local_1c + 8) {
      local_24 = 0x31a - local_1c;
    }
    local_c = local_20 + 6;
    if (600 < local_20 + 8) {
      local_18 = 0x252 - local_20;
    }
    local_14 = local_18 + 3;
    iVar4 = 0;
    if (0 < local_28) {
      do {
        if (iVar4 == 0) {
          FUN_00494bf0(uVar2,local_24,local_18,iVar10,local_c,0xaaff4444);
          FUN_00494bf0(uVar2,local_24 + 3,local_18 + 3,local_1c,local_20,0x222222);
        }
        uVar12 = 1;
        iVar5 = local_24 + 3;
        iVar7 = local_14;
        uVar3 = uVar2;
        uVar11 = FUN_0049a2b0(iVar5,local_14,uVar2,1);
        FUN_00494f10(param_1 + 0x1518,uVar11,iVar5,iVar7,uVar3,uVar12);
        uVar11 = 1;
        piVar9 = &local_8;
        puVar8 = local_4;
        uVar3 = FUN_0049a2b0(puVar8,piVar9,1);
        FUN_004983b0(uVar3,puVar8,piVar9,uVar11);
        local_14 = local_14 + local_8;
        iVar4 = iVar4 + 1;
      } while (iVar4 < local_28);
    }
    iVar4 = local_c;
    FUN_00490920(local_24,local_18,iVar10,local_c);
    FUN_004918d0(local_24,local_18,iVar10,iVar4);
  }
  return;
}


