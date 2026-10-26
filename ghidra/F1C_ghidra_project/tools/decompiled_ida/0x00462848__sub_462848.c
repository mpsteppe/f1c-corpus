// Address: 0x00462848
// Size: 73 bytes
// Name: sub_462848
// Type: char __usercall@<al>(_DWORD *@<ecx>, int@<ebx>, int@<edi>, int@<esi>)
// Source: IDA Hex-Rays decompilation

char __usercall sub_462848@<al>(_DWORD *a1@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  char result; // al

  *(_BYTE *)(a3 - 80) += a2;
  *(_DWORD *)(a4 - 62) += a2;
  if ( sub_4A0590(&unk_7CE24C) )
    return 0;
  if ( dword_7C56A4 == 7 )
    sub_4613E0(*a1);
  sub_460710(*a1);
  sub_45F2B0(-1);
  result = 1;
  *(_BYTE *)(*a1 + 884) = 1;
  return result;
}
