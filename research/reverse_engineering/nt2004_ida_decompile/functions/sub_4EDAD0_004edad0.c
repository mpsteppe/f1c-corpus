int __fastcall sub_4EDAD0(_DWORD *a1)
{
  int v1; // edi
  int *v2; // ebp
  bool v3; // zf
  int v4; // esi
  int result; // eax
  _DWORD *v6; // [esp+8h] [ebp-4h]

  v1 = *a1;
  v6 = a1;
  if ( *a1 )
  {
    do
    {
      v2 = (int *)v1;
      v3 = *(_BYTE *)(v1 + 8) == 0;
      v1 = *(_DWORD *)(v1 + 4);
      if ( !v3 )
      {
        v4 = *v2;
        if ( *v2 )
        {
          if ( *(_DWORD *)(v4 + 40) )
          {
            sub_592310(*(_DWORD *)(v4 + 40));
            *(_DWORD *)(v4 + 40) = 0;
          }
          if ( *(_DWORD *)(v4 + 28) )
            sub_5BE8AE(*(LPVOID *)(v4 + 28));
          if ( *(_DWORD *)(v4 + 12) )
            sub_5BE8AE(*(LPVOID *)(v4 + 12));
          if ( *(_DWORD *)v4 )
            sub_5BE8AE(*(LPVOID *)v4);
          sub_5BE8AE((LPVOID)v4);
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
