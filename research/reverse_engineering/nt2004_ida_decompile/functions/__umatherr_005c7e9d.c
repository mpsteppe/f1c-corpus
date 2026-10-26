double __cdecl _umatherr(int Value, int a2, int a3, int a4, int a5, int a6, double a7, int a8)
{
  if ( _get_fname(a2) )
  {
    _ctrlfp(a8, 0xFFFF);
    if ( !sub_5BFE92() )
      _set_errno(Value);
    return a7;
  }
  else
  {
    _ctrlfp(a8, 0xFFFF);
    _set_errno(Value);
    return a7;
  }
}
