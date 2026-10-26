// Function: FUN_0049d070 @ 0049d070
// Size (bytes): 217


void __fastcall FUN_0049d070(int param_1)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  
  iVar1 = *(int *)(DAT_007c54e0 + 13000);
  if (iVar1 == 0) {
    bVar3 = DAT_007c9081 == '\0';
    cVar2 = DAT_007c9081;
  }
  else if (((iVar1 < 1) || (2 < iVar1)) || (*(float *)(DAT_007c54e0 + 0x39a0) <= DAT_0059e440)) {
    bVar3 = true;
    cVar2 = '\0';
  }
  else {
    bVar3 = true;
    cVar2 = '\x01';
  }
  if (((*(int *)(param_1 + 0x10) != 0) &&
      (iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x54), iVar1 != 0)) &&
     (*(int *)(param_1 + 4) != 0)) {
    FUN_00543440(0,0,*(undefined4 *)(iVar1 + 0x1c),*(undefined4 *)(iVar1 + 0x20),0);
    if (cVar2 == '\0') {
      FUN_0049e4e0(0,0);
    }
    else {
      if (bVar3 == false) {
        FUN_0049d4c0();
      }
      else {
        FUN_0049e4e0(0,0);
      }
      FUN_0049d320();
      FUN_0049d280();
      FUN_0049d3f0();
      FUN_0049d440();
      FUN_0049d480();
    }
  }
  FUN_0049d5d0(bVar3);
  FUN_0049cfc0();
  return;
}


