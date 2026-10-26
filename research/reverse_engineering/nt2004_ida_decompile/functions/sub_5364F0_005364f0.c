int __thiscall sub_5364F0(LPVOID lpMem)
{
  int v2; // edi
  char v4; // al
  int v5; // eax

  v2 = 0;
  if ( !lpMem )
    return -2;
  if ( *((_DWORD *)lpMem + 20) )
    sub_5C1B88(*((LPVOID *)lpMem + 20));
  if ( *((_DWORD *)lpMem + 7) )
  {
    v4 = *((_BYTE *)lpMem + 92);
    if ( v4 == 119 )
    {
      v5 = sub_537810(lpMem);
    }
    else
    {
      if ( v4 != 114 )
        goto LABEL_11;
      v5 = sub_536CA0(lpMem);
    }
    v2 = v5;
  }
LABEL_11:
  if ( *((_DWORD *)lpMem + 16) && fclose(*((FILE **)lpMem + 16)) && *_errno() != 29 )
    v2 = -1;
  if ( *((int *)lpMem + 14) < 0 )
    v2 = *((_DWORD *)lpMem + 14);
  if ( *((_DWORD *)lpMem + 17) )
    sub_5C1B88(*((LPVOID *)lpMem + 17));
  if ( *((_DWORD *)lpMem + 18) )
    sub_5C1B88(*((LPVOID *)lpMem + 18));
  if ( *((_DWORD *)lpMem + 21) )
    sub_5C1B88(*((LPVOID *)lpMem + 21));
  sub_5C1B88(lpMem);
  return v2;
}
