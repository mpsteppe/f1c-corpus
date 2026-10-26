char __thiscall sub_56BAF0(int this, char *Str1, int a3, int a4)
{
  signed int v5; // ecx
  size_t v6; // esi
  const char *v7; // edx
  const char *v8; // edi
  u_short v9; // ax
  SOCKET v10; // ecx
  int v11; // esi
  int v12; // esi
  int v13; // edx
  int v14; // esi
  int v15; // edi
  int v16; // ebx
  unsigned __int16 v17; // ax
  char v18; // dl
  unsigned __int8 v19; // cl
  unsigned __int8 v20; // dl
  int v21; // eax
  int v22; // ebx
  int v23; // edi
  int v24; // esi
  SOCKET v26; // eax
  int v27; // esi
  int v28; // edi
  int v29; // ebx
  void *v30; // eax
  DWORD v31; // eax
  _DWORD *v32; // esi
  int v33; // edi
  int v34; // eax
  _DWORD *v35; // ebx
  int v36; // eax
  char *v37; // ecx
  char *v38; // edi
  void *v39; // eax
  DWORD v40; // eax
  int v41; // ecx
  int v42; // esi
  int v43; // esi
  const char *v44; // eax
  void *v45; // eax
  int v46; // ebp
  DWORD v47; // eax
  int v48; // ecx
  char *v49; // eax
  int v50; // edx
  char v51; // cl
  _DWORD *v52; // [esp-8h] [ebp-1B0h]
  SOCKET s; // [esp+10h] [ebp-198h] BYREF
  int v54; // [esp+14h] [ebp-194h]
  int namelen; // [esp+18h] [ebp-190h] BYREF
  int v56; // [esp+1Ch] [ebp-18Ch] BYREF
  struct sockaddr v57; // [esp+20h] [ebp-188h] BYREF
  int v58; // [esp+30h] [ebp-178h] BYREF
  int v59; // [esp+34h] [ebp-174h] BYREF
  int v60; // [esp+38h] [ebp-170h] BYREF
  struct sockaddr name; // [esp+3Ch] [ebp-16Ch] BYREF
  struct sockaddr hostshort; // [esp+4Ch] [ebp-15Ch] BYREF
  int v63; // [esp+5Ch] [ebp-14Ch] BYREF
  int v64; // [esp+60h] [ebp-148h] BYREF
  char v65[4]; // [esp+64h] [ebp-144h] BYREF
  char v66; // [esp+74h] [ebp-134h]
  void *v67; // [esp+78h] [ebp-130h]
  char Destination[80]; // [esp+7Ch] [ebp-12Ch] BYREF
  char v69[80]; // [esp+CCh] [ebp-DCh] BYREF
  char Buffer[128]; // [esp+11Ch] [ebp-8Ch] BYREF
  int v71; // [esp+1A4h] [ebp-4h]

  if ( (byte_7E0600 & 1) != 0 )
  {
    v5 = dword_7E0604;
  }
  else
  {
    byte_7E0600 |= 1u;
    v5 = strlen(off_61A1EC);
    dword_7E0604 = v5;
  }
  if ( a3 <= v5 || strncmp(Str1, off_61A1EC, v5) )
    return 0;
  v6 = a3 - dword_7E0604;
  if ( a3 - dword_7E0604 >= 79 )
    v6 = 79;
  Destination[0] = 0;
  v71 = 0;
  strncpy(Destination, &Str1[dword_7E0604], v6);
  v7 = off_61A1F4;
  v8 = off_61A1F4;
  Destination[v6] = 0;
  if ( !strncmp(Destination, v7, strlen(v8)) )
  {
    if ( sub_575D90(this) == 4 )
    {
      name.sa_family = 2;
      *(_DWORD *)&name.sa_data[2] = htonl(0);
      v9 = htons(0);
      v10 = *(_DWORD *)(this + 2360);
      *(_WORD *)name.sa_data = v9;
      namelen = 16;
      v11 = getsockname(v10, &name, &namelen);
      *(_WORD *)name.sa_data = ntohs(*(u_short *)name.sa_data);
      if ( !v11 )
      {
        if ( !strcmp(&Destination[strlen(off_61A1F4)], (const char *)(this + 2328)) )
        {
          if ( (unsigned __int8)sub_575290(0, 0) )
          {
            Buffer[0] = 0;
            v17 = *(_WORD *)(a4 + 2);
            v18 = *(_BYTE *)(a4 + 6);
            LOBYTE(v56) = *(_BYTE *)(a4 + 7);
            v19 = *(_BYTE *)(a4 + 5);
            LOBYTE(v58) = v18;
            v20 = *(_BYTE *)(a4 + 4);
            LOBYTE(v59) = v19;
            LOBYTE(v60) = v20;
            v21 = sprintf(
                    Buffer,
                    "%s%s %d %d.%d.%d.%d:%d",
                    off_61A1EC,
                    off_61A1F8,
                    *(unsigned __int16 *)name.sa_data,
                    v20,
                    v19,
                    (unsigned __int8)v58,
                    (unsigned __int8)v56,
                    v17);
            v22 = *(_DWORD *)(a4 + 4);
            *(_DWORD *)&v57.sa_family = *(_DWORD *)a4;
            *(_DWORD *)&v57.sa_data[2] = v22;
            v23 = v21;
            v24 = *(_DWORD *)(a4 + 12);
            *(_DWORD *)&v57.sa_data[6] = *(_DWORD *)(a4 + 8);
            *(_WORD *)v57.sa_data = htons(*(u_short *)v57.sa_data);
            *(_DWORD *)&hostshort.sa_family = *(_DWORD *)&v57.sa_family;
            *(_DWORD *)&hostshort.sa_data[2] = v22;
            *(_DWORD *)&hostshort.sa_data[6] = *(_DWORD *)&v57.sa_data[6];
            *(_DWORD *)&hostshort.sa_data[10] = v24;
            sendto(*(_DWORD *)(this + 2364), Buffer, v23, 0, &hostshort, 16);
            return 1;
          }
          v12 = 4 - (*(_BYTE *)(this + 93) != 0);
        }
        else
        {
          v12 = 2;
        }
        Buffer[0] = 0;
        s = sprintf(Buffer, "%s%s%d", off_61A1EC, off_61A1FC, v12);
        if ( v12 == 2 )
        {
          v13 = sprintf(v69, " (%s)", (const char *)(this + 2328));
          strcat(Buffer, v69);
          s += v13;
        }
        *(_DWORD *)&hostshort.sa_family = *(_DWORD *)a4;
        *(_DWORD *)&hostshort.sa_data[2] = *(_DWORD *)(a4 + 4);
        v14 = *(_DWORD *)&hostshort.sa_data[2];
        v15 = *(_DWORD *)(a4 + 8);
        v16 = *(_DWORD *)(a4 + 12);
        *(_WORD *)hostshort.sa_data = htons(*(u_short *)hostshort.sa_data);
        *(_DWORD *)&v57.sa_family = *(_DWORD *)&hostshort.sa_family;
        *(_DWORD *)&v57.sa_data[2] = v14;
        *(_DWORD *)&v57.sa_data[6] = v15;
        *(_DWORD *)&v57.sa_data[10] = v16;
        sendto(*(_DWORD *)(this + 2364), Buffer, s, 0, &v57, 16);
        return 1;
      }
    }
    return 1;
  }
  if ( strncmp(Destination, off_61A1F8, strlen(off_61A1F8)) )
  {
    if ( !strncmp(Destination, off_61A1FC, strlen(off_61A1FC)) && sub_575D90(this) == 1 )
    {
      sub_575D40(0);
      namelen = 0;
      v69[0] = 0;
      sscanf(&Destination[strlen(off_61A1FC)], aD_5, &namelen, v69);
      v45 = *(void **)(this + 1560);
      v46 = this + 1476;
      if ( v45 && ((v47 = WaitForSingleObject(v45, *(_DWORD *)(v46 + 88))) == 0 || v47 == 128) )
        v48 = v46;
      else
        v48 = 0;
      switch ( namelen )
      {
        case 2:
          *(_DWORD *)v48 = 2;
          v49 = v69;
          v50 = v48 + 4 - (_DWORD)v69;
          do
          {
            v51 = *v49;
            v49[v50] = *v49;
            ++v49;
          }
          while ( v51 );
          goto LABEL_68;
        case 3:
          *(_DWORD *)v48 = 3;
          goto LABEL_67;
        case 4:
          *(_DWORD *)v48 = 4;
          goto LABEL_67;
        case 5:
          *(_DWORD *)v48 = 5;
          goto LABEL_67;
        default:
          *(_DWORD *)v48 = 1;
LABEL_67:
          *(_BYTE *)(v48 + 4) = 0;
LABEL_68:
          if ( *(_DWORD *)(v46 + 84) )
            ReleaseMutex(*(HANDLE *)(v46 + 84));
          break;
      }
    }
    return 1;
  }
  if ( sub_575D90(this) != 1 )
    return 1;
  htonl(0);
  htons(0);
  name.sa_family = 2;
  *(_DWORD *)&name.sa_data[2] = htonl(0);
  *(_WORD *)name.sa_data = htons(0);
  *(_DWORD *)&v57.sa_family = *(_DWORD *)a4;
  *(_DWORD *)&v57.sa_data[2] = *(_DWORD *)(a4 + 4);
  *(_DWORD *)&v57.sa_data[6] = *(_DWORD *)(a4 + 8);
  *(_DWORD *)&v57.sa_data[10] = *(_DWORD *)(a4 + 12);
  namelen = 0;
  v63 = 0;
  v60 = 0;
  v59 = 0;
  v58 = 0;
  v56 = 0;
  sscanf(&Destination[strlen(off_61A1F8)], " %d %d.%d.%d.%d:%d", &namelen, &v63, &v60, &v59, &v58, &v56);
  name.sa_data[2] = v63;
  name.sa_data[3] = v60;
  name.sa_data[4] = v59;
  name.sa_data[5] = v58;
  *(_WORD *)name.sa_data = v56;
  *(_WORD *)v57.sa_data = namelen;
  s = -1;
  v54 = 0;
  while ( 1 )
  {
    do
    {
      v26 = sub_56BAD0((void *)this);
      s = v26;
    }
    while ( v26 == -1 );
    sub_56C3A0(v26, *(unsigned __int16 *)(this + 2320) + v54 + 50);
    v27 = *(_DWORD *)&v57.sa_data[2];
    v28 = *(_DWORD *)&v57.sa_data[6];
    v29 = *(_DWORD *)&v57.sa_data[10];
    *(_DWORD *)v65 = *(_DWORD *)&v57.sa_family;
    *(_WORD *)&v65[2] = htons(*(u_short *)v57.sa_data);
    *(_DWORD *)&hostshort.sa_family = *(_DWORD *)v65;
    *(_DWORD *)&hostshort.sa_data[2] = v27;
    *(_DWORD *)&hostshort.sa_data[6] = v28;
    *(_DWORD *)&hostshort.sa_data[10] = v29;
    if ( !connect(s, &hostshort, 16) )
      break;
    if ( WSAGetLastError() != 10048 || (++v54, v54 > 50) )
    {
      sub_56C4D0(&s, 1);
      return 1;
    }
    sub_56C4D0(&s, 1);
    Sleep(0xAu);
  }
  sub_575D40(2);
  v30 = *(void **)(this + 3052);
  if ( v30 && ((v31 = WaitForSingleObject(v30, *(_DWORD *)(this + 3056))) == 0 || v31 == 128) )
    v54 = this + 3020;
  else
    v54 = 0;
  v32 = 0;
  v33 = v54 + 16;
  sub_414470((int *)(v54 + 16));
  v34 = *(_DWORD *)(v33 + 8);
  if ( v34 )
  {
    v32 = *(_DWORD **)v34;
    v52 = *(_DWORD **)v34;
    *(_BYTE *)(v34 + 8) = 0;
    if ( !(unsigned __int8)sub_571810(v52, 1) )
      v32 = 0;
  }
  v35 = v32;
  if ( !v32 )
  {
    v67 = operator new(4u);
    LOBYTE(v71) = 1;
    if ( v67 )
      v36 = sub_5730B0(0);
    else
      v36 = 0;
    LOBYTE(v71) = 0;
    sub_573530(v36, 0);
    v35 = (_DWORD *)sub_572EA0(v33);
  }
  if ( *(_DWORD *)(this + 3052) )
    ReleaseMutex(*(HANDLE *)(this + 3052));
  sub_56B2A0(v35, s);
  v64 = 16;
  v38 = sub_56B280(v37);
  getpeername(s, (struct sockaddr *)v38, &v64);
  sub_56B260(v35, (_DWORD *)a4);
  v39 = *(void **)(this + 1600);
  if ( v39 && ((v40 = WaitForSingleObject(v39, *(_DWORD *)(this + 1604))) == 0 || v40 == 128) )
    v41 = this + 1572;
  else
    v41 = 0;
  sub_577170(v41);
  if ( *(_DWORD *)(this + 1600) )
    ReleaseMutex(*(HANDLE *)(this + 1600));
  v42 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 88))(this);
  sub_576880(0, 6, 1, 2, -1);
  sub_576A80(&name, 16);
  sub_56ACD0(*(_DWORD *)(v42 + 72), v38);
  sub_574CE0(v42);
  v43 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 88))(this);
  sub_576880(0, 3, 1, 2, -1);
  v44 = (const char *)sub_575090(this);
  if ( v44 )
  {
    strncpy(v65, v44, 0x10u);
    v66 = 0;
  }
  else
  {
    v65[0] = 0;
  }
  sub_576A80(v65, 17);
  sub_56ACD0(*(_DWORD *)(v43 + 72), v38);
  sub_574CE0(v43);
  sub_56DC20(v35);
  return 1;
}
