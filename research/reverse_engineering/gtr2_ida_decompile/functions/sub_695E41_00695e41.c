_DWORD *__thiscall sub_695E41(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  void *v4; // edi
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  void *v8; // [esp-4h] [ebp-9Ch]
  unsigned int v9[32]; // [esp+Ch] [ebp-8Ch] BYREF
  int v10; // [esp+8Ch] [ebp-Ch]
  int v11; // [esp+90h] [ebp-8h] BYREF
  void *Block; // [esp+94h] [ebp-4h]
  int v13; // [esp+A0h] [ebp+8h]

  v11 = 0;
  Block = 0;
  sub_65EC4C(v9);
  if ( a2 )
  {
    v3 = operator new(8u);
    Block = v3 ? unknown_libname_27(v3, (int)this, this[4]) : 0;
    if ( !Block )
      goto LABEL_15;
  }
  if ( sub_661E5C(v9, (_DWORD *)this[1], *this & 0xC3, Block, &v11) < 0 )
    goto LABEL_15;
  v13 = (*(int (__stdcall **)(int))(*(_DWORD *)v11 + 16))(v11);
  v4 = (void *)sub_67EB7E((_DWORD *)dword_FB9E44, v13, 1u);
  v10 = (int)v4;
  if ( !v4 )
    goto LABEL_15;
  qmemcpy(v4, (const void *)(*(int (__stdcall **)(int))(*(_DWORD *)v11 + 12))(v11), v13);
  if ( v11 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v11 + 8))(v11);
    v11 = 0;
  }
  v5 = (_DWORD *)sub_65B229(56);
  v6 = v5 ? sub_67F8F4(v5, this + 8, v10, v13) : 0;
  if ( v6 )
  {
    j__free(Block);
    sub_661299((int)v9);
    return v6;
  }
  else
  {
LABEL_15:
    sub_661299((int)v9);
    v8 = Block;
    this[16] = 1;
    j__free(v8);
    if ( v11 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v11 + 8))(v11);
    return 0;
  }
}
