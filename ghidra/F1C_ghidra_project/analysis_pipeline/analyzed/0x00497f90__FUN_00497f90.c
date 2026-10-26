// Function: FUN_00497f90 @ 00497f90
// Size (bytes): 153


undefined4 __thiscall FUN_00497f90(int param_1,char *param_2)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char local_50 [80];
  
  if (param_2 != (char *)0x0) {
    iVar4 = -1;
    pcVar5 = param_2;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if (iVar4 != -2) {
      iVar4 = -(int)param_2;
      do {
        cVar1 = *param_2;
        param_2[(int)(local_50 + iVar4)] = cVar1;
        param_2 = param_2 + 1;
      } while (cVar1 != '\0');
      puVar2 = (undefined1 *)FUN_00587c20(local_50,&DAT_005cc79c);
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 0;
      }
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x1514)) {
        iVar6 = param_1 + 0x114;
        do {
          iVar3 = FUN_00588410(iVar6,local_50);
          if (iVar3 == 0) {
            return 1;
          }
          iVar4 = iVar4 + 1;
          iVar6 = iVar6 + 0x50;
        } while (iVar4 < *(int *)(param_1 + 0x1514));
      }
    }
  }
  return 0;
}


