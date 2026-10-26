char __userpurge sub_5A1300@<al>(unsigned __int16 *a1@<ecx>, int a2@<ebx>, char *Str1, int a4, int a5)
{
  signed int v6; // eax
  int v7; // esi
  const char *v8; // edx
  const char *v9; // eax
  SOCKET v10; // ecx
  int v11; // esi
  int v12; // esi
  int v13; // ebx
  int v14; // eax
  unsigned int v15; // edx
  char *v16; // edi
  const struct sockaddr *v18; // eax
  int v20; // edi
  const struct sockaddr *v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // ecx
  int v25; // edi
  SOCKET v26; // eax
  SOCKET v27; // esi
  const struct sockaddr *v28; // eax
  int v29; // edi
  int v30; // eax
  int v31; // esi
  int v32; // esi
  int v33; // eax
  char *v34; // ecx
  int v35; // edx
  char v36; // al
  int v37; // [esp-14h] [ebp-198h]
  int v38; // [esp-Ch] [ebp-190h]
  int v39; // [esp-8h] [ebp-18Ch]
  SOCKET v40; // [esp-8h] [ebp-18Ch]
  int v41; // [esp-4h] [ebp-188h]
  int v42; // [esp-4h] [ebp-188h]
  int v43[2]; // [esp+0h] [ebp-184h] BYREF
  int v44; // [esp+8h] [ebp-17Ch] BYREF
  int v45; // [esp+Ch] [ebp-178h] BYREF
  int namelen; // [esp+10h] [ebp-174h] BYREF
  unsigned __int8 v47; // [esp+17h] [ebp-16Dh]
  int v48; // [esp+18h] [ebp-16Ch] BYREF
  int v49; // [esp+1Ch] [ebp-168h] BYREF
  int v50; // [esp+20h] [ebp-164h] BYREF
  int v51; // [esp+24h] [ebp-160h] BYREF
  int v52; // [esp+28h] [ebp-15Ch] BYREF
  sockaddr name; // [esp+2Ch] [ebp-158h] BYREF
  int v54; // [esp+3Ch] [ebp-148h] BYREF
  int tolen[2]; // [esp+40h] [ebp-144h] BYREF
  int v56[6]; // [esp+48h] [ebp-13Ch] BYREF
  char v57[4]; // [esp+60h] [ebp-124h] BYREF
  char v58[76]; // [esp+64h] [ebp-120h] BYREF
  char v59; // [esp+B0h] [ebp-D4h] BYREF
  char v60[76]; // [esp+B4h] [ebp-D0h] BYREF
  char buf[3]; // [esp+100h] [ebp-84h] BYREF
  char v62; // [esp+103h] [ebp-81h] BYREF
  char Buffer[124]; // [esp+104h] [ebp-80h] BYREF
  _DWORD *v64; // [esp+180h] [ebp-4h]

  if ( (dword_FB22D8 & 1) != 0 )
  {
    v6 = dword_FB22D4;
  }
  else
  {
    dword_FB22D8 |= 1u;
    v6 = strlen(off_903EDC);
    dword_FB22D4 = v6;
  }
  if ( a4 <= v6 || strncmp(Str1, off_903EDC, v6) )
    return 0;
  v7 = a4 - dword_FB22D4;
  if ( a4 - dword_FB22D4 >= 79 )
    v7 = 79;
  v58[0] = 0;
  sub_630FE0(v58);
  v8 = off_903EE4;
  v9 = off_903EE4;
  v58[v7] = 0;
  v43[0] = a2;
  if ( strncmp(v58, v8, strlen(v9)) )
  {
    if ( !strncmp(v58, off_903EE8, strlen(off_903EE8)) )
    {
      if ( sub_5A4330(a1) == 1 )
      {
        sub_59CFD0();
        sub_59CFD0();
        v22 = *(_DWORD *)(a5 + 4);
        tolen[0] = *(_DWORD *)a5;
        v23 = *(_DWORD *)(a5 + 8);
        tolen[1] = v22;
        v24 = *(_DWORD *)(a5 + 12);
        v56[0] = v23;
        v56[1] = v24;
        v48 = 0;
        v50 = 0;
        v52 = 0;
        v54 = 0;
        v51 = 0;
        v49 = 0;
        sscanf(&v58[strlen(off_903EE8)], " %d %d.%d.%d.%d:%d", &v48, &v50, &v52, &v54, &v51, &v49);
        name.sa_data[2] = v50;
        name.sa_data[3] = v52;
        name.sa_data[4] = v54;
        name.sa_data[5] = v51;
        *(_WORD *)name.sa_data = v49;
        HIWORD(tolen[0]) = v48;
        v25 = 0;
        while ( 1 )
        {
          do
          {
            (*(void (__thiscall **)(unsigned __int16 *))(*(_DWORD *)a1 + 116))(a1);
            v26 = socket(2, 1, 0);
            v27 = v26;
            namelen = v26;
          }
          while ( v26 == -1 );
          v42 = a1[1174] + v25 + 50;
          v40 = v26;
          sub_59D7B0();
          v28 = (const struct sockaddr *)sub_59C1E0();
          if ( !connect(v27, v28, (int)v56) )
          {
            sub_5A42E0(a1, 2, 16, v40, v42);
            sub_59C510();
            v29 = sub_5A05C0();
            sub_59C540();
            *(_DWORD *)(v29 + 32) = v27;
            v43[0] = 16;
            getpeername(v27, (struct sockaddr *)(v29 + 16), v43);
            sub_59BDC0((_DWORD *)v29, v64);
            v30 = sub_59C350();
            sub_5A6D80(v30);
            sub_59C380();
            v31 = (*(int (__thiscall **)(unsigned __int16 *))(*(_DWORD *)a1 + 88))(a1);
            sub_5A6B10(v31, 0, 6, 1, 2, -1);
            sub_5A6970(&v44, 16);
            sub_59D660();
            sub_5A46A0(a1, v31);
            v32 = (*(int (__thiscall **)(unsigned __int16 *))(*(_DWORD *)a1 + 88))(a1);
            sub_5A6B10(v32, 0, 3, 1, 2, -1);
            sub_5A3C30(a1);
            sub_59C1B0();
            sub_5A6970(&v45, 17);
            sub_59D660();
            sub_5A46A0(a1, v32);
            sub_5A0B40((int)a1, v29);
            return 1;
          }
          if ( WSAGetLastError() != 10048 )
            break;
          if ( ++v25 > 50 )
            break;
          sub_59C700();
          Sleep(0xAu);
        }
        sub_59C700();
        return 1;
      }
    }
    else if ( !strncmp(v58, off_903EEC, strlen(off_903EEC)) && sub_5A4330(a1) == 1 )
    {
      sub_5A42E0(a1, 0, v43[0], v43[1], v44);
      v45 = 0;
      v59 = 0;
      sscanf(&v57[strlen(off_903EEC)], "%d %[^", &v45, &v59);
      v33 = sub_59C300();
      switch ( v45 )
      {
        case 2:
          v34 = &v59;
          *(_DWORD *)v33 = 2;
          v35 = v33 + 4 - (_DWORD)&v59;
          do
          {
            v36 = *v34;
            v34[v35] = *v34;
            ++v34;
          }
          while ( v36 );
          sub_59C330();
          return 1;
        case 3:
          *(_DWORD *)v33 = 3;
          goto LABEL_38;
        case 4:
          *(_DWORD *)v33 = 4;
          goto LABEL_38;
        case 5:
          *(_DWORD *)v33 = 5;
          goto LABEL_38;
        default:
          *(_DWORD *)v33 = 1;
LABEL_38:
          *(_BYTE *)(v33 + 4) = 0;
          sub_59C330();
          break;
      }
    }
    return 1;
  }
  if ( sub_5A4330(a1) != 4 )
    return 1;
  sub_59CFD0();
  v10 = *((_DWORD *)a1 + 597);
  namelen = 16;
  v11 = getsockname(v10, &name, &namelen);
  *(_WORD *)name.sa_data = ntohs(*(u_short *)name.sa_data);
  if ( v11 )
    return 1;
  if ( !strcmp(&v58[strlen(off_903EE4)], (const char *)a1 + 2356) )
  {
    if ( (unsigned __int8)sub_5A3C50(0, 0) )
    {
      v41 = *(unsigned __int16 *)(a5 + 2);
      v39 = *(unsigned __int8 *)(a5 + 7);
      v38 = *(unsigned __int8 *)(a5 + 6);
      v47 = *(_BYTE *)(a5 + 5);
      v37 = *(unsigned __int8 *)(a5 + 4);
      Buffer[0] = 0;
      v20 = sprintf(
              Buffer,
              "%s%s %d %d.%d.%d.%d:%d",
              off_903EDC,
              off_903EE8,
              *(unsigned __int16 *)name.sa_data,
              v37,
              v47,
              v38,
              v39,
              v41);
      v21 = (const struct sockaddr *)sub_59C1E0();
      sendto(*((_DWORD *)a1 + 598), buf, v20, 0, v21, (int)tolen);
      return 1;
    }
    v12 = 4 - (*((_BYTE *)a1 + 97) != 0);
  }
  else
  {
    v12 = 2;
  }
  Buffer[0] = 0;
  v13 = sprintf(Buffer, "%s%s%d", off_903EDC, off_903EEC, v12);
  if ( v12 == 2 )
  {
    v14 = sprintf(v60, " (%s)", (const char *)a1 + 2356);
    v15 = strlen(v60) + 1;
    v16 = &v62;
    while ( *++v16 )
      ;
    qmemcpy(v16, v60, v15);
    v13 += v14;
  }
  v18 = (const struct sockaddr *)sub_59C1E0();
  sendto(*((_DWORD *)a1 + 598), buf, v13, 0, v18, (int)tolen);
  return 1;
}
