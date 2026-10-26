void *__thiscall sub_6CA50D(int *this, _DWORD *a2)
{
  unsigned int v2; // kr00_4
  int v4; // edi
  int v5; // eax
  void *result; // eax
  int v7; // eax
  HMODULE ModuleHandleA; // eax
  int (*Direct3DShaderValidatorCreate9)(void); // eax
  int v10; // eax
  void *v11; // eax
  int v12; // eax
  unsigned int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // edi
  int v17; // ecx
  int *v18; // edi
  int v19; // eax
  int v20; // ecx
  unsigned int v21; // eax
  int v22; // edx
  _DWORD *v23; // eax
  int v24; // ecx
  _DWORD *v25; // edi
  _DWORD *v26; // edx
  unsigned int i; // eax
  int v28; // ecx
  _DWORD *v29; // edx
  unsigned int j; // esi
  int v31; // eax
  int v32; // ecx
  unsigned int v33; // eax
  unsigned int v34; // edi
  int *v35; // esi
  int v36; // eax
  int v37; // esi
  int v38; // eax
  int v39; // eax
  int v40; // edi
  int v41; // edx
  int v42; // ecx
  unsigned int v43; // edi
  size_t v44; // esi
  unsigned int v45; // ecx
  _DWORD *v46; // esi
  unsigned int m; // edi
  int v48; // eax
  int v49; // ecx
  size_t n; // ecx
  int v51; // edx
  int v52; // esi
  int v53; // edx
  int v54; // ecx
  int v55; // edi
  void *v56; // esi
  unsigned int v57; // edi
  size_t v58; // esi
  int v59; // edi
  int v60; // eax
  size_t v61; // esi
  bool v62; // zf
  int v63; // eax
  int v64; // esi
  _DWORD *v65; // edi
  unsigned int v66; // esi
  void **v67; // edi
  void **v68; // edi
  int v69; // ecx
  unsigned int v70; // esi
  _DWORD *v71; // eax
  int v72; // eax
  const void *v73; // esi
  void *v74; // edi
  _DWORD *v75; // ebx
  int v76; // [esp-14h] [ebp-8Ch]
  int v77; // [esp-10h] [ebp-88h]
  char *v78; // [esp-Ch] [ebp-84h]
  double v79; // [esp+0h] [ebp-78h] BYREF
  _DWORD *v80; // [esp+20h] [ebp-58h]
  char ArgList[4]; // [esp+30h] [ebp-48h] BYREF
  void *v82; // [esp+3Ch] [ebp-3Ch]
  unsigned int k; // [esp+40h] [ebp-38h] BYREF
  void *v84; // [esp+44h] [ebp-34h]
  void *v85; // [esp+48h] [ebp-30h]
  void *v86; // [esp+4Ch] [ebp-2Ch]
  void *v87; // [esp+50h] [ebp-28h]
  unsigned int v88; // [esp+54h] [ebp-24h]
  void *v89; // [esp+58h] [ebp-20h]
  void *v90; // [esp+5Ch] [ebp-1Ch]
  void *Block; // [esp+60h] [ebp-18h]
  void *v92; // [esp+64h] [ebp-14h]
  unsigned int v93; // [esp+68h] [ebp-10h]
  unsigned int v94; // [esp+6Ch] [ebp-Ch]
  int v95; // [esp+70h] [ebp-8h]
  size_t Size; // [esp+74h] [ebp-4h]

  v80 = a2;
  this[65] = 0;
  v93 = 0;
  v94 = 0;
  k = 0;
  v88 = 0;
  v84 = 0;
  v89 = 0;
  Block = 0;
  v92 = 0;
  v86 = 0;
  v82 = 0;
  v90 = 0;
  v87 = 0;
  v85 = 0;
  v4 = sub_694A16(this, v80);
  if ( v4 >= 0 )
  {
    v5 = sub_681A51(this, (int)&unk_739B00, 262929, -1, 4);
    this[97] = v5;
    if ( v5 == -1 )
    {
LABEL_3:
      v4 = -2147024882;
      goto LABEL_211;
    }
    result = (void *)(*(int (__thiscall **)(int *))(*this + 160))(this);
    if ( !result )
    {
      v7 = this[108];
      this[67] = 0;
      this[68] = 0;
      this[69] = 0;
      this[71] = 0;
      this[72] = 0;
      if ( v7 )
      {
        (*(void (__cdecl **)(int))(*(_DWORD *)v7 + 8))(v7);
        this[108] = 0;
      }
      if ( (this[51] & 2) == 0 )
      {
        ModuleHandleA = GetModuleHandleA("d3d9.dll");
        if ( ModuleHandleA || (ModuleHandleA = LoadLibraryA("d3d9.dll")) != 0 )
        {
          Direct3DShaderValidatorCreate9 = GetProcAddress(ModuleHandleA, "Direct3DShaderValidatorCreate9");
          if ( Direct3DShaderValidatorCreate9 )
          {
            v10 = Direct3DShaderValidatorCreate9();
            this[108] = v10;
            if ( v10 )
            {
              v4 = (*(int (__cdecl **)(int, int (__stdcall *)(int, int, __int16, int, const char *, int), int *, int))(*(_DWORD *)v10 + 12))(
                     v10,
                     sub_6C656F,
                     this,
                     1);
              if ( v4 < 0 )
                goto LABEL_211;
            }
          }
        }
      }
      if ( (this[51] & 1) != 0 )
      {
        v11 = operator new(48 * this[3]);
        this[73] = (int)v11;
        if ( !v11 )
          goto LABEL_3;
        v12 = 2 * this[3];
        this[74] = 0;
        this[75] = v12;
      }
      this[78] = -1;
      v13 = 0;
      v62 = this[2] == 0;
      this[83] = 0;
      if ( !v62 )
      {
        do
        {
          v14 = *(_DWORD *)(this[5] + 4 * v13++);
          *(_DWORD *)(v14 + 48) = 0;
        }
        while ( v13 < this[2] );
      }
      v62 = this[2] == 0;
      Size = 0;
      v95 = 0;
      if ( !v62 )
      {
        do
        {
          v15 = *(_DWORD *)(this[5] + 4 * v95);
          v16 = *(_DWORD *)(this[4] + 4 * *(_DWORD *)(v15 + 4));
          v17 = *(_DWORD *)(v16 + 4);
          if ( (v17 & 0x10) != 0 && (v17 & 0x200) == 0 || (v17 & 0x20) != 0 )
            (*(void (__thiscall **)(int *, int, _DWORD))(*this + 4))(this, v15, 0);
          if ( *(char *)(v16 + 4) < 0 )
            ++Size;
          ++v95;
        }
        while ( v95 < (unsigned int)this[2] );
      }
      if ( Size > this[19] )
      {
        result = (void *)sub_646152(this[50], 0, ArgList);
        if ( (int)result >= 0 )
        {
          if ( this[19] )
            result = (void *)sub_686791(
                               (int)this,
                               0,
                               4510,
                               "maximum number of samplers exceeded. %s target can have a maximum of %i samplers",
                               *(const char **)ArgList,
                               this[19]);
          else
            result = (void *)sub_686791(
                               (int)this,
                               0,
                               4545,
                               "%s target does not support texture lookups",
                               *(const char **)ArgList);
        }
        goto LABEL_215;
      }
      if ( (this[50] & 0xFFFF0000) == 0xFFFE0000 )
      {
        v4 = sub_6BBB22(this, this[32], this[10], 16, 516, 118);
        if ( v4 < 0 )
          goto LABEL_211;
      }
      if ( (this[50] & 0xFFFF0000) == 0xFFFF0000 )
      {
        v4 = sub_6BBB22(this, -1, this[19], 128, 0, 115);
        if ( v4 < 0 )
          goto LABEL_211;
      }
      if ( this[2] )
      {
        v18 = (int *)this[5];
        Block = (void *)this[2];
        do
        {
          v19 = *v18;
          v20 = *(_DWORD *)(*v18 + 4);
          if ( this[34] == v20 && *(_DWORD *)(v19 + 12) + 1 > k )
          {
            k = *(_DWORD *)(v19 + 12) + 1;
          }
          else if ( this[32] == v20 && *(_DWORD *)(v19 + 12) + 1 > v93 )
          {
            v93 = *(_DWORD *)(v19 + 12) + 1;
          }
          else if ( this[33] == v20 && *(_DWORD *)(v19 + 12) + 1 > v94 )
          {
            v94 = *(_DWORD *)(v19 + 12) + 1;
          }
          else if ( *(char *)(*(_DWORD *)(this[4] + 4 * v20) + 4) < 0 )
          {
            v21 = *(_DWORD *)(v19 + 12) + 1;
            if ( v21 > v88 )
              v88 = v21;
          }
          ++v18;
          Block = (char *)Block - 1;
        }
        while ( Block );
      }
      Size = 4 * v93;
      Block = operator new(4 * v93);
      if ( !Block )
        goto LABEL_3;
      k = 4 * v94;
      v92 = operator new(4 * v94);
      if ( !v92 )
        goto LABEL_3;
      v95 = 4 * v88;
      v86 = operator new(4 * v88);
      if ( !v86 )
        goto LABEL_3;
      v82 = operator new(Size);
      if ( !v82 )
        goto LABEL_3;
      v90 = operator new(4 * v94);
      if ( !v90 )
        goto LABEL_3;
      memset(Block, 0, Size);
      memset(v92, 0, k);
      memset(v86, 0, v95);
      v22 = 0;
      if ( this[2] )
      {
        while ( 1 )
        {
          v23 = *(_DWORD **)(this[5] + 4 * v22);
          v24 = v23[1];
          if ( this[33] == v24 )
            break;
          if ( this[32] == v24 )
          {
            if ( v23[27] == -1 )
            {
              HIDWORD(v79) = "internal error: input register missing semantic";
              goto LABEL_214;
            }
            v25 = Block;
            goto LABEL_64;
          }
          if ( *(char *)(*(_DWORD *)(this[4] + 4 * v24) + 4) < 0 )
          {
            v25 = v86;
LABEL_64:
            v25[v23[3]] = v23;
          }
          if ( ++v22 >= (unsigned int)this[2] )
            goto LABEL_66;
        }
        if ( v23[27] == -1 )
        {
          HIDWORD(v79) = "internal error: output register missing semantic";
          goto LABEL_214;
        }
        v25 = v92;
        goto LABEL_64;
      }
LABEL_66:
      v62 = this[2] == 0;
      v95 = 0;
      if ( !v62 )
      {
        do
        {
          v26 = *(_DWORD **)(this[5] + 4 * v95);
          if ( this[32] == v26[1] )
          {
            for ( i = 0; i < v93; ++i )
            {
              v28 = *((_DWORD *)Block + i);
              if ( v28 && v26[27] == *(_DWORD *)(v28 + 108) )
                v26[3] = i;
            }
          }
          ++v95;
        }
        while ( v95 < (unsigned int)this[2] );
      }
      v29 = Block;
      memset(Block, 0, Size);
      for ( j = 0; j < this[2]; ++j )
      {
        v31 = *(_DWORD *)(this[5] + 4 * j);
        v32 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v31 + 4)) + 4);
        if ( (v32 & 0x10) != 0 && (v32 & 0x204) == 0 )
          v29[*(_DWORD *)(v31 + 12)] = v31;
      }
      v33 = 0;
      for ( k = 0; v33 < v93; ++v33 )
      {
        if ( v29[v33] )
          ++k;
      }
      v4 = sub_6C714F(this);
      if ( v4 < 0 )
        goto LABEL_211;
      v4 = (*(int (__thiscall **)(int *))(*this + 44))(this);
      if ( v4 < 0 )
        goto LABEL_211;
      if ( (this[51] & 4) == 0 || (*((_BYTE *)this + 110) & 0x20) != 0 )
      {
        v4 = sub_6BC1A9(this);
        if ( v4 < 0 )
          goto LABEL_211;
        v4 = (*(int (__thiscall **)(int *))(*this + 40))(this);
        if ( v4 < 0 )
          goto LABEL_211;
      }
      if ( this[99] )
      {
        v95 = sub_681A51(this, (int)"l", 849, -1, 4);
        if ( v95 != -1 )
        {
          v34 = 0;
          v35 = this + 100;
          while ( 1 )
          {
            v36 = sub_681AAA(this, v95, v34 >> 2, v34 & 3, dbl_747B38[v34]);
            *v35 = v36;
            if ( v36 == -1 )
              break;
            ++v34;
            ++v35;
            if ( v34 >= 8 )
              goto LABEL_94;
          }
        }
        goto LABEL_3;
      }
