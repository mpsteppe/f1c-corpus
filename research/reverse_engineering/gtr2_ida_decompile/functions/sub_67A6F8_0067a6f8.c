void **__stdcall sub_67A6F8(_BYTE *a1, int a2, int a3, int a4)
{
  void **v4; // eax
  void **Block; // [esp+8h] [ebp-4h]

  v4 = (void **)sub_6B7209(1);
  Block = v4;
  if ( !v4 )
    return 0;
  if ( _setjmp3(v4, 0) )
  {
    sub_6B72A2((int)Block, Block[39]);
    sub_6B7251(Block);
    return 0;
  }
  sub_679EE7(Block, a2, a3, a4);
  if ( !a1 || *a1 != 49 )
    sub_679F05((int)Block, (int)"Incompatible libpng version in application and library");
  Block[40] = (void *)0x2000;
  Block[39] = (void *)sub_6B7269((int)Block, 0x2000u);
  sub_67A840(Block, 0, 0, 0);
  sub_67A4E7((int)Block, 0, 1, 0, 0);
  return Block;
}
