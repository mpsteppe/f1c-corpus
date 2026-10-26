char __thiscall sub_4B9DA0(int *this, int a2)
{
  char result; // al

  switch ( a2 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
      *(_DWORD *)(*this + 3980) = a2;
      result = 1;
      break;
    case 9:
      SortedLinkedListInsert((_DWORD *)*this, 0);
      result = 1;
      break;
    case 10:
      SpriteOverlayDisplayListCleanup(*this);
      result = 1;
      break;
    case 11:
      LinkedListDestructor_8480(*this);
      result = 1;
      break;
    case 12:
      SortedListSeekByValue(*this);
      result = 1;
      break;
    case 13:
      LinkedListPrioritySearchByFloatThreshold(*this);
      goto LABEL_8;
    default:
LABEL_8:
      result = 1;
      break;
  }
  return result;
}
