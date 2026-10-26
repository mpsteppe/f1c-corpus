int __usercall sub_5373C0@<eax>(int a1@<ecx>, char *a2@<edi>)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 95740) - 1;
  switch ( *(_DWORD *)(a1 + 95740) )
  {
    case 1:
      *(_DWORD *)(a1 + 95740) = 2;
      *(_BYTE *)(a1 + 95744) = 0;
      break;
    case 2:
      *(_DWORD *)(a1 + 95740) = 3;
      *(_BYTE *)(a1 + 95744) = 0;
      break;
    case 3:
      *(_DWORD *)(a1 + 95740) = 4;
      *(_BYTE *)(a1 + 95744) = 0;
      break;
    case 4:
      *(_DWORD *)(a1 + 95740) = 5;
      *(_BYTE *)(a1 + 95744) = 0;
      break;
    case 5:
      *(_DWORD *)(a1 + 95740) = 6;
      *(_BYTE *)(a1 + 95744) = 0;
      break;
    case 6:
      sub_535B50(a1, a2);
      result = sub_530500();
      goto LABEL_8;
    default:
LABEL_8:
      *(_BYTE *)(a1 + 95744) = 0;
      break;
  }
  return result;
}
