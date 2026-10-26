char __userpurge sub_5E5AB0@<al>(int a1@<ecx>, __int32 a2@<ebx>, int a3@<esi>, _DWORD *a4)
{
  char result; // al

  result = (char)a4;
  if ( a4 )
  {
    if ( (BYTE1(*a4) & 0x80u) == 0 )
      return sub_5D9700((int *)(a1 + 388), a2, a3, (int)a4, 1);
    else
      return sub_5D9700((int *)(a1 + 404), a2, a3, (int)a4, 1);
  }
  return result;
}
