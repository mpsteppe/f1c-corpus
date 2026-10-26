_DWORD *__thiscall sub_5DAD60(_DWORD *this, int a2)
{
  _DWORD *result; // eax
  _DWORD *v4; // ecx
  int v5; // eax
  bool v6; // zf
  int v7; // eax
  _DWORD *i; // edi
  int *v9; // eax
  int j; // eax
  int v11; // eax
  int v12; // eax
  int *v13; // eax

  result = (_DWORD *)this[157];
  v4 = this + 157;
  v4[2] = result;
  if ( result )
  {
    result = (_DWORD *)*result;
    if ( result )
    {
      while ( result != (_DWORD *)a2 )
      {
        v5 = v4[2];
        if ( v5 )
          v4[2] = *(_DWORD *)(v5 + 4);
        result = (_DWORD *)v4[2];
        if ( result )
        {
          result = (_DWORD *)*result;
          if ( result )
            continue;
        }
        return result;
      }
      sub_5DAB90(v4, a2, 0);
      v6 = (*(_BYTE *)a2 & 0x10) == 0;
      *(_DWORD *)(a2 + 624) = 0;
      if ( v6 )
      {
        sub_5FDFB0(a2, 1);
        v7 = *(_DWORD *)a2 | 0x200000;
      }
      else
      {
        sub_5FDFB0(a2, 1);
        v7 = *(_DWORD *)a2 | 0x100000;
      }
      *(_DWORD *)a2 = v7;
      result = (_DWORD *)this[133];
      this[135] = result;
      if ( result )
      {
        for ( i = (_DWORD *)*result; *result; i = (_DWORD *)*result )
        {
          if ( i[116] )
          {
            v9 = *(int **)(a2 + 532);
            *(_DWORD *)(a2 + 540) = v9;
            if ( v9 )
            {
              for ( j = *v9; j; j = *v13 )
              {
                v11 = *(_DWORD *)(j + 464);
                if ( v11 )
                  sub_5E66A0(v11);
                v12 = *(_DWORD *)(a2 + 540);
                if ( !v12 )
                  break;
                v13 = *(int **)(v12 + 4);
                *(_DWORD *)(a2 + 540) = v13;
                if ( !v13 )
                  break;
              }
            }
          }
          result = (_DWORD *)this[135];
          if ( !result )
            break;
          result = (_DWORD *)result[1];
          this[135] = result;
          if ( !result )
            break;
        }
      }
    }
  }
  return result;
}
