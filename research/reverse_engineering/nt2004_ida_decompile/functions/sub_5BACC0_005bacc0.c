int __fastcall sub_5BACC0(SOCKET *a1, char *a2, int a3, struct sockaddr *to)
{
  SOCKET *v4; // ebp
  int result; // eax
  char v6; // cl
  int (__fastcall *v7)(char *, int, struct sockaddr *); // ebp
  char v8; // bl
  _BYTE *v9; // edi
  char *v10; // esi
  SOCKET v11; // eax
  int v12; // edx
  char buf[2048]; // [esp+10h] [ebp-804h] BYREF
  int len; // [esp+810h] [ebp-4h]
  signed int v15; // [esp+818h] [ebp+4h]

  v4 = a1;
  result = (int)a2;
  len = 0;
  if ( !a1 )
    v4 = (SOCKET *)off_624A10;
  v6 = *a2;
  if ( *a2 == 59 )
  {
    v7 = (int (__fastcall *)(char *, int, struct sockaddr *))v4[53];
    if ( v7 )
      return v7(a2, a3, to);
  }
  else if ( v6 == 92 )
  {
    sub_5BB5D0(v4, buf);
    return sendto(*v4, buf, len, 0, to, 16);
  }
  else if ( a3 >= 7 && v6 == -2 && a2[1] == -3 )
  {
    if ( (int)v4[44] > 0 )
      v4[44] = 0;
    v8 = a2[2];
    v9 = a2 + 3;
    v10 = a2 + 7;
    v15 = a3 - 7;
    sub_5BAF50(a2 + 3);
    result = v8;
    switch ( v8 )
    {
      case 0:
        sub_5BB260(v10, v15);
        return sendto(*v4, buf, len, 0, to, 16);
      case 1:
        sub_5BAF70(v10, v15);
        return sendto(*v4, buf, len, 0, to, 16);
      case 2:
        if ( v15 > 32 )
          v15 = 32;
        buf[0] = 5;
        qmemcpy(&buf[len], v10, v15);
        len += v15;
        return sendto(*v4, buf, len, 0, to, 16);
      case 4:
        result = v4[44];
        if ( result == -1 )
          return result;
        result = 0;
        while ( v9[result] == *((_BYTE *)v4 + result + 132) )
        {
          if ( ++result >= 4 )
          {
            if ( v15 >= 2 )
            {
              v11 = v4[65];
              v4[44] = -1;
              return ((int (__fastcall *)(_DWORD, char *, SOCKET))v4[39])(*v10, v10 + 1, v11);
            }
            return result;
          }
        }
        return result;
      case 6:
        result = 0;
        break;
      default:
        return result;
    }
    while ( v9[result] == *((_BYTE *)v4 + result + 132) )
    {
      if ( ++result >= 4 )
      {
        if ( v15 >= 4 )
        {
          v12 = *(_DWORD *)v10;
          buf[0] = 7;
          *(_DWORD *)&buf[len] = v12;
          len += 4;
          if ( !sub_5BB890(v4) )
            sub_5BB7F0(v15 - 4);
          return sendto(*v4, buf, len, 0, to, 16);
        }
        return result;
      }
    }
  }
  return result;
}
