int __thiscall sub_534EE0(LPVOID *lpMem)
{
  int v2; // edi
  char v4; // al
  int v5; // eax

  v2 = 0;
  if ( !lpMem )
    return -2;
  if ( lpMem[20] )
    sub_58AA6F(lpMem[20]);
  if ( lpMem[7] )
  {
    v4 = *((_BYTE *)lpMem + 92);
    if ( v4 == 119 )
    {
      v5 = sub_5361D0(lpMem);
    }
    else
    {
      if ( v4 != 114 )
        goto LABEL_11;
      v5 = GuardedFunctionCallCleanup(lpMem);
    }
    v2 = v5;
  }
LABEL_11:
  if ( lpMem[16] && FileCloseWithLock(lpMem[16]) && *(_DWORD *)TLSOffsetGetter() != 29 )
    v2 = -1;
  if ( (int)lpMem[14] < 0 )
    v2 = (int)lpMem[14];
  if ( lpMem[17] )
    sub_58AA6F(lpMem[17]);
  if ( lpMem[18] )
    sub_58AA6F(lpMem[18]);
  if ( lpMem[21] )
    sub_58AA6F(lpMem[21]);
  sub_58AA6F(lpMem);
  return v2;
}

