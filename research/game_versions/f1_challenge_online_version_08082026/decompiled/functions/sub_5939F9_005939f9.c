unsigned int __cdecl sub_5939F9(int a1, int a2, int a3, int a4)
{
  unsigned int result; // eax
  unsigned int *v5; // edi
  unsigned int v6; // eax
  _BYTE *v7; // eax
  void *v8; // [esp-8h] [ebp-30h]
  unsigned int v9; // [esp-4h] [ebp-2Ch]

  result = *(_DWORD *)(a3 + 4);
  if ( !result )
    return result;
  if ( !*(_BYTE *)(result + 8) )
    return result;
  result = *(_DWORD *)(a3 + 8);
  if ( !result )
    return result;
  v5 = (unsigned int *)(result + a2 + 12);
  if ( (*(_BYTE *)a3 & 8) != 0 )
  {
    if ( sub_597321(*(void **)(a1 + 24), 1u) && sub_59733D(v5, 1u) )
    {
      v6 = *(_DWORD *)(a1 + 24);
      *v5 = v6;
      result = sub_593C24(v6, a4 + 8);
LABEL_8:
      *v5 = result;
      return result;
    }
    return sub_593CFD();
  }
  if ( (*(_BYTE *)a4 & 1) == 0 )
  {
    v8 = *(void **)(a1 + 24);
    if ( !*(_DWORD *)(a4 + 24) )
    {
      if ( sub_597321(v8, 1u) && sub_59733D(v5, 1u) )
      {
        v9 = *(_DWORD *)(a4 + 20);
        v7 = (_BYTE *)sub_593C24(*(_DWORD *)(a1 + 24), a4 + 8);
        return sub_58B130((unsigned int)v5, v7, v9);
      }
      return sub_593CFD();
    }
    if ( sub_597321(v8, 1u) && sub_59733D(v5, 1u) && sub_597359(*(FARPROC *)(a4 + 24)) )
    {
      if ( (*(_BYTE *)a4 & 4) != 0 )
      {
        sub_593C24(*(_DWORD *)(a1 + 24), a4 + 8);
        return sub_58A32A((int)v5, *(_DWORD *)(a4 + 24));
      }
      else
      {
        sub_593C24(*(_DWORD *)(a1 + 24), a4 + 8);
        return sub_58A323((int)v5, *(_DWORD *)(a4 + 24));
      }
    }
    return sub_593CFD();
  }
  if ( !sub_597321(*(void **)(a1 + 24), 1u) || !sub_59733D(v5, 1u) )
    return sub_593CFD();
  result = sub_58B130((unsigned int)v5, *(_BYTE **)(a1 + 24), *(_DWORD *)(a4 + 20));
  if ( *(_DWORD *)(a4 + 20) == 4 )
  {
    result = *v5;
    if ( *v5 )
    {
      result = sub_593C24(result, a4 + 8);
      goto LABEL_8;
    }
  }
  return result;
}
