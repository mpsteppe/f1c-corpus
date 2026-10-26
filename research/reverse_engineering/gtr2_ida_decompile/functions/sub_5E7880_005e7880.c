int __usercall sub_5E7880@<eax>(
        int *a1@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>,
        const char *ArgList,
        int a7,
        __int16 a8,
        int a9,
        __int16 a10)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  unsigned int v12; // kr04_4
  const char *v13; // eax
  char *v14; // ecx
  char v15; // dl
  void **v16; // eax
  void **v17; // esi
  int *v18; // edi
  _DWORD *v19; // eax
  char *v20; // ebx
  unsigned int v21; // eax
  char *v22; // edi
  void *v24; // eax
  char v25; // di
  int v26; // eax
  int v27; // eax
  int v29; // [esp+44h] [ebp-148h]
  void *v30; // [esp+4Ch] [ebp-140h]
  int v32; // [esp+70h] [ebp-11Ch] BYREF
  int v33; // [esp+74h] [ebp-118h] BYREF
  char v34[8]; // [esp+78h] [ebp-114h] BYREF
  char v35[240]; // [esp+80h] [ebp-10Ch] BYREF
  char v36[4]; // [esp+170h] [ebp-1Ch]
  int v37; // [esp+174h] [ebp-18h]
  int v38; // [esp+178h] [ebp-14h]
  int v39; // [esp+17Ch] [ebp-10h]
  int v40; // [esp+180h] [ebp-Ch]
  int v41; // [esp+184h] [ebp-8h]
  int v42; // [esp+188h] [ebp-4h]

  v42 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v41 = (int)&loc_6EC84E;
  v40 = (int)ExceptionList;
  v33 = a2;
  v32 = a3;
  if ( (a10 & 0xF) != 0 )
  {
    if ( byte_FB230C )
    {
      v12 = strlen(ArgList);
      v13 = &ArgList[(int)(v12 - 63) <= 0 ? 0 : v12 - 63];
      v14 = (char *)(v35 - v13);
      do
      {
        v15 = *v13;
        v13[(_DWORD)v14] = *v13;
        ++v13;
      }
      while ( v15 );
      sub_5D8EF0((int)(a1 + 10), v35, 63);
    }
    if ( a10 >= 0 )
    {
      v16 = (void **)sub_5E0740(a1, ArgList, 0);
      v17 = v16;
      *(_DWORD *)v34 = v16;
      if ( v16 )
      {
        if ( (*(unsigned __int8 (__thiscall **)(int, void *, void *, int, int))(*(_DWORD *)dword_FB27A4 + 272))(
               dword_FB27A4,
               *v16,
               v16[2],
               a4,
               a5) )
        {
          v18 = a1 + 5;
          if ( (*(int (__thiscall **)(int, void *, void *, int *, int *))(*(_DWORD *)dword_FB27A4 + 268))(
                 dword_FB27A4,
                 *v17,
                 v17[2],
                 &v33,
                 &v32) )
          {
            sub_5D8C80((int)a1, (char *)0xFFFFFFFF, "Could not get info for image file %s", (char)ArgList);
          }
          else
          {
            if ( a1[6] == 7 )
              a1[6] = 14;
            if ( v37 )
              a1[1] = v37;
            else
              a1[1] = (int)(a1 + 5);
            if ( v38 )
              a1[2] = v38;
            else
              a1[2] = (int)(a1 + 6);
            if ( *v18 <= v41 )
              *v18 = 1;
            else
              *v18 -= v41;
            if ( sub_5E72D0(a1, 0, 0, a1[6], *v18, v40) )
            {
              sub_5DF6E0(v17);
              sub_5D8C80((int)a1, (char *)0xFFFFFFFF, "Error initializing image surface %s", (char)ArgList);
            }
            else if ( sub_5E73C0(a1, ArgList, v17, v41, 0) )
            {
              sub_5DF6E0(v17);
              sub_5D8C80((int)a1, (char *)0xFFFFFFFF, "Error loading src temp surface %s", (char)ArgList);
            }
            else
            {
              sub_5DF6E0(v17);
            }
          }
        }
        else
        {
          v19 = operator new(0x88u);
          v33 = (int)v19;
          v40 = 0;
          if ( v19 )
            v20 = (char *)sub_5E70C0(v19);
          else
            v20 = 0;
          v40 = -1;
          if ( byte_FB230C )
          {
            strcpy(v20 + 40, "Tmp_");
            v21 = strlen(v34) + 1;
            v22 = v20 + 39;
            while ( *++v22 )
              ;
            qmemcpy(v22, v34, v21);
            v17 = (void **)v32;
          }
          v33 = a8 & 0x200;
          if ( (a8 & 0x200) != 0 )
            *((_DWORD *)v20 + 7) = a1[7];
          v24 = *v17;
          v30 = v17[2];
          v32 = *(_DWORD *)dword_FB27A4;
          if ( (*(int (__thiscall **)(int, void *, void *, _DWORD *, _DWORD *, _DWORD *))(v32 + 268))(
                 dword_FB27A4,
                 v24,
                 v30,
                 (_DWORD *)v20 + 1,
                 (_DWORD *)v20 + 2,
                 (_DWORD *)v20 + 6) )
          {
            sub_5D8C80((int)a1, (char *)0xFFFFFFFF, "Could not get info for image file %s", v36[0]);
          }
          else
          {
            if ( *((_DWORD *)v20 + 6) == 7 )
              *((_DWORD *)v20 + 6) = 14;
            if ( sub_5E72D0((int *)v20, 0, 0, *((_DWORD *)v20 + 6), *((_DWORD *)v20 + 5), v40) )
            {
              sub_5DF6E0(v17);
              sub_5D8C80((int)a1, (char *)0xFFFFFFFF, "Error initializing image surface %s", v36[0]);
            }
            else
            {
              v25 = v36[0];
              if ( !sub_5E73C0(v20, *(const char **)v36, v17, 0, 0) )
              {
                sub_5DF6E0(v17);
                if ( v20 != (char *)-20 )
                  a1[7] = 0;
                v26 = v39;
                if ( !v39 )
                  v26 = *((_DWORD *)v20 + 6);
                v29 = v40;
                a1[6] = v26;
                if ( !sub_5E71D0((int)a1, v26, v29) )
                {
                  if ( v37 || v38 )
                    v27 = sub_5E72D0(a1, v37, v38, a1[6], a1[5], v40);
                  else
                    v27 = sub_5E72D0(a1, *((_DWORD *)v20 + 1), *((_DWORD *)v20 + 2), a1[6], a1[5], v40);
                  if ( v27 )
                  {
                    nullsub_7(v20);
                    j__free(v20);
                    sub_5D8C80((int)a1, (char *)0xFFFFFFFF, "Error initializing dst surface %s", v25);
                    return off_16C9710();
                  }
                  if ( ((*(_BYTE *)a1 & 1) == 0
                     || !(*(int (__thiscall **)(int, char *, int, int *, int, _DWORD))(*(_DWORD *)dword_FB27A4 + 252))(
                           dword_FB27A4,
                           v20,
                           1,
                           a1,
                           1,
                           0))
                    && ((*(_BYTE *)a1 & 2) == 0
                     || !(*(int (__thiscall **)(int, char *, int, int *, int, _DWORD))(*(_DWORD *)dword_FB27A4 + 252))(
                           dword_FB27A4,
                           v20,
                           1,
                           a1,
                           2,
                           0))
                    && ((*(_BYTE *)a1 & 4) == 0
                     || !(*(int (__thiscall **)(int, char *, int, int *, int, _DWORD))(*(_DWORD *)dword_FB27A4 + 252))(
                           dword_FB27A4,
                           v20,
                           4,
                           a1,
                           4,
                           0))
                    && (*(_BYTE *)a1 & 8) != 0 )
                  {
                    (*(int (__thiscall **)(int, char *, int, int *, int, _DWORD))(*(_DWORD *)dword_FB27A4 + 252))(
                      dword_FB27A4,
                      v20,
                      4,
                      a1,
                      8,
                      0);
                  }
                }
                sub_5E6DD0();
                nullsub_7(v20);
                j__free(v20);
                return off_16C9710();
              }
              sub_5DF6E0(v17);
              nullsub_7(v20);
              j__free(v20);
              sub_5D8C80((int)a1, (char *)0xFFFFFFFF, "Error loading src temp surface %s", v25);
            }
          }
        }
      }
      else
      {
        sub_5D8C80((int)a1, (char *)0xFFFFFFFF, "Error getting stats for surface %s", (char)ArgList);
      }
    }
  }
  return off_16C9710();
}
