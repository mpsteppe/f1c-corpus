int __thiscall sub_5D9DB0(void *this)
{
  int v2; // edi
  int *v3; // ecx
  _DWORD *v4; // esi
  int v5; // eax
  void *v6; // edi
  int v7; // edi
  int *v8; // ecx
  _DWORD *v9; // esi
  int v10; // eax
  void *v11; // edi
  _DWORD *v12; // eax
  int v13; // edx
  _DWORD *v14; // esi
  int v15; // ecx
  void *v16; // edi
  _DWORD *v17; // eax
  int v18; // edx
  _DWORD *v19; // esi
  int v20; // ecx
  void *v21; // edi
  _DWORD *v22; // eax
  int v23; // edx
  _DWORD *v24; // esi
  int v25; // ecx
  void *v26; // edi
  int v27; // edi
  int *v28; // ecx
  _DWORD *v29; // esi
  int v30; // eax
  void *v31; // edi
  _DWORD *v32; // eax
  int v33; // edx
  _DWORD *v34; // esi
  int v35; // ecx
  _DWORD *v36; // eax
  int v37; // edx
  _DWORD *v38; // esi
  int v39; // ecx
  void *v40; // esi
  void *v41; // esi
  void *v42; // esi
  void *v43; // esi
  void *v44; // esi
  int v46; // [esp+0h] [ebp-10h]

  dword_FB28A4 = (int)dword_FB289C;
  if ( dword_FB289C )
  {
    v2 = *(_DWORD *)dword_FB289C;
    if ( *(_DWORD *)dword_FB289C )
    {
      do
      {
        sub_5E6DD0(v2);
        v3 = (int *)dword_FB289C;
        v4 = dword_FB289C;
        v5 = 0;
        if ( dword_FB289C )
        {
          while ( *v4 != v2 )
          {
            v5 = (int)v4;
            v4 = (_DWORD *)v4[1];
            if ( !v4 )
              goto LABEL_18;
          }
          if ( v4 == (_DWORD *)dword_FB28A4 )
            dword_FB28A4 = v4[1];
          if ( v5 )
            *(_DWORD *)(v5 + 4) = v4[1];
          else
            dword_FB289C = (void *)v4[1];
          if ( (_DWORD *)dword_FB28A0 == v4 )
            dword_FB28A0 = v5;
          --dword_FB28A8;
          if ( *((_BYTE *)v4 + 8) )
          {
            v6 = (void *)*v4;
            if ( *v4 )
            {
              j_nullsub_7((void *)*v4);
              j__free(v6);
            }
          }
          j__free(v4);
          v3 = (int *)dword_FB289C;
        }
LABEL_18:
        dword_FB28A4 = (int)v3;
        if ( !v3 )
          break;
        v2 = *v3;
      }
      while ( *v3 );
    }
  }
  dword_FB2D80 = (int)dword_FB2D78;
  if ( dword_FB2D78 )
  {
    v7 = *(_DWORD *)dword_FB2D78;
    if ( *(_DWORD *)dword_FB2D78 )
    {
      do
      {
        sub_5E2B10(v7);
        v8 = (int *)dword_FB2D78;
        v9 = dword_FB2D78;
        v10 = 0;
        if ( dword_FB2D78 )
        {
          while ( *v9 != v7 )
          {
            v10 = (int)v9;
            v9 = (_DWORD *)v9[1];
            if ( !v9 )
              goto LABEL_37;
          }
          if ( v9 == (_DWORD *)dword_FB2D80 )
            dword_FB2D80 = v9[1];
          if ( v10 )
            *(_DWORD *)(v10 + 4) = v9[1];
          else
            dword_FB2D78 = (void *)v9[1];
          if ( (_DWORD *)dword_FB2D7C == v9 )
            dword_FB2D7C = v10;
          --dword_FB2D84;
          if ( *((_BYTE *)v9 + 8) )
          {
            v11 = (void *)*v9;
            if ( *v9 )
            {
              j_j_nullsub_7((void *)*v9);
              j__free(v11);
            }
          }
          j__free(v9);
          v8 = (int *)dword_FB2D78;
        }
LABEL_37:
        dword_FB2D80 = (int)v8;
        if ( !v8 )
          break;
        v7 = *v8;
      }
      while ( *v8 );
    }
  }
  v12 = dword_FB28AC;
  dword_FB28B4 = (int)dword_FB28AC;
  if ( dword_FB28AC )
  {
    v13 = *(_DWORD *)dword_FB28AC;
    if ( *(_DWORD *)dword_FB28AC )
    {
      do
      {
        v14 = v12;
        v15 = 0;
        if ( v12 )
        {
          while ( *v14 != v13 )
          {
            v15 = (int)v14;
            v14 = (_DWORD *)v14[1];
            if ( !v14 )
              goto LABEL_56;
          }
          if ( v14 == v12 )
            dword_FB28B4 = v14[1];
          if ( v15 )
            *(_DWORD *)(v15 + 4) = v14[1];
          else
            dword_FB28AC = (void *)v14[1];
          if ( (_DWORD *)dword_FB28B0 == v14 )
            dword_FB28B0 = v15;
          --dword_FB28B8;
          if ( *((_BYTE *)v14 + 8) )
          {
            v16 = (void *)*v14;
            if ( *v14 )
            {
              sub_5EE130((void *)*v14);
              j__free(v16);
            }
          }
          j__free(v14);
          v12 = dword_FB28AC;
        }
LABEL_56:
        dword_FB28B4 = (int)v12;
        if ( !v12 )
          break;
        v13 = *v12;
      }
      while ( *v12 );
    }
  }
  v17 = dword_FB28CC;
  dword_FB28D4 = (int)dword_FB28CC;
  if ( dword_FB28CC )
  {
    v18 = *(_DWORD *)dword_FB28CC;
    if ( *(_DWORD *)dword_FB28CC )
    {
      do
      {
        v19 = v17;
        v20 = 0;
        if ( v17 )
        {
          while ( *v19 != v18 )
          {
            v20 = (int)v19;
            v19 = (_DWORD *)v19[1];
            if ( !v19 )
              goto LABEL_75;
          }
          if ( v19 == v17 )
            dword_FB28D4 = v19[1];
          if ( v20 )
            *(_DWORD *)(v20 + 4) = v19[1];
          else
            dword_FB28CC = (void *)v19[1];
          if ( (_DWORD *)dword_FB28D0 == v19 )
            dword_FB28D0 = v20;
          --dword_FB28D8;
          if ( *((_BYTE *)v19 + 8) )
          {
            v21 = (void *)*v19;
            if ( *v19 )
            {
              sub_51D670((void *)*v19, 0, v46);
              j__free(v21);
            }
          }
          j__free(v19);
          v17 = dword_FB28CC;
        }
LABEL_75:
        dword_FB28D4 = (int)v17;
        if ( !v17 )
          break;
        v18 = *v17;
      }
      while ( *v17 );
    }
  }
  v22 = dword_FB27D4;
  dword_FB27DC = (int)dword_FB27D4;
  if ( dword_FB27D4 )
  {
    v23 = *(_DWORD *)dword_FB27D4;
    if ( *(_DWORD *)dword_FB27D4 )
    {
      do
      {
        v24 = v22;
        v25 = 0;
        if ( v22 )
        {
          while ( *v24 != v23 )
          {
            v25 = (int)v24;
            v24 = (_DWORD *)v24[1];
            if ( !v24 )
              goto LABEL_94;
          }
          if ( v24 == v22 )
            dword_FB27DC = v24[1];
          if ( v25 )
            *(_DWORD *)(v25 + 4) = v24[1];
          else
            dword_FB27D4 = (void *)v24[1];
          if ( (_DWORD *)dword_FB27D8 == v24 )
            dword_FB27D8 = v25;
          --dword_FB27E0;
          if ( *((_BYTE *)v24 + 8) )
          {
            v26 = (void *)*v24;
            if ( *v24 )
            {
              sub_51D670((void *)*v24, 0, v46);
              j__free(v26);
            }
          }
          j__free(v24);
          v22 = dword_FB27D4;
        }
LABEL_94:
        dword_FB27DC = (int)v22;
        if ( !v22 )
          break;
        v23 = *v22;
      }
      while ( *v22 );
    }
  }
  dword_FB28C4 = (int)dword_FB28BC;
  if ( dword_FB28BC )
  {
    v27 = *(_DWORD *)dword_FB28BC;
    if ( *(_DWORD *)dword_FB28BC )
    {
      do
      {
        sub_5DD4F0(v27);
        v28 = (int *)dword_FB28BC;
        v29 = dword_FB28BC;
        v30 = 0;
        if ( dword_FB28BC )
        {
          while ( *v29 != v27 )
          {
            v30 = (int)v29;
            v29 = (_DWORD *)v29[1];
            if ( !v29 )
              goto LABEL_113;
          }
          if ( v29 == (_DWORD *)dword_FB28C4 )
            dword_FB28C4 = v29[1];
          if ( v30 )
            *(_DWORD *)(v30 + 4) = v29[1];
          else
            dword_FB28BC = (void *)v29[1];
          if ( (_DWORD *)dword_FB28C0 == v29 )
            dword_FB28C0 = v30;
          --dword_FB28C8;
          if ( *((_BYTE *)v29 + 8) )
          {
            v31 = (void *)*v29;
            if ( *v29 )
            {
              sub_5DE8F0(*v29);
              j__free(v31);
            }
          }
          j__free(v29);
          v28 = (int *)dword_FB28BC;
        }
LABEL_113:
        dword_FB28C4 = (int)v28;
        if ( !v28 )
          break;
        v27 = *v28;
      }
      while ( *v28 );
    }
  }
  v32 = dword_FB286C;
  dword_FB2874 = (int)dword_FB286C;
  if ( dword_FB286C )
  {
    v33 = *(_DWORD *)dword_FB286C;
    if ( *(_DWORD *)dword_FB286C )
    {
      do
      {
        v34 = v32;
        v35 = 0;
        if ( v32 )
        {
          while ( *v34 != v33 )
          {
            v35 = (int)v34;
            v34 = (_DWORD *)v34[1];
            if ( !v34 )
              goto LABEL_131;
          }
          if ( v34 == v32 )
            dword_FB2874 = v34[1];
          if ( v35 )
            *(_DWORD *)(v35 + 4) = v34[1];
          else
            dword_FB286C = (void *)v34[1];
          if ( (_DWORD *)dword_FB2870 == v34 )
            dword_FB2870 = v35;
          --dword_FB2878;
          if ( *((_BYTE *)v34 + 8) )
            j__free((void *)*v34);
          j__free(v34);
          v32 = dword_FB286C;
        }
LABEL_131:
        dword_FB2874 = (int)v32;
        if ( !v32 )
          break;
        v33 = *v32;
      }
      while ( *v32 );
    }
  }
  v36 = dword_FB27C4;
  dword_FB27CC = (int)dword_FB27C4;
  if ( dword_FB27C4 )
  {
    v37 = *(_DWORD *)dword_FB27C4;
    if ( *(_DWORD *)dword_FB27C4 )
    {
      do
      {
        v38 = v36;
        v39 = 0;
        if ( v36 )
        {
          while ( *v38 != v37 )
          {
            v39 = (int)v38;
            v38 = (_DWORD *)v38[1];
            if ( !v38 )
              goto LABEL_149;
          }
          if ( v38 == v36 )
            dword_FB27CC = v38[1];
          if ( v39 )
            *(_DWORD *)(v39 + 4) = v38[1];
          else
            dword_FB27C4 = (void *)v38[1];
          if ( (_DWORD *)dword_FB27C8 == v38 )
            dword_FB27C8 = v39;
          --dword_FB27D0;
          if ( *((_BYTE *)v38 + 8) )
            j__free((void *)*v38);
          j__free(v38);
          v36 = dword_FB27C4;
        }
LABEL_149:
        dword_FB27CC = (int)v36;
        if ( !v36 )
          break;
        v37 = *v36;
      }
      while ( *v36 );
    }
  }
  sub_5FBA80(this);
  (*(void (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 600))(dword_FB27A4);
  (*(void (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 96))(dword_FB27A4);
  v40 = dword_FB2790;
  if ( dword_FB2790 )
  {
    j_nullsub_7(dword_FB2790);
    j__free(v40);
  }
  dword_FB2790 = 0;
  v41 = dword_FB2794;
  if ( dword_FB2794 )
  {
    j_nullsub_7(dword_FB2794);
    j__free(v41);
  }
  dword_FB2794 = 0;
  if ( dword_FB40FC )
  {
    v42 = dword_FB40FC;
    sub_601270();
    j__free(v42);
    dword_FB40FC = 0;
  }
  if ( dword_FB2774 )
  {
    v43 = dword_FB2774;
    j_nullsub_7(dword_FB2774);
    j__free(v43);
    dword_FB2774 = 0;
  }
  if ( dword_FB27A8 )
  {
    j__free(dword_FB27A8);
    dword_FB27A8 = 0;
  }
  sub_5F5650(this);
  if ( dword_FB27AC )
  {
    v44 = dword_FB27AC;
    sub_5E8CD0(dword_FB27AC);
    j__free(v44);
    dword_FB27AC = 0;
  }
  return 0;
}
