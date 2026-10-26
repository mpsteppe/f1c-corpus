// Function: FUN_004d7880 @ 004d7880
// Strings:  [D:\dev\F1_1999_2002\Source\tire_manager.cpp, Non-existent tire brand "%s"]


int __thiscall FUN_004d7880(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if (0 < *param_1) {
    iVar5 = 0;
    do {
      puVar2 = *(undefined1 **)(param_1[1] + iVar5);
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_005ea438;
      }
      iVar3 = FUN_00588410(param_2,puVar2);
      if (iVar3 == 0) {
        return param_1[1] + iVar4 * 0x24;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x24;
    } while (iVar4 < *param_1);
  }
  if (DAT_007c569c != 5) {
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_tire__005d45e4,0x438);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_Non_existent_tire_brand___s__005d49e4,param_2);
    }
  }
  return 0;
}


