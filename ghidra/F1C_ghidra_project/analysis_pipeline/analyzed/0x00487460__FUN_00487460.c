// Function: FUN_00487460 @ 00487460
// Size (bytes): 120


undefined4 __fastcall FUN_00487460(int *param_1)

{
  char cVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  
  if ((char)param_1[0x38] != '\0') {
    cVar1 = FUN_00487720();
    puVar3 = (undefined1 *)param_1[0x28];
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    iVar4 = FUN_0049a460(puVar3);
    if (iVar4 != 0) {
      puVar3 = (undefined1 *)param_1[0x2a];
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_005ea438;
      }
      iVar4 = FUN_00588410(iVar4,puVar3);
      FUN_00487260(iVar4 == 0);
    }
    cVar2 = FUN_00487720();
    if (cVar2 != cVar1) {
      (**(code **)(*param_1 + 0x2c))(1);
    }
  }
  return 0;
}


