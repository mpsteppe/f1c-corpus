// f1c  0x004cdb20  size=53
int __usercall sub_4CDB20@<eax>(int a1@<ecx>, double a2@<st0>)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 4);
  switch ( result )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      result = sub_4CC1D0(a1, a2);
      break;
    case 5:
      result = sub_4CB860(a1, a2);
      break;
    case 6:
    case 7:
      result = sub_4CDAD0((_DWORD *)a1, a2);
      break;
    case 8:
      result = sub_4CD980(a1, a2);
      break;
    case 12:
      result = sub_4CD220((float *)a1, a2);
      break;
    case 13:
      result = sub_4CCB30(a1, a2);
      break;
    default:
      return result;
  }
  return result;
}
