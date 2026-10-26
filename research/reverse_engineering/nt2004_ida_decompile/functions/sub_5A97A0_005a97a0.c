int __thiscall sub_5A97A0(void **this)
{
  int result; // eax
  int v3; // edi
  void **v4; // esi

  result = (int)this[1];
  v3 = 0;
  if ( result > 0 )
  {
    v4 = this + 2;
    do
    {
      sub_5A9360(*v4);
      if ( *v4 )
      {
        j_nullsub_6(*v4);
        sub_5BE8AE();
      }
      *v4 = 0;
      result = (int)this[1];
      ++v3;
      ++v4;
    }
    while ( v3 < result );
  }
  return result;
}
