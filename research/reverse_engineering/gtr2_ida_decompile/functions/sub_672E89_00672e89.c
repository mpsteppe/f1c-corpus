char *__thiscall sub_672E89(
        int this,
        int a2,
        int a3,
        const char *ArgList,
        int a5,
        unsigned int a6,
        int a7,
        int a8,
        const char *a9,
        int a10,
        _DWORD *a11,
        _DWORD *a12)
{
  unsigned int v12; // kr00_4
  int v14; // ebx
  int v15; // ebx
  void (__thiscall ***v16)(_DWORD, int); // ecx
  int v17; // ecx
  const char *v18; // eax
  void *v19; // eax
  size_t v20; // ecx
  char *result; // eax
  bool v22; // zf
  void *v23; // eax
  void *v24; // eax
  void *v25; // eax
  void *v26; // eax
  void *v27; // eax
  int v28; // eax
  int v29; // eax
  _DWORD *v30; // eax
  int v31; // ecx
  _DWORD *v32; // eax
  void (__thiscall ***v33)(_DWORD, int); // ecx
  int v34; // [esp-8h] [ebp-B0h]
  _DWORD *v35; // [esp-8h] [ebp-B0h]
  unsigned int v36; // [esp-4h] [ebp-ACh]
  void *v37; // [esp-4h] [ebp-ACh]
  size_t v38[5]; // [esp+0h] [ebp-A8h] BYREF
  char v39[96]; // [esp+14h] [ebp-94h] BYREF
  _BYTE v40[24]; // [esp+74h] [ebp-34h] BYREF
  int v41; // [esp+8Ch] [ebp-1Ch] BYREF
  int v42; // [esp+90h] [ebp-18h]
  int v43; // [esp+98h] [ebp-10h]
  int v44; // [esp+9Ch] [ebp-Ch]
  int v45; // [esp+A0h] [ebp-8h]
  _DWORD *v46; // [esp+A4h] [ebp-4h] BYREF

  sub_67EB04(0x100000, 0x10000);
  v14 = a10;
  v45 = 0;
  v44 = 0;
  if ( (a10 & 0xFFFFF800) != 0 || a3 && (a10 & 0x18) != 0 || !a11 )
    goto LABEL_2;
  v16 = *(void (__thiscall ****)(_DWORD, int))(this + 8);
  if ( v16 )
    (**v16)(v16, 1);
  j__free(*(void **)(this + 24));
  *(_DWORD *)(this + 72) = -1;
  v22 = a6 == 0;
  v17 = a8;
  *(_DWORD *)this = a2;
  v18 = a9;
  *(_DWORD *)(this + 4) = 0;
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 24) = 0;
  *(_DWORD *)(this + 28) = 0;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 80) = 0;
  *(_DWORD *)(this + 84) = 0;
  *(_DWORD *)(this + 88) = 0;
  *(_DWORD *)(this + 92) = 0;
  *(_DWORD *)(this + 96) = 0;
  *(_DWORD *)(this + 100) = 0;
  *(_DWORD *)(this + 12) = v18;
  *(_DWORD *)(this + 20) = v14;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 60) = 0;
  *(_DWORD *)(this + 64) = 0;
  *(_DWORD *)(this + 68) = 0;
  *(_DWORD *)(this + 104) = 0;
  *(_DWORD *)(this + 108) = 0;
  *(_DWORD *)(this + 112) = 0;
  *(_DWORD *)(this + 116) = 0;
  *(_DWORD *)(this + 120) = 0;
  *(_DWORD *)(this + 124) = 0;
  *(_DWORD *)(this + 128) = 0;
  *(_DWORD *)(this + 132) = v17;
  if ( !v22 )
  {
    v38[0] = 508;
    *(_DWORD *)(this + 16) = 1180172800;
    v19 = operator new(v38[0]);
    v20 = v38[0];
    if ( v19 )
      result = (char *)sub_6B3690(v19);
    else
      result = 0;
    *(_BYTE *)(this + 21) |= 1u;
    goto LABEL_61;
  }
  if ( (v14 & 0xC0) == 0 )
  {
LABEL_26:
    if ( sub_6460B4(*(const char **)(this + 12), 2, &v41) < 0 )
      goto LABEL_15;
    v22 = v42 == -130816;
    *(_DWORD *)(this + 16) = v42;
    *(_DWORD *)(this + 20) = v14;
    if ( v22 )
    {
      *(_DWORD *)(this + 16) = -130815;
      v45 = 1;
    }
    if ( *(_DWORD *)(this + 16) == -65280 )
    {
      *(_DWORD *)(this + 16) = -65279;
      v44 = 1;
    }
    result = *(char **)(this + 16);
    v20 = -130049;
    if ( (unsigned int)result > 0xFFFE03FF )
    {
      v20 = -64769;
      if ( (unsigned int)result > 0xFFFF02FF )
      {
        if ( result == (char *)-64768 )
          goto LABEL_58;
        v22 = result + 64513 == 0;
LABEL_56:
        if ( !v22 )
          goto LABEL_57;
LABEL_58:
        v27 = operator new(0x1F8u);
        v20 = v38[0];
        if ( v27 )
        {
          result = (char *)sub_69FF2C(a8);
          goto LABEL_61;
        }
LABEL_60:
        result = 0;
        goto LABEL_61;
      }
      if ( result != (char *)-64769 )
      {
        if ( (unsigned int)result < 0xFFFF0101 )
        {
LABEL_57:
          *(_DWORD *)(this + 8) = 0;
          goto LABEL_62;
        }
        if ( (unsigned int)result <= 0xFFFF0104 )
        {
          v38[0] = 1156;
          *(_DWORD *)(this + 20) = v14 & 0xFFFFFFFB;
          v26 = operator new(v38[0]);
          v20 = v38[0];
          if ( !v26 )
            goto LABEL_60;
          result = (char *)sub_6A22D0(v26);
          goto LABEL_61;
        }
        if ( result != (char *)-65024 && ((unsigned int)result <= 0xFFFF0201 || (unsigned int)result > 0xFFFF0203) )
          goto LABEL_57;
      }
      v25 = operator new(0x22Cu);
      v20 = v38[0];
      if ( !v25 )
        goto LABEL_60;
      result = (char *)sub_6ADE0F(a8);
    }
    else
    {
      if ( result == (char *)-130049 )
        goto LABEL_58;
      if ( result == (char *)1415053568 )
      {
        v38[0] = 508;
        *(_DWORD *)(this + 20) = v14 | 0x100;
        v24 = operator new(v38[0]);
        v20 = v38[0];
        if ( !v24 )
          goto LABEL_60;
        result = (char *)sub_6B3690(v24);
      }
      else
      {
        if ( result != (char *)-130815
          && result != (char *)-130560
          && result != (char *)-130558
          && result != (char *)-130305 )
        {
          v22 = result + 130304 == 0;
          goto LABEL_56;
        }
        v23 = operator new(0x1F8u);
        v20 = v38[0];
        if ( !v23 )
          goto LABEL_60;
        result = (char *)sub_6B0D6D(a8);
      }
    }
LABEL_61:
    *(_DWORD *)(this + 8) = result;
LABEL_62:
    if ( !*(_DWORD *)(this + 8) )
    {
LABEL_63:
      v38[0] = v20;
      v12 = __readeflags();
      _InterlockedExchange((volatile __int32 *)v38, dword_16C6E7C ^ 0x6C9F5425);
      __writeeflags(v12);
      return result;
    }
    if ( a3 )
    {
      *(_DWORD *)(this + 4) = a3;
    }
    else
    {
      v38[0] = this + 4;
      v36 = *(_DWORD *)(this + 20) | 0x80000000;
      v34 = *(_DWORD *)this;
      v28 = sub_694A53(v39);
      v15 = sub_69FE7E(v28, v34, v36, this + 4);
      nullsub_9();
      if ( v15 < 0 )
      {
LABEL_97:
        v33 = *(void (__thiscall ****)(_DWORD, int))(this + 8);
        *(_DWORD *)(this + 4) = 0;
        if ( v33 )
          (**v33)(v33, 1);
        v37 = *(void **)(this + 24);
        *(_DWORD *)(this + 8) = 0;
        j__free(v37);
        *(_DWORD *)(this + 24) = 0;
        sub_6816CF(0);
        sub_681151(0);
        goto LABEL_100;
      }
    }
    if ( v45 )
      sub_663C69(this, 0, (const char *)0xDB1, "vs_1_0 is no longer supported; using vs_1_1");
    if ( v44 )
      sub_663C69(this, 0, (const char *)0xDB1, "ps_1_0 is no longer supported; using ps_1_1");
    if ( !*(_DWORD *)(this + 136) )
    {
      v38[0] = 0x4000;
      *(_DWORD *)(this + 140) = 4096;
      result = (char *)operator new(v38[0]);
      v20 = v38[0];
      *(_DWORD *)(this + 136) = result;
      if ( !result )
        goto LABEL_63;
    }
    sub_6816CF(v40);
    sub_681151(v40);
    v15 = sub_6713D0(this);
    if ( v15 < 0 )
      goto LABEL_97;
    if ( a6 )
    {
      v29 = sub_672D88((_DWORD *)this, a6);
LABEL_86:
      v15 = v29;
      if ( v29 < 0 )
        goto LABEL_97;
      if ( !*(_DWORD *)(this + 76) )
      {
        v15 = sub_663ABB((_DWORD *)this);
        if ( v15 >= 0 )
        {
          v15 = (*(int (__thiscall **)(_DWORD, _DWORD **))(**(_DWORD **)(this + 8) + 8))(*(_DWORD *)(this + 8), &v46);
          if ( v15 >= 0 )
          {
            if ( a12
              && (v35 = v46, v32 = (_DWORD *)(*(int (**)(void))(*v46 + 12))(), v15 = sub_6461A1(v32, v35), v15 < 0) )
            {
              if ( v46 )
              {
                (*(void (__cdecl **)(_DWORD *))(*v46 + 8))(v46);
                v46 = 0;
              }
            }
            else
            {
              *a11 = v46;
              if ( a12 )
                *a12 = v43;
              v15 = 0;
            }
          }
        }
        goto LABEL_97;
      }
      goto LABEL_83;
    }
    if ( ArgList )
    {
      v30 = (_DWORD *)sub_663869((_DWORD *)this, ArgList);
      if ( !v30 )
      {
        sub_663C07((_DWORD *)this, 0, 3501, "'%s': entrypoint not found", ArgList);
LABEL_83:
        v15 = -2147467259;
        goto LABEL_97;
      }
      v31 = 0;
    }
    else
    {
      v30 = (_DWORD *)sub_66397F((_DWORD *)this, a5, &ArgList);
      if ( !v30 )
      {
        sub_663C07((_DWORD *)this, 0, 3501, "overloaded function not found");
        goto LABEL_83;
      }
      v31 = 1;
    }
    v29 = sub_67091B(this, ArgList, v30, a7, 0, 1, v31);
    goto LABEL_86;
  }
  if ( sub_6460B4(v18, 2, &v41) >= 0 )
  {
    if ( (v42 & 0xFFFF0000) == 0xFFFE0000 )
    {
      if ( (v14 & 0x40) != 0 )
      {
        v14 |= 5u;
        if ( (v42 & 0xFF00) == 0x300 )
          *(_DWORD *)(this + 12) = "vs_3_sw";
        else
          *(_DWORD *)(this + 12) = "vs_2_sw";
      }
    }
    else if ( (v42 & 0xFFFF0000) == 0xFFFF0000 && (v14 & 0x80u) != 0 )
    {
      v14 |= 5u;
      if ( (v42 & 0xFF00) == 0x300 )
        *(_DWORD *)(this + 12) = "ps_3_sw";
      else
        *(_DWORD *)(this + 12) = "ps_2_sw";
    }
    goto LABEL_26;
  }
LABEL_15:
  sub_663C07((_DWORD *)this, 0, 3506, "unrecognized compiler target '%s'", *(const char **)(this + 12));
LABEL_2:
  v15 = -2005530516;
LABEL_100:
  sub_67EB5C(v40);
  return (char *)v15;
}
