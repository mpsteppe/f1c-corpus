int *__thiscall sub_5DAC60(_DWORD *this, unsigned int *a2, int a3)
{
  unsigned int v3; // eax
  _DWORD *v5; // ecx
  unsigned int v6; // eax
  int *result; // eax
  int i; // edi
  int *v9; // eax
  int j; // eax
  int v11; // eax
  unsigned int v12; // eax
  int *v13; // eax

  v3 = a2[156];
  if ( v3 )
  {
    v5 = (_DWORD *)(v3 + 628);
  }
  else
  {
    v6 = *a2;
    if ( (*a2 & 0x10) != 0 )
    {
      *a2 = v6 & 0xFFEFFFFF;
      v5 = (_DWORD *)(this[155] + 436);
    }
    else
    {
      *a2 = v6 & 0xFFDFFFFF;
      v5 = (_DWORD *)(this[155] + 452);
    }
  }
  sub_5DAB90(v5, (int)a2, 0);
  sub_5FDFB0(a2, 1);
  a2[156] = (unsigned int)this;
  result = (int *)this[133];
  this[135] = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      if ( *(_DWORD *)(i + 464) )
      {
        v9 = (int *)a2[133];
        a2[135] = (unsigned int)v9;
        if ( v9 )
        {
          for ( j = *v9; j; j = *v13 )
          {
            v11 = *(_DWORD *)(j + 464);
            if ( v11 )
              sub_5E6600(v11);
            v12 = a2[135];
            if ( !v12 )
              break;
            v13 = *(int **)(v12 + 4);
            a2[135] = (unsigned int)v13;
            if ( !v13 )
              break;
          }
        }
      }
      result = (int *)this[135];
      if ( !result )
        break;
      result = (int *)result[1];
      this[135] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
