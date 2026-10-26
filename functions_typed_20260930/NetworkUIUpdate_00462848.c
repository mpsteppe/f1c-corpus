char __usercall sub_462848@<al>(int *a1@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  char result; // al

  *(_BYTE *)(a3 - 80) += a2;
  *(_DWORD *)(a4 - 62) += a2;
  if ( sub_4A0590(&unk_7CE24C) )
    return 0;
  if ( dword_7C56A4 == 7 )
    ShortComputation_13e0((_DWORD *)*a1);
  ConditionalRenderStateUpdate((_DWORD *)*a1);
  SessionUIElementRenderer(*a1, -1);
  result = 1;
  *(_BYTE *)(*a1 + 884) = 1;
  return result;
}

