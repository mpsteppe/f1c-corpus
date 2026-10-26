int *__thiscall sub_4D6CF0(int this)
{
  int v2; // edi
  LPVOID **v3; // ebx
  char v4; // al
  LPVOID *v5; // ebp

  sub_4D5820((_DWORD *)this);
  sub_4D5710((_DWORD *)this);
  v2 = *(_DWORD *)(this + 848);
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v4 = *(_BYTE *)(v2 + 12);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        if ( v5[1] )
          sub_5BE8AE(v5[1]);
        sub_5BE8AE(v5);
      }
    }
    sub_5BE8AE(v3);
  }
  *(_DWORD *)(this + 848) = 0;
  *(_DWORD *)(this + 852) = 0;
  *(_DWORD *)(this + 856) = 0;
  *(_DWORD *)(this + 860) = 0;
  sub_4D4B20((_DWORD *)(this + 2088));
  *(_DWORD *)(this + 2076) = 0;
  *(_DWORD *)(this + 2080) = 0;
  *(_DWORD *)(this + 2160) = 0;
  *(_BYTE *)(this + 864) = 0;
  *(_DWORD *)(this + 1328) = -1;
  *(_DWORD *)(this + 1332) = -1;
  *(_DWORD *)(this + 2164) = 5;
  return sub_4D5920((_DWORD *)this);
}
