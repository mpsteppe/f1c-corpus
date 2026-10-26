int __thiscall sub_59C960(void *this, int a2, char *buf, int len)
{
  int v5; // ebp
  int Error; // edi
  const char *v7; // eax
  int v8; // eax
  int v10; // [esp-18h] [ebp-328h]
  int v11; // [esp-14h] [ebp-324h]
  int v12; // [esp-10h] [ebp-320h]
  int v13; // [esp-Ch] [ebp-31Ch]
  int v14; // [esp-8h] [ebp-318h]
  char Buffer[768]; // [esp+10h] [ebp-300h] BYREF

  v5 = send(*(_DWORD *)(a2 + 32), buf, len, 0);
  if ( v5 != -1 )
    return v5;
  Error = WSAGetLastError();
  v14 = *(unsigned __int16 *)(a2 + 18);
  v13 = *(unsigned __int8 *)(a2 + 23);
  v12 = *(unsigned __int8 *)(a2 + 22);
  v11 = *(unsigned __int8 *)(a2 + 21);
  v10 = *(unsigned __int8 *)(a2 + 20);
  Buffer[0] = 0;
  v7 = sub_59BBD0(Error);
  sprintf(Buffer, "Error (%s) sending to %d.%d.%d.%d:%d", v7, v10, v11, v12, v13, v14);
  v8 = sub_5A3CE0(this);
  (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v8 + 24))(v8, Buffer, 2);
  nullsub_7(this);
  if ( Error == 10035 )
    return 0;
  else
    return v5;
}
