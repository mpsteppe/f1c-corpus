int __userpurge sub_49BEE0@<eax>(int a1@<ecx>, __int32 a2@<ebp>, int a3)
{
  char v5; // bl
  char v6; // [esp+6h] [ebp-2h]
  char v7; // [esp+7h] [ebp-1h]

  sub_540150(off_16C99AC);
  if ( (unsigned __int8)sub_4735A0() )
  {
    if ( !(unsigned __int8)sub_4735E0(&dword_B6CBA8) || !(unsigned __int8)sub_4786A0() )
      return 1;
    goto LABEL_24;
  }
  if ( *(_DWORD *)dword_B72314 != 4 || (v7 = 1, sub_616840("SkipQualifying1")) )
    v7 = 0;
  if ( *(_DWORD *)dword_B72314 != 4 || (v6 = 1, sub_616840("SkipQualifying2")) )
    v6 = 0;
  v5 = byte_B722E4;
  sub_4304C0();
  if ( *(_DWORD *)dword_B640C8 == 3 )
  {
    if ( !byte_B6FEEC && !v7 && !v5 )
      goto LABEL_23;
  }
  else if ( *(_DWORD *)dword_B640C8 != 4 || !byte_B6FF04 && !v6 && !v5 )
  {
    goto LABEL_23;
  }
  if ( (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 48) + 28))(*(_DWORD *)(a1 + 48), 18) )
    sub_49A6B0(a2, a3);
  sub_551D30(&unk_FADD40);
LABEL_23:
  sub_4DE260(1);
  if ( sub_4EC440(-1) )
    return 1;
LABEL_24:
  dword_75B17C = 4;
  return 0;
}
