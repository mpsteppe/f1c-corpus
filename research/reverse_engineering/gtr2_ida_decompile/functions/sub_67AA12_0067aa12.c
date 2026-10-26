void **__stdcall sub_67AA12(_BYTE *a1, int a2, int a3, int a4)
{
  void **v4; // eax
  int v6; // eax
  void **Block; // [esp+4h] [ebp-4h]

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
  Block[33] = sub_679FD8;
  Block[34] = sub_67A02E;
  Block[35] = Block;
  v6 = sub_6B9A04(Block + 25, "1.1.4", 56);
  if ( v6 == -6 )
    sub_679F05((int)Block, (int)"zlib version error");
  if ( v6 == -4 || v6 == -2 )
    sub_679F05((int)Block, (int)"zlib memory error");
  if ( v6 )
    sub_679F05((int)Block, (int)"Unknown zlib error");
  Block[28] = Block[39];
  Block[29] = Block[40];
  sub_67CBDA(Block, 0, 0);
  return Block;
}
