int __usercall sub_4DEB48@<eax>(int result@<eax>, int a2@<edx>, int a3@<ecx>)
{
  *(_DWORD *)(a3 + 4 * result + 332) = a2;
  return result;
}
