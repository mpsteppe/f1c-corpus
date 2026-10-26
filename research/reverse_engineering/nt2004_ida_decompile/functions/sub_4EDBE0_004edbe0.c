int __fastcall sub_4EDBE0(_DWORD *a1)
{
  int v1; // edi
  LPVOID **v2; // ebp
  char v3; // al
  LPVOID *v4; // esi
  int result; // eax
  _DWORD *v6; // [esp+4h] [ebp-4h]

  v1 = *a1;
  v6 = a1;
  if ( *a1 )
  {
    do
    {
      v2 = (LPVOID **)v1;
      v3 = *(_BYTE *)(v1 + 8);
      v1 = *(_DWORD *)(v1 + 4);
      if ( v3 )
      {
        v4 = *v2;
        if ( *v2 )
        {
          if ( v4[5] )
            sub_5BE8AE(v4[5]);
          if ( *v4 )
            sub_5BE8AE(*v4);
          sub_5BE8AE(v4);
        }
      }
      result = sub_5BE8AE(v2);
    }
    while ( v1 );
    a1 = v6;
  }
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
  return result;
}
