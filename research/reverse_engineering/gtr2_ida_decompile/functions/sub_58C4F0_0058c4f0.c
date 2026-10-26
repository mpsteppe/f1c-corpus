int __thiscall sub_58C4F0(int this)
{
  int i; // ebp
  int v3; // esi
  int v4; // ecx
  _DWORD *v5; // esi
  int result; // eax
  int j; // ebp
  int v8; // esi
  int v9; // ecx
  _DWORD *v10; // esi

  if ( *(_DWORD *)(this + 2436) )
  {
    for ( i = 0; i < 236; i += 4 )
    {
      v3 = *(_DWORD *)(this + 2436);
      v4 = *(_DWORD *)(v3 + i);
      v5 = (_DWORD *)(i + v3);
      if ( v4 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(v4);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v5 + 24))(*v5);
        if ( *v5 )
          (**(void (__thiscall ***)(_DWORD, int))*v5)(*v5, 1);
        *v5 = 0;
      }
    }
    j_j__free(*(void **)(this + 2436));
    sub_58C370((_DWORD *)(this + 2200));
  }
  result = *(_DWORD *)(this + 2676);
  if ( result )
  {
    for ( j = 0; j < 236; j += 4 )
    {
      v8 = *(_DWORD *)(this + 2676);
      v9 = *(_DWORD *)(v8 + j);
      v10 = (_DWORD *)(j + v8);
      if ( v9 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 8))(v9);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v10 + 24))(*v10);
        if ( *v10 )
          (**(void (__thiscall ***)(_DWORD, int))*v10)(*v10, 1);
        *v10 = 0;
      }
    }
    j_j__free(*(void **)(this + 2676));
    result = sub_58C370((_DWORD *)(this + 2440));
  }
  *(_BYTE *)(this + 4) = 0;
  *(_DWORD *)(this + 204) = 0;
  *(_DWORD *)(this + 208) = 0;
  *(_DWORD *)(this + 212) = 1006788918;
  *(_DWORD *)(this + 216) = 1092616192;
  *(_DWORD *)(this + 220) = 1114636288;
  *(_DWORD *)(this + 224) = 1116471296;
  *(_DWORD *)(this + 228) = 1036831949;
  *(_DWORD *)(this + 232) = 1123024896;
  *(_DWORD *)(this + 236) = 1124859904;
  *(_DWORD *)(this + 240) = 1028443341;
  *(_DWORD *)(this + 244) = 1090519040;
  return result;
}
