// Function: FUN_005622c0 @ 005622c0
// Size (bytes): 585


void __fastcall FUN_005622c0(undefined *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  char local_678;
  undefined4 local_677;
  char local_578;
  undefined4 local_577;
  
  local_578 = DAT_005ea438;
  local_678 = DAT_005ea438;
  puVar5 = &local_577;
  for (iVar3 = 0x15d; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  *(undefined1 *)((int)puVar5 + 2) = 0;
  iVar3 = 0;
  puVar5 = &local_677;
  for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  *(undefined1 *)((int)puVar5 + 2) = 0;
  if (param_1 == (undefined *)0x0) {
    param_1 = PTR_DAT_005e4dfc;
  }
  if (*param_2 == ';') {
    if (*(code **)(param_1 + 0xfc) != (code *)0x0) {
      (**(code **)(param_1 + 0xfc))(param_4);
      return;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0xe0) = 0;
    *(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0xdc) + 1;
    if ('\0' < (char)param_1[0xe8]) {
      param_1[0xe8] = 0;
    }
    do {
      pcVar2 = (char *)FUN_00562530();
      if (pcVar2 != (char *)0x0) {
        switch(iVar3) {
        case 0:
          FUN_005626b0(&local_578);
          break;
        case 1:
          FUN_00562830(&local_578);
          break;
        case 2:
          FUN_00562890(&local_578);
          break;
        case 3:
          FUN_005628f0(&local_578);
          break;
        case 4:
          FUN_005626b0(&local_578);
          FUN_00562830(&local_578);
          FUN_00562890(&local_578);
          FUN_005628f0(&local_578);
          break;
        case 5:
          FUN_005626b0(&local_578);
          FUN_00562610(&local_578);
          FUN_00562830(&local_578);
          FUN_00562610(&local_578);
          FUN_00562890(&local_578);
          FUN_00562610(&local_578);
          FUN_005628f0(&local_578);
          break;
        case 6:
          FUN_00562950(&local_578,pcVar2);
          break;
        case 7:
          iVar4 = -(int)pcVar2;
          do {
            cVar1 = *pcVar2;
            pcVar2[(int)(&local_678 + iVar4)] = cVar1;
            pcVar2 = pcVar2 + 1;
          } while (cVar1 != '\0');
        }
      }
      iVar4 = iVar3 + 2;
      iVar3 = iVar3 + 1;
    } while (iVar4 < 9);
    FUN_005629b0(&local_578,&local_678);
  }
  return;
}


