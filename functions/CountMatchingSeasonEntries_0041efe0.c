int __fastcall sub_41EFE0(int a1, int a2)
{
  int v4; // ebx
  int v5; // esi
  int v6; // eax
  _DWORD *v7; // edi
  int v8; // eax

  v4 = 0;
  if ( LinkedListDereference(&dword_7D2DB0) )
  {
    v5 = 0;
    v6 = LinkedListDereference(&dword_7D2DB0);
    if ( FlagsGetter(v6) > 0 )
    {
      v7 = (_DWORD *)(a1 + 24);
      do
      {
        if ( *v7 == a2 )
          ++v4;
        ++v5;
        ++v7;
        v8 = LinkedListDereference(&dword_7D2DB0);
      }
      while ( v5 < FlagsGetter(v8) );
    }
  }
  return v4;
}
