void __thiscall sub_4839A0(_DWORD *this)
{
  _DWORD *v1; // edi
  LRESULT (__stdcall *v2)(HWND, int, UINT, WPARAM, LPARAM); // esi
  LRESULT v3; // ebx
  signed int v4; // ebp
  int v5; // edi
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  int v8; // eax
  int v9; // edx
  int v10; // eax
  char v11; // al
  int v12; // eax
  LRESULT v13; // eax
  int v14; // ecx
  LRESULT v15; // eax
  int v16; // ecx
  LRESULT v17; // eax
  int v18; // ecx
  LRESULT v19; // eax
  int v20; // ecx
  LRESULT v21; // eax
  double v22; // st7
  int v23; // ecx
  unsigned __int8 v25; // c0
  unsigned __int8 v26; // c2
  int v27; // eax
  char v28; // cl
  char v29; // cl
  LRESULT v30; // eax
  int v31; // ecx
  int v32; // eax
  LRESULT v33; // eax
  int v34; // ecx
  LPARAM *v35; // [esp-4h] [ebp-3ECh]
  int v36; // [esp+0h] [ebp-3E8h]
  unsigned int v37; // [esp+4h] [ebp-3E4h] BYREF
  int v38; // [esp+8h] [ebp-3E0h]
  _DWORD v39[2]; // [esp+Ch] [ebp-3DCh] BYREF
  _DWORD v40[5]; // [esp+14h] [ebp-3D4h] BYREF
  char v41; // [esp+2Bh] [ebp-3BDh]
  char v42[256]; // [esp+CCh] [ebp-31Ch] BYREF
  LPARAM v43[67]; // [esp+1CCh] [ebp-21Ch] BYREF
  LPARAM lParam[66]; // [esp+2D8h] [ebp-110h] BYREF
  int v45; // [esp+3E0h] [ebp-8h]

  v1 = this;
  v40[0] = this;
  sub_409FB0(this);
  v2 = SendDlgItemMessageA;
  v3 = SendDlgItemMessageA(hWnd, 1003, 0x18Bu, 0, 0);
  v4 = 0;
  if ( v3 > 0 )
  {
    do
    {
      if ( v2(hWnd, 1003, 0x189u, v4, (LPARAM)lParam) != -1 )
      {
        v35 = lParam;
        v5 = sub_53B760(&unk_BE1CFD);
        if ( v5 )
        {
          v6 = operator new(8u);
          v7 = v6;
          v39[0] = v6;
          v45 = 0;
          if ( v6 )
          {
            *v6 = 0;
            v6[1] = -1;
            sub_615860(v5 + 260);
          }
          else
          {
            v7 = 0;
          }
          v45 = -1;
          sub_5FDFB0(v7, 1);
          v2 = SendDlgItemMessageA;
        }
      }
      ++v4;
    }
    while ( v4 < v3 );
    v1 = (_DWORD *)v39[1];
  }
  v1[2] = *v1;
  sub_4744E0(v40);
  v45 = 1;
  if ( (unsigned __int8)sub_473900() )
  {
    switch ( *(_DWORD *)dword_B6CE7C )
    {
      case 1:
      case 2:
        goto LABEL_16;
      case 3:
        v8 = 3;
        break;
      case 4:
        v8 = 4;
        break;
      case 5:
        if ( ::lParam < dword_B6CEAC )
          goto LABEL_18;
        if ( ::lParam >= (dword_B6CEB0 + dword_B6CEB4) / 2 )
          v8 = (::lParam >= 10000) + 3;
        else
LABEL_16:
          v8 = 2;
        break;
      default:
LABEL_18:
        v8 = 1;
        break;
    }
    v9 = dword_B73224;
    dword_B7321C = v8;
    if ( v8 < dword_B73224 || (v9 = dword_B73228, v8 > dword_B73228) )
      dword_B7321C = v9;
    v10 = dword_B7362C;
    dword_B73624 = ::lParam;
    if ( ::lParam < dword_B7362C || (v10 = dword_B73630, ::lParam > dword_B73630) )
      dword_B73624 = v10;
    v11 = byte_B73512;
    byte_B73510 = 1;
    if ( (unsigned __int8)byte_B73512 > 1u || (v11 = byte_B73513) == 0 )
      byte_B73510 = v11;
    v12 = dword_B7231C;
    *(_DWORD *)dword_B72314 = 5;
    if ( dword_B7231C > 5 || (v12 = dword_B72320, dword_B72320 < 5) )
      *(_DWORD *)dword_B72314 = v12;
    v13 = v2(dword_B6CE78, 1028, 0x147u, 0, 0);
    if ( (unsigned int)v13 <= 2 )
    {
      v14 = dword_B70590;
      dword_B70588 = v13;
      if ( v13 < dword_B70590 || (v14 = dword_B70594, v13 > dword_B70594) )
        dword_B70588 = v14;
    }
    v15 = v2(dword_B6CE78, 1029, 0x147u, 0, 0);
    v16 = dword_B72EC4;
    dword_B72EBC = v15;
    if ( v15 < dword_B72EC4 || (v16 = dword_B72EC8, v15 > dword_B72EC8) )
      dword_B72EBC = v16;
    v17 = v2(dword_B6CE78, 1030, 0x147u, 0, 0);
    v18 = dword_B73008;
    dword_B73000 = v17;
    if ( v17 < dword_B73008 || (v18 = dword_B7300C, v17 > dword_B7300C) )
      dword_B73000 = v18;
    v19 = v2(dword_B6CE78, 1031, 0x147u, 0, 0);
    v20 = dword_B6FE28;
    dword_B6FE20 = v19;
    if ( v19 < dword_B6FE28 || (v20 = dword_B6FE2C, v19 > dword_B6FE2C) )
      dword_B6FE20 = v20;
    v21 = v2(dword_B6CE78, 1032, 0x147u, 0, 0);
    v22 = 0.0;
    v38 = v21;
    if ( v21 )
    {
      if ( v21 == 11 )
      {
        v23 = 0;
      }
      else
      {
        v23 = 2;
        v22 = (double)v38 * 0.1;
      }
    }
    else
    {
      v23 = 1;
    }
    flt_B70858 = v22;
    if ( v25 | v26 )
    {
      flt_B70858 = flt_B70860;
    }
    else if ( v22 > flt_B70864 )
    {
      flt_B70858 = flt_B70864;
    }
    v27 = dword_B706D4;
    dword_B706CC = v23;
    if ( v23 < dword_B706D4 || (v27 = dword_B706D8, v23 > dword_B706D8) )
      dword_B706CC = v27;
    sub_50F030(&byte_B6F530, dword_B6CE84, v40, v35);
    sub_501DE0(7, byte_759E64);
    sub_501DE0(8, byte_759E65);
    sub_501DE0(1, byte_759E66);
    sub_501DE0(0, byte_759E67);
    sub_501DE0(2, byte_759E68);
    sub_501DE0(5, byte_B6CE94);
    sub_501DE0(9, byte_759E69);
    sub_501DE0(3, byte_759E6A);
    sub_501DE0(4, byte_759E6B);
    sub_501DE0(10, byte_759E6C);
    v28 = byte_B7352A;
    byte_B73528 = byte_B6CE96;
    if ( (unsigned __int8)byte_B6CE96 < (unsigned __int8)byte_B7352A
      || (v28 = byte_B7352B, (unsigned __int8)byte_B6CE96 > (unsigned __int8)byte_B7352B) )
    {
      byte_B73528 = v28;
    }
    v29 = byte_B73572;
    byte_B73570 = byte_759E6D;
    if ( (unsigned __int8)byte_759E6D < (unsigned __int8)byte_B73572
      || (v29 = byte_B73573, (unsigned __int8)byte_759E6D > (unsigned __int8)byte_B73573) )
    {
      byte_B73570 = v29;
    }
    v30 = v2(hWnd, 1201, 0x400u, 0, 0);
    v31 = dword_B733C8;
    v32 = v30 + 1;
    dword_B733C0 = v32;
    if ( v32 < dword_B733C8 || (v31 = dword_B733CC, v32 > dword_B733CC) )
      dword_B733C0 = v31;
    v33 = v2(dword_B6CE78, 1199, 0x400u, 0, 0);
    v34 = dword_B71DF4;
    dword_B71DEC = v33;
    if ( v33 < dword_B71DF4 || (v34 = dword_B71DF8, v33 > dword_B71DF8) )
      dword_B71DEC = v34;
    sub_477E20();
    memset(v42, 0, sizeof(v42));
    v2(dword_B6CE78, 1024, 0xDu, 0x100u, (LPARAM)v42);
    v37 = strlen(v42);
    if ( v37 )
    {
      sub_630FE0(v39, v42, 31);
    }
    else
    {
      v37 = strlen((const char *)v39);
      if ( v37 )
      {
LABEL_73:
        memset(v43, 0, 256);
        v2(dword_B6CE78, 1025, 0xDu, 0x100u, (LPARAM)v43);
        sub_473A20();
        sub_474770();
        *(_DWORD *)(v36 + 868) = (*(_DWORD *)(v36 + 868) != 0) + 1;
        sub_481D60((const CHAR ****)v36);
        goto LABEL_74;
      }
      sub_630FE0(v39, "My Server", 31);
    }
    v41 = 0;
    goto LABEL_73;
  }
LABEL_74:
  lParam[62] = -1;
  nullsub_7(&v37);
}
