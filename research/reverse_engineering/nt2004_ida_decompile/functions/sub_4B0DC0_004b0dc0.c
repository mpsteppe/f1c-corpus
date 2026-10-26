int __thiscall sub_4B0DC0(void **this, void **a2)
{
  void **v2; // ebx
  char *v4; // edi
  int result; // eax

  v2 = a2;
  if ( !a2 )
    v2 = this + 2;
  v4 = (char *)*v2;
  if ( *v2 )
  {
    sub_4B0DC0(v4 + 36);
    sub_4B0DC0(v4 + 32);
    result = sub_5BE8AE(v4);
  }
  *v2 = 0;
  this[3] = 0;
  return result;
}
