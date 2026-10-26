int __thiscall sub_60FE30(_DWORD *this, _DWORD *a2)
{
  _DWORD *v2; // ebx
  int v4; // edi
  int v5; // ebp
  int v6; // eax
  _DWORD *v7; // ebx
  int v8; // ecx
  int v9; // ecx
  char *v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // ebx
  bool v13; // cc
  int v15; // [esp+7Ch] [ebp-38h]
  bool v16; // [esp+A2h] [ebp-12h]
  bool v17; // [esp+A3h] [ebp-11h]
  _DWORD *v18; // [esp+A4h] [ebp-10h]
  int v19; // [esp+A4h] [ebp-10h]
  int v20; // [esp+A8h] [ebp-Ch]
  int v21; // [esp+ACh] [ebp-8h]
  int v22; // [esp+B0h] [ebp-4h]

  v2 = a2;
  if ( (*a2 & 0x1000) == 0 )
    *a2 &= 0xFFFEF7FF;
  if ( (*a2 & 0x10800) == 0x10800 )
    return 1;
  if ( (*(int (__stdcall **)(_DWORD))(*(_DWORD *)this[2387] + 12))(this[2387]) )
    return 0;
  v17 = sub_5EB310(a2);
  v16 = (*a2 & 0x20000000) != 0;
  v22 = 0;
  if ( (int)a2[90] <= 0 )
  {
LABEL_40:
    *v2 |= 0x11800u;
    return 1;
  }
  v20 = 0;
  while ( 1 )
  {
    v4 = v20 + v2[91];
    v5 = (int)this[1204] <= 1 ? ((*(_BYTE *)v4 & 8) != 0 ? 0x8000 : 4096) : sub_60AE80((int *)v4);
    if ( v16 )
      break;
    if ( v17 )
    {
      v10 = *(char **)(v4 + 44);
      if ( v10 )
      {
        if ( *v10 >= 0 && **(char **)(v4 + 48) >= 0 )
        {
          (*(void (__thiscall **)(_DWORD *, char *, _DWORD, _DWORD, int))(*this + 412))(
            this,
            v10,
            *(_DWORD *)(v4 + 52),
            *(_DWORD *)(v4 + 8),
            v5);
          (*(void (__thiscall **)(_DWORD *, int, _DWORD, _DWORD))(*this + 388))(this, v4, 0, 0);
          (*(void (__thiscall **)(_DWORD *, _DWORD, int))(*this + 416))(this, *(_DWORD *)(v4 + 44), v5);
          v2 = a2;
          goto LABEL_39;
        }
      }
      else
      {
        v19 = this[172];
        v21 = this[182];
        v11 = sub_5EA670(a2);
        v12 = v11;
        if ( v11 )
          sub_5DA590(v11, v5);
        if ( (*(int (__thiscall **)(_DWORD *, _DWORD *, int, _DWORD, int, int, int, _DWORD *, int))(*this + 376))(
               this,
               this + 173,
               v19,
               *(_DWORD *)(v4 + 8),
               v5,
               v4 + 44,
               v4 + 52,
               v12,
               1) )
        {
          (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 340))(this, 0);
          if ( (*(int (__thiscall **)(_DWORD *, _DWORD *, int, _DWORD, int, int, int, _DWORD *, int))(*this + 376))(
                 this,
                 this + 173,
                 v19,
                 *(_DWORD *)(v4 + 8),
                 v5,
                 v4 + 44,
                 v4 + 52,
                 v12,
                 1) )
          {
            return 0;
          }
        }
        if ( (*(int (__thiscall **)(_DWORD *, _DWORD *, int, _DWORD, int, int, _DWORD *, int))(*this + 380))(
               this,
               this + 183,
               v21,
               *(_DWORD *)(v4 + 36),
               v4 + 48,
               v4 + 56,
               v12,
               1) )
        {
          (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 340))(this, 0);
          if ( (*(int (__thiscall **)(_DWORD *, _DWORD *, int, _DWORD, int, int, _DWORD *, int))(*this + 380))(
                 this,
                 this + 183,
                 v21,
                 *(_DWORD *)(v4 + 36),
                 v4 + 48,
                 v4 + 56,
                 v12,
                 1) )
          {
            return 0;
          }
        }
      }
      (*(void (__thiscall **)(_DWORD *, int, _DWORD, int))(*this + 388))(this, v4, 0, 1);
      v2 = a2;
    }
    else if ( !*(_DWORD *)(v4 + 44) )
    {
      if ( (*(int (__thiscall **)(_DWORD *, _DWORD *, _DWORD, _DWORD, int, int, int, _DWORD, _DWORD))(*this + 376))(
             this,
             this + 168,
             this[167],
             *(_DWORD *)(v4 + 8),
             v5,
             v4 + 44,
             v4 + 52,
             0,
             0)
        || (*(int (__thiscall **)(_DWORD *, _DWORD *, _DWORD, _DWORD, int, int, _DWORD, _DWORD))(*this + 380))(
             this,
             this + 178,
             this[177],
             *(_DWORD *)(v4 + 36),
             v4 + 48,
             v4 + 56,
             0,
             0) )
      {
        return 0;
      }
      (*(void (__thiscall **)(_DWORD *, int, _DWORD, int))(*this + 388))(this, v4, 0, 1);
    }
