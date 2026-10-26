// Function: FUN_004c5cb0 @ 004c5cb0
// Strings:  [SceneOrder]


void __fastcall FUN_004c5cb0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  param_1[3] = 0x7fffffff;
  FUN_00568210(s_SceneOrder_005d28b4);
  iVar4 = 0;
  iVar3 = *param_1 * 0x18c + DAT_008ac490;
  if (iVar3 != 0) {
    iVar1 = thunk_FUN_0059d6a9(0);
    if (iVar1 != 0) {
      while( true ) {
        uVar2 = FUN_00499e20(iVar3 + 0x104);
        iVar1 = FUN_00588410(uVar2);
        if (iVar1 == 0) break;
        iVar4 = iVar4 + 1;
        iVar1 = thunk_FUN_0059d6a9(iVar4);
        if (iVar1 == 0) {
          return;
        }
      }
      param_1[3] = iVar4;
    }
  }
  return;
}


