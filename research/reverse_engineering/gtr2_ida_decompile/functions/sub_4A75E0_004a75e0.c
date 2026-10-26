int __thiscall sub_4A75E0(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // ebx
  int v11; // esi
  int v12; // edx
  int v13; // ebp
  int v14; // eax
  int v15; // ecx
  int v16; // esi
  int v17; // edx
  int v18; // eax
  int v19; // ebp
  int v20; // ebx
  int v21; // eax
  int v22; // eax
  int v23; // ebp
  int v24; // eax
  unsigned __int64 v25; // rax
  int v26; // edx
  int v27; // eax
  int v28; // edx
  int v29; // eax
  int v30; // eax
  float v32; // [esp+0h] [ebp-9Ch]
  int v33; // [esp+14h] [ebp-88h]
  int v34; // [esp+18h] [ebp-84h]
  int v35; // [esp+1Ch] [ebp-80h]
  int v36; // [esp+24h] [ebp-78h] BYREF
  float v37; // [esp+28h] [ebp-74h]
  float v38; // [esp+2Ch] [ebp-70h]
  int v39; // [esp+30h] [ebp-6Ch]
  int v40; // [esp+38h] [ebp-64h]
  int v41; // [esp+3Ch] [ebp-60h]
  int v42; // [esp+40h] [ebp-5Ch]
  _DWORD v43[22]; // [esp+44h] [ebp-58h] BYREF

  sub_4CE5F0(a2, a3, a4, a5);
  v6 = sub_4E0080(this[12], "G_Folder0000.bmp", 0, 0, 1, 0, 0, 0, 0);
  v7 = this[12];
  v43[9] = v6;
  v8 = sub_4E0080(v7, "G_Folder0100.bmp", 0, 0, 1, 0, 0, 0, 0);
  v9 = this[135];
  v10 = this[133];
  v11 = this[136];
  v12 = this[1];
  v13 = this[3];
  v43[0] = v8;
  v14 = this[145];
  v15 = v12 + v10 + v9;
  v16 = v13 + this[134] + v11;
  v17 = 0;
  v43[7] = v16;
  v42 = v15;
  v41 = 0;
  if ( v14 > 0 )
  {
    while ( 1 )
    {
      v18 = v17 + this[139];
      if ( v18 > this[37] )
        break;
      v19 = v43[0];
      v20 = v15 + v17 * this[142];
      if ( v18 != this[146] )
        v19 = v43[1];
      if ( v19 )
      {
        v21 = *(_DWORD *)(v19 + 20);
        v37 = 0.0;
        v36 = 0;
        v35 = v21;
        v22 = sub_4DDFE0(&unk_B6E2A0, v17);
        sub_4D5E10(this, v19, 0, 0, v22, v16, v20, v35);
      }
      if ( *((_BYTE *)this + 596) )
      {
        sub_4DE540(v43, &v36);
        v23 = v20 + this[142];
        v41 = v23;
        if ( v43[0] > v16 )
        {
          v24 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
          if ( v43[0] < v24 && v36 > v20 && v36 < v23 )
          {
            v25 = (unsigned __int64)((double)((*(int (__thiscall **)(_DWORD *))(*this + 4))(this) - v16) * 0.75);
            v37 = *(float *)&v25;
            v42 = v16;
            v39 = v16 + v25;
            if ( v16 < v16 + (int)v25 )
            {
              v38 = (float)v40;
              v37 = (float)SLODWORD(v37);
              do
              {
                v32 = ((double)v42 - v38) / v37;
                v42 = sub_499940(255, (int)byte_FFFFFF, v32);
                v27 = sub_4DDFE0(&unk_B6E2A0, v26);
                sub_4DDDB0(v16, v20, v16 + 3, v20, v42, v27);
                v29 = sub_4DDFE0(&unk_B6E2A0, v28);
                sub_4DDDB0(v16, v41, v16 + 3, v41, v42, v29);
                v16 += 3;
                v42 = v16;
              }
              while ( v16 < v39 );
              v23 = v41;
              v16 = v40;
            }
            v30 = sub_4DDFE0(&unk_B6E2A0, HIDWORD(v25));
            sub_4DDDB0(v16, v20, v16, v23, 255, v30);
          }
        }
      }
      v17 = ++v33;
      if ( v33 >= this[145] )
        break;
      v15 = v34;
    }
  }
  *((_BYTE *)this + 596) = 0;
  return 0;
}
