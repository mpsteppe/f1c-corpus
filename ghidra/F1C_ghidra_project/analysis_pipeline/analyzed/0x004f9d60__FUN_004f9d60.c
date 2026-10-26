// Function: FUN_004f9d60 @ 004f9d60
// Size (bytes): 414


undefined1 FUN_004f9d60(undefined4 param_1,float param_2,char param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  undefined4 *puVar5;
  float10 fVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int local_150 [20];
  undefined1 local_100;
  undefined4 local_ff;
  
  uVar4 = 0;
  local_150[0] = 0;
  FUN_00568ba0();
  iVar1 = FUN_00494fb0(local_150,param_1,1);
  if (iVar1 != 0) {
    local_100 = DAT_005ea438;
    puVar5 = &local_ff;
    for (iVar1 = 0x3f; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    *(undefined2 *)puVar5 = 0;
    *(undefined1 *)((int)puVar5 + 2) = 0;
    puVar2 = DAT_005ec408;
    if (DAT_005ec408 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    FUN_0058815f(&local_100,&DAT_005be860,puVar2,param_1);
    local_150[0] = 0;
    iVar1 = FUN_00494fb0(local_150,&local_100,1);
    if (iVar1 != 0) {
      FUN_004b0170();
      return 0;
    }
  }
  if (local_150[0] != 0) {
    uVar10 = *(undefined4 *)(local_150[0] + 0x20);
    uVar9 = *(undefined4 *)(local_150[0] + 0x1c);
    uVar12 = 0;
    uVar11 = 0xffffffff;
    uVar8 = 0;
    uVar7 = 0;
    uVar3 = FUN_00495150(0,0,uVar9,uVar10,0xffffffff,0);
    FUN_00543250(0,0,uVar3,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12);
    FUN_00495080();
    uVar10 = *(undefined4 *)(local_150[0] + 0x20);
    uVar9 = *(undefined4 *)(local_150[0] + 0x1c);
    uVar12 = 0;
    uVar11 = 0xffffffff;
    uVar8 = 0;
    uVar7 = 0;
    uVar3 = FUN_00495150(0,0,uVar9,uVar10,0xffffffff,0);
    FUN_00543250(0,0,uVar3,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12);
    FUN_00495080();
    FUN_00568be0(1);
    fVar6 = (float10)FUN_00568d90();
    if (fVar6 < (float10)param_2) {
      do {
        if (param_3 != '\0') {
          FUN_004537b0(0x3d4ccccd);
          if (0 < DAT_007cb218) break;
        }
        fVar6 = (float10)FUN_00568d90();
      } while (fVar6 < (float10)param_2);
    }
    FUN_00494fd0(local_150[0]);
    FUN_004950c0();
    local_150[0] = 0;
    uVar4 = 1;
  }
  FUN_004b0170();
  return uVar4;
}


