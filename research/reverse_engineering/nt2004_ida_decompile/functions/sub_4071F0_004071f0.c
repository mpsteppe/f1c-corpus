int __thiscall sub_4071F0(_DWORD *this)
{
  int result; // eax

  result = this[3];
  if ( result )
    return AIL_pause_stream(result, 1);
  return result;
}
