int __userpurge sub_59E4C0@<eax>(int a1@<ecx>, int a2@<edi>, int a3, int a4)
{
  int v5; // ebp
  int v7; // kr00_4
  const struct sockaddr *v8; // eax
  int v9; // eax
  void *v10; // esi
  int v11; // [esp-8h] [ebp-78h]
  int v12; // [esp-4h] [ebp-74h]
  int tolen; // [esp+10h] [ebp-60h] BYREF
  u_long v14; // [esp+14h] [ebp-5Ch]
  char buf[4]; // [esp+1Ch] [ebp-54h] BYREF
  char Buffer[80]; // [esp+20h] [ebp-50h] BYREF

  v5 = 1;
  (*(void (__thiscall **)(int))(*(_DWORD *)a1 + 72))(a1);
  sub_5A3F00(a4);
  LOWORD(tolen) = 2;
  v14 = htonl(0);
  HIWORD(tolen) = htons(0);
  if ( (unsigned __int8)((int (__thiscall *)(int, int, int *))byte_59C790)(a1, a3, &tolen) )
  {
    sub_5A4030(a1);
    v12 = *(unsigned __int16 *)(a1 + 2348);
    v11 = *(_DWORD *)(a1 + 2392);
    if ( sub_59D7B0() <= 0 )
      return 1;
    Buffer[0] = 0;
    sprintf(Buffer, "%s%s%s", off_903EDC, off_903EE4, (const char *)(a1 + 2356));
    v7 = strlen(Buffer);
    v8 = (const struct sockaddr *)sub_59C1E0();
    if ( v7 == sendto(*(_DWORD *)(a1 + 2392), buf, v7, 0, v8, (int)&tolen) )
    {
      sub_5A42E0(a1, 1, a2, v11, v12);
      v9 = sub_59C300();
      *(_DWORD *)v9 = 0;
      *(_BYTE *)(v9 + 4) = 0;
      v10 = *(void **)(a1 + 1576);
      if ( v10 )
        ReleaseMutex(v10);
      return 0;
    }
  }
  return v5;
}
