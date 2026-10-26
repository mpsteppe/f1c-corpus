int __usercall sub_4D4A58@<eax>(int result@<eax>)
{
  *(_DWORD *)(result + 4) = 4;
  *(_DWORD *)(result + 8) = 0;
  return result;
}
