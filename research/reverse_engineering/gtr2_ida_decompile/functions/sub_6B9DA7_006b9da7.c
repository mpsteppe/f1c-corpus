int __userpurge sub_6B9DA7@<eax>(int a1@<eax>, unsigned __int8 *a2)
{
  int v2; // ecx

  HIWORD(v2) = HIWORD(a2);
  LOWORD(a1) = *a2;
  LOWORD(v2) = a2[1];
  return v2 + (a1 << 8);
}
