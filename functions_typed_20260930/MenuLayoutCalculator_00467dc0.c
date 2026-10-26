int __thiscall MenuLayoutCalculator(int this)
{
  const char *v2; // eax

  CreditsTxtParser((_DWORD *)this);
  HTMLOutputSectionProcessor((_DWORD *)this);
  *(_DWORD *)(this + 236) = *(_DWORD *)(this + 4) + (*(_DWORD *)(this + 8) - *(_DWORD *)(this + 4)) / 2;
  v2 = *(const char **)(this + 184);
  if ( !v2 )
    v2 = byte_5EA438;
  *(_DWORD *)(this + 264) = sub_497AD0(*(_DWORD **)(this + 64), v2, 0);
  return 0;
}

