char __thiscall sub_57D6C0(_DWORD *this, unsigned int a2, _DWORD *a3)
{
  int v4; // ebp
  int v5; // ebx
  SOCKET v6; // edx
  char result; // al
  int v8; // eax
  u_short hostshort[2]; // [esp+14h] [ebp-628h]
  int v10; // [esp+1Ch] [ebp-620h]
  int v11; // [esp+20h] [ebp-61Ch]
  int v12; // [esp+24h] [ebp-618h] BYREF
  struct sockaddr to; // [esp+28h] [ebp-614h] BYREF
  unsigned __int16 buf[770]; // [esp+38h] [ebp-604h] BYREF

  StructuredMemoryCopyWithHeaderPrepend(a2, buf);
  v4 = buf[0] + buf[1] + 4;
  *(_DWORD *)hostshort = *a3;
  v5 = a3[1];
  v10 = a3[2];
  v11 = a3[3];
  hostshort[1] = htons(HIWORD(*a3));
  *(_DWORD *)&to.sa_family = *(_DWORD *)hostshort;
  *(_DWORD *)&to.sa_data[6] = v10;
  *(_DWORD *)&to.sa_data[10] = v11;
  v6 = this[591];
  *(_DWORD *)&to.sa_data[2] = v5;
  if ( sendto(v6, (const char *)buf, v4, 0, &to, 16) != -1 )
    return 1;
  switch ( WSAGetLastError() )
  {
    case 10038:
      MutexProtectedLinkedListLookupByID(*a3, a3[1], a3[2], a3[3], aWsaenotsock);
      goto LABEL_5;
    case 10047:
      MutexProtectedLinkedListLookupByID(*a3, a3[1], a3[2], a3[3], aWsaeafnosuppor);
      goto LABEL_5;
    case 10049:
      MutexProtectedLinkedListLookupByID(*a3, a3[1], a3[2], a3[3], aWsaeaddrnotava);
      goto LABEL_5;
    case 10050:
      MutexProtectedLinkedListLookupByID(*a3, a3[1], a3[2], a3[3], aWsaenetdown);
      goto LABEL_5;
    case 10053:
      MutexProtectedLinkedListLookupByID(*a3, a3[1], a3[2], a3[3], aWsaeconnaborte);
      goto LABEL_5;
    case 10054:
      MutexProtectedLinkedListLookupByID(*a3, a3[1], a3[2], a3[3], aWsaeconnreset);
      goto LABEL_5;
    case 10055:
      if ( (unsigned __int8)ThreadSafeMutexQueueWithTimedWait((int)a3, (int)&v12, 1u) )
      {
        v8 = FieldGetter_5cc0(this);
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 56))(v8, v12);
        EmptyStub_0170();
      }
      goto LABEL_15;
    case 10058:
      MutexProtectedLinkedListLookupByID(*a3, a3[1], a3[2], a3[3], aWsaeshutdown);
      goto LABEL_5;
    case 10060:
      MutexProtectedLinkedListLookupByID(*a3, a3[1], a3[2], a3[3], aWsaetimedout);
LABEL_5:
      result = 0;
      break;
    default:
LABEL_15:
      result = 0;
      break;
  }
  return result;
}

