char __thiscall sub_57CB50(char *this, SOCKET s, char a3)
{
  SOCKET v3; // ebp
  int v4; // edi
  char v5; // bl
  int v6; // eax
  void *v7; // eax
  DWORD v8; // eax
  char *v9; // edx
  int *v10; // eax
  bool v11; // zf
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int *v15; // eax
  char *v16; // ebx
  int v17; // esi
  signed int v18; // esi
  void *v19; // eax
  DWORD v20; // eax
  char *v21; // edx
  int *v22; // eax
  int i; // eax
  int v24; // ecx
  unsigned __int16 v25; // cx
  int v26; // eax
  int *v27; // eax
  void *v28; // eax
  DWORD v29; // eax
  char *v30; // ecx
  int *v31; // eax
  int v32; // edi
  int v33; // eax
  int v34; // eax
  int *v35; // eax
  int v36; // ebp
  _WORD *v37; // esi
  int v38; // edi
  void *v39; // eax
  DWORD v40; // eax
  char *v41; // ecx
  int *v42; // eax
  int v43; // eax
  __int16 v44; // dx
  int v45; // edi
  int v46; // eax
  int *v47; // eax
  void *v48; // eax
  DWORD v49; // eax
  char *v50; // edi
  _DWORD **v51; // eax
  _DWORD *v52; // esi
  int v53; // eax
  _DWORD **v54; // eax
  int v55; // eax
  int v56; // esi
  char *v57; // esi
  char v59; // [esp+11h] [ebp-76Fh]
  bool v60; // [esp+12h] [ebp-76Eh]
  bool v61; // [esp+13h] [ebp-76Dh]
  char v62; // [esp+14h] [ebp-76Ch]
  char v63; // [esp+15h] [ebp-76Bh]
  char v64; // [esp+16h] [ebp-76Ah]
  char v65; // [esp+17h] [ebp-769h]
  signed int v67; // [esp+1Ch] [ebp-764h]
  float v68; // [esp+1Ch] [ebp-764h]
  int v69; // [esp+1Ch] [ebp-764h]
  signed int hostlong; // [esp+20h] [ebp-760h]
  struct sockaddr from; // [esp+28h] [ebp-758h] BYREF
  int v72; // [esp+38h] [ebp-748h]
  int v73; // [esp+3Ch] [ebp-744h] BYREF
  u_long v74; // [esp+40h] [ebp-740h]
  int v75; // [esp+44h] [ebp-73Ch]
  int v76; // [esp+48h] [ebp-738h]
  int v77; // [esp+4Ch] [ebp-734h] BYREF
  u_long v78; // [esp+50h] [ebp-730h]
  int v79; // [esp+54h] [ebp-72Ch]
  int v80; // [esp+58h] [ebp-728h]
  int fromlen; // [esp+5Ch] [ebp-724h] BYREF
  struct timeval timeout; // [esp+60h] [ebp-720h] BYREF
  int v83[4]; // [esp+68h] [ebp-718h] BYREF
  fd_set readfds; // [esp+78h] [ebp-708h] BYREF
  unsigned __int16 v85; // [esp+17Ch] [ebp-604h] BYREF
  unsigned __int16 v86; // [esp+17Eh] [ebp-602h]

  v3 = s;
  v64 = 0;
  timeout.tv_sec = 0;
  timeout.tv_usec = 0;
  v60 = 0;
  readfds.fd_array[0] = s;
  readfds.fd_count = 1;
  v62 = 0;
  v72 = 0;
  while ( 1 )
  {
    v4 = (int)this;
    if ( v62 )
      return v64;
    v5 = 0;
    v61 = 0;
    v59 = 0;
    hostlong = 0;
    v6 = select(0, &readfds, 0, 0, &timeout);
    if ( v6 == -1 )
    {
      WSAGetLastError();
      sub_57D400(-1);
    }
    else
    {
      v61 = v6 != 0;
    }
    if ( a3 )
    {
      if ( v61 )
        goto LABEL_30;
    }
    else
    {
      if ( v61 )
        goto LABEL_30;
      if ( !v60 )
        v60 = sub_57B9A0((struct sockaddr *)(this + 2692), v3);
      htonl(0);
      htons(0);
      sub_57B9F0((_DWORD *)this + 673, v83);
      v7 = (void *)*((_DWORD *)this + 687);
      if ( v7 && ((v8 = WaitForSingleObject(v7, *((_DWORD *)this + 688))) == 0 || v8 == 128) )
        v9 = this + 2732;
      else
        v9 = 0;
      v10 = *(int **)v9;
      v11 = *(_DWORD *)v9 == 0;
      *((_DWORD *)v9 + 2) = *(_DWORD *)v9;
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
            v14 = *((_DWORD *)v9 + 2);
            if ( v14 )
            {
              v15 = *(int **)(v14 + 4);
              *((_DWORD *)v9 + 2) = v15;
              if ( v15 )
              {
                v12 = *v15;
                if ( v12 )
                  continue;
              }
            }
            goto LABEL_27;
          }
          if ( *(_WORD *)(v12 + 4152) >= 4u )
            v5 = 1;
        }
      }
