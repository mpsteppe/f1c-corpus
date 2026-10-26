int __thiscall sub_407210(_DWORD *this)
{
  int result; // eax

  result = this[3];
  if ( result )
    return AIL_pause_stream(result, 0);
  return result;
}
