int __thiscall sub_55BF70(void **this)
{
  int result; // eax
  int v3; // edi
  void **v4; // esi
  void *v5; // ebx

  result = (int)this[1];
  v3 = 0;
  if ( result > 0 )
  {
    v4 = this + 2;
    do
    {
      sub_55BBA0(*v4);
      v5 = *v4;
      if ( *v4 )
      {
        j_nullsub_3(*v4);
        sub_587BCF(v5);
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
