int __thiscall sub_4D74A0(_DWORD *this, int *a2, int a3, int *a4, int a5)
{
  int result; // eax
  int v7; // edi
  int v8; // edi
  int v9; // ebx
  int v10; // ecx
  int v11; // eax
  int v12; // edi
  int v13; // ebx
  int v14; // ebp
  int v15; // eax
  int v16; // ebx
  int v17; // ebp
  int v18; // ecx
  int v19; // eax
  _DWORD *v20; // eax
  int v21; // eax
  int v22; // ebx
  int v23; // eax
  int v24; // edi
  int v25; // ecx
  int v26; // ebp
  int v27; // eax
  int v28; // ebp
  int v29; // eax
  int v30; // edi
  int v31; // eax
  int v32; // ebx
  int v33; // edx
  int v34; // eax
  int *v35; // edi
  int v36; // eax
  int v37; // ebx
  int v38; // edx
  int v39; // eax
  int v40; // ebp
  int v41; // edx
  int v42; // eax
  int v43; // [esp+0h] [ebp-4Ch]
  int v44; // [esp+8h] [ebp-44h]
  int v45; // [esp+28h] [ebp-24h]
  int v46; // [esp+2Ch] [ebp-20h]
  int v47; // [esp+30h] [ebp-1Ch]
  _DWORD *v48; // [esp+34h] [ebp-18h]
  int v49; // [esp+38h] [ebp-14h]
  int v50; // [esp+3Ch] [ebp-10h]
  int v51; // [esp+40h] [ebp-Ch]
  int v52; // [esp+40h] [ebp-Ch]
  int v53; // [esp+44h] [ebp-8h]
  int v54; // [esp+48h] [ebp-4h]

  result = -1;
  if ( (this[5] != -1 || this[6] != -1 || this[7] != -1 || this[8] != -1) && (int)this[213] > 0 )
  {
    v7 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
    v8 = v7 - (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
    v9 = (*(int (__thiscall **)(_DWORD *))(*this + 16))(this);
    v53 = v9 - (*(int (__thiscall **)(_DWORD *))(*this + 8))(this);
    v10 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
    v11 = v8;
    v12 = this[214];
    v13 = v11 / 2 + v10 - this[216] % v12;
    v14 = this[216] / v12;
    v15 = (v13 - (*(int (__thiscall **)(_DWORD *))(*this + 4))(this)) / v12 + 1;
    v16 = v13 - v15 * v12;
    v17 = v14 - v15;
    v46 = v16;
    v45 = v17;
    if ( v17 < 0 )
    {
      do
        v17 += this[213];
      while ( v17 < 0 );
      v45 = v17;
    }
    for ( ; v16 < (*(int (__thiscall **)(_DWORD *))(*this + 12))(this); v46 = v16 )
    {
      v18 = v17;
      if ( v17 < 0 || v17 >= this[213] )
      {
        this[212] = 0;
      }
      else
      {
        this[212] = this[210];
        if ( v17 > 0 )
        {
          do
          {
            v19 = this[212];
            if ( !v19 )
              break;
            --v18;
            this[212] = *(_DWORD *)(v19 + 4);
          }
          while ( v18 > 0 );
        }
      }
      v20 = (_DWORD *)this[212];
      if ( v20 )
      {
        v20 = (_DWORD *)*v20;
        v48 = v20;
      }
      else
      {
        v48 = 0;
      }
      if ( v20 )
      {
        v21 = v20[1];
        if ( v21 )
        {
          v22 = *(_DWORD *)(v21 + 20);
          v23 = *(_DWORD *)(v21 + 24);
          v49 = v23;
          if ( v22 > 0 && v23 > 0 )
          {
            v24 = this[214] - v22;
            v25 = v53 - v23;
            v26 = 0;
            v51 = v53 - v23;
            if ( v24 <= 0 )
            {
              v47 = 0;
              v27 = 0;
            }
            else
            {
              v27 = v24 / 2;
              v47 = v24 / 2;
            }
            if ( v25 > 0 )
            {
              v27 = v47;
              v26 = v25 / 2;
            }
            v50 = v46 + v27;
            v54 = v26 + (*(int (__thiscall **)(_DWORD *))(*this + 8))(this);
            if ( v24 <= 0 )
            {
              v28 = v24 / -2;
              v22 -= 2 * (v24 / -2);
            }
            else
            {
              v28 = 0;
            }
            v29 = v51;
            v30 = v22;
            if ( v51 <= 0 )
            {
              v52 = v51 / -2;
              v49 -= 2 * (v29 / -2);
            }
            else
            {
              v52 = 0;
            }
            if ( v46 >= (*(int (__thiscall **)(_DWORD *))(*this + 4))(this)
              || (v31 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this) - v47 - v46, v31 <= 0) )
            {
              v32 = v50;
            }
            else
            {
              v28 += v31;
              v32 = v31 + v50;
              v30 -= v31;
            }
            if ( v30 >= (*(int (__thiscall **)(_DWORD *))(*this + 12))(this) - v32 )
              v30 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this) - v32;
            if ( v30 > 0 && v49 > 0 )
            {
              v34 = sub_4DDFE0(&unk_B6E2A0, v33);
              sub_4D5E10(this, v48[1], v28, v52, v34, v32, v54, v30);
            }
            v17 = v45;
          }
          v16 = v46;
        }
      }
      v45 = ++v17;
      if ( v17 > this[213] - 1 )
      {
        v45 = 0;
        v17 = 0;
      }
      v16 += this[214];
    }
    if ( this[61] )
      v35 = (int *)sub_4E29F0(this[33]);
    else
      v35 = 0;
    v36 = this[34];
    if ( v36 > 0 )
    {
      do
      {
        if ( v35 )
          v35 = (int *)v35[9];
        --v36;
      }
      while ( v36 );
    }
    if ( v35 )
    {
      *a4 = this[3];
      v37 = this[1];
      *a2 = v37;
      v38 = v35[7];
      v39 = v35[1] - *v35;
      v40 = *(_DWORD *)(v38 + 20);
      v41 = *(_DWORD *)(v38 + 24);
      if ( v39 > v40 )
        v39 = v40;
      v44 = v39;
      v43 = *a4;
      v42 = sub_4DDFE0(&unk_B6E2A0, v41);
      sub_4D5E10(this, v35[7], *v35, v35[2], v42, v43, v37, v44);
    }
    return 0;
  }
  return result;
}
