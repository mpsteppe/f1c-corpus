int __usercall sub_427FE4@<eax>(_DWORD *a1@<eax>)
{
  LOBYTE(a1) = (unsigned __int8)a1 | 0x69;
  *a1 -= a1;
  return 100;
}
