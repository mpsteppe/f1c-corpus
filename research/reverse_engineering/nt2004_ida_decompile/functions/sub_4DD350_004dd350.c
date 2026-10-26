unsigned int __thiscall sub_4DD350(int this, int a2, int a3, int a4, int a5)
{
  unsigned int result; // eax
  int v7; // edi

  result = *(_DWORD *)this;
  if ( *(_DWORD *)(*(_DWORD *)this + 16584) != 3 && dword_75CBB0 == 7 )
  {
    result = *(_DWORD *)(this + 56);
    if ( !result )
    {
      if ( a4 )
      {
        if ( a4 == 2 )
          *(_DWORD *)(this + 16) = 2;
        else
          *(_DWORD *)(this + 16) = a4;
      }
      else
      {
        if ( *(_DWORD *)(this + 8) == 9 && !(unsigned __int8)sub_4BBF20() )
        {
          *(_DWORD *)(this + 8) = 5;
          if ( dword_75CBB4 == 3 )
          {
            sub_4FAFF0(a2, *(_DWORD *)(this + 4));
            sub_42F950(&dword_75CBA8, 5);
          }
          sub_421590(*(_DWORD *)this, 16, 0);
        }
        if ( *(_DWORD *)(this + 16) == 2 )
          ++*(_DWORD *)(this + 280);
        *(_DWORD *)(this + 116) = 2;
        *(_DWORD *)(this + 16) = 0;
        *(_DWORD *)(this + 12) = 0;
        *(_DWORD *)(this + 120) = a3;
        *(_BYTE *)(this + 36) = 0;
      }
      result = *(_DWORD *)(*(_DWORD *)this + 16584);
      if ( result <= 1 )
      {
        v7 = dword_7D3C44;
        if ( dword_79FC40 < 1023 )
        {
          ++dword_79FC40;
          dword_7D3C44 += 208;
        }
        result = sub_4D0D00((_DWORD *)v7, 4, 8, 8, *(_DWORD *)(this + 4), a3, a4 != 0 ? 0 : 3);
        *(_DWORD *)(v7 + 8) = a3;
        *(_WORD *)(v7 + 12) = a4;
        *(_WORD *)(v7 + 14) = -1;
      }
    }
  }
  return result;
}
