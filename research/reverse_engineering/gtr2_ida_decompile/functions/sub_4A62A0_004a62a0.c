int __thiscall sub_4A62A0(int this)
{
  int v2; // ecx
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int *v9; // ecx
  int v10; // eax

  if ( *(_DWORD *)(this + 288) )
  {
    v2 = *(_DWORD *)(this + 292);
    if ( v2 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 92))(v2);
    v3 = *(_DWORD *)(this + 288);
    if ( v3 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 92))(v3);
    v4 = sub_4CE1B0(*(_DWORD *)(this + 288));
    v5 = *(_DWORD *)(this + 276);
    v6 = v4 + 1;
    *(_DWORD *)(this + 284) = v6;
    if ( v5 == 717 )
      v7 = v6 + 1;
    else
      v7 = v6 - 1;
    *(_DWORD *)(this + 284) = v7;
    v8 = *(_DWORD *)(this + 288);
    if ( *(_DWORD *)(this + 284) > *(_DWORD *)(v8 + 148) )
      *(_DWORD *)(this + 284) = 1;
    if ( *(int *)(this + 284) < 1 )
      *(_DWORD *)(this + 284) = *(_DWORD *)(v8 + 148);
    v9 = *(int **)(this + 296);
    *(_BYTE *)(this + 280) = 1;
    v10 = *v9;
    *((_BYTE *)v9 + 316) = 1;
    (*(void (__stdcall **)(int))(v10 + 40))(1);
  }
  return 0;
}
