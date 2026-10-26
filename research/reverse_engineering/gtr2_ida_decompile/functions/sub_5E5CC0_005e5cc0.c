int __userpurge sub_5E5CC0@<eax>(
        unsigned int *a1@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        unsigned int a4,
        int a5,
        unsigned int ArgList,
        int a7,
        int a8,
        int a9,
        int a10,
        __int16 a11)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  int v12; // ebx
  int v15; // eax
  bool v16; // zf
  int *v17; // eax
  unsigned int v18; // edi
  int v19; // ebp
  int v20; // ecx
  int v21; // eax
  _DWORD *v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // ecx
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // edi
  void *v29; // eax
  int v30; // eax
  unsigned int v31; // edx
  unsigned int v32; // eax
  int v33; // ebp
  _DWORD *v34; // eax
  unsigned int v35; // eax
  _DWORD *v36; // eax
  float v37; // [esp-10h] [ebp-4Ch]
  int v38; // [esp-8h] [ebp-44h]
  int v39; // [esp-4h] [ebp-40h]
  int v42; // [esp+18h] [ebp-24h] BYREF
  int v43; // [esp+1Ch] [ebp-20h] BYREF
  int v44; // [esp+20h] [ebp-1Ch] BYREF
  int v45; // [esp+24h] [ebp-18h] BYREF
  int v46; // [esp+28h] [ebp-14h] BYREF
  _DWORD v47[3]; // [esp+2Ch] [ebp-10h] BYREF
  int v48; // [esp+38h] [ebp-4h]

  v48 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v47[2] = &loc_6EC78B;
  v47[1] = ExceptionList;
  v12 = a4;
  if ( (*(_BYTE *)a1 & 1) == 0 )
  {
    if ( !a4 )
    {
      sub_5D8C80((int)a1, (char *)0xFFFFFFFF, "Invalid scene parameter.", a2);
      return -1;
    }
    v15 = a5;
    v16 = a5 == 0;
    a1[15] = a4;
    if ( v16 )
    {
      if ( *(int *)(v12 + 764) > 0 && (v17 = *(int **)(v12 + 752)) != 0 )
        v15 = *v17;
      else
        v15 = 0;
    }
    v18 = ArgList;
    v16 = ArgList == 0;
    a1[13] = v15;
    if ( !v16 )
      a1[12] = v18;
    (*(void (__thiscall **)(int, _DWORD, _DWORD, unsigned int *, int, int))(*(_DWORD *)dword_FB27A4 + 636))(
      dword_FB27A4,
      0,
      0,
      &a4,
      a2,
      a3);
    if ( ArgList == 514 || ArgList == 1028 || ArgList == 1032 )
    {
      v19 = a11 & 0x400;
      v20 = dword_FB27A4;
      if ( (a11 & 0x400) != 0 )
      {
        v21 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)dword_FB27A4 + 632))(
                dword_FB27A4,
                "L1SHADOWDRAWTEX");
        goto LABEL_20;
      }
    }
    else
    {
      v19 = a11 & 0x400;
      v20 = dword_FB27A4;
      if ( (a11 & 0x400) != 0 )
      {
        v21 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)dword_FB27A4 + 632))(
                dword_FB27A4,
                "L0SHADOWDRAWTEX");
LABEL_20:
        v22 = (_DWORD *)a1[13];
        a1[14] = v21;
        v45 = 0;
        v46 = 0;
        v47[0] = 0;
        v42 = 0;
        v43 = -1082130432;
        v44 = 0;
        if ( v22 )
          sub_5DCE20(v22, &v42, &v43, &v44);
        v23 = a1[12];
        if ( v23 )
          sub_5DA7A0(*(_DWORD **)(v23 + 392), &v45, &v46, v47);
        v24 = a1[12];
        if ( !v24 )
          goto LABEL_31;
        if ( *(_DWORD *)(*(_DWORD *)(v24 + 392) + 624) )
        {
          v25 = *(_DWORD *)(v24 + 464);
          if ( v25 )
          {
            v26 = *(_DWORD *)(v25 + 64);
            if ( v26 )
              a1[1] = *(_DWORD *)(v26 + 4) + *(_DWORD *)(v26 + 80);
LABEL_44:
            v32 = a1[12];
            *a1 = *a1 & 0xFFFFFFB6 | 0x41;
            if ( v32 )
            {
              *(_DWORD *)(v32 + 464) = a1;
              if ( (**(_BYTE **)(a1[12] + 392) & 0x10) == 0 )
                *a1 |= 0x100u;
            }
            if ( v19 )
              *a1 |= 0x400u;
            v33 = a9;
            if ( (a9 & 0x4000) != 0 )
              *a1 |= 0x4000u;
            goto LABEL_52;
          }
        }
        if ( (unsigned __int8)sub_5EB310(v24) )
          v27 = *(_DWORD *)(a1[15] + 624);
        else
LABEL_31:
          v27 = *(_DWORD *)(a1[15] + 608);
        a1[1] = 100 * v27;
        v28 = 0;
        if ( (a9 & 0x4000) != 0 )
          v28 = 128;
        if ( (a9 & 0x2000) != 0 )
          v28 |= 0x40u;
        if ( (a9 & 0x10000000) != 0 )
          v28 |= 0x10000000u;
        v29 = operator new(0x140u);
        v48 = 0;
        if ( v29 )
          v30 = sub_6002C0(v29);
        else
          v30 = 0;
        v39 = a8;
        v31 = a1[12];
        v38 = a7;
        a1[11] = v30;
        v37 = *(float *)(v31 + 20);
        v48 = -1;
        if ( sub_5FFAF0(v30, v12, (int)&v45, (int)&v42, v37, 1167867904, v38, v39, v28) )
        {
          sub_5D8C80((int)a1, (char *)0xFFFFFFFF, "Error creating projector for shadow caster %d.", a1[1]);
          return -1;
        }
        LOBYTE(v18) = ArgList;
        *(_DWORD *)(a1[11] + 292) = 1022739087;
        *(_DWORD *)(a1[11] + 236) = *(_DWORD *)(a1[12] + 244);
        goto LABEL_44;
      }
    }
    v21 = (*(int (__thiscall **)(int))(*(_DWORD *)v20 + 632))(v20);
    goto LABEL_20;
  }
  LOBYTE(v18) = ArgList;
  v33 = a9;
LABEL_52:
  v34 = (_DWORD *)a1[17];
  a1[19] = (unsigned int)v34;
  if ( v34 && *v34 )
  {
    do
    {
      sub_5E5CC0(v12, a5, v18, a7, a8, v33);
      v35 = a1[19];
      if ( !v35 )
        break;
      v36 = *(_DWORD **)(v35 + 4);
      a1[19] = (unsigned int)v36;
      if ( !v36 )
        break;
    }
    while ( *v36 );
  }
  return 0;
}
