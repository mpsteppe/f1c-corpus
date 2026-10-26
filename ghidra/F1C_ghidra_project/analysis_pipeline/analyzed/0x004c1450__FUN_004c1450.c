// Function: FUN_004c1450 @ 004c1450
// Size (bytes): 331


int FUN_004c1450(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int local_b4;
  undefined1 local_a8 [32];
  undefined1 local_88 [32];
  char local_68 [104];
  
  pcVar8 = local_68;
  for (iVar6 = 0x1a; iVar6 != 0; iVar6 = iVar6 + -1) {
    pcVar8[0] = '\0';
    pcVar8[1] = '\0';
    pcVar8[2] = '\0';
    pcVar8[3] = '\0';
    pcVar8 = pcVar8 + 4;
  }
  if (param_1 != 0) {
    iVar6 = FUN_004c13c0(param_1);
    local_b4 = 1;
    iVar2 = FUN_004c1370();
    iVar2 = iVar2 + 1;
    iVar7 = 0;
    if (0 < iVar2) {
      do {
        if (local_68[iVar7] == '\0') {
          if (iVar7 == 0) {
            iVar3 = FUN_004c1390();
          }
          else {
            iVar3 = FUN_004c13a0(iVar7 + -1);
          }
          if (iVar3 != 0) {
            local_68[iVar7] = '\x01';
            FUN_004c0a20(local_a8,0x20);
            iVar3 = FUN_00588410(local_a8,param_1);
            if (iVar3 != 0) {
              iVar4 = FUN_004c13c0(local_a8);
              iVar3 = iVar7;
              while (iVar1 = iVar3, iVar3 = iVar1 + 1, iVar3 < iVar2) {
                if (iVar3 == 0) {
                  FUN_004c1390();
                }
                else {
                  FUN_004c13a0(iVar1);
                }
                FUN_004c0a20(local_88,0x20);
                iVar5 = FUN_00588410(local_88,local_a8);
                if (iVar5 == 0) {
                  local_68[iVar1 + 1] = '\x01';
                }
              }
              if (iVar6 < iVar4) {
                local_b4 = local_b4 + 1;
              }
            }
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar2);
      return local_b4;
    }
    return 1;
  }
  return -1;
}


