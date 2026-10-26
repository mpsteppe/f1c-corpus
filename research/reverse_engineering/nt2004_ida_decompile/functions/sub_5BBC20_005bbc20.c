int __fastcall sub_5BBC20(_DWORD *a1, int a2)
{
  DWORD TickCount; // eax
  char v5; // al
  signed int v6; // eax
  int v7; // eax
  int v8; // ecx
  bool v9; // zf
  __int16 v10; // dx
  struct sockaddr to; // [esp+Ch] [ebp-110h] BYREF
  char buf[256]; // [esp+1Ch] [ebp-100h] BYREF

  sub_5BBBD0(a1 + 2, a2);
  TickCount = GetTickCount();
  *(_DWORD *)(a2 + 28) = TickCount;
  if ( *a1 == 1 )
  {
    *(_DWORD *)&buf[3] = TickCount;
    v5 = *(_BYTE *)(a2 + 20);
    buf[0] = -2;
    buf[1] = -3;
    buf[2] = 0;
    if ( (v5 & 4) != 0 )
    {
      buf[7] = *((_BYTE *)a1 + 60);
      v6 = a1[15];
      if ( v6 > 0 )
        qmemcpy(&buf[8], a1 + 10, v6);
      buf[v6 + 8] = 0;
      buf[v6 + 9] = 0;
      v7 = v6 + 10;
    }
    else
    {
      buf[7] = -1;
      *(_WORD *)&buf[8] = -1;
      v7 = 10;
    }
  }
  else if ( (*(_BYTE *)(a2 + 20) & 4) != 0 )
  {
    qmemcpy(buf, "\\basic\\\\info\\", 13);
    v7 = 13;
  }
  else
  {
    qmemcpy(buf, "\\status\\", 8);
    v7 = 8;
  }
  v8 = *(_DWORD *)a2;
  v9 = *(_DWORD *)a2 == a1[9];
  to.sa_family = 2;
  if ( v9 && (*(_BYTE *)(a2 + 21) & 2) != 0 )
  {
    v10 = *(_WORD *)(a2 + 12);
    *(_DWORD *)&to.sa_data[2] = *(_DWORD *)(a2 + 8);
    *(_WORD *)to.sa_data = v10;
  }
  else
  {
    *(_DWORD *)&to.sa_data[2] = v8;
    *(_WORD *)to.sa_data = *(_WORD *)(a2 + 4);
  }
  return sendto(a1[8], buf, v7, 0, &to, 16);
}
