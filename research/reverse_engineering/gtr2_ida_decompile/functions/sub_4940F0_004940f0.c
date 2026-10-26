_DWORD *__thiscall sub_4940F0(int *this)
{
  _DWORD *result; // eax
  int v2; // eax

  result = (_DWORD *)this[69];
  if ( result )
  {
    if ( *result )
    {
      v2 = *this;
      this[67] = 0;
    }
    else
    {
      v2 = *this;
      this[67] = 1;
    }
    return (_DWORD *)(*(int (__stdcall **)(int))(v2 + 44))(this[67]);
  }
  return result;
}
