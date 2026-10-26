const char *__thiscall sub_681C52(_DWORD *this, int a2)
{
  const char *result; // eax

  result = "input";
  if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(a2 + 4)) + 4) & 0x20) != 0 )
    return "output";
  return result;
}
