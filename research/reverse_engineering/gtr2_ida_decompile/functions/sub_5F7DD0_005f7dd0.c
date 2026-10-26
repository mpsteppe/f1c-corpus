int __thiscall sub_5F7DD0(_DWORD **this)
{
  int v1; // edi
  int v2; // esi
  _DWORD **v3; // ebp
  _DWORD *v4; // edx
  int v5; // eax
  int v6; // edi
  int v7; // ecx
  int v8; // edx
  bool v9; // zf
  int result; // eax
  char *v11; // edx
  _DWORD *v12; // [esp+10h] [ebp-14h]
  int v13; // [esp+14h] [ebp-10h]
  int v14; // [esp+18h] [ebp-Ch]
  int v15; // [esp+1Ch] [ebp-8h]
  int v16; // [esp+20h] [ebp-4h]

  v14 = -8400 - (_DWORD)this;
  v1 = -24 - (_DWORD)this;
  v2 = 756;
  v3 = this + 2277;
  v15 = -8328 - (_DWORD)this;
  v16 = -24 - (_DWORD)this;
  do
  {
    v4 = *v3;
    v12 = *v3;
    if ( (int)*(v3 - 6) > 0 )
    {
      v13 = (int)*(v3 - 6);
      do
      {
        v5 = *v4;
        if ( *v4 )
        {
          v6 = **(_DWORD **)(v2 + v5);
          v7 = 0;
          if ( v6 > 0 )
          {
            do
            {
              v8 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + v5) + 4) + 4 * v7++);
              *(_BYTE *)(v8 + 200) = 0;
              *(_DWORD *)(v8 + 208) = 0;
            }
            while ( v7 < v6 );
            v4 = v12;
          }
          *v4 = 0;
          **(_DWORD **)(v2 + v5) = 0;
          *(_DWORD **)((char *)v3 + v14 + v5) = 0;
          *(_DWORD **)((char *)v3 + v15 + v5) = 0;
        }
        ++v4;
        v9 = v13 == 1;
        v12 = v4;
        --v13;
      }
      while ( !v9 );
      v1 = v16;
    }
    result = dword_FB27A4;
    v11 = (char *)v3 + v1;
    v2 += 4;
    ++v3;
    *(_DWORD *)&v11[dword_FB27A4] = 0;
  }
  while ( v2 < 780 );
  return result;
}
