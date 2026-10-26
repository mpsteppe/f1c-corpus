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
        AudioSoundEffectController(0);
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
      v3 = StateCheckWithTernaryLogic(this);
      AudioSoundEffectController(0);
    }
    AudioSoundEffectController(v3);
    result = dword_7C54F0[dword_7C54DC];
    this[14] = *(_DWORD *)(result + 18580);
  }
  return result;
}
