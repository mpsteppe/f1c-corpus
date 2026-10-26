int __userpurge sub_5FFF80@<eax>(int a1@<ecx>, char a2@<dil>, int a3, int a4, int a5, char a6)
{
  int v8; // eax
  void **v9; // edi
  int v10; // ecx
  int v11; // ecx
  int v12; // edx
  void *v13; // ebp
  int v14; // eax
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // eax
  _DWORD **v19; // eax
  bool v20; // zf
  _DWORD *i; // eax
  int v22; // eax
  _DWORD **v23; // eax
  int v24; // eax
  unsigned int v25; // eax
  int v26; // eax
  int v27; // ecx
  int v28; // ecx
  int v29; // eax
  void *v30; // ebp
  int v31; // eax
  int v32; // edx
  int v33; // eax
  _DWORD **v34; // eax
  _DWORD *j; // eax
  int v36; // [esp+34h] [ebp-14h]

  if ( (*(_BYTE *)a1 & 2) == 0 )
    return 16;
  if ( *(float *)(a1 + 292) <= sub_5F5900(*(_DWORD *)(a1 + 296)) )
  {
    if ( (*(_DWORD *)a1 & 0x10000) == 0 )
    {
      v8 = *(_DWORD *)(a1 + 164);
      v9 = (void **)(a1 + 164);
      if ( v8 )
      {
        v10 = *(_DWORD *)(v8 + 12);
        if ( v10 <= 0 || (v11 = v10 - 1, (*(_DWORD *)(v8 + 12) = v11) == 0) )
          (*(void (__thiscall **)(int, void *, _DWORD))(*(_DWORD *)dword_FB27A4 + 408))(dword_FB27A4, *v9, 0);
      }
      v12 = *(_DWORD *)(a1 + 156);
      *v9 = 0;
      if ( (*(int (__thiscall **)(int, int, int, int, int))(*(_DWORD *)dword_FB27A4 + 404))(
             dword_FB27A4,
             a1 + 164,
             v12,
             0x4000,
             14) )
      {
        nullsub_7(*v9);
        v13 = *v9;
        if ( *v9 )
        {
          nullsub_7(*v9);
          j__free(v13);
        }
        v36 = *(_DWORD *)(a1 + 40);
        goto LABEL_43;
      }
      ++*((_DWORD *)*v9 + 3);
      sub_60ADF0(32, 0);
      v14 = *(_DWORD *)a1 | 0x10000;
      *(_DWORD *)a1 = v14;
      *(_DWORD *)a1 = v14 | 0x10000;
    }
    if ( (*(_BYTE *)a1 & 4) != 0 )
    {
      do
      {
        v15 = *(_DWORD *)(a1 + 164);
        *(_DWORD *)(a1 + 152) = 0;
        (*(void (__thiscall **)(int, int, _DWORD, _DWORD, int))(*(_DWORD *)dword_FB27A4 + 412))(
          dword_FB27A4,
          v15,
          0,
          0,
          0x4000);
        v17 = *(_DWORD *)(a1 + 164);
        if ( !v17 )
          return 16;
        v18 = *(_DWORD *)(v17 + 76);
        if ( !v18 )
          return 16;
        *(_DWORD *)(a1 + 168) = v18;
        if ( a3 )
        {
          v19 = *(_DWORD ***)a3;
          v20 = *(_DWORD *)a3 == 0;
          *(_DWORD *)(a3 + 8) = *(_DWORD *)a3;
          if ( !v20 )
          {
            for ( i = *v19; i; i = *v23 )
            {
              if ( i != *(_DWORD **)(a1 + 276) )
                sub_5FF6F0(a1, v16, i);
              v22 = *(_DWORD *)(a3 + 8);
              if ( !v22 )
                break;
              v23 = *(_DWORD ***)(v22 + 4);
              *(_DWORD *)(a3 + 8) = v23;
              if ( !v23 )
                break;
            }
          }
        }
        (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)dword_FB27A4 + 416))(
          dword_FB27A4,
          *(_DWORD *)(a1 + 164),
          0x4000);
        v24 = *(_DWORD *)(a1 + 160);
        if ( v24 <= 0 )
        {
          v25 = *(_DWORD *)a1 & 0xFFFFFFFB;
        }
        else
        {
          *(_DWORD *)(a1 + 156) += v24;
          *(_DWORD *)(a1 + 160) = 0;
          if ( sub_5FEA10((int *)a1, 1, 0) )
            goto LABEL_28;
          v25 = *(_DWORD *)a1 | 0x10000;
        }
        *(_DWORD *)a1 = v25;
      }
      while ( (v25 & 4) != 0 );
    }
    if ( (*(_DWORD *)a1 & 0x80u) != 0 && a5 )
    {
      if ( (*(_DWORD *)a1 & 0x10000) == 0 )
      {
        v26 = *(_DWORD *)(a1 + 164);
        v9 = (void **)(a1 + 164);
        if ( v26 )
        {
          v27 = *(_DWORD *)(v26 + 12);
          if ( v27 <= 0 || (v28 = v27 - 1, (*(_DWORD *)(v26 + 12) = v28) == 0) )
            (*(void (__thiscall **)(int, void *, _DWORD))(*(_DWORD *)dword_FB27A4 + 408))(dword_FB27A4, *v9, 0);
        }
        v29 = *(_DWORD *)(a1 + 156);
        *v9 = 0;
        if ( (*(int (__thiscall **)(int, int, int, int, int))(*(_DWORD *)dword_FB27A4 + 404))(
               dword_FB27A4,
               a1 + 164,
               v29,
               0x4000,
               14) )
        {
          nullsub_7(*v9);
          v30 = *v9;
          if ( *v9 )
          {
            nullsub_7(*v9);
            j__free(v30);
          }
          v36 = *(_DWORD *)(a1 + 40);
LABEL_43:
          *v9 = 0;
          sub_5D8C80(a1, (char *)0xFFFFFFFF, "Error creating vertex buffer for projector %d", v36);
LABEL_28:
          sub_5D8C80(a1, (char *)0xFFFFFFFF, "Could not expand projector vertex cache", a2);
          return 16;
        }
        ++*((_DWORD *)*v9 + 3);
        sub_60ADF0(32, 0);
        *(_DWORD *)a1 |= 0x10000u;
      }
      v31 = *(_DWORD *)(a1 + 164);
      *(_DWORD *)a1 |= 0x10000u;
      (*(void (__thiscall **)(int, int, _DWORD, _DWORD, int))(*(_DWORD *)dword_FB27A4 + 412))(
        dword_FB27A4,
        v31,
        0,
        0,
        0x4000);
      v33 = *(_DWORD *)(*(_DWORD *)(a1 + 164) + 76);
      if ( !v33 )
        return 16;
      *(_DWORD *)(a1 + 168) = v33;
      v34 = *(_DWORD ***)a5;
      v20 = *(_DWORD *)a5 == 0;
      *(_DWORD *)(a5 + 8) = *(_DWORD *)a5;
      if ( !v20 )
      {
        for ( j = *v34; j; j = (_DWORD *)sub_473B70() )
          sub_5FF6F0(a1, v32, j);
      }
      *(_DWORD *)a1 &= ~4u;
    }
    if ( !a6 )
      sub_5F5A20(*(_DWORD *)(a1 + 296));
  }
  return *(_DWORD *)(a1 + 152) != 0 ? 0 : 0x10;
}
