int __thiscall sub_5A26B0(_DWORD *this, float a2)
{
  int result; // eax
  _DWORD *i; // ebp
  int v4; // edi
  int v5; // ebx
  float *v6; // esi
  float v7; // eax
  long double v8; // st7
  long double v9; // st6
  double v10; // st7

  result = this[69];
  for ( i = *(_DWORD **)(result + 48); i; i = (_DWORD *)i[1] )
  {
    v4 = *i;
    result = *(_DWORD *)(*i + 176);
    v5 = 0;
    if ( *(int *)(*i + 172) > 0 )
    {
      v6 = (float *)(result + 64);
      do
      {
        if ( *((int *)v6 + 2) > 1 )
        {
          v7 = *v6;
          if ( v6[7] < (double)v6[6] )
          {
            v10 = a2 + v6[7];
            *(_DWORD *)v6 = LODWORD(v7) & 0xFFFFFFFB;
          }
          else
          {
            v8 = v6[7];
            v9 = v6[6];
            *(_DWORD *)v6 = LODWORD(v7) | 4;
            v10 = fmod(v8, v9);
          }
          v6[7] = v10;
        }
        result = *(_DWORD *)(v4 + 172);
        v6 += 37;
        ++v5;
      }
      while ( v5 < result );
    }
  }
  return result;
}
