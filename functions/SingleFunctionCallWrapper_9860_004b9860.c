int __thiscall sub_4B9860(int *this, int a2)
{
  int result; // eax
  int v3; // ecx

  v3 = *this;
  result = a2;
  *(_DWORD *)(v3 + 2476) = a2;
  switch ( a2 )
  {
    case 0:
      *(_DWORD *)(v3 + 3964) = 1042983595;
      break;
    case 1:
      *(_DWORD *)(v3 + 3964) = 1040187392;
      break;
    case 2:
      *(_DWORD *)(v3 + 3964) = 1036831949;
      break;
    case 3:
      *(_DWORD *)(v3 + 3964) = 1034594987;
      break;
    case 4:
      *(_DWORD *)(v3 + 3964) = 1026206379;
      break;
    default:
      return result;
  }
  return result;
}
