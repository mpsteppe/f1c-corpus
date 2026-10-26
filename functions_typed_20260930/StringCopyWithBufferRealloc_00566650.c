int __thiscall sub_566650(int this, const char *a2)
{
  unsigned int v4; // kr04_4

  if ( !a2 )
    return -1;
  v4 = strlen(a2) + 1;
  if ( !*(_DWORD *)this )
    goto LABEL_6;
  if ( *(_DWORD *)(this + 4) < (signed int)(v4 - 1) )
  {
    FreeWrapper_7bcf(*(LPVOID *)this);
LABEL_6:
    *(_DWORD *)this = OperatorNewNhMallocWrapper(v4);
    *(_DWORD *)(this + 4) = v4 - 1;
  }
  strcpy(*(char **)this, a2);
  return 0;
}

