// f1c  0x00406a70  size=29
int __thiscall sub_406A70(_DWORD *this)
{
  int result; // eax

  result = this[23];
  if ( result != -1 )
  {
    result = sub_58C331(this[23]);
    this[23] = -1;
  }
  return result;
}
