int __userpurge sub_40D2CA@<eax>(int a1@<edx>, _DWORD *a2@<ecx>, int a3@<ebx>, int a4)
{
  int v4; // eax
  int result; // eax
  int i; // esi

  *(_DWORD *)(a3 + 1418395647) = a1;
  if ( (_BYTE)a1 )
    v4 = dword_7C54DC + 1;
  else
    v4 = dword_7C54DC - 1;
  if ( v4 >= 0 )
  {
    if ( v4 >= dword_5C329C )
      v4 = 0;
  }
  else
  {
    v4 = dword_5C329C - 1;
  }
  GameStateDispatchChain(a2, *(_DWORD *)(dword_7C54F0[v4] + 18580));
  result = dword_5C329C;
  for ( i = 0; i < dword_5C329C; ++i )
  {
    sub_4F0D20(dword_7C54F0[i] + 12);
    result = dword_5C329C;
  }
  return result;
}
