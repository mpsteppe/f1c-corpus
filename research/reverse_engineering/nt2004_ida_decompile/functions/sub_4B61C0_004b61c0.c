int __thiscall sub_4B61C0(_DWORD *this)
{
  int result; // eax

  result = this[2];
  if ( result )
  {
    result = sub_5A2B00(result);
    this[2] = 0;
  }
  return result;
}
