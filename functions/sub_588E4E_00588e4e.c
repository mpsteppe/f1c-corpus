void *__cdecl sub_588E4E(_BYTE *a1, _BYTE *a2, _WORD *a3, _DWORD *a4)
{
  void *result; // eax
  _BYTE v5[136]; // [esp+Ch] [ebp-88h] BYREF

  if ( !a1 )
    return 0;
  if ( *a1 == 67 && !a1[1] )
  {
    result = a2;
    a2[1] = 0;
    *a2 = 67;
    if ( a3 )
    {
      *a3 = 0;
      a3[1] = 0;
      a3[2] = 0;
    }
    if ( a4 )
      *a4 = 0;
    return result;
  }
  if ( sub_58FB90(&unk_5E6468, a1) && sub_58FB90(&unk_5E63E4, a1) )
  {
    if ( sub_588F8B(v5, a1) || !sub_58FD90(v5, &unk_8D3E48, v5) )
      return 0;
    dword_8D3E50 = (unsigned __int16)word_8D3E4C;
    sub_589057(&unk_5E6468, v5);
    sub_58FCA0(&unk_5E63E4);
  }
  if ( a3 )
    MemoryCopy_cc00(a3, &unk_8D3E48, 6);
  if ( a4 )
    MemoryCopy_cc00(a4, &dword_8D3E50, 4);
  sub_58FCA0(a2);
  return &unk_5E6468;
}
