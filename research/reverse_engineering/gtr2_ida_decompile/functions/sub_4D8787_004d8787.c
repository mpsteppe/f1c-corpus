// positive sp value has been detected, the output may be wrong!
int __usercall sub_4D8787@<eax>(_DWORD *a1@<ecx>, __int32 a2@<ebx>, int a3@<esi>)
{
  *a1 = &off_711E90;
  if ( dword_B6E198 )
  {
    sub_5DEBD0(dword_B6E198);
    dword_B6E198 = 0;
  }
  a1[67] = 0;
  return sub_4D82A0(a2, a3);
}
