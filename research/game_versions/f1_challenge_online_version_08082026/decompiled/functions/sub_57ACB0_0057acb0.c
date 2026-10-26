int __stdcall sub_57ACB0(_DWORD *a1)
{
  int v1; // eax
  _DWORD *v2; // esi
  int v4; // eax
  int v5; // eax
  _DWORD *v6; // edi

  v1 = sub_585CC0(*a1);
  (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 4))(v1);
  nullsub_3();
  v2 = (_DWORD *)dword_8D3BFC;
  if ( !dword_8D3BFC )
    return 1;
  while ( (_DWORD *)*v2 != a1 )
  {
    v2 = (_DWORD *)v2[1];
    if ( !v2 )
      return 1;
  }
  if ( v2 == (_DWORD *)dword_8D3C04 )
    dword_8D3C04 = v2[1];
  v4 = v2[2];
  if ( v4 )
    *(_DWORD *)(v4 + 4) = v2[1];
  else
    dword_8D3BFC = v2[1];
  v5 = v2[1];
  if ( v5 )
    *(_DWORD *)(v5 + 8) = v2[2];
  if ( (_DWORD *)dword_8D3C00 == v2 )
    dword_8D3C00 = v2[2];
  --dword_8D3C08;
  if ( *((_BYTE *)v2 + 12) )
  {
    v6 = (_DWORD *)*v2;
    if ( *v2 )
    {
      sub_57A4C0((_DWORD *)*v2);
      sub_587BCF(v6);
    }
  }
  sub_587BCF(v2);
  return 0;
}
