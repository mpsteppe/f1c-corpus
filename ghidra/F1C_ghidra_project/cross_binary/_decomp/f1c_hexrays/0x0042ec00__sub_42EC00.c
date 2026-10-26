// f1c  0x0042ec00  size=96
int __thiscall sub_42EC00(_DWORD *this, int a2)
{
  const char *v2; // esi

  v2 = &byte_5C3738;
  if ( this[1] != 1 )
    v2 = &byte_5C3734;
  if ( sub_423A00(byte_5EC4C0, v2, byte_5EC4CC) )
  {
    if ( v2 )
      strcpy(byte_5EC4CC, v2);
    else
      byte_5EC4CC[0] = 0;
  }
  return sub_58815F(a2, &off_5C3730, byte_5EC4CC);
}
