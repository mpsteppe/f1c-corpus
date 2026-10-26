// f1c  0x0040c7a0  size=199
int __thiscall sub_40C7A0(_DWORD *this)
{
  int result; // eax
  int v3; // esi
  char *v4; // esi

  result = this[14];
  if ( result != *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580) )
  {
    if ( result < 0 )
    {
      v4 = (char *)&unk_5ECDC8;
      do
      {
        sub_4E0ED0(0);
        v4 += 18624;
      }
      while ( (int)v4 < (int)byte_7C5BC8 );
      if ( dword_7CFDC4 )
      {
        if ( dword_7CFDC4 == 1 )
        {
          v3 = 1;
        }
        else if ( dword_7CFDC4 == 2 )
        {
          v3 = 3;
        }
        else
        {
          v3 = 0;
        }
      }
      else
      {
        v3 = dword_7CFCC8 != 0 ? 0 : 2;
      }
    }
    else
    {
      v3 = sub_40C8D0(this);
      sub_4E0ED0(0);
    }
    sub_4E0ED0(v3);
    result = dword_7C54F0[dword_7C54DC];
    this[14] = *(_DWORD *)(result + 18580);
  }
  return result;
}
