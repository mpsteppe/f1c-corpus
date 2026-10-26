// f1c  0x00405a30  size=22
int __thiscall sub_405A30(_DWORD *this)
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
