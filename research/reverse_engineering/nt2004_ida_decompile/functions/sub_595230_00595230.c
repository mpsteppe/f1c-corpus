int __thiscall sub_595230(int this, float *a2)
{
  int v2; // eax
  double v4; // st7
  unsigned int v5; // esi
  double v6; // st6
  double v7; // st5
  int v8; // esi
  int v9; // edi
  float *i; // edx
  double v11; // st7

  v2 = *(_DWORD *)(this + 4);
  if ( (v2 & 0x50) != 0 )
  {
    *(_DWORD *)(this + 4) = v2 | 2;
    return 0;
  }
  else
  {
    v4 = a2[9] + *(float *)(this + 124);
    v5 = v2 & 0xFFFFFFF0;
    v6 = a2[10] + *(float *)(this + 128);
    v7 = a2[11];
    *(_DWORD *)(this + 4) = v2 & 0xFFFFFFF0;
    if ( sqrt((v7 + *(float *)(this + 132)) * (v7 + *(float *)(this + 132)) + v6 * v6 + v4 * v4) - *(float *)(this + 24) <= a2[2] )
    {
      v8 = v5 | 1;
      v9 = 0;
      *(_DWORD *)(this + 4) = v8;
      for ( i = a2 + 65; ; i += 4 )
      {
        v11 = -(*(i - 2) * *(float *)(this + 124))
            - *(i - 1) * *(float *)(this + 128)
            - *i * *(float *)(this + 132)
            - i[1];
        if ( v11 > *(float *)(this + 24) )
        {
          *(_DWORD *)(this + 4) = v8 & 0xFFFFFFFC | 2;
          return 0;
        }
        if ( v11 > -*(float *)(this + 24) )
          break;
        if ( ++v9 >= 6 )
          return 0;
      }
      *(_DWORD *)(this + 4) = v8 & 0xFFFFFFFA | 4;
      return 0;
    }
    else
    {
      *(_DWORD *)(this + 4) = v5 | 8;
      return 0;
    }
  }
}
