int __usercall sub_6DA811@<eax>(int a1@<eax>)
{
  int result; // eax

  sub_6D987A(a1 + 140, *(_DWORD *)(a1 + 2836), (_WORD *)a1);
  sub_6D987A(a1 + 2432, *(_DWORD *)(a1 + 2848), (_WORD *)a1);
  sub_6DA62E();
  for ( result = 18; result >= 3; --result )
  {
    if ( *(_WORD *)(a1 + 4 * (unsigned __int8)byte_748104[result] + 2678) )
      break;
  }
  *(_DWORD *)(a1 + 5792) += 3 * result + 17;
  return result;
}