LABEL_27:
      if ( *((_DWORD *)this + 687) )
        ReleaseMutex(*((HANDLE *)this + 687));
      if ( v5 )
      {
LABEL_30:
        v65 = 0;
        while ( !v62 )
        {
          v67 = 0;
          from.sa_family = 2;
          *(_DWORD *)&from.sa_data[2] = htonl(0);
          *(_WORD *)from.sa_data = htons(0);
          v16 = (char *)sub_563E70((void *)(v4 + 2680));
          v17 = sub_55BFC0((_DWORD *)(v4 + 2680));
          fromlen = 16;
          if ( a3 )
          {
            v18 = recvfrom(v3, v16, v17, 0, &from, &fromlen);
            hostlong = v18;
            *(_WORD *)from.sa_data = ntohs(*(u_short *)from.sa_data);
            if ( sub_57BF00(v4, (int)v16, v18, (int)&from) )
              goto LABEL_126;
            v59 = 1;
            v67 = v18;
            if ( v18 <= 0 )
              goto LABEL_126;
            v60 = sub_57B950(
                    (void *)(v4 + 2692),
                    *(int *)&from.sa_family,
                    *(int *)&from.sa_data[2],
                    *(int *)&from.sa_data[6],
                    *(int *)&from.sa_data[10],
                    v3);
            goto LABEL_87;
          }
          v63 = 1;
          if ( !v61 )
            goto LABEL_59;
          v19 = (void *)*((_DWORD *)this + 687);
          if ( v19 && ((v20 = WaitForSingleObject(v19, *((_DWORD *)this + 688))) == 0 || v20 == 128) )
            v21 = this + 2732;
          else
            v21 = 0;
          v22 = *(int **)v21;
          v11 = *(_DWORD *)v21 == 0;
          *((_DWORD *)v21 + 2) = *(_DWORD *)v21;
          if ( !v11 )
          {
            for ( i = *v22; i; i = *v27 )
            {
              v24 = *(_DWORD *)(i + 32);
              if ( v24 != -1 && v3 != -1 && v24 == v3 )
              {
                v25 = *(_WORD *)(i + 4152);
                if ( v17 >= 4096 - v25 )
                  v17 = 4096 - v25;
              }
              v26 = *((_DWORD *)v21 + 2);
              if ( !v26 )
                break;
              v27 = *(int **)(v26 + 4);
              *((_DWORD *)v21 + 2) = v27;
              if ( !v27 )
                break;
            }
          }
          if ( *((_DWORD *)this + 687) )
            ReleaseMutex(*((HANDLE *)this + 687));
          if ( v17 > 0 )
          {
            v59 = 1;
            hostlong = recv(v3, v16, v17, 0);
            if ( hostlong > 0 )
              v63 = 0;
          }
          else
          {
LABEL_59:
            if ( !v59 )
              goto LABEL_62;
          }
          if ( !v60 )
            v60 = sub_57B9A0((struct sockaddr *)(this + 2692), v3);
LABEL_62:
          v28 = (void *)*((_DWORD *)this + 687);
          if ( v28 && ((v29 = WaitForSingleObject(v28, *((_DWORD *)this + 688))) == 0 || v29 == 128) )
            v30 = this + 2732;
          else
            v30 = 0;
          v31 = *(int **)v30;
          v11 = *(_DWORD *)v30 == 0;
          *((_DWORD *)v30 + 2) = *(_DWORD *)v30;
          if ( !v11 )
          {
            v32 = *v31;
            if ( *v31 )
            {
              while ( 1 )
              {
                v33 = *(_DWORD *)(v32 + 32);
                if ( v33 != -1 && s != -1 && v33 == s )
                  break;
                v34 = *((_DWORD *)v30 + 2);
                if ( v34 )
                {
                  v35 = *(int **)(v34 + 4);
                  *((_DWORD *)v30 + 2) = v35;
                  if ( v35 )
                  {
                    v32 = *v35;
                    if ( *v35 )
                      continue;
                  }
                }
                goto LABEL_84;
              }
              if ( v59 && hostlong > 0 )
              {
                sub_57B550(v32 + 54, (int)v16, hostlong);
                v63 = 1;
              }
              v36 = *(unsigned __int16 *)(v32 + 4152);
              if ( (unsigned __int16)v36 >= 4u )
              {
                v37 = (_WORD *)(v32 + 54);
                if ( sub_57B630(v32 + 54, (int)&v85, 4) )
                {
                  v38 = v86 + v85 + 4;
                  if ( v36 >= v38 )
                  {
                    if ( sub_57B5C0(v37, (int)v16, v86 + v85 + 4) )
                      v67 = v38;
                  }
                }
              }
            }
          }
LABEL_84:
          if ( *((_DWORD *)this + 687) )
            ReleaseMutex(*((HANDLE *)this + 687));
          if ( !v63 )
          {
LABEL_126:
            v65 = 1;
            goto LABEL_127;
          }
LABEL_87:
          if ( v67 <= 0 )
            goto LABEL_126;
          if ( (unsigned int)v67 <= 0x604 )
          {
            qmemcpy(&v85, v16, v67);
            if ( v67 == v86 + v85 + 4 )
            {
              v64 = 1;
              v68 = sub_584F90(this);
              sub_57B9F0((_DWORD *)this + 673, &from);
              v39 = (void *)*((_DWORD *)this + 687);
              if ( v39 && ((v40 = WaitForSingleObject(v39, *((_DWORD *)this + 688))) == 0 || v40 == 128) )
                v41 = this + 2732;
              else
                v41 = 0;
              v42 = *(int **)v41;
              v11 = *(_DWORD *)v41 == 0;
              *((_DWORD *)v41 + 2) = *(_DWORD *)v41;
              if ( !v11 )
              {
                v43 = *v42;
                if ( v43 )
                {
                  v44 = *(_WORD *)from.sa_data;
                  v45 = *(_DWORD *)&from.sa_data[2];
                  while ( (*(_DWORD *)(v43 + 4) != v45 || *(_WORD *)(v43 + 2) != v44)
                       && (*(_DWORD *)(v43 + 20) != v45 || *(_WORD *)(v43 + 18) != v44) )
                  {
                    v46 = *((_DWORD *)v41 + 2);
                    if ( v46 )
                    {
                      v47 = *(int **)(v46 + 4);
                      *((_DWORD *)v41 + 2) = v47;
                      if ( v47 )
                      {
                        v43 = *v47;
                        if ( v43 )
                          continue;
                      }
                    }
                    goto LABEL_107;
                  }
                  *(float *)(v43 + 44) = v68;
                }
              }
LABEL_107:
              if ( *((_DWORD *)this + 687) )
                ReleaseMutex(*((HANDLE *)this + 687));
              v69 = -1;
              v48 = (void *)*((_DWORD *)this + 694);
              if ( v48 && ((v49 = WaitForSingleObject(v48, *((_DWORD *)this + 695))) == 0 || v49 == 128) )
                v50 = this + 2760;
              else
                v50 = 0;
              v51 = *(_DWORD ***)v50;
              v11 = *(_DWORD *)v50 == 0;
              *((_DWORD *)v50 + 2) = *(_DWORD *)v50;
              if ( !v11 )
              {
                v52 = *v51;
                if ( *v51 )
                {
                  while ( !sub_57B840(v52, &from) )
                  {
                    v53 = *((_DWORD *)v50 + 2);
                    if ( v53 )
                    {
                      v54 = *(_DWORD ***)(v53 + 4);
                      *((_DWORD *)v50 + 2) = v54;
                      if ( v54 )
                      {
                        v52 = *v54;
                        if ( *v54 )
                          continue;
                      }
                    }
                    goto LABEL_122;
                  }
                  v69 = sub_5871F0(v52);
                }
              }
LABEL_122:
              if ( *((_DWORD *)this + 694) )
                ReleaseMutex(*((HANDLE *)this + 694));
              v55 = (*(int (__thiscall **)(char *))(*(_DWORD *)this + 88))(this);
              v56 = v55;
              if ( v55 )
              {
                sub_57D660(&v85, v55);
                *(_DWORD *)(v56 + 4) = v69;
                sub_585400(v56);
              }
            }
          }
LABEL_127:
          if ( v59 )
          {
            if ( hostlong == -1 )
            {
              switch ( WSAGetLastError() )
              {
                case 10014:
                  v57 = aFault;
                  break;
                case 10022:
                  v57 = aInvalid;
                  break;
                case 10038:
                  v57 = aNotSocket;
                  break;
                case 10040:
                  sub_5875C0(512);
                  v4 = (int)this;
                  v3 = s;
                  goto LABEL_30;
                case 10045:
                  v57 = aNotSupported;
                  break;
                case 10050:
                  v57 = aNetworkDown;
                  break;
                case 10052:
                  v57 = aNetworkReset;
                  break;
                case 10053:
                  v57 = aAborted;
                  break;
                case 10054:
                  if ( a3 )
                    goto LABEL_131;
                  v57 = aTcpConnectionR;
                  break;
                case 10057:
                  v57 = aNotConnected;
                  break;
                case 10058:
                  v57 = aShutdown;
                  break;
                case 10060:
                  v57 = aTimedOut;
                  break;
                case 10093:
                  v57 = aNotInitialised;
                  break;
                default:
                  goto LABEL_131;
              }
              LOWORD(v77) = 2;
              v78 = htonl(0);
              HIWORD(v77) = htons(0);
              sub_57B9F0((_DWORD *)this + 673, &v77);
              sub_57DFF0(v77, v78, v79, v80, v57);
              v62 = 1;
              break;
            }
            if ( !hostlong )
            {
              LOWORD(v73) = 2;
              v74 = htonl(0);
              HIWORD(v73) = htons(0);
              sub_57B9F0((_DWORD *)this + 673, &v73);
              sub_57DFF0(v73, v74, v75, v76, aClosedGraceful);
              v62 = 1;
            }
          }
LABEL_131:
          if ( v65 )
            break;
          v4 = (int)this;
          v3 = s;
        }
      }
    }
    if ( ++v72 >= 1 )
      return v64;
    v3 = s;
  }
}
