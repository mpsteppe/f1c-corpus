// Function: FUN_00564b80 @ 00564b80
// Size (bytes): 188


void __fastcall FUN_00564b80(undefined1 *param_1,int param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar3 = param_3;
  if (param_2 < 1) {
    *param_3 = 0;
    return;
  }
  do {
    iVar2 = 0;
    do {
      if (iVar4 < param_2) {
        uVar1 = *param_1;
        param_1 = param_1 + 1;
        *(undefined1 *)((int)&param_3 + iVar2) = uVar1;
      }
      else {
        *(undefined1 *)((int)&param_3 + iVar2) = 0;
      }
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar2 < 3);
    iVar2 = 0;
    do {
      uVar1 = FUN_00564c40();
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
  } while (iVar4 < param_2);
  *puVar3 = 0;
  return;
}


