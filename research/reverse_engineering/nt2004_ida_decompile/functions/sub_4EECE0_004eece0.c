int __thiscall sub_4EECE0(_DWORD *this, char a2)
{
  int v2; // eax
  int result; // eax

  v2 = this[6324];
  if ( a2 )
  {
    result = v2 | 8;
    this[6324] = result;
  }
  else
  {
    this[6324] = v2 & 0xFFFFFFF7;
    return sub_51F0F0(this + 21);
  }
  return result;
}
