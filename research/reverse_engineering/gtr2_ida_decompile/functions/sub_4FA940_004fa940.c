char __thiscall sub_4FA940(_DWORD *this, float a2)
{
  int v3; // edi
  int v4; // edx
  unsigned int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // edi
  bool v10; // zf
  _BYTE *v11; // eax
  int v12; // eax
  float *v13; // ecx
  int v14; // ebx
  int v15; // ebp
  int v16; // edi
  int v17; // ecx
  char v18; // al
  _DWORD *v19; // ecx
  int v20; // ebx
  int v21; // ebp
  char v22; // al
  int v23; // ebp
  int v24; // edi
  _DWORD *v25; // ecx
  _DWORD *v26; // ecx
  int v27; // edi
  int v28; // edx
  _BYTE *v29; // eax
  float v31; // [esp+0h] [ebp-1Ch]
  float v32; // [esp+0h] [ebp-1Ch]
  float *v33; // [esp+18h] [ebp-4h]
  int v34; // [esp+18h] [ebp-4h]

  v3 = off_9034A4;
  if ( dword_82F4A0 < 1023 )
  {
    ++dword_82F4A0;
    off_9034A4 += 848;
  }
  v31 = dbl_FB1D18;
  sub_51B2A0(6, 6, 16, *(_DWORD *)(*this + 22468), LODWORD(v31), 1);
  v4 = 0;
  *(_DWORD *)(v3 + 8) = 0;
  if ( (this[3] & 1) != 0 )
    v5 = 0x80000000;
  else
    v5 = 0;
  *(_DWORD *)(v3 + 8) = v5;
  v6 = *(_DWORD *)(v3 + 8);
  if ( *(_BYTE *)(*this + 5753) )
    v7 = v6 | 1;
  else
    v7 = v6 & 0xFFFFFFFE;
  *(_DWORD *)(v3 + 8) = v7;
  if ( this[75] )
  {
    v8 = this[3];
    if ( (v8 & 1) != 0 )
    {
      if ( this[2] != 6 && (v8 & 8) != 0 )
      {
        v9 = this[72];
        v10 = v9 == 0;
        if ( v9 > 0 )
        {
          v11 = (_BYTE *)(this[73] + 160);
          do
          {
            if ( *(v11 - 152) && (v11[80] || *(_DWORD *)v11 && *(_DWORD *)(*(_DWORD *)v11 + 104) == 2) )
              break;
            ++v4;
            v11 += 768;
          }
          while ( v4 < this[72] );
          v10 = v4 == v9;
        }
        if ( v10 )
        {
          sub_4F8030(this, 8);
          this[2] = 6;
        }
      }
      switch ( this[2] )
      {
        case 0:
          v12 = this[74];
          if ( v12 && !*(_BYTE *)(v12 + 240) )
          {
            sub_4F8030(this, 1);
            this[2] = 1;
          }
          goto LABEL_27;
        case 1:
          if ( *(_DWORD *)(*this + 15576) == 2 )
          {
            v25 = (_DWORD *)this[74];
            if ( v25 )
            {
              if ( sub_4F1AB0(v25) < 5625.0 )
              {
                sub_4F8030(this, 2);
                this[2] = 2;
              }
            }
          }
          goto LABEL_27;
        case 2:
          if ( *(_DWORD *)(*this + 15576) == 3 )
          {
            sub_4F8030(this, 3);
            this[2] = 3;
          }
          goto LABEL_27;
        case 3:
          sub_4F8030(this, 4);
          this[2] = 4;
          goto LABEL_27;
        case 4:
          v26 = (_DWORD *)this[74];
          if ( (!v26 || sub_4F13F0(v26)) && *(_DWORD *)(*this + 15576) == 4 && sub_4F20F0(this) && sub_4F1D60(this) )
          {
            sub_4EE120(dword_B6F1C8, 80, *this);
            sub_4EE120(dword_B6F1C8, 56, *this);
            sub_4EE320(54, *this);
            sub_4F8030(this, 5);
            this[2] = 5;
          }
          goto LABEL_27;
        case 6:
          v27 = this[72];
          v28 = 0;
          if ( v27 > 0 )
          {
            v29 = (_BYTE *)(this[73] + 160);
            do
            {
              if ( *(v29 - 152) && (v29[80] || *(_DWORD *)v29 && *(_DWORD *)(*(_DWORD *)v29 + 104) == 3) )
                break;
              ++v28;
              v29 += 768;
            }
            while ( v28 < this[72] );
          }
          if ( v28 != v27 )
            goto LABEL_27;
          LOBYTE(v7) = sub_4F7EC0(this, 0, 1);
          return v7;
        default:
LABEL_27:
          if ( (this[3] & 2) != 0 )
          {
            v13 = (float *)(this + 7);
            v14 = 0;
            v33 = (float *)(this + 7);
            a2 = a2 - *((float *)this + 5);
            do
            {
              if ( *((float *)this + 6) < (double)*v13 && a2 >= (double)*v13 )
              {
                v15 = 0;
                if ( (int)this[72] > 0 )
                {
                  v16 = 0;
                  do
                  {
                    v17 = this[73];
                    v18 = *(_BYTE *)(v17 + v16 + 8);
                    v19 = (_DWORD *)(v16 + v17);
                    if ( v18 )
                      sub_4F7DD0(v19, v14);
                    ++v15;
                    v16 += 768;
                  }
                  while ( v15 < this[72] );
                  v13 = v33;
                }
              }
              ++v14;
              v33 = ++v13;
            }
            while ( v14 < 35 );
          }
          break;
      }
    }
    LOBYTE(v7) = byte_B6413C;
    if ( !byte_B6413C && dword_BE1204 != 2 )
    {
      LOBYTE(v7) = sub_521050(&dword_BE120C);
      if ( !(_BYTE)v7 )
      {
        v7 = this[72];
        v20 = 0;
        if ( v7 > 0 )
        {
          v34 = 0;
          do
          {
            v21 = this[73];
            v22 = *(_BYTE *)(v21 + v34 + 8);
            v23 = v34 + v21;
            if ( v22 )
            {
              v24 = off_9034A4;
              if ( dword_82F4A0 < 1023 )
              {
                ++dword_82F4A0;
                off_9034A4 += 848;
              }
              v32 = dbl_FB1D18;
              sub_51B2A0(6, 7, 16, *(_DWORD *)(*this + 22468), LODWORD(v32), 1);
              *(_DWORD *)(v24 + 8) = 0;
              *(_DWORD *)(v24 + 8) = v20 | *(_DWORD *)(v24 + 8) & 0xFFFFFFE0;
              sub_4F91E0(v23, v24, (float *)(v24 + 8));
            }
            v7 = this[72];
            ++v20;
            v34 += 768;
          }
          while ( v20 < v7 );
        }
        *((float *)this + 6) = a2;
      }
    }
  }
  return v7;
}
