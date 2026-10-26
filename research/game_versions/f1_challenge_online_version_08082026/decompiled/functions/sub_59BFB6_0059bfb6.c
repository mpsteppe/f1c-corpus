const char *__thiscall sub_59BFB6(_DWORD *this)
{
  const char *result; // eax

  result = (const char *)this[1];
  if ( !result )
    return "Unknown exception";
  return result;
}
