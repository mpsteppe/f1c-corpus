// f1_2002_full  0x0052dad0  size=139
int __thiscall sub_52DAD0(_DWORD *this, int a2, int a3)
{
  int result; // eax
  int v5; // esi
  int v6; // [esp+Ch] [ebp-4h] BYREF

  result = 0;
  v6 = 0;
  if ( a3 )
  {
LABEL_9:
    sub_5342E0(a2, &v6);
    return v6;
  }
  v5 = this[63];
  if ( !v5 )
  {
LABEL_8:
    if ( !this[65] )
      return result;
    goto LABEL_9;
  }
  while ( !result )
  {
    if ( *(_DWORD *)(v5 + 236) )
    {
      sub_5342E0(a2, &v6);
      result = v6;
    }
    v5 = *(_DWORD *)(v5 + 260);
    if ( !v5 )
    {
      if ( result )
        return result;
      goto LABEL_8;
    }
  }
  return result;
}
