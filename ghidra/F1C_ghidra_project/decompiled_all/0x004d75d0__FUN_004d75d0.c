// Function: FUN_004d75d0 @ 004d75d0
// Strings:  [D:\dev\F1_1999_2002\Source\tire_manager.cpp, Tire brand doesn't have curve name %s]


int __thiscall FUN_004d75d0(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    iVar5 = 0;
    do {
      puVar2 = *(undefined1 **)(*(int *)(param_1 + 0xc) + iVar5);
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_005ea438;
      }
      iVar3 = FUN_00588410(param_2,puVar2);
      if (iVar3 == 0) {
        return *(int *)(param_1 + 0xc) + iVar4 * 0x18;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x18;
    } while (iVar4 < *(int *)(param_1 + 8));
  }
  cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_tire__005d45e4,0x3e3);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Tire_brand_doesn_t_have_curve_na_005d497c,param_2);
  }
  return 0;
}


