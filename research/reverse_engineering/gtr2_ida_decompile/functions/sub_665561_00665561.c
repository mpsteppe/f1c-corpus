int __thiscall sub_665561(_DWORD *this, unsigned int a2, _DWORD *a3, int a4, int a5, int a6)
{
  bool v7; // zf
  int v8; // edi
  int v9; // eax
  int v11; // eax
  int v12; // eax
  char *v13; // eax
  unsigned int i; // ecx
  unsigned int v15; // edx
  int v16; // edx
  _DWORD *v17; // eax
  unsigned int v18; // ecx
  int v19; // [esp-Ch] [ebp-CCh]
  int v20; // [esp-Ch] [ebp-CCh]
  int v21; // [esp+14h] [ebp-ACh]
  unsigned int v22; // [esp+18h] [ebp-A8h]
  unsigned int v23; // [esp+1Ch] [ebp-A4h]
  unsigned int v24; // [esp+20h] [ebp-A0h]
  int v25; // [esp+24h] [ebp-9Ch]
  int v26; // [esp+28h] [ebp-98h]
  unsigned int v27; // [esp+2Ch] [ebp-94h]
  unsigned int v28; // [esp+30h] [ebp-90h]
  int v29; // [esp+34h] [ebp-8Ch]
  unsigned int v30; // [esp+38h] [ebp-88h]
  int v31; // [esp+3Ch] [ebp-84h]
  int v32; // [esp+40h] [ebp-80h]
  _DWORD *v33; // [esp+44h] [ebp-7Ch]
  _DWORD *v34; // [esp+48h] [ebp-78h]
  _DWORD *v35; // [esp+4Ch] [ebp-74h]
  _DWORD *v36; // [esp+50h] [ebp-70h]
  int v37; // [esp+54h] [ebp-6Ch]
  _DWORD *v38; // [esp+58h] [ebp-68h]
  _DWORD *v39; // [esp+5Ch] [ebp-64h]
  _DWORD *v40; // [esp+60h] [ebp-60h]
  _DWORD *v41; // [esp+64h] [ebp-5Ch]
  _DWORD *v42; // [esp+68h] [ebp-58h]
  _DWORD *v43; // [esp+6Ch] [ebp-54h]
  _DWORD *v44; // [esp+70h] [ebp-50h]
  _DWORD *v45; // [esp+74h] [ebp-4Ch]
  _DWORD *v46; // [esp+78h] [ebp-48h]
  int v47; // [esp+7Ch] [ebp-44h]
  int v48; // [esp+80h] [ebp-40h]
  _DWORD *v49; // [esp+84h] [ebp-3Ch]
  _DWORD *v50; // [esp+88h] [ebp-38h]
  _DWORD *v51; // [esp+8Ch] [ebp-34h]
  unsigned int v52; // [esp+90h] [ebp-30h]
  _DWORD *v53; // [esp+94h] [ebp-2Ch]
  unsigned int v54; // [esp+98h] [ebp-28h]
  unsigned int v55; // [esp+9Ch] [ebp-24h]
  unsigned int v56; // [esp+A0h] [ebp-20h]
  unsigned int v57; // [esp+A4h] [ebp-1Ch]
  unsigned int v58; // [esp+A8h] [ebp-18h]
  unsigned int v59; // [esp+ACh] [ebp-14h]
  void *Block; // [esp+B0h] [ebp-10h]
  int v61; // [esp+B4h] [ebp-Ch]
  int v62; // [esp+B8h] [ebp-8h]
  int v63; // [esp+BCh] [ebp-4h]
  int v64; // [esp+D8h] [ebp+18h]

  v7 = (*(_BYTE *)(this[2] + 109) & 2) == 0;
  Block = 0;
  if ( v7 )
  {
    v11 = sub_681AAA(*(_DWORD *)(this[2] + 120), 0, 0, -0.0187293);
    v19 = *(_DWORD *)(this[2] + 120);
    v61 = v11;
    v12 = sub_681AAA(v19, 0, 0, 0.07426099999999999);
    v20 = *(_DWORD *)(this[2] + 120);
    v62 = v12;
    v21 = sub_681AAA(v20, 0, 0, -0.2121144);
    v31 = sub_681AAA(*(_DWORD *)(this[2] + 120), 0, 0, 1.5707288);
    v26 = sub_681AAA(*(_DWORD *)(this[2] + 120), 0, 0, -2.0);
    v29 = sub_681AAA(*(_DWORD *)(this[2] + 120), 0, 0, 3.141592741012573);
    v25 = sub_681AAA(*(_DWORD *)(this[2] + 120), 0, 0, 1.570796370506287);
    v13 = (char *)operator new(112 * a6);
    Block = v13;
    if ( v13 )
    {
      for ( i = 0; i < 0x1C; ++i )
      {
        *(&v32 + i) = (int)v13;
        v13 += 4 * a6;
      }
      v15 = 0;
      while ( 1 )
      {
        v8 = sub_6624CC((void *)*(&v32 + v15), a6);
        if ( v8 < 0 )
          break;
        v15 = v16 + 1;
        if ( v15 >= 0x14 )
        {
          if ( a6 )
          {
            v17 = v53;
            v28 = v54 - (_DWORD)v53;
            v22 = v55 - (_DWORD)v53;
            v24 = v56 - (_DWORD)v53;
            v30 = v57 - (_DWORD)v53;
            v27 = v58 - (_DWORD)v53;
            v18 = v52 - (_DWORD)v53;
            v23 = v59 - (_DWORD)v53;
            v63 = a6;
            do
            {
              *(_DWORD *)((char *)v17 + v18) = this[8];
              *v17 = v61;
              *(_DWORD *)((char *)v17 + v28) = v62;
              *(_DWORD *)((char *)v17 + v22) = v21;
              *(_DWORD *)((char *)v17 + v24) = v31;
              *(_DWORD *)((char *)v17 + v30) = v26;
              *(_DWORD *)((char *)v17 + v27) = v29;
              *(_DWORD *)((char *)v17++ + v23) = v25;
              --v63;
            }
            while ( v63 );
          }
          v63 = a6 & 0xFFFFF | 0x10100000;
          v64 = a6 & 0xFFFFF;
          v8 = sub_6641F3(this, a2, v63, v32, a3, 0);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v64 | 0x20100000, (int)v33, a3, (unsigned int)v32 | 0x400000000LL);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v63, (int)v34, v33, 0x800000000LL);
          if ( v8 < 0 )
            break;
          v62 = v64 | 0x20400000;
          v8 = sub_6641F3(this, a2, v64 | 0x20400000, (int)v35, v34, v52);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v64 | 0x10700000, (int)v36, v35, 0x400000000LL);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v64 | 0x10300000, v37, v36, 0x400000000LL);
          if ( v8 < 0 )
            break;
          v61 = v64 | 0x20500000;
          v8 = sub_6641F3(this, a2, v64 | 0x20500000, (int)v38, v53, (unsigned int)v33);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v62, (int)v39, v38, v54);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v61, (int)v40, v39, (unsigned int)v33);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v62, (int)v41, v40, v55);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v61, (int)v42, v41, (unsigned int)v33);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v62, (int)v43, v42, v56);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v61, (int)v44, v43, (unsigned int)v37);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v61, (int)v45, v44, v57);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v62, (int)v46, v45, v58);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v64 | 0x20200000, v47, a3, (unsigned int)v32 | 0x1700000000LL);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v61, v48, v46, (unsigned int)v47);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v62, (int)v49, v44, (unsigned int)v48 | 0x400000000LL);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v63, (int)v50, v49, 0x800000000LL);
          if ( v8 < 0 )
            break;
          v8 = sub_6641F3(this, a2, v62, (int)v51, v50, v59);
          if ( v8 < 0 )
            break;
          if ( a4 )
          {
            v8 = sub_6641F3(this, a2, v64 | 0x10000000, a4, v51, 0);
            if ( v8 < 0 )
              break;
          }
          if ( !a5 )
            goto LABEL_7;
          v9 = sub_6641F3(this, a2, v64 | 0x10000000, a5, v49, 0x400000000LL);
          goto LABEL_6;
        }
      }
    }
    else
    {
      v8 = -2147024882;
    }
  }
  else if ( !a4 || (v8 = sub_6641F3(this, a2, a6 & 0xFFFFF | 0x10A00000, a4, a3, 0), v8 >= 0) )
  {
    if ( !a5 )
      goto LABEL_7;
    v9 = sub_6641F3(this, a2, a6 & 0xFFFFF | 0x10B00000, a5, a3, 0x400000000LL);
LABEL_6:
    v8 = v9;
    if ( v9 >= 0 )
LABEL_7:
      v8 = 0;
  }
  j__free(Block);
  return v8;
}
