unsigned int __thiscall sub_5BA9E0(void *this)
{
  DWORD TickCount; // edi
  unsigned int result; // eax
  int v4; // eax
  int v5; // [esp-4h] [ebp-Ch]

  TickCount = GetTickCount();
  result = *(_DWORD *)this;
  if ( *(_DWORD *)this != -1 )
  {
    v4 = *((_DWORD *)this + 44);
    if ( v4 <= 0 || TickCount - *((_DWORD *)this + 42) <= 0x2710 )
    {
      result = *((_DWORD *)this + 42);
      if ( TickCount - result > 0xEA60 || !result || TickCount < result )
        result = sub_5BB940(this, 0);
    }
    else if ( v4 < 4 )
    {
      result = sub_5BB940(this, 3);
      ++*((_DWORD *)this + 44);
    }
    else
    {
      v5 = *((_DWORD *)this + 65);
      *((_DWORD *)this + 44) = 0;
      result = (*((int (__fastcall **)(int, char *, int))this + 39))(5, aNoChallengeVal, v5);
    }
    if ( TickCount - *((_DWORD *)this + 43) > 0x4E20 )
      return sub_5BB8E0(this);
  }
  return result;
}
