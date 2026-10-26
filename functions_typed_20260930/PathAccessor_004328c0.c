char *__thiscall PathAccessor(void *this)
{
  char *result; // eax

  result = *(char **)(*(_DWORD *)this + 8);
  if ( !result )
    return byte_5EA438;
  return result;
}

