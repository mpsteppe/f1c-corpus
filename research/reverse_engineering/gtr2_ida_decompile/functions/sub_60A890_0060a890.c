int __thiscall sub_60A890(_DWORD *this, int a2, int a3, int a4, char a5, char a6)
{
  int v6; // esi
  int result; // eax
  _DWORD *v9; // ebx
  signed int v10; // ebp
  int v11; // esi
  int v12; // ebp
  int v13; // eax
  int v14; // eax
  int v15; // ebp
  int v16; // eax
  bool v17; // zf
  int v18; // [esp+4h] [ebp-2Ch]
  int v19; // [esp+8h] [ebp-28h]
  signed int v20; // [esp+1Ch] [ebp-14h]
  _DWORD **v21; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  int v23; // [esp+28h] [ebp-8h]
  int v24; // [esp+2Ch] [ebp-4h]

  v6 = a4;
  result = this[a4 + 2271];
  v21 = (_DWORD **)this[a4 + 2277];
  if ( result > 0 )
  {
    v23 = this[a4 + 2271];
    do
    {
      v9 = *v21;
      v10 = 0;
      v20 = 0;
      do
      {
        (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD *, signed int, _DWORD))(*this + 40))(this, 0, v9, v10, 0);
        sub_5F7B60(v9, 0, v10);
        sub_5F7BF0(v9, v10);
        v24 = *(_DWORD *)v9[v6 + 189];
        for ( i = 0; i < v24; ++i )
        {
          v11 = *(_DWORD *)(*(_DWORD *)(v9[v6 + 189] + 4) + 4 * i);
          if ( v10 && a5 )
          {
            v12 = *(_DWORD *)(sub_5E80D0((_DWORD *)v11, 0) + 124);
            v13 = sub_5E8830((_DWORD *)v11, 0);
            (*(void (__thiscall **)(_DWORD *, int, int, int))(*this + 20))(this, v13 | 0x800, 131074, v12);
          }
          else
          {
            v14 = sub_5E80D0((_DWORD *)v11, 0);
            v15 = *this;
            v19 = *(_DWORD *)(v14 + 124);
            v18 = *(_DWORD *)(v11 + 236) | (*(_DWORD *)(v11 + 240) << 16);
            v16 = sub_5E8830((_DWORD *)v11, 0);
            (*(void (__thiscall **)(_DWORD *, int, int, int))(v15 + 20))(this, v16, v18, v19);
          }
          if ( a6 && !v20 )
          {
            *(_BYTE *)(v11 + 200) = 0;
            *(_DWORD *)(v11 + 208) = 0;
          }
          v10 = v20;
          v6 = a4;
        }
        v20 = ++v10;
      }
      while ( v10 < 1 );
      if ( a6 )
      {
        *v21 = 0;
        *(_DWORD *)v9[v6 + 189] = 0;
        v9[v6 + 177] = 0;
        v9[v6 + 195] = 0;
      }
      result = v23 - 1;
      v17 = v23 == 1;
      ++v21;
      --v23;
    }
    while ( !v17 );
  }
  return result;
}
