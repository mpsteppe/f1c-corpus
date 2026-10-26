int __thiscall sub_49D280(_DWORD *this)
{
  int result; // eax
  unsigned int v3; // edi

  result = this[8];
  if ( result )
  {
    result = this[9];
    if ( result )
    {
      result = this[10];
      if ( result )
      {
        result = this[11];
        if ( result )
        {
          result = dword_7C54E0;
          if ( *(_DWORD *)(dword_7C54E0 + 3984) || *(_DWORD *)(dword_7C54E0 + 3964) )
          {
            v3 = sub_49B7A0(&unk_7CE234);
            AudioEffectTrigger(v3 & 1, this[8]);
            AudioEffectTrigger((v3 >> 1) & 1, this[9]);
            AudioEffectTrigger((v3 >> 2) & 1, this[10]);
            return AudioEffectTrigger((v3 >> 3) & 1, this[11]);
          }
        }
      }
    }
  }
  return result;
}
