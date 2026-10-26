void __thiscall sub_5C4380(int this, int a2, int a3)
{
  int v4; // ecx
  int v5; // eax
  int v6; // edi
  int *v7; // eax
  _DWORD *v8; // edi
  int i; // edi
  int v10; // ebp
  int v11; // eax
  int v12; // eax
  int v13; // [esp+0h] [ebp-1Ch]

  (*(void (__thiscall **)(_DWORD, _DWORD, int))(**(_DWORD **)(a2 + 60) + 16))(
    *(_DWORD *)(a2 + 60),
    *(_DWORD *)(this + 4),
    a2);
  v4 = *(_DWORD *)(this + 16);
  v5 = *(_DWORD *)(this + 12) + 1;
  *(_DWORD *)(this + 12) = v5;
  if ( v4 < v5 )
  {
    v6 = v5 + 1;
    sub_4F14D0(v13);
    *(_DWORD *)(this + 20) = sub_5A8CF0(*(void **)(this + 20), 4 * v6, 2, 16, 2);
    *(_DWORD *)(this + 16) = v6;
  }
  v7 = (int *)(*(_DWORD *)(this + 20) + 4 * (*(_DWORD *)(this + 12) - 1));
  if ( v7 )
    *v7 = a2;
  *(_BYTE *)(a2 + 80) = 0;
  if ( *(_DWORD *)(this + 36) )
  {
    v8 = *(_DWORD **)(this + 36);
    while ( *(_DWORD *)(v8[2] + 56) > *(_DWORD *)(a3 + 20) )
    {
      v8 = (_DWORD *)v8[4];
      if ( !v8 )
      {
        for ( i = *(_DWORD *)(this + 36); *(_DWORD *)(i + 16); i = *(_DWORD *)(i + 16) )
          ;
        if ( operator new(0x14u) )
          v12 = sub_5D1BE0(*(_DWORD *)(this + 4), this, a2, 0, i);
        else
          v12 = 0;
        *(_DWORD *)(i + 16) = v12;
        goto LABEL_26;
      }
    }
    v10 = v8[3];
    if ( operator new(0x14u) )
      v11 = sub_5D1BE0(*(_DWORD *)(this + 4), this, a2, v8, v10);
    else
      v11 = 0;
    v8[3] = v11;
    if ( v10 )
      *(_DWORD *)(v10 + 16) = v11;
    if ( *(_DWORD **)(this + 36) == v8 )
      *(_DWORD *)(this + 36) = v11;
LABEL_26:
    sub_5C2530(a2, *(float *)(a3 + 12), *(float *)a3);
  }
  else
  {
    sub_5C2530(a2, *(float *)(a3 + 12), *(float *)a3);
    if ( operator new(0x14u) )
      *(_DWORD *)(this + 36) = sub_5D1BE0(*(_DWORD *)(this + 4), this, a2, 0, 0);
    else
      *(_DWORD *)(this + 36) = 0;
  }
}
