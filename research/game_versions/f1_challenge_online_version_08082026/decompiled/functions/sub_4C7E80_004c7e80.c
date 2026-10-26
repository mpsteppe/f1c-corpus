int __fastcall sub_4C7E80(int a1)
{
  int *v1; // ebp
  int v2; // esi
  _DWORD *v3; // edi
  bool v4; // zf
  int result; // eax
  int *v6; // ebp
  int v7; // esi
  _DWORD *v8; // edi
  int v9; // [esp+8h] [ebp-4h]

  v1 = *(int **)(a1 + 12);
  v9 = a1;
  if ( v1 )
  {
    v2 = *v1;
    if ( *v1 )
    {
      do
      {
        v3 = (_DWORD *)v2;
        v4 = *(_BYTE *)(v2 + 8) == 0;
        v2 = *(_DWORD *)(v2 + 4);
        if ( !v4 && *v3 )
          (**(void (__thiscall ***)(_DWORD, int))*v3)(*v3, 1);
        result = sub_587BCF(v3);
      }
      while ( v2 );
      a1 = v9;
    }
    *v1 = 0;
    v1[1] = 0;
    v1[2] = 0;
    v1[3] = 0;
    v6 = *(int **)(a1 + 12);
    if ( v6 )
    {
      v7 = *v6;
      while ( v7 )
      {
        v8 = (_DWORD *)v7;
        v4 = *(_BYTE *)(v7 + 8) == 0;
        v7 = *(_DWORD *)(v7 + 4);
        if ( !v4 )
        {
          if ( *v8 )
            (**(void (__thiscall ***)(_DWORD, int))*v8)(*v8, 1);
        }
        sub_587BCF(v8);
      }
      *v6 = 0;
      v6[1] = 0;
      v6[2] = 0;
      v6[3] = 0;
      result = sub_587BCF(v6);
      a1 = v9;
    }
    *(_DWORD *)(a1 + 12) = 0;
  }
  return result;
}
