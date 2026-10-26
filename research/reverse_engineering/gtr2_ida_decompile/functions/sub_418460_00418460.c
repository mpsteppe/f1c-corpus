int __thiscall sub_418460(int *this)
{
  int result; // eax
  int v3; // eax

  result = this[8];
  switch ( result )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      sub_46FF50(this + 4);
      v3 = *this;
      if ( *this == -1 )
      {
        sub_52F560(this);
      }
      else
      {
        --dword_91BF88;
        *(_DWORD *)(dword_91BF90 + 4 * v3) = *(_DWORD *)(dword_91BF90 + 4 * dword_91BF88);
        **(_DWORD **)(dword_91BF90 + 4 * v3) = v3;
        *this = -1;
        sub_52F4B0(this);
      }
      result = sub_52FC50(this);
      break;
    default:
      return result;
  }
  return result;
}
