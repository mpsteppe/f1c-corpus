int __thiscall sub_4FB440(int **this, int a2)
{
  int v3; // eax
  int result; // eax
  int *v5; // ecx

  if ( (unsigned __int8)sub_5BFC80(this[4]) )
  {
    v3 = this[4][25];
    if ( *(_DWORD *)(v3 + 15576) == 4
      && !*(_DWORD *)(v3 + 14820)
      && (unsigned __int8)sub_577A80(v3 + 16)
      && !byte_FADD28 )
    {
      sub_4FB250(this[4]);
      if ( !byte_B6F118 )
        sub_4094C0();
      sub_54B280(this[4] + 20);
    }
  }
  result = sub_5BFC80(this[4]);
  if ( !(_BYTE)result )
  {
    v5 = this[4];
    if ( *(_DWORD *)(v5[25] + 15576) )
    {
      return sub_4074A0(v5);
    }
    else
    {
      sub_54B280(v5 + 15);
      return sub_4094C0();
    }
  }
  return result;
}
