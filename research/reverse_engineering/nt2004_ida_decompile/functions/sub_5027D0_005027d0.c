int __stdcall sub_5027D0(int a1)
{
  int result; // eax
  int *v2; // esi

  result = a1 - 1;
  switch ( a1 )
  {
    case 1:
      v2 = &dword_7D79E0;
      goto LABEL_7;
    case 2:
      v2 = &dword_7D79E4;
      goto LABEL_7;
    case 3:
      v2 = &dword_7D79E8;
      goto LABEL_7;
    case 4:
      v2 = &dword_7D79EC;
      goto LABEL_7;
    case 5:
      v2 = (int *)&flt_7D79F0;
LABEL_7:
      result = *v2;
      if ( *v2 )
      {
        result = sub_5A1AD0(*v2);
        *v2 = 0;
      }
      break;
    default:
      return result;
  }
  return result;
}
