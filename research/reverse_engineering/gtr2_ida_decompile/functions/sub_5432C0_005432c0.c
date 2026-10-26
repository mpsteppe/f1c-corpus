float *__thiscall sub_5432C0(float *this, float a2, float a3, _DWORD *a4)
{
  int v4; // edx
  int v5; // ebx
  int v6; // esi
  int v8; // edx
  float *v9; // ebx
  float *i; // ebx
  float v11; // [esp+0h] [ebp-4h]
  float v12; // [esp+8h] [ebp+4h]

  v4 = 0;
  v5 = dword_757C10;
  if ( dword_757C10 <= 0 )
    goto LABEL_7;
  do
  {
    v6 = (v5 + v4) >> 1;
    v11 = a2 - a3;
    if ( v11 >= (double)this[v6 + 104] )
      v4 = v6 + 1;
    else
      v5 = (v5 + v4) >> 1;
  }
  while ( v4 < v5 );
  if ( v4 < dword_757C10 )
  {
    v8 = v6;
    v12 = a2 + a3;
    if ( dword_757C10 - v6 < 4 )
    {
LABEL_15:
      if ( v8 < dword_757C10 )
      {
        for ( i = &this[v8 + 104]; v12 >= (double)*i; ++i )
        {
          if ( ++v8 >= dword_757C10 )
          {
            *a4 = v8 - v6;
            return &this[v6];
          }
        }
      }
    }
    else
    {
      v9 = &this[v6 + 105];
      while ( v12 >= (double)*(v9 - 1) )
      {
        if ( v12 < (double)*v9 )
        {
          *a4 = v8 + 1 - v6;
          return &this[v6];
        }
        if ( v12 < (double)v9[1] )
        {
          *a4 = v8 + 2 - v6;
          return &this[v6];
        }
        if ( v12 < (double)v9[2] )
        {
          v8 += 3;
          break;
        }
        v8 += 4;
        v9 += 4;
        if ( v8 >= dword_757C10 - 3 )
          goto LABEL_15;
      }
    }
    *a4 = v8 - v6;
    return &this[v6];
  }
  else
  {
LABEL_7:
    *a4 = 0;
    return 0;
  }
}
