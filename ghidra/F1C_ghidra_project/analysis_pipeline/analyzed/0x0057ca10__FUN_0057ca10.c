// Function: FUN_0057ca10 @ 0057ca10
// Size (bytes): 308


undefined4 FUN_0057ca10(char *param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  char *pcVar7;
  int iVar8;
  char local_68 [7];
  undefined1 local_61;
  char local_60 [31];
  undefined1 local_41;
  char local_40 [64];
  
  local_40[0] = '\0';
  iVar8 = -(int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)(local_40 + iVar8)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  pcVar7 = (char *)FUN_005897ca(local_40,&DAT_005c3f6c);
  if (pcVar7 != (char *)0x0) {
    local_60[0] = '\0';
    _strncpy(local_60,pcVar7,0x1f);
    local_41 = 0;
    pcVar7 = (char *)FUN_005897ca(0,&DAT_005c3f6c);
    if (pcVar7 != (char *)0x0) {
      local_68[0] = '\0';
      _strncpy(local_68,pcVar7,7);
      local_61 = 0;
      iVar8 = FUN_005897ca(local_60,&DAT_005beb48);
      if (iVar8 != 0) {
        uVar2 = FUN_00587ece(iVar8);
        iVar8 = FUN_005897ca(0,&DAT_005beb48);
        if (iVar8 != 0) {
          uVar3 = FUN_00587ece(iVar8);
          iVar8 = FUN_005897ca(0,&DAT_005beb48);
          if (iVar8 != 0) {
            uVar4 = FUN_00587ece(iVar8);
            iVar8 = FUN_005897ca(0,&DAT_005beb48);
            if (iVar8 != 0) {
              uVar5 = FUN_00587ece(iVar8);
              *(undefined1 *)(param_2 + 7) = uVar5;
              *(undefined1 *)(param_2 + 4) = uVar2;
              *(undefined1 *)(param_2 + 5) = uVar3;
              *(undefined1 *)(param_2 + 6) = uVar4;
              uVar6 = FUN_00587ece(local_68);
              *(undefined2 *)(param_2 + 2) = uVar6;
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}


