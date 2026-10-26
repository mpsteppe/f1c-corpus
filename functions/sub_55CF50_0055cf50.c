int __thiscall sub_55CF50(int *this, _DWORD *a2, int a3, int a4, int a5)
{
  int v5; // ebp
  int v6; // edi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // ebx
  int v12; // edi
  int v13; // ebp
  int v14; // ebx
  int result; // eax
  int v16; // eax
  bool v17; // cc
  int v18; // eax
  int *v19; // ecx
  int v20; // edi
  int v21; // eax
  int i; // [esp+44h] [ebp-4Ch]
  _DWORD *v23; // [esp+48h] [ebp-48h]
  int *v24; // [esp+4Ch] [ebp-44h]
  int v25[8]; // [esp+50h] [ebp-40h] BYREF
  int v26; // [esp+70h] [ebp-20h]
  int v27; // [esp+74h] [ebp-1Ch]
  int v28; // [esp+7Ch] [ebp-14h]

  v5 = a3;
  v6 = *(_DWORD *)(a3 + 4);
  v23 = (_DWORD *)v6;
  StructInitWithDefaultValues(v25);
  if ( this[1267] )
  {
    v8 = this[1088];
    this[1267] = 0;
    *this = (*(int (__stdcall **)(int, int, int *))(*(_DWORD *)v8 + 148))(v8, 256, this + 1283);
  }
  if ( this[1340] )
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 28, 1);
  if ( this[1265] != 1 )
  {
    v9 = this[1088];
    this[1265] = 1;
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v9 + 200))(v9, 136, 1);
  }
  ModeStateSetterThroughVtable(this, 1);
  this[1116] = 256;
  if ( (*(_BYTE *)(v6 + 156) & 0x20) != 0 )
  {
    ModeStateSetterThroughVtable(this, 0);
    this[1116] |= 0x800u;
  }
  if ( (*(_BYTE *)(v6 + 156) & 0x40) != 0 )
    this[1116] |= 0x400u;
  if ( *(char *)(*(_DWORD *)(v6 + 168) + 64) < 0 )
    this[1116] |= 1u;
  sub_554790(this, this[1116], *(_DWORD *)(v6 + 172), *(_DWORD *)(*(_DWORD *)(v6 + 168) + 132));
  v10 = *(_DWORD *)(v6 + 164);
  v11 = 0;
  for ( i = 0; v11 < v10; v10 = v23[41] )
  {
    v12 = 0;
    if ( v11 < v10 )
    {
      v13 = 148 * v11;
      v24 = &this[17 * v11 + 1118];
      do
      {
        if ( v12 >= this[1260] )
          break;
        v14 = IndexedArrayLookupWithBoundsCheck(v23, 0, v11);
        if ( v14 )
        {
          result = sub_554F80((int)this, a2, v14);
          if ( !result )
            return result;
          v16 = *(_DWORD *)(v23[42] + v13 + 64);
          v26 = 7;
          v27 = 2;
          v28 = v14;
          if ( (v16 & 0x80u) != 0 )
            v27 = 3;
        }
        else
        {
          v26 = 0;
          v28 = 0;
        }
        MultiFieldSetterDispatchingTo7SubSetters(v24, v25, v12);
        v13 += 148;
        ++v12;
        v17 = i + 1 < v23[41];
        v24 += 17;
        v11 = ++i;
      }
      while ( v17 );
      v5 = a3;
    }
    StateFieldSetWithChainedInit(&this[17 * v12 + 1118], v12);
    PropertyValueSetterWithRefreshOnChange(this, *(_DWORD **)(v5 + 28));
    v18 = (*(int (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)this[1088] + 340))(
            this[1088],
            *(_DWORD *)(*(_DWORD *)(v5 + 36) + 24),
            *(_DWORD *)(v5 + 44));
    v19 = (int *)this[1088];
    *this = v18;
    v20 = *v19;
    if ( (*(_BYTE *)v5 & 0x10) != 0 )
      v21 = (*(int (__stdcall **)(int *, int, _DWORD, int, _DWORD, int))(v20 + 284))(
              v19,
              2,
              0,
              a4,
              *(_DWORD *)(v5 + 48),
              a5 / 2);
    else
      v21 = (*(int (__stdcall **)(int *, int, _DWORD, int, _DWORD, int))(v20 + 284))(
              v19,
              4,
              0,
              a4,
              *(_DWORD *)(v5 + 48),
              a5 / 3);
    *this = v21;
  }
  result = this[1340];
  if ( result )
  {
    result = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this[1088] + 200))(this[1088], 28, 0);
    *this = result;
  }
  return result;
}
