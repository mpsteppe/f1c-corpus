int __thiscall sub_413EC0(int this)
{
  int v2; // edi
  long double v3; // st7
  long double v4; // st7
  int v5; // ebx
  int v6; // edi
  int v8; // eax

  v2 = 0;
  if ( !*(_BYTE *)(this + 48) )
  {
    v3 = dword_BE1204 == 2 ? fabs(sub_5210C0(&dword_BE120C)) : dbl_FB1D10;
    v4 = *(float *)(this + 72) - v3;
    *(float *)(this + 72) = v4;
    if ( v4 <= 0.0 )
    {
      v5 = sub_410B50((_DWORD *)this);
      v8 = dword_16C9AC8 & rand();
      if ( v8 < 0 )
        v8 = (((_BYTE)v8 - 1) | 0xFFFFFFFC) + 1;
      switch ( v8 )
      {
        case 0:
          v6 = 0;
          break;
        case 1:
          v6 = 3;
          break;
        case 2:
          v6 = 4;
          break;
        default:
          v6 = 5;
          break;
      }
      sub_412EB0((_DWORD *)this, v6, 1);
      if ( v6 != v5 )
        sub_412EB0((_DWORD *)this, v6, 1);
      v2 = 1;
      sub_410C30(this, *(_DWORD *)(this + 60), *(_DWORD *)(this + 64));
    }
  }
  return v2;
}
