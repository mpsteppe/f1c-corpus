int __thiscall sub_40A340(_DWORD *this)
{
  int result; // eax

  result = this[22];
  if ( result )
  {
    result = *(_DWORD *)(result + 16);
    if ( result )
      return AIL_stop_sample(result);
  }
  return result;
}