LABEL_94:
      v4 = sub_6BBB22(this, this[31], this[14], 512, 270464, 99);
      if ( v4 < 0 )
        goto LABEL_211;
      v4 = sub_6BBB22(this, this[39], this[24], 8704, 128, 98);
      if ( v4 < 0 )
        goto LABEL_211;
      v4 = sub_6BBB22(this, this[44], this[16], 262656, 128, 105);
      if ( v4 < 0 )
        goto LABEL_211;
      v37 = 0;
      v62 = this[3] == 0;
      this[65] = 0;
      v38 = v62 ? 0 : *(_DWORD *)this[6];
      this[64] = v38;
      v39 = *this;
      this[63] = 0;
      v4 = (*(int (__thiscall **)(int *))(v39 + 56))(this);
      if ( v4 < 0 )
        goto LABEL_211;
      Size = 0;
      if ( this[2] )
      {
        v40 = this[4];
        v41 = this[5];
        v87 = (void *)this[2];
        do
        {
          v42 = *(_DWORD *)(*(_DWORD *)(v40 + 4 * *(_DWORD *)(*(_DWORD *)v41 + 4)) + 4);
          if ( (v42 & 0x100) != 0 && *(_DWORD *)(*(_DWORD *)v41 + 8) == -1 && ((v42 & 0x800) == 0 || this[86]) )
            ++v37;
          v41 += 4;
          v87 = (char *)v87 - 1;
        }
        while ( v87 );
      }
      v43 = 16 * v37;
      v87 = operator new(16 * v37);
      if ( !v87 )
        goto LABEL_3;
      v44 = 4 * v37;
      result = operator new(v44);
      v84 = result;
      if ( result )
      {
        memset(v87, 0, v43);
        v45 = v44;
        v46 = v84;
        memset(v84, 0, v45);
        for ( m = 0; m < this[2]; ++m )
        {
          v48 = *(_DWORD *)(this[5] + 4 * m);
          v49 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v48 + 4)) + 4);
          if ( (v49 & 0x100) != 0
            && *(_DWORD *)(v48 + 8) == -1
            && *(_DWORD *)(v48 + 56) == -1
            && (v49 & 0x40000) == 0
            && ((v49 & 0x800) == 0 || this[86]) )
          {
            for ( n = 0; n < Size; ++n )
            {
              if ( v46[n] == *(_DWORD *)(v48 + 12) )
                break;
            }
            if ( n == Size )
            {
              v51 = *(_DWORD *)(v48 + 12);
              ++Size;
              v46[n] = v51;
            }
            *((float *)v87 + 4 * n + *(_DWORD *)(v48 + 16)) = *(double *)(v48 + 32);
          }
        }
        v52 = 0;
        if ( Size )
        {
          v95 = (int)v87;
          do
          {
            v4 = (*(int (__thiscall **)(int *, _DWORD, int))(*this + 60))(this, *((_DWORD *)v84 + v52), v95);
            if ( v4 < 0 )
              goto LABEL_211;
            v95 += 16;
          }
          while ( ++v52 < Size );
        }
        v62 = this[2] == 0;
        v85 = 0;
        Size = 0;
        if ( !v62 )
        {
          v53 = this[4];
          v54 = this[5];
          v55 = this[2];
          do
          {
            if ( (*(_BYTE *)(*(_DWORD *)(v53 + 4 * *(_DWORD *)(*(_DWORD *)v54 + 4)) + 5) & 1) != 0
              && *(_DWORD *)(*(_DWORD *)v54 + 8) == -1 )
            {
              v85 = (char *)v85 + 1;
            }
            v54 += 4;
            --v55;
          }
          while ( v55 );
        }
        v56 = v85;
        v57 = 16 * (_DWORD)v85;
        v85 = operator new(16 * (_DWORD)v85);
        if ( !v85 )
          goto LABEL_3;
        v58 = 4 * (_DWORD)v56;
        result = operator new(v58);
        v89 = result;
        if ( result )
        {
          v95 = 0;
          memset(v85, 0, v57);
          memset(v89, 0, v58);
          if ( this[2] )
          {
            do
            {
              v59 = *(_DWORD *)(this[5] + 4 * v95);
              v60 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v59 + 4)) + 4);
              if ( (v60 & 0x100) != 0
                && *(_DWORD *)(v59 + 8) == -1
                && *(_DWORD *)(v59 + 56) == -1
                && (v60 & 0x40000) != 0 )
              {
                v61 = 0;
                v62 = Size == 0;
                if ( Size )
                {
                  do
                  {
                    if ( *((_DWORD *)v89 + v61) == *(_DWORD *)(v59 + 12) )
                      break;
                    ++v61;
                  }
                  while ( v61 < Size );
                  v62 = v61 == Size;
                }
                if ( v62 )
                {
                  v63 = *(_DWORD *)(v59 + 12);
                  ++Size;
                  *((_DWORD *)v89 + v61) = v63;
                }
                *((_DWORD *)v85 + 4 * v61 + *(_DWORD *)(v59 + 16)) = (__int64)*(double *)(v59 + 32);
              }
              ++v95;
            }
            while ( v95 < (unsigned int)this[2] );
          }
          v64 = 0;
          if ( Size )
          {
            v95 = (int)v85;
            do
            {
              v4 = (*(int (__thiscall **)(int *, _DWORD, int))(*this + 64))(this, *((_DWORD *)v89 + v64), v95);
              if ( v4 < 0 )
                goto LABEL_211;
              v95 += 16;
            }
            while ( ++v64 < Size );
          }
          if ( k <= this[17] )
          {
            v95 = 0;
            if ( v93 )
            {
              v65 = Block;
              k = v93;
              do
              {
                if ( *v65
                  && (*(int (__thiscall **)(int *, _DWORD, int))(*this + 68))(
                       this,
                       *v65,
                       (int)v65 + (_BYTE *)v82 - (_BYTE *)Block) < 0 )
                {
                  v95 = 1;
                }
                ++v65;
                --k;
              }
              while ( k );
            }
            result = (void *)(*(int (__thiscall **)(int *))(*this + 76))(this);
            v4 = (int)result;
            v66 = 0;
            if ( (int)result < 0 )
              goto LABEL_211;
            if ( v88 )
            {
              do
              {
                result = (void *)*((_DWORD *)v86 + v66);
                if ( result )
                {
                  result = (void *)(*(int (__thiscall **)(int *, _DWORD))(*this + 72))(this, *((_DWORD *)v86 + v66));
                  if ( (int)result < 0 )
                    v95 = 1;
                }
                ++v66;
              }
              while ( v66 < v88 );
            }
            if ( *((char *)this + 112) >= 0 )
            {
              if ( v94 )
              {
                v68 = (void **)v92;
                k = v94;
                do
                {
                  result = *v68;
                  if ( *v68 )
                  {
                    result = (void *)(*(int (__thiscall **)(int *, void *, int, _DWORD, _DWORD))(*this + 108))(
                                       this,
                                       result,
                                       (int)v68 + (_BYTE *)v90 - (_BYTE *)v92,
                                       0,
                                       0);
                    if ( (int)result < 0 )
                      v95 = 1;
                  }
                  ++v68;
                  --k;
                }
                while ( k );
              }
            }
            else if ( v94 )
            {
              v67 = (void **)v92;
              k = v94;
              do
              {
                result = *v67;
                if ( *v67 )
                {
                  result = (void *)(*(int (__thiscall **)(int *, void *, int))(*this + 68))(
                                     this,
                                     result,
                                     (int)v67 + (_BYTE *)v90 - (_BYTE *)v92);
                  if ( (int)result < 0 )
                    v95 = 1;
                }
                ++v67;
                --k;
              }
              while ( k );
            }
            v69 = 0;
            if ( !v95 )
            {
              v70 = 0;
              if ( !v94 )
              {
LABEL_194:
                if ( (*((_BYTE *)this + 110) & 0x40) == 0 )
                {
                  v4 = sub_6BC1A9(this);
                  if ( v4 < 0 )
                    goto LABEL_211;
                }
                v4 = (*(int (__thiscall **)(int *))(*this + 36))(this);
                if ( v4 < 0 )
                  goto LABEL_211;
                if ( this[56] )
                {
                  v4 = sub_6C9387((int)this);
                  if ( v4 < 0 )
                    goto LABEL_211;
                }
                v4 = sub_6C94AF(this);
                if ( v4 < 0 )
                  goto LABEL_211;
                if ( (this[51] & 1) != 0 )
                {
                  v4 = sub_6C9E19(this);
                  if ( v4 < 0 )
                    goto LABEL_211;
                }
                v4 = sub_6C9357(this, 0xFFFF);
                if ( v4 < 0 )
                  goto LABEL_211;
                v4 = sub_6C64E6(this);
                if ( v4 < 0 )
                  goto LABEL_211;
                v72 = this[108];
                if ( v72 )
                {
                  if ( !this[53] )
                  {
                    v4 = (*(int (__cdecl **)(int))(*(_DWORD *)v72 + 20))(this[108]);
                    if ( v4 < 0 )
                      goto LABEL_211;
                  }
                }
                if ( a2 )
                {
                  v4 = sub_677265(4 * this[68], &k);
                  if ( v4 < 0 )
                    goto LABEL_211;
                  v73 = (const void *)this[67];
                  v88 = 4 * this[68];
                  v74 = (void *)(*(int (__cdecl **)(unsigned int))(*(_DWORD *)k + 12))(k);
                  qmemcpy(v74, v73, v88);
                  *a2 = k;
                }
                v4 = 0;
                goto LABEL_211;
              }
              while ( 1 )
              {
                if ( *(_DWORD *)((char *)v92 + v69) )
                {
                  k = 0;
                  if ( v69 )
                    break;
                }
LABEL_193:
                ++v70;
                v69 += 4;
                if ( v70 >= v94 )
                  goto LABEL_194;
              }
              v71 = v90;
              while ( !*(_DWORD *)((char *)v71 + (_BYTE *)v92 - (_BYTE *)v90) || *(_DWORD *)((char *)v90 + v69) != *v71 )
              {
                ++k;
                ++v71;
                if ( k >= v70 )
                  goto LABEL_193;
              }
LABEL_214:
              result = (void *)sub_686791((int)this, v76, v77, v78);
            }
          }
          else
          {
            result = (void *)sub_686791((int)this, 0, 4506, "maximum number of inputs exceeded");
          }
        }
      }
    }
LABEL_215:
    HIDWORD(v79) = dword_16C999C;
    v2 = __readeflags();
    _InterlockedExchange((volatile __int32 *)&v79 + 1, dword_16C6C74 - dword_16F3B30);
    __writeeflags(v2);
    return result;
  }
LABEL_211:
  j__free(Block);
  j__free(v92);
  j__free(v82);
  j__free(v90);
  j__free(0);
  j__free(v87);
  j__free(v84);
  j__free(v86);
  j__free(v85);
  j__free(v89);
  j__free((void *)this[67]);
  this[67] = 0;
  j__free((void *)this[73]);
  this[73] = 0;
  v75 = this + 108;
  if ( *v75 )
  {
    (*(void (__cdecl **)(_DWORD))(*(_DWORD *)*v75 + 8))(*v75);
    *v75 = 0;
  }
  return (void *)v4;
}
