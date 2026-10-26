int __fastcall sub_4D2670(_DWORD *a1)
{
  int result; // eax
  int v2; // ebx
  int *v3; // edi
  int v4; // esi
  LPVOID *v5; // ebp
  char v6; // al
  _DWORD *v7; // [esp+10h] [ebp-4h]

  result = 0;
  v7 = a1;
  v2 = 0;
  v3 = a1 + 576;
  do
  {
    v4 = *v3;
    if ( *v3 )
    {
      do
      {
        v5 = (LPVOID *)v4;
        v6 = *(_BYTE *)(v4 + 8);
        v4 = *(_DWORD *)(v4 + 4);
        if ( v6 )
          sub_5BE8AE(*v5);
        sub_5BE8AE(v5);
      }
      while ( v4 );
      a1 = v7;
      result = 0;
    }
    *v3 = 0;
    v3[1] = 0;
    v3[2] = 0;
    v3[3] = 0;
    *((_BYTE *)a1 + v2++) = 0;
    v3 += 4;
  }
  while ( v2 < 256 );
  a1[1600] = 0;
  a1[1601] = 0;
  return result;
}
