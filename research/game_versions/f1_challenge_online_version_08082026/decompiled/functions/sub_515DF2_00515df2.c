int __cdecl sub_515DF2(_DWORD *a1)
{
  _BYTE *v1; // edi
  int v3; // ebp
  bool v4; // zf
  int v5; // esi

  v1 = (_BYTE *)a1[99];
  if ( v1[17] )
    return 2;
  v3 = (*(int (__cdecl **)(_DWORD *))(a1[100] + 4))(a1);
  if ( v3 == 1 )
  {
    if ( v1[20] )
    {
      sub_5159F5((int)a1);
      v1[20] = 0;
    }
    else
    {
      if ( !v1[16] )
      {
        *(_DWORD *)(*a1 + 20) = 34;
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      }
      sub_515DB8((int)a1);
    }
  }
  else if ( v3 == 2 )
  {
    v4 = v1[20] == 0;
    v1[17] = 1;
    if ( v4 )
    {
      v5 = a1[31];
      if ( a1[33] > v5 )
        a1[33] = v5;
    }
    else if ( *(_BYTE *)(a1[100] + 81) )
    {
      *(_DWORD *)(*a1 + 20) = 58;
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    }
  }
  return v3;
}
