int __thiscall sub_6C5CC7(_DWORD *this, int a2, unsigned int *a3, _DWORD *a4)
{
  int v4; // edi
  int v5; // eax
  bool v7; // zf
  int v8; // ecx
  unsigned int v9; // eax
  bool v10; // cf
  unsigned int v11; // ecx
  int v12; // ecx
  int result; // eax
  int v14; // ecx
  int v15; // ecx
  unsigned int v16; // eax
  unsigned int *v17; // ecx
  char *v18; // [esp-4h] [ebp-18h]
  unsigned int v19; // [esp+Ch] [ebp-8h] BYREF
  int v20; // [esp+10h] [ebp-4h]

  v4 = a2;
  v5 = *(_DWORD *)(a2 + 4);
  v7 = this[34] == v5;
  v8 = *(_DWORD *)(this[4] + 4 * v5);
  if ( v7 )
  {
    v9 = *(_DWORD *)(a2 + 12);
    a2 = 0;
    v10 = v9 < this[11];
    v19 = v9;
    if ( !v10 )
    {
      v18 = "maximum temp register index exceeded";
LABEL_4:
      sub_686791((int)this, *(_DWORD *)(this[64] + 60), 4505, v18);
      return -2005529767;
    }
    v11 = this[20];
    if ( v11 && v9 >= v11 )
    {
      v9 -= v11;
      v19 = v9;
      a2 = 3;
    }
    goto LABEL_16;
  }
  v12 = *(_DWORD *)(v8 + 4);
  if ( (v12 & 0x10) != 0 && (v12 & 4) != 0 )
  {
    a2 = 15;
    v9 = 0;
LABEL_11:
    v19 = v9;
    goto LABEL_16;
  }
  if ( (v12 & 0x10) != 0 && (v12 & 0x200) == 0 )
  {
    result = (*(int (__thiscall **)(_DWORD *, int, unsigned int *, int *))(*this + 136))(this, a2, &v19, &a2);
    if ( result < 0 )
      return result;
    LOWORD(v9) = v19;
    goto LABEL_16;
  }
  if ( (v12 & 0x200) != 0 && (v12 & 0x42080) == 0 )
  {
    v16 = *(_DWORD *)(a2 + 12);
    v10 = v16 < this[14];
    v19 = v16;
    if ( !v10 )
    {
      sub_686791(
        (int)this,
        *(_DWORD *)(this[64] + 60),
        4507,
        "maximum constant register index exceeded - Try reducing number of constants referenced");
      return -2005529767;
    }
    if ( v16 >= 0x800 )
    {
      if ( v16 >= 0x1000 )
        a2 = 13 - (v16 < 0x1800);
      else
        a2 = 11;
    }
    else
    {
      a2 = 2;
    }
    v9 = v16 & 0x7FF;
    goto LABEL_11;
  }
  if ( (v12 & 0x200) != 0 )
  {
    if ( (v12 & 0x80u) != 0 )
      goto LABEL_34;
    if ( (v12 & 0x2000) != 0 )
    {
      v9 = *(_DWORD *)(a2 + 12);
      v10 = v9 < this[24];
      v19 = v9;
      a2 = 14;
      if ( !v10 )
      {
        sub_686791((int)this, *(_DWORD *)(this[64] + 60), 4500, "maximum bool register index exceeded");
        return -2005529767;
      }
      goto LABEL_16;
    }
  }
  if ( (v12 & 0x80u) != 0 )
  {
LABEL_34:
    v9 = *(_DWORD *)(a2 + 12);
    v10 = v9 < this[19];
    a2 = 10;
    v19 = v9;
    if ( !v10 )
    {
      v18 = "maximum sampler register index exceeded";
      goto LABEL_4;
    }
    goto LABEL_16;
  }
  if ( (v12 & 0x40000) != 0 )
  {
    v9 = *(_DWORD *)(a2 + 12);
    v10 = v9 < this[16];
    a2 = 7;
    v19 = v9;
    if ( !v10 )
    {
      v18 = "maximum loop register index exceeded";
      goto LABEL_4;
    }
  }
  else
  {
    if ( this[36] != *(_DWORD *)(a2 + 4) )
    {
      sub_686791((int)this, 0, 0, "internal error: unexpected input register type");
      return -2147467259;
    }
    v9 = *(_DWORD *)(a2 + 12);
    v10 = v9 < this[13];
    a2 = 19;
    v19 = v9;
    if ( !v10 )
    {
      sub_686791((int)this, *(_DWORD *)(this[64] + 60), 4549, "maximum predicate register index exceeded");
      return -2005529767;
    }
  }
LABEL_16:
  v14 = *(_DWORD *)(v4 + 60);
  v20 = 0;
  v15 = v14 & 0x1F0000;
  switch ( v15 )
  {
    case 1048576:
      v20 = 184549376;
      break;
    case 1572864:
      v20 = 201326592;
      break;
    case 524288:
      v20 = (int)&dword_1000000;
      break;
    case 131072:
      v20 = (int)&dword_2000000;
      break;
    case 655360:
      v20 = 50331648;
      break;
    case 393216:
      v20 = 0x4000000;
      break;
    case 917504:
      v20 = 83886080;
      break;
    case 65536:
      v20 = 100663296;
      break;
    case 262144:
      v20 = 117440512;
      break;
    case 786432:
      v20 = 0x8000000;
      break;
  }
  v17 = a3;
  if ( a3 )
    *a3 = v20 | v9 & 0x7FF | ((a2 & 0x18 | ((a2 | 0xFFFFFFF8) << 20)) << 8);
  if ( a4 )
    *a4 = *(_DWORD *)(v4 + 8);
  if ( *(_DWORD *)(v4 + 8) == -1 )
    return 0;
  if ( this[85] )
  {
    *((_BYTE *)v17 + 1) |= 0x20u;
    return 0;
  }
  sub_686791((int)this, *(_DWORD *)(this[64] + 60), 4511, "target does not support relative addressing");
  return -2147467259;
}
