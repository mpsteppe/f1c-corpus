int __thiscall sub_4AC1A0(void *this)
{
  int v2; // eax
  char Buffer[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v5; // [esp+45h] [ebp-3h]
  char v6; // [esp+47h] [ebp-1h]

  memset(Buffer, 0, sizeof(Buffer));
  v5 = 0;
  v6 = 0;
  v2 = *((_DWORD *)this + 214);
  if ( v2 == 4 )
    sub_4331B0((int)&byte_B64150, *((const char ***)this + 212));
  else
    sub_433050(v2, *((_DWORD *)this + 213));
  sprintf(Buffer, "%s", (const char *)(*((_DWORD *)this + 211) + 30));
  sub_499010();
  if ( *(_DWORD *)(*((_DWORD *)this + 211) + 16) )
    (*(void (__thiscall **)(void *, _DWORD, char *))(*(_DWORD *)this + 36))(this, 0, Buffer);
  else
    (*(void (__thiscall **)(void *, int, char *))(*(_DWORD *)this + 36))(this, 1, Buffer);
  return 0;
}
