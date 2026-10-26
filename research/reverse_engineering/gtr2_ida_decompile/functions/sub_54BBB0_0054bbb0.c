void __thiscall sub_54BBB0(int this)
{
  int v2; // eax
  int v3; // [esp-8h] [ebp-Ch]

  if ( !*(_BYTE *)(this + 3978617) && *(_BYTE *)(this + 3978616) )
  {
    sub_521110(&dword_BE1204, 1);
    if ( *(float *)(this + 3978620) >= 0.0 )
    {
      if ( dbl_FB1D18 <= *(float *)(this + 3978620) )
        return;
      *(_BYTE *)(this + 3978616) = 0;
      *(_DWORD *)(this + 3978620) = -1082130432;
      sub_54B5A0((_DWORD *)this);
      v2 = 3978616 * *(_DWORD *)(this + 3978628) + this;
      if ( *(_BYTE *)(v2 + 152) )
      {
        if ( *(_DWORD *)(v2 + 148) == 2 )
          sub_4304C0();
      }
      else if ( !*(_DWORD *)(dword_91E084 + 19380) )
      {
        sub_4304C0();
        sub_4E5FC0(&dword_B6E4D0, 5);
        sub_44A5B0();
        sub_521110(&dword_BE1204, 0);
        return;
      }
      sub_521110(&dword_BE1204, 0);
    }
    else
    {
      v3 = 3978616 * *(_DWORD *)(this + 3978628) + this + 5;
      sub_4363E0();
      sub_54BAB0((void *)this, v3);
      sub_4363E0();
      byte_B64150 = *(_BYTE *)(3978616 * *(_DWORD *)(this + 3978628) + this + 133);
      *(float *)(this + 3978620) = dbl_FB1D18;
      sub_54B5A0((_DWORD *)this);
      if ( *(_DWORD *)(dword_91E084 + 19380) || *(_BYTE *)(3978616 * *(_DWORD *)(this + 3978628) + this + 152) )
      {
        sub_4304C0();
        if ( *(_DWORD *)dword_B640C8 == 6 && dbl_FB1D18 > flt_FADE1C )
        {
          if ( byte_B722E4 )
            sub_4E1810((_DWORD *)dword_B6E090, (int)"ENDURANCE POST RACE MONITOR", 0);
          else
            sub_4E1810((_DWORD *)dword_B6E090, (int)"POST RACE MONITOR", 0);
        }
        else
        {
          sub_4E1810((_DWORD *)dword_B6E090, (int)"MONITOR_SINGLE", 0);
        }
      }
      else
      {
        dword_75B17C = 2;
        sub_4EAB20();
      }
      if ( *(_BYTE *)(3978616 * *(_DWORD *)(this + 3978628) + this + 3976720) )
        sub_53E6A0((void *)dword_91E084, 1);
      if ( !byte_B70918 && !byte_B722CC || !byte_B70900 && byte_B722CC )
        sub_540AC0((int)&unk_BE1D30, 2.0);
    }
  }
}
