void __thiscall sub_5A8BC0(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // eax
  int v3; // edi
  int v4; // ecx
  _DWORD *v5; // eax
  int v6; // esi
  int v7; // ebx
  int v8; // edx
  int i; // ebx
  int v10; // edi
  int v11; // [esp+Ch] [ebp-14h]
  int v13; // [esp+18h] [ebp-8h]
  int v14; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v2 = this[1];
  v3 = 0;
  v13 = v2;
  if ( v2 - 1 > 0 )
  {
    do
    {
      v4 = v3 + 1;
      v11 = v3;
      if ( v3 + 1 < v2 )
      {
        v5 = (_DWORD *)*v1;
        v6 = v3;
        v14 = v3;
        do
        {
          if ( *(_DWORD *)(v5[v4] + 4) >= *(_DWORD *)(v5[v6] + 4) )
          {
            v7 = v11;
          }
          else
          {
            v7 = v4;
            v11 = v4;
            v6 = v4;
          }
          ++v4;
        }
        while ( v4 < v13 );
        if ( v7 > v3 )
        {
          v8 = v5[v14];
          v5[v14] = v5[v7];
          v5[v7] = v8;
        }
        v4 = v3 + 1;
        v1 = this;
      }
      v2 = v1[1];
      v3 = v4;
      v13 = v2;
    }
    while ( v4 < v2 - 1 );
  }
  for ( i = 0; i < v1[1]; ++i )
  {
    v10 = *(_DWORD *)(*v1 + 4 * i);
    if ( v10 )
    {
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v10 + 4))(*(_DWORD *)(*v1 + 4 * i));
      (**(void (__thiscall ***)(int, int))v10)(v10, 1);
    }
  }
  free((void *)*v1);
}
