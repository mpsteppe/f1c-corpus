int __thiscall sub_46DC60(_DWORD **this, char a2)
{
  _DWORD *v4; // eax

  VirtualCallOnDAT008ac4c4_8d80();
  if ( SessionStateCheckWrapper(dword_7CD25C) )
  {
    if ( !StateCheckWrapper(dword_7CD25C) || !(unsigned __int8)((int (__thiscall *)(_DWORD *))loc_462850)(dword_7CD25C) )
      return 1;
  }
  else
  {
    sub_42D210(&dword_7C569C, 1);
    if ( dword_7C56A4 == 5 && byte_7CEBC4 )
    {
      v4 = (_DWORD *)(*(int (__thiscall **)(_DWORD *, int))(*this[16] + 28))(this[16], 30);
      if ( v4 )
        sub_46BF10(v4, a2);
      sub_4D2450(dword_8ACEE0);
    }
    ShortComputation_7250(this[16], 1);
    if ( sub_4A0590(&unk_7CE24C) )
      return 1;
  }
  dword_5CC9E8 = 4;
  return 0;
}

