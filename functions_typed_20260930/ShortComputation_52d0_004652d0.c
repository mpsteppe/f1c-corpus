_BYTE *__thiscall sub_4652D0(void *this, int a2)
{
  _BYTE *result; // eax

  result = (_BYTE *)(560 * a2 + *(_DWORD *)this + 248);
  if ( !*result )
  {
    *result = 1;
    result = *(_BYTE **)this;
    ++*(_DWORD *)(*(_DWORD *)this + 58380);
  }
  return result;
}

