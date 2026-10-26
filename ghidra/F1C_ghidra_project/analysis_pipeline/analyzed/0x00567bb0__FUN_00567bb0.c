// Function: FUN_00567bb0 @ 00567bb0
// Size (bytes): 257


undefined4 FUN_00567bb0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined3 uVar3;
  undefined1 *puVar2;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined1 local_401;
  char local_400 [512];
  undefined4 local_200 [128];
  
  uVar6 = 0;
  puVar7 = local_200;
  for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  pcVar8 = local_400;
  for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
    pcVar8[0] = '\0';
    pcVar8[1] = '\0';
    pcVar8[2] = '\0';
    pcVar8[3] = '\0';
    pcVar8 = pcVar8 + 4;
  }
  local_401 = 0;
  while( true ) {
    iVar4 = FUN_00566cc0(local_200,0x200);
    uVar3 = 0;
    if (iVar4 == 0) break;
    local_401 = 1;
    uVar1 = FUN_00567b10(local_200,local_400);
    if ((char)uVar1 != '\0') {
      uVar3 = (undefined3)((uint)uVar1 >> 8);
      if (local_400[0] == '{') {
        FUN_00567bb0(param_1,uVar6);
      }
      else {
        if (local_400[0] == '}') break;
        puVar2 = (undefined1 *)FUN_00587c20(local_400,&DAT_005c30ac);
        if (puVar2 == (undefined1 *)0x0) {
          puVar2 = *(undefined1 **)(param_1 + 4);
          if (puVar2 == (undefined1 *)0x0) {
            puVar2 = &DAT_005ea438;
          }
          uVar6 = FUN_00567fb0(local_400,0,puVar2,param_2);
        }
        else {
          *puVar2 = 0;
          puVar5 = *(undefined1 **)(param_1 + 4);
          if (puVar5 == (undefined1 *)0x0) {
            puVar5 = &DAT_005ea438;
          }
          uVar6 = FUN_00567fb0(local_400,puVar2 + 1,puVar5,param_2);
        }
      }
    }
  }
  return CONCAT31(uVar3,local_401);
}


