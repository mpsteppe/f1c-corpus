int __usercall sub_42E469@<eax>(int result@<eax>, char a2@<cl>)
{
  *(_BYTE *)(result + 29) = a2;
  *(_BYTE *)(result + 30) = a2;
  return result;
}
