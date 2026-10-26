int __thiscall sub_48D9D0(_DWORD *this, int a2, int a3, int a4, int a5)
{
  _DWORD *v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  const char **v11; // eax
  const char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char v15; // al
  int v16; // edx
  int v17; // eax
  int v18; // ecx
  int v19; // edi
  int v20; // ebx
  int v21; // eax
  int v22; // ebp
  const char ***v23; // eax
  const char *v24; // edi
  char *v25; // eax
  char *v26; // eax
  int v27; // edx
  int i; // ecx
  int v29; // eax
  char *v30; // eax
  int v31; // eax
  int v32; // edi
  int v34; // [esp-14h] [ebp-38h]
  int v35; // [esp-14h] [ebp-38h]
  int v36; // [esp-14h] [ebp-38h]
  int v37; // [esp-10h] [ebp-34h]
  int v38; // [esp-10h] [ebp-34h]
  int v39; // [esp-10h] [ebp-34h]
  int v40; // [esp-10h] [ebp-34h]
  int v41; // [esp-10h] [ebp-34h]
  int v42; // [esp-10h] [ebp-34h]
  int v43; // [esp-Ch] [ebp-30h]
  int v44; // [esp-Ch] [ebp-30h]
  int v45; // [esp-Ch] [ebp-30h]
  int v46; // [esp-Ch] [ebp-30h]
  int v47; // [esp-8h] [ebp-2Ch]
  int v48; // [esp-8h] [ebp-2Ch]
  int v49; // [esp+8h] [ebp-1Ch] BYREF
  int v50; // [esp+Ch] [ebp-18h] BYREF
  int v51; // [esp+10h] [ebp-14h]
  int v52; // [esp+14h] [ebp-10h]
  int v53; // [esp+18h] [ebp-Ch] BYREF
  int v54; // [esp+1Ch] [ebp-8h] BYREF
  int v55; // [esp+20h] [ebp-4h]

  this[66] = sub_487060(this, 0);
  this[70] = sub_4870E0(this, 0);
  this[67] = sub_487060(this, 1);
  this[71] = sub_4870E0(this, 1);
  this[68] = sub_487060(this, 2);
  this[72] = sub_4870E0(this, 2);
  this[69] = sub_487060(this, 3);
  this[73] = sub_4870E0(this, 3);
  v6 = (_DWORD *)this[58];
  this[60] = v6;
  if ( !v6 || !*v6 )
    return 0;
  v7 = this[63];
  v8 = this[62] - 1;
  v52 = 0;
  if ( v7 > v8 )
    this[63] = v8;
  v9 = this[63];
  if ( v9 >= 0 && v9 < this[61] )
  {
    v10 = this[58];
    if ( v9 <= 0 )
    {
LABEL_10:
      if ( v10 )
      {
        v11 = *(const char ***)v10;
        goto LABEL_13;
      }
    }
    else
    {
      while ( v10 )
      {
        v10 = *(_DWORD *)(v10 + 4);
        if ( --v9 <= 0 )
          goto LABEL_10;
      }
    }
  }
  v11 = 0;
LABEL_13:
  v12 = *v11;
  if ( !*v11 )
    v12 = byte_5EA438;
  if ( BinarySearchInStringTable(byte_5EC4C0, v12, byte_5EC4CC) )
  {
    if ( v12 )
      strcpy(byte_5EC4CC, v12);
    else
      byte_5EC4CC[0] = 0;
  }
  v13 = UIStringAccessor_62c0(this);
  ShortComputation_4f00(v13, byte_5EC4CC, &v50, &v49);
  v43 = GlobalAccessor_5150(&unk_7CDE00);
  v37 = this[73];
  v34 = this[69];
  v14 = UIStringAccessor_62c0(this);
  UIMessageDispatch(v14, v12, v34, v37, v43, 1);
  v47 = v49;
  v44 = v50 + 20;
  v38 = this[73];
  v35 = this[69];
  Accessor();
  RenderSurfaceFillCopy(v35, v38, v44, v47);
  DualFieldRead(&v54, &v53);
  v15 = ShortComputation_6720(this);
  if ( v15 == 3 || v15 == 5 || v15 == 4 || v15 == 8 || v15 == 9 )
  {
    v16 = ShortComputation_adb0(this[50] + 108);
    v17 = this[64];
    v55 = v16;
    if ( v17 < 0 || v17 >= this[61] )
    {
      this[60] = 0;
    }
    else
    {
      for ( this[60] = this[58]; v17 > 0; this[60] = *(_DWORD *)(v18 + 4) )
      {
        v18 = this[60];
        if ( !v18 )
          break;
        --v17;
      }
    }
    v19 = 4;
    this[65] = this[63];
    v51 = 4;
    if ( v16 > 4 )
    {
      do
      {
        v20 = sub_487060(this, v19);
        v21 = sub_4870E0(this, v19);
        v22 = v21;
        if ( v21 > v52 )
          v52 = v49 + v21;
        v23 = (const char ***)this[60];
        if ( v23 && *v23 )
        {
          v24 = **v23;
          if ( !v24 )
            v24 = byte_5EA438;
          if ( BinarySearchInStringTable(byte_5EC4C0, v24, byte_5EC4CC) )
          {
            if ( v24 )
              strcpy(byte_5EC4CC, v24);
            else
              byte_5EC4CC[0] = 0;
          }
          v25 = UIStringAccessor_62c0(this);
          ShortComputation_4f00(v25, byte_5EC4CC, &v50, &v49);
          if ( v53 <= v22 || v53 >= v49 + v22 || v54 <= v20 || v54 >= v20 + v50 )
          {
            v40 = GlobalAccessor_5150(&unk_7CDE00);
            v30 = UIStringAccessor_62c0(this);
            UIMessageDispatch(v30, v24, v20, v22, v40, 1);
          }
          else
          {
            v39 = GlobalAccessor_5150(&unk_7CDE00);
            v26 = UIStringAccessor_62e0(this);
            UIMessageDispatch(v26, v24, v20, v22, v39, 1);
            v27 = this[60];
            i = -1;
            if ( v27 )
            {
              v29 = this[58];
              for ( i = 0; v29; ++i )
              {
                if ( v29 == v27 )
                  break;
                v29 = *(_DWORD *)(v29 + 4);
              }
            }
            this[65] = i;
          }
          v45 = v49;
          v41 = v50 + 20;
          Accessor();
          RenderSurfaceFillCopy(v20, v22, v41, v45);
          v31 = this[60];
          v19 = v51;
          if ( v31 )
            this[60] = *(_DWORD *)(v31 + 4);
        }
        v51 = ++v19;
      }
      while ( v19 < v55 );
    }
  }
  v32 = ConditionalDelegation_6460(this, this[33]);
  if ( v32 )
  {
    v48 = *(_DWORD *)(v32 + 12);
    v46 = *(_DWORD *)(v32 + 4);
    v42 = this[1];
    v36 = this[3];
    Accessor();
    RenderSurfaceFillCopy(v36, v42, v46, v48);
    (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD, _DWORD, _DWORD))(*this + 16))(
      this,
      this[1],
      *(_DWORD *)(v32 + 12),
      this[3],
      *(_DWORD *)(v32 + 4));
  }
  (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, 0);
  return 0;
}

