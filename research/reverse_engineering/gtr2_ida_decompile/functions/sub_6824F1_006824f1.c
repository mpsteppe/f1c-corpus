unsigned int __thiscall sub_6824F1(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  unsigned int v6; // esi
  unsigned int result; // eax
  int i; // ecx

  if ( !a5 )
  {
    result = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 4 * (a4 + a3 * *(_DWORD *)(a2 + 12)));
    goto LABEL_8;
  }
  v5 = *(_DWORD *)(a2 + 8);
  v6 = *(_DWORD *)(v5 + 4 * a4);
  result = *(_DWORD *)(v5 + 4 * (a4 + *(_DWORD *)(a2 + 12)));
  if ( !a3 )
  {
    if ( v6 > result )
      goto LABEL_8;
    goto LABEL_4;
  }
  if ( v6 > result )
LABEL_4:
    result = v6;
LABEL_8:
  for ( i = this[5];
        result != *(_DWORD *)(*(_DWORD *)(i + 4 * result) + 48);
        result = *(_DWORD *)(*(_DWORD *)(i + 4 * result) + 48) )
  {
    ;
  }
  return result;
}
