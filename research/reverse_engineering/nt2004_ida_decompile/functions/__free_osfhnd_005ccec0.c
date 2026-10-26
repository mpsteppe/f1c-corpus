int __cdecl _free_osfhnd(int a1)
{
  int v1; // eax

  if ( a1 >= uNumber
    || (v1 = 36 * (a1 & 0x1F) + dword_8003E0[a1 >> 5], (*(_BYTE *)(v1 + 4) & 1) == 0)
    || *(_DWORD *)v1 == -1 )
  {
    *_errno() = 9;
    *__doserrno() = 0;
    return -1;
  }
  else
  {
    if ( dword_625274 == 1 )
    {
      if ( a1 )
      {
        if ( a1 == 1 )
        {
          SetStdHandle(0xFFFFFFF5, 0);
        }
        else if ( a1 == 2 )
        {
          SetStdHandle(0xFFFFFFF4, 0);
        }
      }
      else
      {
        SetStdHandle(0xFFFFFFF6, 0);
      }
    }
    *(_DWORD *)(dword_8003E0[a1 >> 5] + 36 * (a1 & 0x1F)) = -1;
    return 0;
  }
}
