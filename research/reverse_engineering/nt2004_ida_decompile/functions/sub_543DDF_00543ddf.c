int __thiscall sub_543DDF(_DWORD *this)
{
  unsigned int v2; // ebx
  unsigned int j; // edi
  int i; // [esp+8h] [ebp-10h]

  *this = &off_5F3120;
  if ( this[1071] )
  {
    if ( this[1072] )
    {
      v2 = this[1063];
      for ( i = this[1072]; v2 < this[1064]; ++v2 )
      {
        for ( j = this[1060]; j < this[1062]; j += 4 )
        {
          sub_5BE8AE();
          i += 8;
        }
      }
    }
  }
  sub_5BE8AE();
  sub_5BE8AE();
  return sub_543AD2(this);
}
