int __thiscall sub_4B61E0(_DWORD *this)
{
  int result; // eax

  result = this[1];
  if ( result )
  {
    result = sub_5A1AD0(result);
    this[1] = 0;
  }
  return result;
}
