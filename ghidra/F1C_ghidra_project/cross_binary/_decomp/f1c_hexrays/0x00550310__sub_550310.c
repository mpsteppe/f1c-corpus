// f1c  0x00550310  size=141
int __thiscall sub_550310(_DWORD *this, float a2)
{
  int result; // eax
  _DWORD *i; // edi
  int v4; // ebx
  float *v5; // esi
  float v6; // eax
  double v7; // st7

  result = this[68];
  for ( i = *(_DWORD **)(result + 36); i; i = (_DWORD *)i[48] )
  {
    result = i[39];
    if ( (result & 0x400) != 0 )
    {
      result = i[42];
      v4 = 0;
      if ( (int)i[41] > 0 )
      {
        v5 = (float *)(result + 64);
        do
        {
          if ( *((int *)v5 + 2) > 1 )
          {
            v6 = *v5;
            if ( v5[7] < (double)v5[6] )
            {
              v7 = a2 + v5[7];
              *(_DWORD *)v5 = LODWORD(v6) & 0xFFFFFFFB;
            }
            else
            {
              v7 = v5[7];
              *(_DWORD *)v5 = LODWORD(v6) | 4;
              sub_58957A(v7);
            }
            v5[7] = v7;
          }
          result = i[41];
          v5 += 37;
          ++v4;
        }
        while ( v4 < result );
      }
    }
  }
  return result;
}
