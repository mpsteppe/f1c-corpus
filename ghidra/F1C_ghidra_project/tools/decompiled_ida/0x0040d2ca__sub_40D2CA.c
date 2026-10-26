// Address: 0x0040d2ca
// Size: 105 bytes
// Name: sub_40D2CA
// Type: int __userpurge@<eax>(int@<edx>, int@<ebx>, int)
// Source: IDA Hex-Rays decompilation

int __userpurge sub_40D2CA@<eax>(int a1@<edx>, int a2@<ebx>, int a3)
{
  int v3; // eax
  int result; // eax
  int i; // esi

  *(_DWORD *)(a2 + 1418395647) = a1;
  if ( (_BYTE)a1 )
    v3 = dword_7C54DC + 1;
  else
    v3 = dword_7C54DC - 1;
  if ( v3 >= 0 )
  {
    if ( v3 >= dword_5C329C )
      v3 = 0;
  }
  else
  {
    v3 = dword_5C329C - 1;
  }
  sub_40D240(*(_DWORD *)(dword_7C54F0[v3] + 18580));
  result = dword_5C329C;
  for ( i = 0; i < dword_5C329C; ++i )
  {
    sub_4F0D20(dword_7C54F0[i] + 12);
    result = dword_5C329C;
  }
  return result;
}
