
undefined4 __fastcall FUN_0046c8b0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_8;
  undefined1 auStack_4 [4];
  
  FUN_00498880(auStack_4,&uStack_8);
  iVar1 = FUN_00489f40(uStack_8,1);
  if (-1 < iVar1) {
    uVar2 = FUN_0046c750(*(undefined1 *)(param_1 + 0x174),iVar1);
    FUN_0046c7b0(*(char *)(param_1 + 0x174) == '\0',uVar2,0xffffffff);
  }
  return 0;
}

