int __thiscall sub_541E70(char *this)
{
  double v2; // st7
  int v3; // edi
  char *v4; // esi
  int v5; // eax
  _DWORD v7[3]; // [esp+4h] [ebp-Ch] BYREF

  if ( *(_DWORD *)dword_B640C8 )
  {
    v2 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
    if ( v2 < flt_BE1D28 * 0.15000001 )
    {
      v3 = 0;
      v4 = this + 28;
      do
      {
        if ( *(_DWORD *)v4 && (*(int (**)(void))(**(_DWORD **)v4 + 28))() != 2 )
          break;
        ++v3;
        v4 += 4;
      }
      while ( v3 < 3 );
      if ( v3 == 3 )
      {
        v5 = *(_DWORD *)&this[4 * (rand() % 3) + 28];
        if ( v5 )
        {
          memset(v7, 0, sizeof(v7));
          (*(void (__thiscall **)(int, _DWORD, _DWORD *, _DWORD *, int, int, int))(*(_DWORD *)v5 + 4))(
            v5,
            0,
            (_DWORD *)this + 2,
            v7,
            dword_B70948,
            1065353216,
            1);
        }
      }
    }
  }
  return 0;
}
