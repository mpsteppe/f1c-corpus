int __thiscall sub_4C7AA0(_DWORD *this, char a2)
{
  int v3; // ecx
  int v4; // eax

  v3 = this[4655];
  if ( a2 )
  {
    this[4655] = v3 | 6;
    if ( *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580) == this[4645] )
    {
      v4 = StateCheckWithTernaryLogic(&dword_5EA510);
      return AudioSoundEffectController(v4);
    }
    else
    {
      return AudioSoundEffectController(0);
    }
  }
  else
  {
    this[4655] = v3 & 0xFFFFFFF9;
    return AudioSoundEffectController(3);
  }
}
