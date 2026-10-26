BOOL __thiscall sub_4634A0(int *this)
{
  int v2; // ecx
  BOOL result; // eax

  result = 0;
  if ( sub_4633A0(this) )
  {
    v2 = *(_DWORD *)(*this + 6708);
    if ( v2 )
    {
      if ( sub_56A630(v2) )
        return 1;
    }
  }
  return result;
}
