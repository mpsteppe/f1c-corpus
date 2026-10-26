// Function: FUN_00497ba0 @ 00497ba0
// Strings:  [Unable to load surface "%s"]


int __thiscall FUN_00497ba0(int param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if (param_2 != 0) {
    for (iVar1 = *(int *)(param_1 + 0x104); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
      puVar2 = *(undefined1 **)(iVar1 + 4);
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_005ea438;
      }
      iVar3 = FUN_00588410(puVar2,param_2);
      if (iVar3 == 0) {
        if (*(int *)(iVar1 + 0xc) == 0) {
          puVar2 = *(undefined1 **)(iVar1 + 4);
          if (puVar2 == (undefined1 *)0x0) {
            puVar2 = &DAT_005ea438;
          }
          iVar3 = FUN_00495890(puVar2);
          *(int *)(iVar1 + 0xc) = iVar3;
          if (iVar3 == 0) {
            puVar2 = *(undefined1 **)(iVar1 + 4);
            if (puVar2 == (undefined1 *)0x0) {
              puVar2 = &DAT_005ea438;
            }
            FUN_0058815f(&DAT_007cde38,s_Unable_to_load_surface___s__005cca5c,puVar2);
            FUN_004986d0(&DAT_007cde38);
          }
        }
        return iVar1;
      }
    }
  }
  return 0;
}


