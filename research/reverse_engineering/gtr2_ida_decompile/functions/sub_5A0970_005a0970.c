char __thiscall sub_5A0970(_DWORD *this, int a2, int a3)
{
  int v4; // ebx
  char result; // al
  int v6; // eax
  SOCKET v7; // [esp-16h] [ebp-65Ch]
  const char *v8; // [esp-2h] [ebp-648h]
  char v9; // [esp+5h] [ebp-641h]
  u_short hostshort[2]; // [esp+16h] [ebp-630h]
  int v11; // [esp+1Eh] [ebp-628h]
  int v12; // [esp+22h] [ebp-624h]
  _BYTE v13[4]; // [esp+26h] [ebp-620h] BYREF
  struct sockaddr to; // [esp+2Ah] [ebp-61Ch] BYREF
  char buf[2]; // [esp+3Ah] [ebp-60Ch] BYREF
  unsigned __int16 v16; // [esp+3Ch] [ebp-60Ah]
  _BYTE v17[1540]; // [esp+42h] [ebp-604h] BYREF
  _DWORD *retaddr; // [esp+646h] [ebp+0h]

  v9 = HIBYTE(a2);
  sub_59C8D0();
  v4 = retaddr[1];
  *(_DWORD *)hostshort = *retaddr;
  v11 = retaddr[2];
  v12 = retaddr[3];
  hostshort[1] = htons(HIWORD(*retaddr));
  *(_DWORD *)&to.sa_family = *(_DWORD *)hostshort;
  *(_DWORD *)&to.sa_data[6] = v11;
  *(_DWORD *)&to.sa_data[10] = v12;
  v7 = this[598];
  *(_DWORD *)&to.sa_data[2] = v4;
  if ( sendto(v7, buf, v16 + *(unsigned __int16 *)buf + 4, 0, &to, 16) != -1 )
    return 1;
  switch ( WSAGetLastError() )
  {
    case 10038:
      v8 = "WSAENOTSOCK";
      goto LABEL_5;
    case 10047:
      v8 = "WSAEAFNOSUPPORT";
      goto LABEL_5;
    case 10049:
      v8 = "WSAEADDRNOTAVAIL";
      goto LABEL_5;
    case 10050:
      v8 = "WSAENETDOWN";
      goto LABEL_5;
    case 10053:
      v8 = "WSAECONNABORTED";
      goto LABEL_5;
    case 10054:
      v8 = "WSAECONNRESET";
      goto LABEL_5;
    case 10055:
      if ( (unsigned __int8)sub_59CD10() )
      {
        v6 = sub_5A3CE0(this);
        (*(void (__thiscall **)(int, int, _DWORD *, _BYTE *, int, int, _BYTE *))(*(_DWORD *)v6 + 56))(
          v6,
          v4,
          retaddr,
          v13,
          1,
          a2,
          v17);
        nullsub_7(this);
      }
      goto LABEL_15;
    case 10058:
      v8 = "WSAESHUTDOWN";
      goto LABEL_5;
    case 10060:
      v8 = "WSAETIMEDOUT";
LABEL_5:
      sub_59FC50();
      result = HIBYTE(v8);
      break;
    default:
LABEL_15:
      result = v9;
      break;
  }
  return result;
}
