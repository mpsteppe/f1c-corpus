// Function: FUN_004330d0 @ 004330d0
// Size (bytes): 196


void __thiscall FUN_004330d0(int param_1,undefined4 param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined1 local_31c [28];
  undefined1 local_300 [256];
  undefined1 local_200 [512];
  
  iVar3 = FUN_00432cf0(param_2,local_300,0x100);
  if (iVar3 == 0) {
    FUN_005668b0();
    FUN_00568620(0x200);
    FUN_0058ba36(local_200,0x180);
    cVar2 = FUN_00566940(local_300,0,1,1);
    if (cVar2 != '\0') {
      piVar1 = *(int **)(param_1 + 0x1c);
      *(int **)(param_1 + 0x24) = piVar1;
      if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
        while( true ) {
          FUN_00432bf0(local_31c);
          if (*(int *)(param_1 + 0x24) == 0) break;
          piVar1 = *(int **)(*(int *)(param_1 + 0x24) + 4);
          *(int **)(param_1 + 0x24) = piVar1;
          if ((piVar1 == (int *)0x0) || (*piVar1 == 0)) break;
        }
      }
      FUN_00566b90();
    }
    FUN_005668d0();
  }
  return;
}


