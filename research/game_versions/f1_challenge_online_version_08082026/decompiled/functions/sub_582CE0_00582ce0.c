int __fastcall sub_582CE0(_DWORD *a1)
{
  _DWORD *v1; // ebp
  int v2; // esi
  _BYTE *v3; // edi
  int result; // eax
  _DWORD *v5; // esi
  _BYTE *v6; // ebp
  _DWORD *v7; // edi
  _DWORD *v8; // [esp+10h] [ebp-14h]

  v8 = a1;
  v1 = a1 + 4;
  v2 = a1[4];
  if ( v2 )
  {
    do
    {
      v3 = (_BYTE *)v2;
      v2 = *(_DWORD *)(v2 + 4);
      if ( v3[8] && *(_DWORD *)v3 )
        (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)v3 + 4))(*(_DWORD *)v3, 1);
      result = sub_587BCF(v3);
    }
    while ( v2 );
    a1 = v8;
  }
  *v1 = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  v5 = (_DWORD *)*a1;
  if ( *a1 )
  {
    do
    {
      v6 = v5;
      v5 = (_DWORD *)v5[1];
      if ( v6[8] )
      {
        v7 = *(_DWORD **)v6;
        if ( *(_DWORD *)v6 )
        {
          if ( *v7 )
            (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)*v7 + 4))(*v7, 3);
          sub_587BCF(v7);
        }
      }
      result = sub_587BCF(v6);
    }
    while ( v5 );
    a1 = v8;
  }
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
  return result;
}
