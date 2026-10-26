char __thiscall sub_56C740(char *this, SOCKET s, char a3)
{
  SOCKET v3; // edi
  int v4; // ebp
  char v5; // bl
  int v6; // eax
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
  int v17; // edi
  int v18; // edi
  void *v19; // eax
  DWORD v20; // eax
  char *v21; // edx
  int *v22; // eax
  int v23; // eax
  SOCKET v24; // ebx
  int v25; // ecx
  unsigned __int16 v26; // cx
  int v27; // eax
  int *v28; // eax
  int v29; // esi
  void *v30; // eax
  DWORD v31; // eax
  char *v32; // edx
  int *v33; // eax
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  int *v37; // eax
  int v38; // edx
  int v39; // ecx
  int v40; // ebp
  char *v41; // edi
  int v42; // edx
  char v43; // bl
  int v44; // ebp
  int v45; // ecx
  int i; // edi
  int v47; // edi
  int j; // ecx
  void *v49; // eax
  DWORD v50; // eax
  char *v51; // ecx
  int *v52; // eax
  int v53; // eax
  __int16 v54; // dx
  int v55; // edi
  int v56; // eax
  int *v57; // eax
  void *v58; // eax
  DWORD v59; // eax
  char *v60; // edi
  _DWORD **v61; // eax
  _DWORD *v62; // esi
  int v63; // eax
  _DWORD **v64; // eax
  int v65; // eax
  int v66; // esi
  char *v67; // esi
  bool v69; // [esp+11h] [ebp-773h]
  char v70; // [esp+12h] [ebp-772h]
  char v71; // [esp+13h] [ebp-771h]
  bool v72; // [esp+14h] [ebp-770h]
  char v73; // [esp+15h] [ebp-76Fh]
  char v74; // [esp+16h] [ebp-76Eh]
  char v75; // [esp+17h] [ebp-76Dh]
  signed int v77; // [esp+1Ch] [ebp-768h]
  int v78; // [esp+1Ch] [ebp-768h]
  u_long hostlong; // [esp+20h] [ebp-764h]
  char *buf; // [esp+24h] [ebp-760h]
  float v81; // [esp+28h] [ebp-75Ch]
  struct sockaddr from; // [esp+2Ch] [ebp-758h] BYREF
  int v83; // [esp+3Ch] [ebp-748h]
  int fromlen; // [esp+40h] [ebp-744h] BYREF
  int v85; // [esp+44h] [ebp-740h] BYREF
  u_long v86; // [esp+48h] [ebp-73Ch]
  int v87; // [esp+4Ch] [ebp-738h]
  int v88; // [esp+50h] [ebp-734h]
  int v89; // [esp+54h] [ebp-730h] BYREF
  u_long v90; // [esp+58h] [ebp-72Ch]
  int v91; // [esp+5Ch] [ebp-728h]
  int v92; // [esp+60h] [ebp-724h]
  struct timeval timeout; // [esp+64h] [ebp-720h] BYREF
  int v94[4]; // [esp+6Ch] [ebp-718h] BYREF
  fd_set readfds; // [esp+7Ch] [ebp-708h] BYREF
  unsigned __int16 v96; // [esp+180h] [ebp-604h] BYREF
  unsigned __int16 v97; // [esp+182h] [ebp-602h]

  v3 = s;
  v4 = (int)this;
  v74 = 0;
  timeout.tv_sec = 0;
  timeout.tv_usec = 0;
  v69 = 0;
  readfds.fd_array[0] = s;
  readfds.fd_count = 1;
  v71 = 0;
  v83 = 0;
  while ( !v71 )
  {
    v5 = 0;
    v72 = 0;
    v70 = 0;
    hostlong = 0;
    v6 = select(0, &readfds, 0, 0, &timeout);
    if ( v6 == -1 )
    {
      WSAGetLastError();
      sub_56D0B0(-1);
    }
    else
    {
      v72 = v6 != 0;
    }
    if ( a3 )
    {
      if ( v72 )
        goto LABEL_30;
    }
    else
    {
      if ( v72 )
        goto LABEL_30;
      if ( !v69 )
        v69 = sub_56B590((struct sockaddr *)(v4 + 2692), v3);
      htonl(0);
      htons(0);
      sub_56B5E0((_DWORD *)(v4 + 2692), v94);
      v7 = *(void **)(v4 + 2748);
      if ( v7 && ((v8 = WaitForSingleObject(v7, *(_DWORD *)(v4 + 2752))) == 0 || v8 == 128) )
        v9 = v4 + 2732;
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
            if ( v13 != -1 && v3 != -1 && v13 == v3 )
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
            goto LABEL_27;
          }
          if ( *(_WORD *)(v12 + 2104) >= 4u )
            v5 = 1;
        }
      }
