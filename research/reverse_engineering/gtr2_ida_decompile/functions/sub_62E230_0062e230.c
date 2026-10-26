int __usercall sub_62E230@<eax>(int a1@<eax>)
{
  int result; // eax

  sub_62D0B0((unsigned __int16 *)(a1 + 138), *(_DWORD *)(a1 + 2834), (_WORD *)a1);
  sub_62D0B0((unsigned __int16 *)(a1 + 2430), *(_DWORD *)(a1 + 2846), (_WORD *)a1);
  sub_62E040(a1, (int *)(a1 + 2854));
  for ( result = 18; result >= 3; --result )
  {
    if ( *(_WORD *)(a1 + 4 * (unsigned __int8)byte_72F444[result] + 2676) )
      break;
  }
  *(_DWORD *)(a1 + 5787) += 3 * result + 17;
  return result;
}
