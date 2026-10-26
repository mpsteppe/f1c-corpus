int __stdcall sub_5E43D0(float a1)
{
  int result; // eax
  float *v2; // esi
  float v3; // eax
  long double v4; // st7
  long double v5; // st6
  double v6; // st7

  result = dword_FB282C;
  dword_FB2834 = dword_FB282C;
  if ( dword_FB282C )
  {
    v2 = *(float **)dword_FB282C;
    if ( *(_DWORD *)dword_FB282C )
    {
      do
      {
        v3 = *v2;
        if ( v2[23] < (double)v2[22] )
        {
          v6 = a1 + v2[23];
          *(_DWORD *)v2 = LODWORD(v3) & 0xFFFEFFFF;
        }
        else
        {
          v4 = v2[23];
          v5 = v2[22];
          *(_DWORD *)v2 = LODWORD(v3) | 0x10000;
          v6 = fmod(v4, v5);
        }
        v2[23] = v6;
        result = dword_FB2834;
        if ( !dword_FB2834 )
          break;
        dword_FB2834 = *(_DWORD *)(dword_FB2834 + 4);
        result = dword_FB2834;
        if ( !dword_FB2834 )
          break;
        v2 = *(float **)dword_FB2834;
      }
      while ( *(_DWORD *)dword_FB2834 );
    }
  }
  return result;
}