LABEL_27:
      if ( *(_DWORD *)(v4 + 2748) )
        ReleaseMutex(*(HANDLE *)(v4 + 2748));
      if ( v5 )
      {
LABEL_30:
        v73 = 0;
        while ( 1 )
        {
          if ( v71 )
            goto LABEL_149;
          v77 = 0;
          from.sa_family = 2;
          *(_DWORD *)&from.sa_data[2] = htonl(0);
          *(_WORD *)from.sa_data = htons(0);
          v16 = (char *)sub_577650(v4 + 2680);
          buf = v16;
          v17 = sub_5A97F0(v4 + 2680);
          fromlen = 16;
          if ( a3 )
          {
            v18 = recvfrom(s, v16, v17, 0, &from, &fromlen);
            hostlong = v18;
            *(_WORD *)from.sa_data = ntohs(*(u_short *)from.sa_data);
            if ( sub_56BAF0(v4, v16, v18, (int)&from) )
              goto LABEL_138;
            v70 = 1;
            v77 = v18;
            if ( v18 <= 0 )
              goto LABEL_138;
            v69 = sub_56B540(
                    (void *)(v4 + 2692),
                    *(int *)&from.sa_family,
                    *(int *)&from.sa_data[2],
                    *(int *)&from.sa_data[6],
                    *(int *)&from.sa_data[10],
                    s);
            goto LABEL_99;
          }
          v75 = 1;
          if ( !v72 )
            break;
          v19 = (void *)*((_DWORD *)this + 687);
          if ( v19 && ((v20 = WaitForSingleObject(v19, *((_DWORD *)this + 688))) == 0 || v20 == 128) )
            v21 = this + 2732;
          else
            v21 = 0;
          v22 = *(int **)v21;
          v11 = *(_DWORD *)v21 == 0;
          *((_DWORD *)v21 + 2) = *(_DWORD *)v21;
          if ( v11 || (v23 = *v22) == 0 )
          {
            v24 = s;
          }
          else
          {
            v24 = s;
            do
            {
              v25 = *(_DWORD *)(v23 + 32);
              if ( v25 != -1 && s != -1 && v25 == s )
              {
                v26 = *(_WORD *)(v23 + 2104);
                if ( v17 >= 2048 - v26 )
                  v17 = 2048 - v26;
              }
              v27 = *((_DWORD *)v21 + 2);
              if ( !v27 )
                break;
              v28 = *(int **)(v27 + 4);
              *((_DWORD *)v21 + 2) = v28;
              if ( !v28 )
                break;
              v23 = *v28;
            }
            while ( v23 );
          }
          if ( *((_DWORD *)this + 687) )
            ReleaseMutex(*((HANDLE *)this + 687));
          if ( v17 <= 0 )
            goto LABEL_63;
          v70 = 1;
          v29 = recv(v24, buf, v17, 0);
          hostlong = v29;
          if ( v29 > 0 )
            v75 = 0;
LABEL_64:
          if ( !v69 )
            v69 = sub_56B590((struct sockaddr *)(this + 2692), v24);
LABEL_66:
          v30 = (void *)*((_DWORD *)this + 687);
          if ( v30 && ((v31 = WaitForSingleObject(v30, *((_DWORD *)this + 688))) == 0 || v31 == 128) )
            v32 = this + 2732;
          else
            v32 = 0;
          v33 = *(int **)v32;
          v11 = *(_DWORD *)v32 == 0;
          *((_DWORD *)v32 + 2) = *(_DWORD *)v32;
          if ( !v11 )
          {
            v34 = *v33;
            if ( v34 )
            {
              while ( 1 )
              {
                v35 = *(_DWORD *)(v34 + 32);
                if ( v35 != -1 && v24 != -1 && v35 == v24 )
                  break;
                v36 = *((_DWORD *)v32 + 2);
                if ( v36 )
                {
                  v37 = *(int **)(v36 + 4);
                  *((_DWORD *)v32 + 2) = v37;
                  if ( v37 )
                  {
                    v34 = *v37;
                    if ( v34 )
                      continue;
                  }
                }
                goto LABEL_96;
              }
              if ( v70 && v29 > 0 )
              {
                v38 = *(unsigned __int16 *)(v34 + 2104);
                if ( (unsigned __int16)v38 + v29 <= 2048 )
                {
                  v39 = v38 + *(__int16 *)(v34 + 2102);
                  v40 = v29;
                  v41 = &buf[-v39];
                  do
                  {
                    v42 = v39 % 2048;
                    v43 = v41[v39++];
                    --v40;
                    *(_BYTE *)(v42 + v34 + 54) = v43;
                  }
                  while ( v40 );
                  *(_WORD *)(v34 + 2104) += v29;
                }
                v75 = 1;
              }
              v44 = *(unsigned __int16 *)(v34 + 2104);
              if ( (unsigned __int16)v44 >= 4u && (unsigned __int16)v44 >= 4u )
              {
                v45 = *(__int16 *)(v34 + 2102);
                for ( i = 0; i < 4; ++i )
                {
                  *((_BYTE *)&v96 + i) = *(_BYTE *)(v45 + v34 + 54);
                  v45 = (v45 + 1) % 2048;
                }
                v47 = v97 + v96 + 4;
                if ( v44 >= v47 && v47 <= *(unsigned __int16 *)(v34 + 2104) )
                {
                  for ( j = 0; j < v47; *(_WORD *)(v34 + 2102) = (__int16)(*(_WORD *)(v34 + 2102) + 1) % 2048 )
                    buf[j++] = *(_BYTE *)(*(__int16 *)(v34 + 2102) + v34 + 54);
                  *(_WORD *)(v34 + 2104) -= v47;
                  v77 = v47;
                }
              }
            }
          }
LABEL_96:
          if ( *((_DWORD *)this + 687) )
            ReleaseMutex(*((HANDLE *)this + 687));
          if ( !v75 )
          {
LABEL_138:
            v73 = 1;
            goto LABEL_139;
          }
LABEL_99:
          if ( v77 <= 0 )
            goto LABEL_138;
          if ( (unsigned int)v77 <= 0x604 )
          {
            qmemcpy(&v96, buf, v77);
            if ( v77 == v97 + v96 + 4 )
            {
              v74 = 1;
              v81 = sub_575000(this);
              sub_56B5E0((_DWORD *)this + 673, &from);
              v49 = (void *)*((_DWORD *)this + 687);
              if ( v49 && ((v50 = WaitForSingleObject(v49, *((_DWORD *)this + 688))) == 0 || v50 == 128) )
                v51 = this + 2732;
              else
                v51 = 0;
              v52 = *(int **)v51;
              v11 = *(_DWORD *)v51 == 0;
              *((_DWORD *)v51 + 2) = *(_DWORD *)v51;
              if ( !v11 )
              {
                v53 = *v52;
                if ( v53 )
                {
                  v54 = *(_WORD *)from.sa_data;
                  v55 = *(_DWORD *)&from.sa_data[2];
                  while ( (*(_DWORD *)(v53 + 4) != v55 || *(_WORD *)(v53 + 2) != v54)
                       && (*(_DWORD *)(v53 + 20) != v55 || *(_WORD *)(v53 + 18) != v54) )
                  {
                    v56 = *((_DWORD *)v51 + 2);
                    if ( v56 )
                    {
                      v57 = *(int **)(v56 + 4);
                      *((_DWORD *)v51 + 2) = v57;
                      if ( v57 )
                      {
                        v53 = *v57;
                        if ( v53 )
                          continue;
                      }
                    }
                    goto LABEL_119;
                  }
                  *(float *)(v53 + 44) = v81;
                }
              }
LABEL_119:
              if ( *((_DWORD *)this + 687) )
                ReleaseMutex(*((HANDLE *)this + 687));
              v78 = -1;
              v58 = (void *)*((_DWORD *)this + 694);
              if ( v58 && ((v59 = WaitForSingleObject(v58, *((_DWORD *)this + 695))) == 0 || v59 == 128) )
                v60 = this + 2760;
              else
                v60 = 0;
              v61 = *(_DWORD ***)v60;
              v11 = *(_DWORD *)v60 == 0;
              *((_DWORD *)v60 + 2) = *(_DWORD *)v60;
              if ( !v11 )
              {
                v62 = *v61;
                if ( *v61 )
                {
                  while ( !sub_56B430(v62, &from) )
                  {
                    v63 = *((_DWORD *)v60 + 2);
                    if ( v63 )
                    {
                      v64 = *(_DWORD ***)(v63 + 4);
                      *((_DWORD *)v60 + 2) = v64;
                      if ( v64 )
                      {
                        v62 = *v64;
                        if ( *v64 )
                          continue;
                      }
                    }
                    goto LABEL_134;
                  }
                  v78 = sub_577280(v62);
                }
              }
LABEL_134:
              if ( *((_DWORD *)this + 694) )
                ReleaseMutex(*((HANDLE *)this + 694));
              v65 = (*(int (__thiscall **)(char *))(*(_DWORD *)this + 88))(this);
              v66 = v65;
              if ( v65 )
              {
                sub_56D310(&v96, v65);
                *(_DWORD *)(v66 + 4) = v78;
                sub_575470(v66);
              }
            }
          }
LABEL_139:
          if ( v70 )
          {
            if ( hostlong == -1 )
            {
              switch ( WSAGetLastError() )
              {
                case 10014:
                  v67 = aFault;
                  break;
                case 10022:
                  v67 = aInvalid;
                  break;
                case 10038:
                  v67 = aNotSocket;
                  break;
                case 10040:
                  sub_577660(512);
                  v4 = (int)this;
                  goto LABEL_30;
                case 10045:
                  v67 = aNotSupported;
                  break;
                case 10050:
                  v67 = aNetworkDown;
                  break;
                case 10052:
                  v67 = aNetworkReset;
                  break;
                case 10053:
                  v67 = aAborted;
                  break;
                case 10054:
                  if ( a3 )
                    goto LABEL_143;
                  v67 = aTcpConnectionR;
                  break;
                case 10057:
                  v67 = aNotConnected;
                  break;
                case 10058:
                  v67 = aShutdown;
                  break;
                case 10060:
                  v67 = aTimedOut;
                  break;
                case 10093:
                  v67 = aNotInitialised;
                  break;
                default:
                  goto LABEL_143;
              }
              LOWORD(v85) = 2;
              v86 = htonl(0);
              HIWORD(v85) = htons(0);
              sub_56B5E0((_DWORD *)this + 673, &v85);
              sub_56E010(v85, v86, v87, v88, v67);
              v71 = 1;
              goto LABEL_149;
            }
            if ( !hostlong )
            {
              LOWORD(v89) = 2;
              v90 = htonl(0);
              HIWORD(v89) = htons(0);
              sub_56B5E0((_DWORD *)this + 673, &v89);
              sub_56E010(v89, v90, v91, v92, aClosedGraceful);
              v71 = 1;
            }
          }
LABEL_143:
          if ( v73 )
            goto LABEL_149;
          v4 = (int)this;
        }
        v24 = s;
LABEL_63:
        v29 = hostlong;
        if ( !v70 )
          goto LABEL_66;
        goto LABEL_64;
      }
    }
LABEL_149:
    if ( ++v83 >= 1 )
      return v74;
    v4 = (int)this;
    v3 = s;
  }
  return v74;
}
