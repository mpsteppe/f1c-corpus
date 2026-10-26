int __userpurge sub_4ECA20@<eax>(int a1@<edi>, int a2@<esi>, int a3, int a4, int a5)
{
  int result; // eax

  (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 35, a1, a2);
  result = sub_4CE380();
  if ( (_BYTE)result )
    return sub_4D67D0(a5);
  return result;
}
