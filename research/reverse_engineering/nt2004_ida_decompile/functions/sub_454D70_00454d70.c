int __thiscall sub_454D70(_DWORD *this)
{
  int result; // eax

  if ( !*this )
  {
    result = this[1];
    byte_761FFC[result] = *((_BYTE *)this + 8);
  }
  return result;
}
