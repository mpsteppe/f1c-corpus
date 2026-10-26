int __thiscall sub_4A4120(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  const char *v6; // esi
  const char *v7; // eax
  int v9; // esi
  int v10; // eax
  int v11; // [esp-Ch] [ebp-14h]
  int v12; // [esp-8h] [ebp-10h]

  v6 = (const char *)this[40];
  if ( !v6 )
    v6 = &byte_629120;
  v7 = (const char *)this[70];
  if ( !v7 )
    v7 = &byte_629120;
  if ( !strcmp(v7, v6) )
  {
    if ( !this[68] && this[67] )
    {
      v9 = this[69];
      if ( v9 < sub_5A8900() && v9 > 0 )
      {
        v12 = this[1];
        v11 = this[3];
        v10 = sub_4AB570(&unk_765B00);
        sub_5A8E30(v10, v9, v11, v12, 32);
      }
      *a2 = this[1];
      *a4 = this[3];
      *a5 = this[3] + *(_DWORD *)(this[67] + 268);
      *a3 = this[1] + *(_DWORD *)(this[67] + 272);
    }
    return 0;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD *))(*this + 152))(this);
    return 0;
  }
}
