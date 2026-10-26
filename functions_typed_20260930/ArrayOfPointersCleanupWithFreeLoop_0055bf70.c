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
      LinkedListFreeWithTraversalAndNulling(*v4);
      v5 = *v4;
      if ( *v4 )
      {
        EmptyStub_7470(*v4);
        FreeWrapper_7bcf(v5);
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

