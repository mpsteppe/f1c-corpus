// f1c  0x0044f6f6  size=70
int __userpurge sub_44F6F6@<eax>(int result@<eax>, _DWORD *a2@<ecx>, int a3, int a4, int a5, int a6)
{
  switch ( result )
  {
    case 0:
      result = a6;
      a2[44] = a6;
      break;
    case 1:
      a2[45] = a6;
      break;
    case 2:
      result = a6;
      a2[46] = a6;
      break;
    case 3:
      result = a6 + a2[47];
      a2[47] = result;
      break;
  }
  return result;
}
