// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
// positive sp value has been detected, the output may be wrong!
int __userpurge sub_4B811C@<eax>(
        int a1@<ecx>,
        int a2@<ebp>,
        int a3,
        int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        int a10,
        int a11,
        __int64 *a12,
        int a13,
        __int128 a14,
        __int64 a15,
        __int64 a16,
        int a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int128 a26)
{
  int v27; // esi
  int result; // eax
  int v29; // eax
  int v30; // edi
  int v31; // eax
  double v32; // st7
  int v33; // eax
  char v34; // cl
  const char *v35; // eax
  int v36; // eax
  int v37; // eax
  char v38; // cl
  int v39; // esi
  int v40; // edi
  int v41; // eax
  char v42; // cl
  int v43; // eax
  char v44; // cl
  int v45; // eax
  const char *v46; // esi
  int v47; // eax
  char v48; // cl
  int v49; // eax
  const char *v50; // eax
  const char *v51; // edx
  unsigned int v52; // eax
  char *v53; // edi
  unsigned int v56; // eax
  char *v57; // edi
  unsigned int v59; // eax
  char *v60; // edi
  char *v62; // edi
  const char *v64; // edx
  unsigned int v65; // eax
  char *v66; // edi
  int v68; // eax
  char v69; // cl
  char *v70; // edi
  char *v72; // edi
  int v75; // eax
  int v76; // [esp-30h] [ebp-40h]
  int v77; // [esp-4h] [ebp-14h]
  int v78; // [esp+0h] [ebp-10h]
  int v79; // [esp+0h] [ebp-10h]
  int v80; // [esp+4h] [ebp-Ch]
  int v81; // [esp+8h] [ebp-8h]
  int v82; // [esp+Ch] [ebp-4h]
  void *retaddr; // [esp+10h] [ebp+0h]

  sub_409FB0((_DWORD *)(a1 + 52));
  a12 = (__int64 *)dword_BE1BD0;
  LOBYTE(a26) = 0;
  memset((char *)&a26 + 1, 0, 0xFCu);
  LOWORD(STACK[0x1B5]) = 0;
  LOWORD(v82) = 45;
  LOBYTE(STACK[0x1B7]) = 0;
  sub_4D0AC0(v78);
  *(_DWORD *)(a1 + 596) = *(_DWORD *)(a2 + 8);
  v27 = sub_532D20(&unk_B76270);
  LODWORD(a5) = v27;
  result = sub_48F670();
  if ( result < 1 )
    *(_DWORD *)(a1 + 600) = 0;
  if ( v27 )
  {
    v29 = ((int (__thiscall *)(int))sub_5304B0)(v27);
    *(_DWORD *)((char *)&a18 + 1) = 0;
    *(_DWORD *)((char *)&a18 + 5) = 0;
    *(_DWORD *)((char *)&a19 + 1) = 0;
    *(_DWORD *)((char *)&a19 + 5) = 0;
    *(_DWORD *)((char *)&a20 + 1) = 0;
    *(_DWORD *)((char *)&a20 + 5) = 0;
    *(_DWORD *)((char *)&a21 + 1) = 0;
    *(_WORD *)((char *)&a21 + 5) = 0;
    v30 = v29 + 1;
    a13 = v29 + 1;
    LOBYTE(a18) = 0;
    HIBYTE(a21) = 0;
    ((void (__thiscall *)(int))sub_5304D0)(v27);
    sub_532290(&a18, 31);
    if ( v30 > 0 )
    {
      while ( 1 )
      {
        v31 = ((int (__thiscall *)(_DWORD))sub_5304D0)(a5);
        *(_DWORD *)((char *)&a14 + 1) = 0;
        *(_DWORD *)((char *)&a14 + 5) = 0;
        *(_DWORD *)((char *)&a14 + 9) = 0;
        *(_DWORD *)((char *)&a14 + 13) = 0;
        *(_DWORD *)((char *)&a15 + 1) = 0;
        *(_DWORD *)((char *)&a21 + 5) = 0;
        *(_DWORD *)((char *)&a15 + 5) = 0;
        *(_DWORD *)((char *)&a22 + 1) = 0;
        *(_DWORD *)((char *)&a16 + 1) = 0;
        *(_DWORD *)((char *)&a22 + 5) = 0;
        *(_WORD *)((char *)&a16 + 5) = 0;
        *(_DWORD *)((char *)&a23 + 1) = 0;
        *(_DWORD *)((char *)&a23 + 5) = 0;
        *(_DWORD *)((char *)&a24 + 1) = 0;
        HIBYTE(a16) = 0;
        BYTE4(a21) = 0;
        *(_DWORD *)((char *)&a24 + 5) = 0;
        a7 = 0;
        a9 = 0;
        *(_DWORD *)((char *)&a25 + 1) = 0;
        a8 = 0;
        a6 = 0;
        a5 = 0;
        LOBYTE(a14) = 0;
        v32 = *(float *)(v31 + 792);
        v82 = v31;
        if ( (int)(unsigned __int64)v32 <= 0 )
        {
          v33 = 0;
          do
          {
            v34 = *((_BYTE *)&v81 + v33);
            *((_BYTE *)&a7 + v33++) = v34;
          }
          while ( v34 );
        }
        else
        {
          sprintf((char *const)&a7, "%d", (unsigned int)(unsigned __int64)v32);
        }
        sub_532290(&a14, 31);
        v35 = (const char *)sub_530460(v77, v79);
        sub_632041((char *)&a22 + 4, 32, "%s", v35);
        v36 = sub_5326E0((char *)&a14 + 8);
        if ( v36 <= 0 )
        {
          v37 = 0;
          do
          {
            v38 = *((_BYTE *)&retaddr + v37);
            *((_BYTE *)&a9 + v37++) = v38;
          }
          while ( v38 );
        }
        else
        {
          sprintf((char *const)&a9, "%d", v36);
        }
        v39 = (unsigned __int64)MEMORY[0x31C];
        v40 = sub_532DB0((char *)&a14 + 8, MEMORY[0x34C]);
        if ( (int)a5 <= 0 || (int)a5 < MEMORY[0x34C] || v39 <= 0 )
        {
          v41 = 0;
          do
          {
            v42 = *((_BYTE *)&retaddr + v41);
            *((_BYTE *)&a10 + v41++) = v42;
          }
          while ( v42 );
        }
        else
        {
          sprintf((char *const)&a10, "%d", v39);
        }
        if ( (int)a5 <= 0 || (int)a5 < MEMORY[0x34C] || v40 <= 0 )
        {
          v43 = 0;
          do
          {
            v44 = *((_BYTE *)&retaddr + v43);
            *((_BYTE *)&a7 + v43++) = v44;
          }
          while ( v44 );
        }
        else
        {
          sprintf((char *const)&a7, "%d", v40);
        }
        v45 = *(_DWORD *)(a1 + 600);
        if ( v45 )
          a12 = (__int64 *)&a10;
        else
          a12 = &a8;
        v46 = (const char *)&a9;
        if ( v45 )
          v46 = (const char *)&a7;
        DWORD1(a14) = MEMORY[0x338];
        if ( MEMORY[0x338] <= 0 )
        {
          v47 = 0;
          do
          {
            v48 = *((_BYTE *)&retaddr + v47);
            *((_BYTE *)&a6 + v47++) = v48;
          }
          while ( v48 );
        }
        else if ( dword_B72454 == 1 )
        {
          sprintf((char *const)&a6, "%.0flbs", (double)SDWORD1(a14) * 2.2);
        }
        else
        {
          sprintf((char *const)&a6, "%dkg", DWORD1(a14));
        }
        v49 = *(_DWORD *)(a2 + 8);
        if ( !v49 )
          break;
        if ( v49 == 1 )
        {
          v50 = (const char *)MEMORY[0];
          if ( !MEMORY[0] )
            v50 = WindowName;
          sprintf((char *const)&a26 + 4, "%s", v50);
          sub_4CE140(a1, (char *)&a26 + 4);
          if ( *(_DWORD *)(a1 + 608) )
          {
            v51 = (const char *)((int (__thiscall *)(void *))sub_530600)(retaddr);
            v52 = strlen(v51) + 1;
            v53 = (char *)&a25 + 7;
            while ( *++v53 )
              ;
          }
          else
          {
            v51 = (char *)&a14 + 4;
            v52 = strlen((const char *)&a14 + 4) + 1;
            v53 = (char *)&a25 + 7;
            while ( *++v53 )
              ;
          }
          qmemcpy(v53, v51, v52);
          sub_4CE140(a1, &a26);
          v56 = strlen((const char *)&a5) + 1;
          v57 = (char *)&a25 + 3;
          while ( *++v57 )
            ;
          qmemcpy(v57, &a5, v56);
          sub_4CE140(a1, (char *)&a25 + 4);
          v59 = strlen((const char *)(v81 + 912)) + 1;
          v60 = (char *)&a24 + 7;
          while ( *++v60 )
            ;
          qmemcpy(v60, (const void *)(v81 + 912), v59);
          sub_4CE140(a1, &a25);
          v62 = (char *)&a24 + 3;
          while ( *++v62 )
            ;
          strcpy(v62, "  ");
          sub_4CE140(a1, (char *)&a24 + 4);
          v64 = (const char *)HIDWORD(a8);
          v65 = strlen((const char *)HIDWORD(a8)) + 1;
          v66 = (char *)&a23 + 7;
          while ( *++v66 )
            ;
          goto LABEL_63;
        }
LABEL_64:
        if ( (!*(_BYTE *)(a1 + 604) || *(_DWORD *)(v79 + 844) == *(_DWORD *)(a1 + 600))
          && !(unsigned __int8)sub_4CE310((char *)&a24, 0) )
        {
          if ( v80 )
            v76 = sub_4CF8C0(a1);
          else
            v76 = sub_4CF8E0(a1);
          sub_4D93B0(&a24, 0, v76, 0, 0, 0, -1, -1, -1, -1);
        }
        if ( ++v80 >= SHIDWORD(a9) )
          goto LABEL_72;
      }
      v68 = 0;
      do
      {
        v69 = *((_BYTE *)&a14 + v68 + 8);
        *((_BYTE *)&a26 + v68++ + 4) = v69;
      }
      while ( v69 );
      sub_4CE140(a1, (char *)&a26 + 4);
      v70 = (char *)&a25 + 7;
      while ( *++v70 )
        ;
      strcpy(v70, "  ");
      sub_4CE140(a1, &a26);
      v72 = (char *)&a25 + 3;
      while ( *++v72 )
        ;
      strcpy(v72, "  ");
      sub_4CE140(a1, (char *)&a25 + 4);
      v64 = v46;
      v65 = strlen(v46) + 1;
      v66 = (char *)&a24 + 7;
      while ( *++v66 )
        ;
LABEL_63:
      qmemcpy(v66, v64, v65);
      goto LABEL_64;
    }
LABEL_72:
    v75 = *(_DWORD *)(a2 + 8);
    if ( v75 )
    {
      if ( v75 == 1 )
      {
        sub_4D41C0(1, 2);
        if ( *(int *)(a1 + 600) <= 0 )
        {
          sub_4D41C0(2, 3);
          sub_4D41C0(1, 5);
        }
        else
        {
          sub_4D41C0(1, 5);
          sub_4D41C0(2, 3);
        }
      }
    }
    else if ( *(int *)(a1 + 600) <= 0 )
    {
      sub_4D41C0(2, 1);
      sub_4D41C0(1, 2);
      sub_4D41C0(1, 3);
    }
    else
    {
      sub_4D41C0(1, 3);
      sub_4D41C0(1, 2);
      sub_4D41C0(2, 1);
    }
    sub_4CF900(a1);
    sub_4CE460(a1);
    result = a8;
    dword_BE1BD0 = a8;
  }
  else
  {
    dword_BE1BD0 = (int)a12;
  }
  return result;
}
