unsigned __int8 __stdcall sub_47A040(int a1, int a2)
{
  unsigned __int8 result; // al
  int v3; // ebp
  unsigned __int8 v4; // dl
  int v5; // ecx
  _DWORD *v6; // edi
  unsigned __int8 v7; // bl
  _DWORD *v8; // esi
  unsigned __int8 v9; // al
  int v10; // ecx
  int v11; // eax
  _DWORD *v12; // ecx
  unsigned __int8 v13; // [esp+Bh] [ebp-1h]
  unsigned __int8 v14; // [esp+14h] [ebp+8h]

  result = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 92))(dword_76BB24);
  v3 = a1;
  v4 = 0;
  v13 = result;
  if ( a2 > 0 )
  {
    v5 = 0;
    do
    {
      *(_DWORD *)(a1 + 4 * v5) = 0;
      v5 = ++v4;
    }
    while ( v4 < a2 );
  }
  LOBYTE(a1) = 0;
  if ( result )
  {
    do
    {
      v6 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_76BB24 + 96))(dword_76BB24, a1);
      v7 = 0;
      while ( 1 )
      {
        v8 = *(_DWORD **)(v3 + 4 * v7);
        if ( !v8 )
        {
          *(_DWORD *)(v3 + 4 * v7) = v6;
          goto LABEL_17;
        }
        if ( sub_40EFA0(v6) )
        {
          if ( sub_40EFA0(v8) )
          {
            v14 = *(_BYTE *)(sub_40EFA0(v6) + 16);
            if ( v14 < *(_BYTE *)(sub_40EFA0(v8) + 16) )
              break;
          }
        }
        if ( ++v7 >= v13 )
          goto LABEL_17;
      }
      v9 = v13 - 1;
      if ( (unsigned __int8)(v13 - 1) > v7 )
      {
        v10 = v9;
        v11 = (unsigned __int8)(v9 - v7);
        v12 = (_DWORD *)(v3 + 4 * v10);
        do
        {
          *v12 = *(v12 - 1);
          --v12;
          --v11;
        }
        while ( v11 );
      }
      *(_DWORD *)(v3 + 4 * v7) = v6;
LABEL_17:
      result = a1 + 1;
      LOBYTE(a1) = a1 + 1;
    }
    while ( (unsigned __int8)a1 < v13 );
  }
  return result;
}
