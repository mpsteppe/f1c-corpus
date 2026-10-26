int __thiscall sub_406750(_DWORD *this)
{
  int result; // eax

  if ( this[3] )
  {
    AIL_close_stream(this[3]);
    this[3] = 0;
  }
  if ( this[23] != -1 )
    sub_406A70(this);
  result = sub_4080B0(this[7]);
  if ( result )
    return StructInitWithVTableDispatchAndZeroFill(result);
  return result;
}
