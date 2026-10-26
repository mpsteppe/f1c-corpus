int __thiscall sub_661E5C(unsigned int *this, _DWORD *a2, unsigned int a3, _DWORD *a4, _DWORD *a5)
{
  unsigned int v5; // kr00_4
  __int32 v6; // ebp
  int *v7; // ebp
  int result; // eax
  _DWORD *v10; // ecx
  _DWORD *v11; // eax
  int v12; // edi
  unsigned int v13; // eax
  _DWORD *v14; // eax
  _DWORD *v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  HMODULE ModuleHandleA; // eax
  int (*Direct3DShaderValidatorCreate9)(void); // eax
  int v20; // eax
  _DWORD *v21; // ecx
  unsigned int v22; // eax
  _DWORD *v23; // eax
  _DWORD *v24; // eax
  __int32 v25[4]; // [esp+0h] [ebp-20h] BYREF
  _DWORD v26[3]; // [esp+10h] [ebp-10h] BYREF
  int v27; // [esp+1Ch] [ebp-4h] BYREF
  int _20; // [esp+20h] [ebp+0h] BYREF

  v7 = &_20;
  if ( (a3 & 0xFFFFFF3C) != 0 )
    return -2005530516;
  if ( !a5 )
    return -2005530516;
  *a5 = 0;
  j__free((void *)this[22]);
  v10 = (_DWORD *)this[30];
  if ( v10 )
    sub_660C49(v10, 1);
  dword_FB9E40 = (int)this;
  this[14] = -1;
  *this = (unsigned int)(a2 + 6);
  this[15] = a3;
  v25[0] = 0;
  this[1] = (unsigned int)a2;
  this[2] = 0;
  this[12] = 0;
  this[13] = 0;
  this[22] = 0;
  this[23] = 0;
  this[24] = 0;
  this[25] = 0;
  this[26] = 0;
  this[19] = 0;
  this[20] = 0;
  this[21] = 0;
  this[27] = 0;
  this[28] = 0;
  this[29] = 0;
  sub_65A048(a2, &v27, (_DWORD *)v25[0]);
  if ( !v27 )
    sub_65A077((_DWORD *)this[1], this + 27, this + 28);
  result = sub_65A004((_DWORD *)this[1], 2);
  if ( result >= 0 )
  {
    sub_660C6A((int)this);
    if ( this[4] == 9 && sub_6460B4((const char *)this[6], 1, v26) >= 0 )
    {
      v11 = (_DWORD *)v26[1];
      this[4] = 0;
      this[6] = (unsigned int)v11;
    }
    if ( this[4] )
    {
      sub_65DD1F((_DWORD *)*this, (int)(this + 4), 2001, "shader version expected");
      goto LABEL_15;
    }
    if ( this[6] == -130816 )
    {
      sub_65DDE6((_DWORD *)*this, (int)(this + 4), (const char *)0x7DF, "vs_1_0 is no longer supported; using vs_1_1");
      this[6] = -130815;
    }
    if ( this[6] == -65280 )
    {
      sub_65DDE6((_DWORD *)*this, (int)(this + 4), (const char *)0x7DF, "ps_1_0 is no longer supported; using ps_1_1");
      this[6] = -65279;
    }
    if ( this[6] == -65022 )
      this[6] = -65023;
    if ( (a3 & 0x40) != 0 && (this[6] & 0xFFFF0000) == 0xFFFE0000
      || (a3 & 0x80u) != 0 && (this[6] & 0xFFFF0000) == 0xFFFF0000 )
    {
      this[15] |= 1u;
    }
    v13 = this[6];
    if ( v13 > 0xFFFF0102 )
    {
      switch ( v13 )
      {
        case 0xFFFF0103:
          this[14] = 8;
          break;
        case 0xFFFF0104:
          this[14] = 9;
          break;
        case 0xFFFF0200:
          this[14] = 10;
          break;
        case 0xFFFF0201:
          this[14] = 11;
          break;
        case 0xFFFF02FF:
          this[14] = 12;
          break;
        case 0xFFFF0300:
          this[14] = 13;
          break;
        case 0xFFFF03FF:
          this[14] = 14;
          break;
        default:
          goto LABEL_51;
      }
    }
    else
    {
      switch ( v13 )
      {
        case 0xFFFF0102:
          this[14] = 7;
          break;
        case 0xFFFE0101:
          this[14] = 0;
          break;
        case 0xFFFE0200:
          this[14] = 1;
          break;
        case 0xFFFE0201:
          this[14] = 2;
          break;
        case 0xFFFE02FF:
          this[14] = 3;
          break;
        case 0xFFFE0300:
          this[14] = 4;
          break;
        case 0xFFFE03FF:
          this[14] = 5;
          break;
        case 0xFFFF0101:
          this[14] = 6;
          break;
        default:
LABEL_51:
          sub_65DD1F((_DWORD *)*this, (int)(this + 4), 2002, "unrecognized shader version");
          goto LABEL_15;
      }
    }
    if ( a4 )
    {
      this[15] |= 2u;
      v25[0] = (__int32)&_20;
      v5 = __readeflags();
      v6 = __ROR4__(dword_16C6F24, 255);
      __writeeflags(v5);
      v7 = (int *)_InterlockedExchange(v25, v6);
      this[31] = (unsigned int)a4;
      v14 = operator new(v25[0]);
      if ( v14 )
        v15 = sub_66081B(v14, this[14]);
      else
        v15 = 0;
      this[30] = (unsigned int)v15;
      if ( !v15 )
        return -2147024882;
      v16 = this[14];
      if ( (unsigned int)v16 > 5 )
      {
        if ( v16 < 10 || v16 > 14 )
        {
          sub_65DD1F(
            (_DWORD *)*this,
            (int)(this + 4),
            2001,
            "only vs_1_1, vs_2_0, vs_2_x, vs_2_sw, ps_2_0, ps_2_x, and ps_2_sw are supported for assembly fragments");
          goto LABEL_72;
        }
        v17 = (unsigned int)&unk_7FFF00 | *((unsigned __int8 *)this + 25);
      }
      else
      {
        v17 = (unsigned int)&unk_7FFE00 | *((unsigned __int8 *)this + 25);
      }
      this[6] = (unsigned __int8)this[6] | (v17 << 8);
    }
LABEL_72:
    if ( (this[15] & 2) == 0 )
    {
      ModuleHandleA = GetModuleHandleA("d3d9.dll");
      if ( ModuleHandleA || (ModuleHandleA = LoadLibraryA("d3d9.dll")) != 0 )
      {
        Direct3DShaderValidatorCreate9 = GetProcAddress(ModuleHandleA, "Direct3DShaderValidatorCreate9");
        if ( Direct3DShaderValidatorCreate9 )
        {
          v20 = Direct3DShaderValidatorCreate9();
          this[2] = v20;
          if ( v20 )
          {
            v12 = (*(int (__stdcall **)(int, int (__stdcall *)(int, int, __int16, int, const char *, _DWORD **), unsigned int *, _DWORD))(*(_DWORD *)v20 + 12))(
                    v20,
                    sub_65ED28,
                    this,
                    0);
            if ( v12 < 0 )
              goto LABEL_98;
          }
        }
      }
    }
    v12 = sub_65F908(this, this[6]);
    if ( v12 < 0 )
      goto LABEL_98;
    v12 = sub_65F822(this, (int)(this + 4));
    if ( v12 < 0 )
      goto LABEL_98;
    if ( !this[19] )
    {
      if ( sub_661875() )
        this[19] = 1;
      if ( !this[19] )
      {
        if ( this[27] )
        {
          sub_65A077((_DWORD *)this[1], (unsigned int *)v7 + 3, 0);
          v21 = (_DWORD *)this[27];
          v22 = v7[3];
          if ( (unsigned int)v21 < v22 && (unsigned int)v21 + this[28] > v22 )
            this[28] = v22 - (_DWORD)v21;
        }
        if ( this[30] )
        {
          v12 = sub_660174(this);
          if ( v12 < 0 )
            goto LABEL_98;
        }
        if ( (this[15] & 1) != 0 )
        {
          v12 = sub_66040C((_DWORD **)this);
          if ( v12 < 0 )
            goto LABEL_98;
        }
        v12 = sub_65F908(this, 0xFFFF);
        if ( v12 < 0 )
          goto LABEL_98;
        v12 = sub_65F822(this, (int)(this + 4));
        if ( v12 < 0 )
          goto LABEL_98;
        v23 = (_DWORD *)this[2];
        if ( v23 )
        {
          v12 = (*(int (__stdcall **)(unsigned int))(*v23 + 20))(this[2]);
          if ( v12 < 0 )
            goto LABEL_98;
        }
        if ( !sub_65D7E1((_DWORD *)*this) )
        {
          v12 = sub_660732((int)this, (_DWORD *)v7[5]);
          if ( v12 >= 0 )
          {
            v12 = 0;
            goto LABEL_100;
          }
LABEL_98:
          this[19] = 1;
LABEL_100:
          v24 = (_DWORD *)this[2];
          if ( v24 )
          {
            (*(void (__stdcall **)(unsigned int))(*v24 + 8))(this[2]);
            this[2] = 0;
          }
          sub_65D529((_DWORD *)this[1]);
          return v12;
        }
      }
    }
LABEL_15:
    v12 = -2005529767;
    goto LABEL_98;
  }
  return result;
}
