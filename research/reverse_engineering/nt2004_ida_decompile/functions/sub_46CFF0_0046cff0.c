_BYTE *__thiscall sub_46CFF0(void *this, int a2)
{
  _BYTE *result; // eax

  result = (_BYTE *)(284 * a2 + *(_DWORD *)this + 196);
  if ( !*result )
  {
    *result = 1;
    result = *(_BYTE **)this;
    ++*(_DWORD *)(*(_DWORD *)this + 14056);
  }
  return result;
}
