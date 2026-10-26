
void __fastcall FUN_00459010(int param_1)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = 0;
  uStack_8 = 0;
  uStack_4 = 0;
  FUN_00456150(&uStack_c);
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined1 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0x3f800000;
  FUN_00456130(param_1 + 0x90);
  *(undefined1 *)(param_1 + 0xa0) = 1;
  return;
}

