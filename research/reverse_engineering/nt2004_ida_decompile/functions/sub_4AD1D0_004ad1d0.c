void __thiscall sub_4AD1D0(int this)
{
  Concurrency::details::VirtualProcessor *v2; // eax
  CHAR *v3; // edx
  int v4; // esi
  int v5; // ebx
  double v6; // st7
  int v7; // ebp
  int v8; // eax
  int v9; // [esp-2Ch] [ebp-40h]
  int v10; // [esp-28h] [ebp-3Ch]
  int v11; // [esp-24h] [ebp-38h]

  if ( *(float *)(this + 272) > 0.2 && *(_DWORD *)(this + 388) )
  {
    v2 = sub_4AC170((_DWORD *)this, 0, 0);
    if ( !v2 )
      goto LABEL_8;
    v3 = *(CHAR **)(this + 372);
    if ( !v3 )
      v3 = &byte_629120;
    if ( (*(unsigned __int8 (__thiscall **)(Concurrency::details::VirtualProcessor *, CHAR *))(*(_DWORD *)v2 + 108))(
           v2,
           v3) == 1 )
      v4 = *(_DWORD *)(this + 388);
    else
LABEL_8:
      v4 = sub_4ADBB0(aNodropicon0000);
    if ( v4 )
    {
      v5 = *(_DWORD *)(v4 + 20);
      v6 = (double)dword_6152E8 * 0.00125;
      v7 = *(_DWORD *)(v4 + 24);
      v11 = (__int64)((double)*(int *)(this + 92) * v6);
      v10 = (__int64)((double)(*(_DWORD *)(this + 88) - v5) * v6);
      v9 = sub_4AB570();
      v8 = sub_4B07C0(v4);
      sub_4AAF50(
        *(float *)(v8 + 16),
        0,
        0,
        v5,
        v7,
        v9,
        v10,
        v11,
        (__int64)((double)v5 * v6),
        (__int64)((double)v7 * v6),
        -1,
        -1,
        -1,
        -1);
    }
  }
}
