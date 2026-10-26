int __fastcall sub_578800(_DWORD *a1)
{
  int v1; // esi
  _BYTE *v2; // ebp
  int result; // eax
  _DWORD *v4; // [esp+4h] [ebp-4h]

  v1 = *a1;
  v4 = a1;
  if ( *a1 )
  {
    do
    {
      v2 = (_BYTE *)v1;
      v1 = *(_DWORD *)(v1 + 4);
      if ( v2[8] && *(_DWORD *)v2 )
      {
        if ( *(_DWORD *)(*(_DWORD *)v2 + 324) )
          sub_5BE8AE();
        sub_5BE8AE();
      }
      result = sub_5BE8AE();
    }
    while ( v1 );
    a1 = v4;
  }
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
  return result;
}
