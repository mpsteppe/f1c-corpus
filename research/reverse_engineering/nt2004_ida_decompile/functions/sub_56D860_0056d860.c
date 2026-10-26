int __thiscall sub_56D860(void *this, char *a2, char *buf, int len)
{
  char *v5; // eax
  int result; // eax
  void *Error; // esi
  char *v8; // eax
  char *v9; // eax
  int v10; // eax
  int v11; // [esp-18h] [ebp-340h]
  int v12; // [esp-14h] [ebp-33Ch]
  int v13; // [esp-10h] [ebp-338h]
  int v14; // [esp-Ch] [ebp-334h]
  int v15; // [esp-8h] [ebp-330h]
  char Buffer[768]; // [esp+1Ch] [ebp-30Ch] BYREF
  int v17; // [esp+324h] [ebp-4h]

  v5 = sub_56B290(a2);
  result = send(*(_DWORD *)v5, buf, len, 0);
  if ( result == -1 )
  {
    Error = (void *)WSAGetLastError();
    v8 = sub_56B280(a2);
    Buffer[0] = 0;
    v15 = *((unsigned __int16 *)v8 + 1);
    v14 = (unsigned __int8)v8[7];
    v13 = (unsigned __int8)v8[6];
    v12 = (unsigned __int8)v8[5];
    v11 = (unsigned __int8)v8[4];
    v17 = 0;
    v9 = sub_56D0B0(Error);
    sprintf(Buffer, "Error (%s) sending to %d.%d.%d.%d:%d", v9, v11, v12, v13, v14, v15);
    v10 = sub_575D30(this);
    (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v10 + 24))(v10, Buffer, 2);
    nullsub_6(this);
    if ( Error == (void *)10035 )
      return 0;
    else
      return -1;
  }
  return result;
}
