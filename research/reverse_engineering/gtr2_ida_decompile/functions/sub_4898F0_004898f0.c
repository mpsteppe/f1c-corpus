_DWORD *__thiscall sub_4898F0(_DWORD *this)
{
  _DWORD *result; // eax
  int *v2; // edx

  result = this;
  v2 = (int *)*this;
  if ( !*(_BYTE *)(*this + 21) )
  {
    do
    {
      result = v2;
      v2 = (int *)*v2;
    }
    while ( !*((_BYTE *)v2 + 21) );
  }
  return result;
}
