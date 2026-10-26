int __thiscall sub_5E3A10(_DWORD *this, const char *a2, int a3)
{
  if ( a2 )
  {
    sub_5D8EF0((int)(this + 3), a2, 64);
    *this |= a3;
  }
  else
  {
    *this |= a3;
  }
  return 0;
}
