int __thiscall sub_4074F0(_DWORD *this)
{
  int result; // eax

  if ( this[3] )
  {
    AIL_close_stream(this[3]);
    this[3] = 0;
  }
  if ( this[23] != -1 )
    sub_407820(this);
  result = sub_408E90(this[7]);
  if ( result )
    return sub_4062E0(result);
  return result;
}