LABEL_39:
    v13 = ++v22 < v2[90];
    v20 += 108;
    if ( !v13 )
      goto LABEL_40;
  }
  v6 = *(_DWORD *)(v4 + 44);
  v7 = (_DWORD *)(v4 + 44);
  if ( v6 )
  {
    v8 = *(_DWORD *)(v6 + 12);
    if ( v8 <= 0 || (v9 = v8 - 1, (*(_DWORD *)(v6 + 12) = v9) == 0) )
      (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)dword_FB27A4 + 408))(dword_FB27A4, *v7, 0);
  }
  v15 = *(_DWORD *)(v4 + 8);
  *v7 = 0;
  if ( (*(int (__thiscall **)(_DWORD *, _DWORD *, _DWORD, int, int, int, int, int))(*this + 368))(
         this,
         this + 173,
         this[172],
         v15,
         v5,
         v4 + 44,
         v4 + 52,
         1) )
  {
    (*(void (__thiscall **)(_DWORD *, _DWORD, int))(*this + 416))(this, *v7, v5);
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 340))(this, 0);
    if ( (*(int (__thiscall **)(_DWORD *, _DWORD *, _DWORD, _DWORD, int, int, int, int))(*this + 368))(
           this,
           this + 173,
           this[172],
           *(_DWORD *)(v4 + 8),
           v5,
           v4 + 44,
           v4 + 52,
           1) )
    {
      (*(void (__thiscall **)(_DWORD *, _DWORD, int))(*this + 416))(this, *(_DWORD *)(v4 + 44), v5);
      return 0;
    }
  }
  if ( *v7 )
    ++*(_DWORD *)(*v7 + 12);
  v18 = (_DWORD *)(v4 + 48);
  if ( *(_DWORD *)(v4 + 48)
    || !(*(int (__thiscall **)(_DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD *, int, _DWORD, int))(*this + 380))(
          this,
          this + 183,
          this[182],
          *(_DWORD *)(v4 + 36),
          v18,
          v4 + 56,
          0,
          1)
    || ((*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 456))(this, *v18),
        (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 340))(this, 0),
        !(*(int (__thiscall **)(_DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD *, int, _DWORD, int))(*this + 380))(
           this,
           this + 183,
           this[182],
           *(_DWORD *)(v4 + 36),
           v18,
           v4 + 56,
           0,
           1)) )
  {
    (*(void (__thiscall **)(_DWORD *, int, _DWORD, int))(*this + 388))(this, v4, 0, 1);
    (*(void (__thiscall **)(_DWORD *, _DWORD, int))(*this + 416))(this, *v7, v5);
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 456))(this, *v18);
    v2 = a2;
    goto LABEL_39;
  }
  (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 456))(this, *(_DWORD *)(v4 + 48));
  return 0;
}
