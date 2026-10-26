// Function: FUN_004064c0 @ 004064c0
// Size (bytes): 81


void __fastcall FUN_004064c0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00406750();
  }
  puVar1 = (undefined4 *)(param_1 + 0x1c);
  iVar2 = 3;
  do {
    FUN_00566650(&DAT_005ea438);
    puVar1[-1] = 0xffffffff;
    *puVar1 = 0xffffffff;
    *(undefined1 *)(puVar1 + 1) = 0;
    puVar1 = puVar1 + 5;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_00406700(0);
  return;
}


