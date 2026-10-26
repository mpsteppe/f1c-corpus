int __thiscall QOrder0000BmpQualifyingOrderReset(int this)
{
  int v2; // ecx
  int result; // eax
  void *v4; // edi
  int v5; // ecx

  if ( *(_BYTE *)(this + 372) )
  {
    v2 = dword_5C329C;
    result = 0;
    if ( dword_5C329C <= 0 )
      goto LABEL_5;
    do
    {
      dword_7CD2B8[result] = *(_DWORD *)(LODWORD(dword_7C54F0[result]) + 18580);
      ++result;
    }
    while ( result < v2 );
    if ( result >= 104 )
    {
      *(_DWORD *)(this + 376) = -1;
    }
    else
    {
LABEL_5:
      v4 = (void *)(4 * result + 8180408);
      v5 = 104 - result;
      result = -1;
      memset(v4, 0xFFu, 4 * v5);
      *(_DWORD *)(this + 376) = -1;
    }
  }
  else
  {
    sub_497AD0(*(_DWORD **)(this + 64), off_5C6674, 0);
    result = -1;
    memset(&dword_7CD470, 0xFFu, 0x1A0u);
    *(_DWORD *)(this + 376) = -1;
  }
  return result;
}

