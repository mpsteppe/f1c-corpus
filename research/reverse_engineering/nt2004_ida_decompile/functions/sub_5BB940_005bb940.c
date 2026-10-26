DWORD __fastcall sub_5BB940(int a1, int a2)
{
  int v4; // esi
  struct in_addr *v5; // ebp
  char *v6; // eax
  const char *v7; // edx
  DWORD result; // eax
  char Buffer[20]; // [esp+Ch] [ebp-818h] BYREF
  char buf[2048]; // [esp+20h] [ebp-804h] BYREF
  int len; // [esp+820h] [ebp-4h]

  v4 = 0;
  len = 0;
  sub_5BAF50((int)buf, 3, (_DWORD *)(a1 + 132));
  if ( dword_7FEFDC > 0 )
  {
    v5 = (struct in_addr *)dword_7FEFC8;
    do
    {
      sprintf(Buffer, "localip%d", v4);
      sub_5BABA0((int)buf, Buffer);
      v6 = inet_ntoa(*v5);
      sub_5BABA0((int)buf, v6);
      ++v4;
      ++v5;
    }
    while ( v4 < dword_7FEFDC );
  }
  sub_5BABA0((int)buf, aLocalport);
  sub_5BAB70((int)buf, *(_DWORD *)(a1 + 184));
  sub_5BABA0((int)buf, aNatneg);
  v7 = a1_0;
  if ( !*(_DWORD *)(a1 + 192) )
    v7 = a0;
  sub_5BABA0((int)buf, v7);
  if ( a2 )
  {
    sub_5BABA0((int)buf, aStatechanged);
    sub_5BAB70((int)buf, a2);
  }
  sub_5BABA0((int)buf, aGamename_0);
  sub_5BABA0((int)buf, (const char *)(a1 + 4));
  if ( a2 == 2 )
  {
    if ( 2048 - len >= 1 )
      buf[len++] = 0;
  }
  else
  {
    sub_5BB340(255, 0, 255, 0, 255, 0);
  }
  sendto(*(_DWORD *)a1, buf, len, 0, (const struct sockaddr *)(a1 + 196), 16);
  result = GetTickCount();
  *(_DWORD *)(a1 + 168) = result;
  *(_DWORD *)(a1 + 172) = result;
  return result;
}
