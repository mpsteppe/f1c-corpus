int __thiscall sub_4D7750(_DWORD *this, int a2, int a3, float a4, float a5)
{
  int *v5; // eax
  int v6; // edx
  int v7; // ebx
  double v8; // st7
  int v9; // eax
  int v10; // esi
  _DWORD *v11; // eax
  int v12; // edi
  size_t v13; // esi
  int v15; // [esp+10h] [ebp-408h]
  _DWORD *v16; // [esp+14h] [ebp-404h]
  _BYTE Buffer[1024]; // [esp+18h] [ebp-400h] BYREF

  v5 = (int *)this[233];
  v6 = 0;
  v16 = this;
  v15 = 0;
  this[235] = v5;
  if ( !v5 )
    return v6;
  v7 = *v5;
  if ( !*v5 )
    return v6;
  while ( 1 )
  {
    v8 = *(float *)v7;
    if ( v8 > a5 )
      return v6;
    v9 = this[235];
    v10 = v7;
    if ( v9 )
      this[235] = *(_DWORD *)(v9 + 4);
    v11 = (_DWORD *)this[235];
    v7 = v11 ? *v11 : 0;
    if ( v8 >= a4 )
      break;
LABEL_21:
    if ( !v7 )
      return v6;
  }
  sub_57A5B0(*(_DWORD *)(v10 + 4));
  if ( v7 )
  {
    v12 = *(_DWORD *)(v7 + 4) - *(_DWORD *)(v10 + 4);
LABEL_14:
    while ( v12 > 0 )
    {
      v13 = 1024;
      if ( v12 <= 1024 )
        v13 = v12;
      sub_57A3D0(Buffer, v13);
      if ( sub_57A3A0(Buffer, v13) == v13 )
      {
        v12 -= v13;
        v15 += v13;
      }
    }
    v6 = v15;
    this = v16;
    goto LABEL_21;
  }
  if ( (unsigned __int8)sub_57A570(a2) )
  {
    v12 = sub_57A620(a2) - *(_DWORD *)(v10 + 4);
    sub_57A5B0(*(_DWORD *)(v10 + 4));
    goto LABEL_14;
  }
  return v15;
}
