char __thiscall sub_5A19D0(int this, SOCKET s, int a3)
{
  void *v3; // ebp
  char v4; // bl
  int v5; // eax
  bool v6; // bl
  void *v7; // eax
  DWORD v8; // eax
  int v9; // edx
  int *v10; // eax
  bool v11; // zf
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int *v15; // eax
  char *v16; // ebx
  int v17; // esi
  int v18; // edi
  signed int v19; // ebp
  void *v20; // eax
  DWORD v21; // eax
  int v22; // edx
  int *v23; // eax
  int i; // eax
  void *v25; // ecx
  int v26; // ecx
  int v27; // eax
  int *v28; // eax
  bool v29; // bl
  void *v30; // eax
  DWORD v31; // eax
  int v32; // ecx
  int *v33; // eax
  int v34; // edi
  int v35; // eax
  int v36; // eax
  int *v37; // eax
  unsigned int v38; // esi
  int v39; // ecx
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // edi
  int v44; // eax
  int v45; // edx
  void *v46; // eax
  DWORD v47; // eax
  int v48; // edi
  int *v49; // eax
  int v50; // esi
  int v51; // eax
  int *v52; // eax
  void *v53; // eax
  DWORD v54; // eax
  int v55; // edi
  int *v56; // eax
  int v57; // esi
  int v58; // ecx
  int v59; // eax
  int *v60; // eax
  int v61; // eax
  int v62; // ebp
  int v63; // eax
  const char *v65; // [esp+Ch] [ebp-758h]
  char v66; // [esp+13h] [ebp-751h]
  char v67; // [esp+21h] [ebp-743h]
  bool v68; // [esp+23h] [ebp-741h]
  int v69; // [esp+24h] [ebp-740h]
  int v71; // [esp+2Ch] [ebp-738h] BYREF
  int namelen; // [esp+30h] [ebp-734h] BYREF
  u_long hostlong; // [esp+34h] [ebp-730h]
  struct sockaddr from; // [esp+38h] [ebp-72Ch] BYREF
  int v75; // [esp+48h] [ebp-71Ch]
  int v76; // [esp+4Ch] [ebp-718h] BYREF
  int fromlen; // [esp+50h] [ebp-714h] BYREF
  timeval timeout; // [esp+54h] [ebp-710h] BYREF
  fd_set readfds; // [esp+5Ch] [ebp-708h] BYREF
  unsigned __int16 v80; // [esp+160h] [ebp-604h] BYREF
  unsigned __int16 v81; // [esp+162h] [ebp-602h]
  int v82[384]; // [esp+164h] [ebp-600h] BYREF
  void *retaddr; // [esp+764h] [ebp+0h]

  timeout.tv_sec = 0;
  timeout.tv_usec = 0;
  v68 = 0;
  readfds.fd_array[0] = s;
  readfds.fd_count = 1;
  BYTE1(v69) = 0;
  v75 = 0;
  do
  {
    v3 = (void *)s;
    if ( BYTE1(v69) )
      break;
    v4 = 0;
    LOBYTE(v69) = 0;
    v67 = 0;
    hostlong = 0;
    v5 = select(0, &readfds, 0, 0, &timeout);
    if ( v5 == -1 )
    {
      WSAGetLastError();
      sub_59BBD0(-1);
    }
    else
    {
      LOBYTE(v69) = v5 != 0;
    }
    if ( (_BYTE)a3 )
    {
      if ( (_BYTE)v69 )
        goto LABEL_31;
    }
    else
    {
      if ( (_BYTE)v69 )
        goto LABEL_31;
      if ( !v68 )
      {
        namelen = 16;
        v6 = getpeername(s, (struct sockaddr *)(this + 2720), &namelen) == 0;
        if ( getsockname(s, (struct sockaddr *)(this + 2736), &namelen) )
          v6 = 0;
        v68 = v6;
        v4 = 0;
      }
      htonl(0);
      htons(0);
      v7 = *(void **)(this + 2776);
      if ( v7 && ((v8 = WaitForSingleObject(v7, *(_DWORD *)(this + 2780))) == 0 || v8 == 128) )
        v9 = this + 2760;
      else
        v9 = 0;
      v10 = *(int **)v9;
      v11 = *(_DWORD *)v9 == 0;
      *(_DWORD *)(v9 + 8) = *(_DWORD *)v9;
      if ( !v11 )
      {
        v12 = *v10;
        if ( v12 )
        {
          while ( 1 )
          {
            v13 = *(_DWORD *)(v12 + 32);
            if ( v13 != -1 && s != -1 && v13 == s )
              break;
            v14 = *(_DWORD *)(v9 + 8);
            if ( v14 )
            {
              v15 = *(int **)(v14 + 4);
              *(_DWORD *)(v9 + 8) = v15;
              if ( v15 )
              {
                v12 = *v15;
                if ( v12 )
                  continue;
              }
            }
            goto LABEL_28;
          }
          if ( *(_WORD *)(v12 + 2108) >= 4u )
            v4 = 1;
        }
      }
LABEL_28:
      if ( *(_DWORD *)(this + 2776) )
        ReleaseMutex(*(HANDLE *)(this + 2776));
      if ( v4 )
      {
        while ( 1 )
        {
LABEL_31:
          if ( BYTE1(v69) )
            break;
          *(float *)&v71 = 0.0;
          from.sa_family = 2;
          *(_DWORD *)&from.sa_data[2] = htonl(0);
          *(_WORD *)from.sa_data = htons(0);
          v16 = (char *)sub_5A7130(this + 2708);
          namelen = (int)v16;
          v17 = sub_5C3D80(this + 2708);
          fromlen = 16;
          if ( (_BYTE)a3 )
          {
            v18 = recvfrom((SOCKET)v3, v16, v17, 0, &from, &fromlen);
            hostlong = v18;
            *(_WORD *)from.sa_data = ntohs(*(u_short *)from.sa_data);
            if ( sub_5A1300((unsigned __int16 *)this, (int)v16, v16, v18, (int)&from) )
              goto LABEL_128;
            v67 = 1;
            v19 = v18;
            if ( v18 <= 0 )
              goto LABEL_128;
            *(struct sockaddr *)(this + 2720) = from;
            v71 = 16;
            v68 = getsockname(s, (struct sockaddr *)(this + 2736), &v71) == 0;
            goto LABEL_90;
          }
          BYTE2(v69) = 1;
          if ( !(_BYTE)v69 )
            goto LABEL_59;
          v20 = *(void **)(this + 2776);
          if ( v20 && ((v21 = WaitForSingleObject(v20, *(_DWORD *)(this + 2780))) == 0 || v21 == 128) )
            v22 = this + 2760;
          else
            v22 = 0;
          v23 = *(int **)v22;
          v11 = *(_DWORD *)v22 == 0;
          *(_DWORD *)(v22 + 8) = *(_DWORD *)v22;
          if ( !v11 )
          {
            for ( i = *v23; i; i = *v28 )
            {
              v25 = *(void **)(i + 32);
              if ( v25 != (void *)-1 && v3 != (void *)-1 && v25 == v3 )
              {
                v26 = *(unsigned __int16 *)(i + 2108);
                if ( v17 >= 2048 - v26 )
                  v17 = 2048 - v26;
              }
              v27 = *(_DWORD *)(v22 + 8);
              if ( !v27 )
                break;
              v28 = *(int **)(v27 + 4);
              *(_DWORD *)(v22 + 8) = v28;
              if ( !v28 )
                break;
            }
          }
          if ( *(_DWORD *)(this + 2776) )
            ReleaseMutex(*(HANDLE *)(this + 2776));
          if ( v17 > 0 )
          {
            v67 = 1;
            hostlong = recv((SOCKET)v3, v16, v17, 0);
            if ( (int)hostlong > 0 )
              BYTE2(v69) = 0;
          }
          else
          {
LABEL_59:
            if ( !v67 )
              goto LABEL_64;
          }
          if ( !v68 )
          {
            v76 = 16;
            v29 = getpeername((SOCKET)v3, (struct sockaddr *)(this + 2720), &v76) == 0;
            if ( getsockname((SOCKET)v3, (struct sockaddr *)(this + 2736), &v76) )
              v29 = 0;
            v68 = v29;
          }
LABEL_64:
          v30 = *(void **)(this + 2776);
          if ( v30 && ((v31 = WaitForSingleObject(v30, *(_DWORD *)(this + 2780))) == 0 || v31 == 128) )
            v32 = this + 2760;
          else
            v32 = 0;
          v33 = *(int **)v32;
          v11 = *(_DWORD *)v32 == 0;
          *(_DWORD *)(v32 + 8) = *(_DWORD *)v32;
          if ( !v11 )
          {
            v34 = *v33;
            if ( *v33 )
            {
              while ( 1 )
              {
                v35 = *(_DWORD *)(v34 + 32);
                if ( v35 != -1 && s != -1 && v35 == s )
                  break;
                v36 = *(_DWORD *)(v32 + 8);
                if ( v36 )
                {
                  v37 = *(int **)(v36 + 4);
                  *(_DWORD *)(v32 + 8) = v37;
                  if ( v37 )
                  {
                    v34 = *v37;
                    if ( *v37 )
                      continue;
                  }
                }
                goto LABEL_86;
              }
              if ( v67 && (int)hostlong > 0 )
              {
                BYTE2(v65) = BYTE2(hostlong);
                sub_59C3A0();
              }
              v38 = *(unsigned __int16 *)(v34 + 2108);
              if ( v38 >= 4 )
              {
                v39 = v34 + 56;
                if ( *(_WORD *)(v34 + 2108) >= 4u )
                {
                  v40 = *(_DWORD *)(v34 + 2104);
                  LOBYTE(readfds.fd_array[62]) = *(_BYTE *)(v40 + v39);
                  v41 = (v40 + 1) % 2048;
                  BYTE1(readfds.fd_array[62]) = *(_BYTE *)(v41 + v39);
                  v42 = (v41 + 1) % 2048;
                  BYTE2(readfds.fd_array[62]) = *(_BYTE *)(v42 + v39);
                  HIBYTE(readfds.fd_array[62]) = *(_BYTE *)((v42 + 1) % 2048 + v39);
                  v43 = HIWORD(readfds.fd_array[62]) + LOWORD(readfds.fd_array[62]) + 4;
                  if ( (int)v38 >= v43 )
                  {
                    if ( sub_59C400(v39, this, HIWORD(readfds.fd_array[62]) + LOWORD(readfds.fd_array[62]) + 4) )
                      v69 = v43;
                  }
                }
              }
            }
          }
LABEL_86:
          if ( *(_DWORD *)(this + 2776) )
            ReleaseMutex(*(HANDLE *)(this + 2776));
          if ( BYTE2(v69) )
          {
            v19 = v71;
LABEL_90:
            if ( v19 > 0 && (unsigned int)v19 <= 0x604 )
            {
              qmemcpy(&v80, (const void *)namelen, v19);
              if ( v19 == v81 + v80 + 4 )
              {
                *(float *)&v71 = sub_5A3EA0(this);
                v44 = *(_DWORD *)(this + 2724);
                *(_DWORD *)&from.sa_family = *(_DWORD *)(this + 2720);
                v45 = *(_DWORD *)(this + 2728);
                *(_DWORD *)&from.sa_data[2] = v44;
                *(_DWORD *)&from.sa_data[10] = *(_DWORD *)(this + 2732);
                v46 = *(void **)(this + 2776);
                *(_DWORD *)&from.sa_data[6] = v45;
                if ( v46 && ((v47 = WaitForSingleObject(v46, *(_DWORD *)(this + 2780))) == 0 || v47 == 128) )
                  v48 = this + 2760;
                else
                  v48 = 0;
                v49 = *(int **)v48;
                v11 = *(_DWORD *)v48 == 0;
                *(_DWORD *)(v48 + 8) = *(_DWORD *)v48;
                if ( !v11 )
                {
                  v50 = *v49;
                  if ( *v49 )
                  {
                    while ( !sub_59C230(v50, &from) )
                    {
                      v51 = *(_DWORD *)(v48 + 8);
                      if ( v51 )
                      {
                        v52 = *(int **)(v51 + 4);
                        *(_DWORD *)(v48 + 8) = v52;
                        if ( v52 )
                        {
                          v50 = *v52;
                          if ( *v52 )
                            continue;
                        }
                      }
                      goto LABEL_106;
                    }
                    *(float *)(v50 + 44) = *(float *)&v71;
                  }
                }
LABEL_106:
                if ( *(_DWORD *)(this + 2776) )
                  ReleaseMutex(*(HANDLE *)(this + 2776));
                v53 = *(void **)(this + 2804);
                *(float *)&v71 = NAN;
                if ( v53 && ((v54 = WaitForSingleObject(v53, *(_DWORD *)(this + 2808))) == 0 || v54 == 128) )
                  v55 = this + 2788;
                else
                  v55 = 0;
                v56 = *(int **)v55;
                v11 = *(_DWORD *)v55 == 0;
                *(_DWORD *)(v55 + 8) = *(_DWORD *)v55;
                if ( !v11 )
                {
                  v57 = *v56;
                  if ( *v56 )
                  {
                    while ( 1 )
                    {
                      v58 = *(_DWORD *)(v57 + 28);
                      if ( v58 )
                      {
                        if ( sub_59C230(v58, &from) )
                          break;
                      }
                      v59 = *(_DWORD *)(v55 + 8);
                      if ( v59 )
                      {
                        v60 = *(int **)(v59 + 4);
                        *(_DWORD *)(v55 + 8) = v60;
                        if ( v60 )
                        {
                          v57 = *v60;
                          if ( *v60 )
                            continue;
                        }
                      }
                      goto LABEL_122;
                    }
                    *(float *)&v71 = COERCE_FLOAT(sub_5A6E90(v57));
                  }
                }
LABEL_122:
                if ( *(_DWORD *)(this + 2804) )
                  ReleaseMutex(*(HANDLE *)(this + 2804));
                v61 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 88))(this);
                v62 = v61;
                if ( v61 )
                {
                  v63 = *(_DWORD *)(v61 + 36) >> 3;
                  if ( v80 == v63 + ((*(_DWORD *)(v62 + 36) & 7) != 0) )
                    qmemcpy(*(void **)(v62 + 20), v82, v63 + ((*(_DWORD *)(v62 + 36) & 7) != 0));
                  sub_5A7080((int)v82 + v80, v81);
                  *(float *)(v62 + 4) = *(float *)&v71;
                  sub_5A5D70(v62);
                }
              }
            }
          }
LABEL_128:
          if ( v67 )
          {
            if ( hostlong == -1 )
            {
              switch ( WSAGetLastError() )
              {
                case 10014:
                case 10022:
                case 10038:
                case 10045:
                case 10050:
                case 10052:
                case 10053:
                case 10057:
                case 10058:
                case 10060:
                case 10093:
                  break;
                case 10040:
                  sub_5A7140(this + 2708, 512);
                  v3 = retaddr;
                  continue;
                case 10054:
                  if ( (_BYTE)a3 )
                    goto LABEL_132;
                  break;
                default:
                  goto LABEL_132;
              }
              htonl(0);
              htons(0);
              return off_16C946C(this, s, a3);
            }
            if ( !hostlong )
            {
              htonl(0);
              htons(0);
              v65 = "Closed Gracefully";
              sub_59FC50();
            }
          }
LABEL_132:
          if ( BYTE2(v65) )
            break;
          v3 = (void *)v82[380];
        }
      }
    }
    ++hostlong;
  }
  while ( (int)hostlong < 1 );
  return v66;
}
