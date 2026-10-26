int __userpurge sub_5BD220@<eax>(__int64 a1@<edx:eax>, int a2@<ecx>, _BYTE *a3, int a4, int a5)
{
  _DWORD *v6; // ebx
  int v7; // edi
  u_short *v8; // esi
  int v9; // ebp
  int v10; // edx
  __int16 v11; // ax
  int v12; // edx
  int v13; // eax
  int v14; // eax
  u_short v15; // ax
  int v16; // eax
  unsigned int v17; // ecx
  __int64 v18; // rax
  unsigned int v19; // ecx
  const char *v20; // esi
  unsigned int v21; // ebp
  unsigned int v22; // ecx
  __int64 v23; // rax
  int v26; // [esp+14h] [ebp-8h]
  int v28; // [esp+20h] [ebp+4h]
  char v29; // [esp+24h] [ebp+8h]

  v6 = (_DWORD *)HIDWORD(a1);
  v7 = a2;
  BYTE4(a1) = *a3;
  v29 = *a3;
  sub_5BA5B0(a1, (int)v6);
  v8 = (u_short *)(a3 + 5);
  v9 = a4 - 5;
  if ( (v29 & 0x10) != 0 )
  {
    v8 = (u_short *)(a3 + 7);
    v9 -= 2;
  }
  if ( (v29 & 2) != 0 )
  {
    v10 = *(_DWORD *)v8;
    v8 += 2;
    v9 -= 4;
  }
  else
  {
    v10 = 0;
  }
  if ( (v29 & 0x20) != 0 )
  {
    v11 = *v8++;
    v9 -= 2;
  }
  else
  {
    v11 = *(_WORD *)(v7 + 1176);
  }
  sub_5BA5C0((int)v6, v10, v11);
  if ( (v29 & 8) != 0 )
  {
    v12 = *(_DWORD *)v8;
    v8 += 2;
    v9 -= 4;
    sub_5BA5D0((int)v6, v12);
  }
  if ( (v29 & 0x40) != 0 )
  {
    v26 = sub_577650(*(void **)(v7 + 8));
    v28 = 0;
    if ( v26 > 0 )
    {
      while ( 1 )
      {
        v13 = *(_DWORD *)(sub_5BE1B0(*(_DWORD *)(v7 + 8), v28) + 4);
        if ( v13 )
        {
          v14 = v13 - 1;
          if ( v14 )
          {
            if ( v14 == 1 )
            {
              v15 = ntohs(*v8);
              sub_5BA120(v6, v15);
              ++v8;
              v9 -= 2;
            }
          }
          else
          {
            sub_5BA120(v6, *(unsigned __int8 *)v8);
            v8 = (u_short *)((char *)v8 + 1);
            --v9;
          }
        }
        else if ( a5 && (v16 = *(unsigned __int8 *)v8, v8 = (u_short *)((char *)v8 + 1), --v9, v16 != 255) )
        {
          sub_5BA0E0(v6, *(_DWORD *)(a2 + 4 * v16 + 124));
        }
        else
        {
          sub_5BA0E0(v6, (int)v8);
          v17 = strlen((const char *)v8) + 1;
          v8 = (u_short *)((char *)v8 + v17);
          v9 -= v17;
        }
        if ( ++v28 >= v26 )
          break;
        v7 = a2;
      }
    }
    LOBYTE(v18) = sub_5BA5F0(v6);
    BYTE4(v18) = v18 | 1;
    sub_5BA5E0(v18, (int)v6);
  }
  if ( v29 < 0 )
  {
    for ( ; *(_BYTE *)v8; v9 = v21 - v22 )
    {
      if ( v9 <= 0 )
        break;
      v19 = strlen((const char *)v8) + 1;
      v20 = (char *)v8 + v19;
      v21 = v9 - v19;
      sub_5BA0E0(v6, (int)v20);
      v22 = strlen(v20) + 1;
      v8 = (u_short *)&v20[v22];
    }
    --v9;
    LOBYTE(v23) = sub_5BA5F0(v6);
    BYTE4(v23) = v23 | 2;
    sub_5BA5E0(v23, (int)v6);
  }
  return a4 - v9;
}
