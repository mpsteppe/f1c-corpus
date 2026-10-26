int __stdcall sub_4D5AF0(int a1)
{
  int v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v6; // [esp+8h] [ebp-4h] BYREF

  v1 = sub_587DB0(a1, aRb);
  v6 = 0;
  if ( !v1 )
    return sub_4D5BE0(&v6, 4);
  while ( StreamGetcWithUnderflowHandler(v1) != -1 )
    ++v6;
  sub_4D5BE0(&v6, 4);
  sub_587F64(v1, 0, 0);
  while ( 1 )
  {
    v2 = StreamGetcWithUnderflowHandler(v1);
    if ( v2 == -1 )
      break;
    LOBYTE(a1) = v2 ^ 0x5C;
    sub_4D5BE0(&a1, 1);
    v3 = StreamGetcWithUnderflowHandler(v1);
    if ( v3 == -1 )
      break;
    LOBYTE(a1) = v3 ^ 0xB4;
    sub_4D5BE0(&a1, 1);
    v4 = StreamGetcWithUnderflowHandler(v1);
    if ( v4 == -1 )
      break;
    LOBYTE(a1) = v4 ^ 0x12;
    sub_4D5BE0(&a1, 1);
  }
  return FileCloseWithLock(v1);
}
