int __thiscall sub_4B07C0(_DWORD *this)
{
  int result; // eax

  result = this[2];
  if ( !result )
  {
    sub_4B07E0(this);
    return this[2];
  }
  return result;
}
