float *__thiscall sub_4C9C70(float *this, float a2, float a3, _DWORD *a4)
{
  int v4; // esi
  int v5; // edi
  int v6; // edx
  int v8; // esi
  float *v9; // edi
  float v10; // [esp+0h] [ebp-4h]
  float v11; // [esp+8h] [ebp+4h]

  v4 = 0;
  v5 = dword_5C329C;
  if ( dword_5C329C <= 0 )
    goto LABEL_7;
  do
  {
    v6 = (v5 + v4) >> 1;
    v10 = a2 - a3;
    if ( v10 >= (double)this[v6 + 104] )
      v4 = v6 + 1;
    else
      v5 = (v5 + v4) >> 1;
  }
  while ( v4 < v5 );
  if ( v4 < dword_5C329C )
  {
    v8 = v6;
    v11 = a2 + a3;
    if ( v6 < dword_5C329C )
    {
      v9 = &this[v6 + 104];
      do
      {
        if ( v11 < (double)*v9 )
          break;
        ++v8;
        ++v9;
      }
      while ( v8 < dword_5C329C );
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

