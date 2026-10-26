// f1c  0x0040e710  size=63
int __thiscall sub_40E710(_DWORD *this, int a2)
{
  int result; // eax

  result = this[7];
  switch ( result )
  {
    case 0:
    case 3:
      result = this[8];
      *(_DWORD *)(result + 208) = a2;
      break;
    case 1:
    case 4:
      result = a2;
      *(_DWORD *)(this[8] + 208) = a2;
      break;
    case 2:
    case 5:
      *(_DWORD *)(this[8] + 208) = a2;
      break;
    default:
      return result;
  }
  return result;
}
