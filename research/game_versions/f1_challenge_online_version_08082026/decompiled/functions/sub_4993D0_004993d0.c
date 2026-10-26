int __thiscall sub_4993D0(_DWORD *this)
{
  int v2; // edx
  int *v4; // eax
  __int16 *v5; // esi
  int v6; // esi
  int v7; // edi
  int v8; // eax
  int *v9; // eax
  _DWORD *i; // ebx
  int v11; // [esp-24h] [ebp-48h]
  int v12; // [esp-20h] [ebp-44h]
  int v13; // [esp-1Ch] [ebp-40h]
  int v14; // [esp-18h] [ebp-3Ch]
  __int16 v15; // [esp+4h] [ebp-20h] BYREF
  __int16 v16; // [esp+6h] [ebp-1Eh]
  __int16 v17; // [esp+8h] [ebp-1Ch]
  __int16 v18; // [esp+Ah] [ebp-1Ah]
  __int16 v19; // [esp+14h] [ebp-10h] BYREF
  __int16 v20; // [esp+16h] [ebp-Eh]
  __int16 v21; // [esp+18h] [ebp-Ch]
  __int16 v22; // [esp+1Ah] [ebp-Ah]

  v2 = this[19];
  if ( !v2 )
    return -1;
  sub_491300(
    &v19,
    this[3] + *(_DWORD *)(this[20] + 12),
    this[1] + *(_DWORD *)(this[20] + 4),
    *(_DWORD *)(*(_DWORD *)(v2 + 12) + 28),
    *(_DWORD *)(*(_DWORD *)(v2 + 12) + 32));
  v4 = (int *)sub_490920();
  v5 = (__int16 *)sub_491CF0(v4);
  (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, 0);
  while ( v5 )
  {
    sub_491300(&v15, *v5, v5[1], v5[2], v5[3]);
    sub_491600(&v15, v19, v20, v21, v22);
    if ( v17 > 0 && v18 > 0 )
    {
      v6 = v15 - v19;
      v7 = v16 - v20;
      v14 = v18;
      v13 = v17;
      v12 = v16;
      v11 = v15;
      v8 = sub_495150();
      sub_494A30(*(_DWORD *)(this[19] + 12), v6, v7, v8, v11, v12, v13, v14, 0, 0);
    }
    v9 = (int *)sub_490920();
    v5 = (__int16 *)sub_491D10(v9);
    nullsub_3(&v15);
  }
  for ( i = (_DWORD *)this[17]; i; i = (_DWORD *)sub_486320(i) )
    (*(void (__thiscall **)(_DWORD *))(*i + 68))(i);
  nullsub_3(&v19);
  return 0;
}
