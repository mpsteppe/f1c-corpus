int __userpurge sub_4DB763@<eax>(int result@<eax>, char a2@<dl>, int a3, int a4)
{
  *(_DWORD *)(result + 4) = 0;
  *(_BYTE *)(result + 8) = a2;
  return result;
}
