void __thiscall sub_405C10(int *this)
{
  int v1; // esi
  const char *v2; // eax
  CHAR *v3; // esi
  int v4; // esi
  int v6; // ecx

  sub_4B9460(&byte_766124);
  sub_4B96C0(&byte_766124);
  if ( sub_405BF0(this) )
    sub_4AD720(aMainMenu, 1);
  v6 = *this;
  v1 = v6;
  if ( *(_BYTE *)(v6 + 20) )
  {
    if ( *(_DWORD *)(v6 + 36) == 1 )
    {
      dword_761FF8 = *(_DWORD *)(v6 + 92);
      *(_DWORD *)dword_76BB84 = *(_DWORD *)(v6 + 84);
      v4 = *(_DWORD *)(v6 + 88);
      *(_DWORD *)dword_7689CC = v4;
      if ( v4 >= dword_7689D4 )
      {
        if ( v4 > dword_7689D8 )
          *(_DWORD *)dword_7689CC = dword_7689D8;
      }
      else
      {
        *(_DWORD *)dword_7689CC = dword_7689D4;
      }
      sub_5074D0(0.1);
      if ( flt_767898 > 0.0 )
        sub_4EFA70(&byte_7D6B78);
    }
    else if ( *(_DWORD *)(v6 + 36) == 2 )
    {
      dword_761FF8 = *(_DWORD *)(v6 + 92);
      *(_DWORD *)dword_7689CC = *(_DWORD *)(v6 + 88);
      if ( *(int *)dword_7689CC >= dword_7689D4 )
      {
        if ( *(int *)dword_7689CC > dword_7689D8 )
          *(_DWORD *)dword_7689CC = dword_7689D8;
      }
      else
      {
        *(_DWORD *)dword_7689CC = dword_7689D4;
      }
      sub_5074D0(0.1);
      if ( flt_767898 > 0.0 )
        sub_4EFA70(&byte_7D6B78);
      v2 = *(const char **)(v1 + 100);
      if ( !v2 )
        v2 = &byte_629120;
      if ( strlen(v2) )
      {
        v3 = *(CHAR **)(v1 + 100);
        if ( !v3 )
          v3 = &byte_629120;
        sub_4E8D60(v3);
        sub_4E8A30(&byte_7D6A30);
      }
    }
  }
}
