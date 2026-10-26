int __thiscall sub_49CF90(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // ebx
  int v11; // edi
  int v12; // edx
  int v13; // ebp
  int v14; // eax
  int v15; // ecx
  int v16; // edi
  int v17; // edx
  int v18; // eax
  float v19; // ebx
  int v20; // ebp
  int v21; // eax
  int v22; // eax
  int v23; // ebx
  int v24; // eax
  int v25; // eax
  int v26; // ebx
  int v27; // edi
  int v28; // ebp
  int v29; // edi
  int v30; // ebx
  int v31; // eax
  int v32; // edx
  int v33; // eax
  int v34; // edx
  int v35; // eax
  int v36; // edx
  int v37; // eax
  int v39; // [esp+0h] [ebp-88h]
  int v40; // [esp+4h] [ebp-84h]
  int v41; // [esp+8h] [ebp-80h]
  int v42; // [esp+10h] [ebp-78h] BYREF
  int v43; // [esp+14h] [ebp-74h]
  int v44; // [esp+18h] [ebp-70h]
  int v45; // [esp+1Ch] [ebp-6Ch]
  float v46; // [esp+24h] [ebp-64h]
  int v47; // [esp+28h] [ebp-60h] BYREF
  int v48; // [esp+2Ch] [ebp-5Ch]
  float v49; // [esp+30h] [ebp-58h]
  float v50; // [esp+34h] [ebp-54h]
  int v51; // [esp+54h] [ebp-34h]

  sub_4CE5F0(a2, a3, a4, a5);
  v6 = sub_4E0080(this[12], "G_Folder0000.bmp", 0, 0, 1, 0, 0, 0, 0);
  v7 = this[12];
  v51 = v6;
  *(float *)&v8 = COERCE_FLOAT(sub_4E0080(v7, "G_Folder0100.bmp", 0, 0, 1, 0, 0, 0, 0));
  v9 = this[135];
  v10 = this[133];
  v11 = this[136];
  v12 = this[1];
  v13 = this[3];
  v49 = *(float *)&v8;
  v14 = this[145];
  v15 = v12 + v10 + v9;
  v16 = v13 + this[134] + v11;
  v17 = 0;
  v51 = v16;
  v48 = v15;
  v47 = 0;
  if ( v14 > 0 )
  {
    while ( 1 )
    {
      v18 = v17 + this[139];
      if ( v18 > this[37] )
        break;
      v19 = v49;
      v20 = v15 + v17 * this[142];
      if ( v18 != this[146] )
        v19 = v50;
      if ( v19 != 0.0 )
      {
        v21 = *(_DWORD *)(LODWORD(v19) + 20);
        v43 = 0;
        v42 = 0;
        v41 = v21;
        v22 = sub_4DDFE0(&unk_B6E2A0, v17);
        sub_4D5E10(this, LODWORD(v19), 0, 0, v22, v16, v20, v41);
      }
      if ( *((_BYTE *)this + 596) )
      {
        v46 = (double)*(int *)dword_903EB8 * 0.00125;
        v49 = (double)dword_903EBC * 0.0016666667;
        sub_4DE540(&v47, &v42);
        v23 = v20 + this[142];
        v44 = v23;
        if ( v47 > v16 )
        {
          v24 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
          if ( v47 < v24 && v42 > v20 && v42 < v23 )
          {
            v25 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
            v26 = this[1];
            v45 = v25 - v16;
            v27 = 1 - v26 + sub_4CFD30(2);
            v43 = v27 + v20;
            v44 += v27;
            v28 = (unsigned __int64)((double)(v27 + v20) * v49);
            v29 = (unsigned __int64)((double)v44 * v49);
            v30 = (unsigned __int64)((double)v48 * v46);
            LODWORD(v49) = (unsigned __int64)((double)(v48 + v45) * v46);
            v31 = sub_4DDFE0(&unk_B6E2A0, (unsigned __int64)((double)(v48 + v45) * v46) >> 32);
            sub_4DDDB0(v30, v28, LODWORD(v49), v28, dword_FF0000, v31);
            v33 = sub_4DDFE0(&unk_B6E2A0, v32);
            sub_4DDDB0(v30, v29, LODWORD(v49), v29, dword_FF0000, v33);
            v35 = sub_4DDFE0(&unk_B6E2A0, v34);
            sub_4DDDB0(v30, v28, v30, v29, dword_FF0000, v35);
            v37 = sub_4DDFE0(&unk_B6E2A0, v36);
            sub_4DDDB0(LODWORD(v49), v28, LODWORD(v49), v29, dword_FF0000, v37);
            v16 = v48;
          }
        }
      }
      v17 = ++v39;
      if ( v39 >= this[145] )
        break;
      v15 = v40;
    }
  }
  *((_BYTE *)this + 596) = 0;
  return 0;
}
