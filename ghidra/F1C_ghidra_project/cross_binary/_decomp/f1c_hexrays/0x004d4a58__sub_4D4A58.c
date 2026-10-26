// f1c  0x004d4a58  size=15
int __usercall sub_4D4A58@<eax>(int result@<eax>)
{
  *(_DWORD *)(result + 4) = 4;
  *(_DWORD *)(result + 8) = 0;
  return result;
}
