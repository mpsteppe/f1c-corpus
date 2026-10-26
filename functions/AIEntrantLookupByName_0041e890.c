int __thiscall sub_41E890(void *this)
{
  int v2; // esi
  char *v3; // eax

  v2 = 0;
  while ( 1 )
  {
    if ( LinkedListDereference(&dword_7D2DB0) )
    {
      LinkedListDereference(&dword_7D2DB0);
      if ( ShortComputation_13a0(v2) )
      {
        LinkedListDereference(&dword_7D2DB0);
        v3 = *(char **)ShortComputation_13a0(v2);
        if ( !v3 )
          v3 = &byte_5EA438;
        if ( !sub_588410(v3, this) )
          break;
      }
    }
    if ( ++v2 >= 103 )
      return 0;
  }
  LinkedListDereference(&dword_7D2DB0);
  return *(_DWORD *)(ShortComputation_13a0(v2) + 408);
}
