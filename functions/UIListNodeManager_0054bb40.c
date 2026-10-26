int __thiscall sub_54BB40(_DWORD *this, int a2)
{
  int v3; // edi
  int v4; // ebx
  _DWORD *v5; // eax
  int i; // eax
  int v7; // ecx
  _DWORD *v8; // esi
  int v9; // eax
  int v10; // ecx
  int v11; // ecx
  _BYTE v13[32]; // [esp+0h] [ebp-B0h] BYREF
  int v14; // [esp+20h] [ebp-90h]
  int v15; // [esp+24h] [ebp-8Ch]
  int v16; // [esp+34h] [ebp-7Ch]
  int v17; // [esp+58h] [ebp-58h]
  int v18; // [esp+5Ch] [ebp-54h]
  int v19; // [esp+60h] [ebp-50h]

  v3 = this[133];
  if ( v3 )
  {
    for ( i = *(_DWORD *)(v3 + 36); i; i = *(_DWORD *)(i + 36) )
      v3 = i;
    v4 = a2;
    if ( OperatorNewNhMallocWrapper(40) )
      v5 = (_DWORD *)sub_5510F0(*(_DWORD *)(a2 + 12));
    else
      v5 = 0;
    *(_DWORD *)(v3 + 36) = v5;
  }
  else
  {
    v4 = a2;
    if ( OperatorNewNhMallocWrapper(40) )
    {
      v5 = (_DWORD *)sub_5510F0(*(_DWORD *)(a2 + 12));
      this[133] = v5;
    }
    else
    {
      v5 = 0;
      this[133] = 0;
    }
  }
  v7 = *(_DWORD *)(v4 + 12);
  v8 = v5;
  v9 = 0;
  v8[5] = v7;
  if ( v7 > 0 )
  {
    v10 = 0;
    do
    {
      *(_DWORD *)(v10 + v8[6]) = v9++;
      v10 += 136;
    }
    while ( v9 < v8[5] );
  }
  EntityFlagSetSubInitChain(v8);
  v8[7] = v4;
  sub_557350(v13);
  v11 = this[134];
  v15 = *(_DWORD *)(v4 + 12);
  v16 = 1120403456;
  v14 = 2;
  v19 = 14671647;
  v17 = 16;
  v18 = 0;
  if ( !v11 )
    sub_559200(this + 134, v13);
  EmptyStub_0170();
  return 0;
}
