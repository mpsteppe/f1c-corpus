int __thiscall sub_427FC0(_DWORD *this)
{
  int result; // eax

  result = this[6006];
  if ( result != 3 )
  {
    this[5931] = 0;
    if ( !result )
      this[6006] = 5;
  }
  return result;
}
