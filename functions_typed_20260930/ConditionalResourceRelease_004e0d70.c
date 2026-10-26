int __stdcall sub_4E0D70(int *a1)
{
  int result; // eax

  result = *a1;
  if ( *a1 )
  {
    if ( *((_BYTE *)a1 + 64) )
    {
      DoublyLinkedListNodeTransplant(*a1);
      *((_BYTE *)a1 + 64) = 0;
      return FlagFieldBitManipulation(1, 1, 1, 0);
    }
  }
  return result;
}

