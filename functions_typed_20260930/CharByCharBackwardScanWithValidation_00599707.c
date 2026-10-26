char __cdecl sub_599707(int a1, _DWORD *a2, int a3)
{
  int v3; // esi
  bool v4; // zf
  int v5; // edi
  int v6; // eax
  int v8; // edi

  v3 = a3;
  v4 = a3 == 0;
  v5 = a1 + a3;
  if ( a3 )
  {
    do
    {
      v6 = *(unsigned __int8 *)--v5;
      if ( FileIOWrapperWithLock(v6, (unsigned int)a2) == -1 )
        break;
      --v3;
    }
    while ( v3 );
    v4 = v3 == 0;
  }
  if ( v4 )
    return 1;
  v8 = 1;
  if ( !v3 )
  {
    do
    {
      StreamGetcWithUnderflowHandler(a2);
      --v8;
    }
    while ( v8 );
  }
  return 0;
}

