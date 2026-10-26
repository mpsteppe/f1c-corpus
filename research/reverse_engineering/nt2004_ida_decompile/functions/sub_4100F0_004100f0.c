int __fastcall sub_4100F0(_DWORD *a1)
{
  int v1; // esi
  LPVOID **v2; // ebp
  bool v3; // zf
  LPVOID *v4; // edi
  int result; // eax
  _DWORD *v6; // [esp+8h] [ebp-4h]

  v1 = a1[15];
  v6 = a1;
  if ( v1 )
  {
    do
    {
      v2 = (LPVOID **)v1;
      v3 = *(_BYTE *)(v1 + 8) == 0;
      v1 = *(_DWORD *)(v1 + 4);
      if ( !v3 )
      {
        v4 = *v2;
        if ( *v2 )
        {
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
  a1[15] = 0;
  a1[16] = 0;
  a1[17] = 0;
  a1[18] = 0;
  return result;
}
