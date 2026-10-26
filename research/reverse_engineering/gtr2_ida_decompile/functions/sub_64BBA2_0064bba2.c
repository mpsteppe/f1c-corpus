int __thiscall sub_64BBA2(_DWORD *this)
{
  _WORD *v2; // ecx
  int v3; // esi
  unsigned __int16 *v4; // ebx
  unsigned __int16 *v5; // edi
  unsigned __int16 *v6; // edx
  int v7; // esi
  int v8; // ecx
  int v9; // edx
  int v10; // edi
  unsigned int v11; // ebx
  int v12; // esi
  unsigned int v13; // edx
  int v14; // edi
  _WORD *v15; // ecx
  unsigned __int16 *i; // [esp+10h] [ebp-24h]
  unsigned __int16 *v18; // [esp+14h] [ebp-20h]
  unsigned __int16 *v19; // [esp+18h] [ebp-1Ch]
  _WORD *v20; // [esp+1Ch] [ebp-18h]
  unsigned __int16 *v21; // [esp+20h] [ebp-14h]
  unsigned __int16 *v22; // [esp+24h] [ebp-10h]
  int v23; // [esp+28h] [ebp-Ch]
  _WORD *v24; // [esp+2Ch] [ebp-8h]
  int v25; // [esp+30h] [ebp-4h]

  v2 = *(_WORD **)(this[1] + 32);
  v3 = *this;
  v4 = *(unsigned __int16 **)(*this + 32);
  v5 = (unsigned __int16 *)((char *)v4 + *(_DWORD *)(*this + 96) * *(_DWORD *)(*this + 108));
  v20 = v2;
  v19 = v4;
  for ( i = v5; v4 < v5; v19 = v4 )
  {
    v6 = (unsigned __int16 *)((char *)v4 + *(_DWORD *)(v3 + 96));
    v24 = v2;
    v22 = v4;
    v21 = v6;
    v18 = &v4[*(_DWORD *)(v3 + 104)];
    if ( v4 < v18 )
    {
      do
      {
        v7 = v6[1];
        v8 = *v6;
        v9 = *v4;
        v10 = v4[1];
        v25 = v8;
        v23 = v9;
        LOWORD(v9) = (unsigned __int8)*v4;
        v11 = (v8 & 0xFFFF00FF) + v9 + (v7 & 0xFFFF00FF);
        HIWORD(v8) = HIWORD(v7);
        v12 = v7 & 0xFF00;
        LOWORD(v8) = v12;
        v13 = v11 + (v10 & 0xFFFF00FF) + 2;
        HIWORD(v11) = HIWORD(v10);
        v14 = v10 & 0xFF00;
        LOWORD(v11) = v14;
        LOWORD(v13) = (((v25 & 0xFF00) + (v23 & 0xFF00u) + v12 + v14 + 512) >> 2)
                    ^ (unsigned __int8)((((v25 & 0xFFFFFF00) + (v23 & 0xFFFFFF00) + v8 + v11 + 512) >> 2) ^ (v13 >> 2));
        v15 = v24++;
        *v15 = v13;
        v4 = v22 + 2;
        v6 = v21 + 2;
        v22 = v4;
        v21 += 2;
      }
      while ( v4 < v18 );
      v2 = v20;
      v4 = v19;
      v5 = i;
    }
    v2 = (_WORD *)((char *)v2 + *(_DWORD *)(this[1] + 96));
    v3 = *this;
    v4 += *(_DWORD *)(*this + 96);
    v20 = v2;
  }
  return 0;
}
