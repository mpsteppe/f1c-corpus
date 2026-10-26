int *__thiscall FAILWRONGTRIAGE(int *this)
{
  int v2; // eax

  v2 = OperatorNewNhMallocWrapper(88);
  if ( v2 )
  {
    *(_DWORD *)(v2 + 16) = 0;
    *(_DWORD *)(v2 + 12) = 0;
    *(_DWORD *)(v2 + 8) = 0;
    *(_DWORD *)(v2 + 4) = 0;
    *(_DWORD *)v2 = 0;
    *(_DWORD *)(v2 + 40) = 0;
    *(_DWORD *)(v2 + 44) = -1;
    *(_DWORD *)(v2 + 48) = 0;
    *(_DWORD *)(v2 + 52) = -1;
    *(_DWORD *)(v2 + 56) = 0;
    *(_DWORD *)(v2 + 60) = -1;
    *(_DWORD *)(v2 + 64) = 0;
    *(_DWORD *)(v2 + 68) = 0;
    *(_DWORD *)(v2 + 72) = 0;
    *(_DWORD *)(v2 + 76) = 0;
    *(_DWORD *)(v2 + 24) = 1142292480;
    *(_DWORD *)(v2 + 32) = 0;
    *(_BYTE *)(v2 + 36) = 0;
    *(_DWORD *)(v2 + 80) = 0;
    *(_DWORD *)(v2 + 84) = 0;
    *(_BYTE *)(v2 + 20) = 0;
    *(_BYTE *)(v2 + 21) = 0;
    *(_DWORD *)(v2 + 28) = 0;
    *this = v2;
  }
  else
  {
    *this = 0;
  }
  return this;
}

