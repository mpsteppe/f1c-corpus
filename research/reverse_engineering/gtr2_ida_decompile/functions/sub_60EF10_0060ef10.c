int __thiscall sub_60EF10(_DWORD *this, int a2, int a3, char a4, char a5)
{
  int result; // eax
  _DWORD *v7; // ebp
  int v8; // esi
  signed int v9; // ebx
  int v10; // ebp
  int v11; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // ebx
  int v15; // eax
  int v16; // ebx
  _DWORD *v17; // esi
  bool v18; // zf
  int v19; // [esp+40h] [ebp-44h]
  int v20; // [esp+44h] [ebp-40h]
  int v21; // [esp+58h] [ebp-2Ch]
  signed int v22; // [esp+5Ch] [ebp-28h]
  signed int v23; // [esp+60h] [ebp-24h]
  _DWORD *v24; // [esp+64h] [ebp-20h]
  int v25; // [esp+68h] [ebp-1Ch]
  signed int v26; // [esp+6Ch] [ebp-18h]
  int v27; // [esp+70h] [ebp-14h]
  _DWORD *v28; // [esp+74h] [ebp-10h]
  int v29; // [esp+78h] [ebp-Ch]
  int v30; // [esp+7Ch] [ebp-8h]
  int v31; // [esp+80h] [ebp-4h]

  result = this[2276];
  v7 = (_DWORD *)this[2282];
  v24 = v7;
  if ( result > 0 )
  {
    v25 = this[2276];
    do
    {
      v8 = *v7;
      v30 = *v7;
      sub_5F7B20(a2);
      v9 = v26;
      v22 = v26;
      if ( v26 < v23 )
      {
        do
        {
          (*(void (__thiscall **)(_DWORD *, _DWORD, int, signed int, _DWORD))(*this + 40))(this, 0, v8, v9, 0);
          v29 = sub_5F7B60((_DWORD *)v8, 0, v9);
          v28 = (_DWORD *)sub_5F7BF0((_DWORD *)v8, v9);
          v31 = **(_DWORD **)(v8 + 776);
          v21 = 0;
          if ( v31 > 0 )
          {
            do
            {
              v10 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v8 + 776) + 4) + 4 * v21);
              if ( a5 )
              {
                v11 = *(_DWORD *)(sub_5E80D0((_DWORD *)v10, 0) + 124);
                v12 = sub_5E8830((_DWORD *)v10, 0);
                (*(void (__thiscall **)(_DWORD *, unsigned int, _DWORD, int))(*this + 20))(
                  this,
                  v12 & 0xFFFFE7FF,
                  0,
                  v11);
              }
              else
              {
                v13 = sub_5E80D0((_DWORD *)v10, 0);
                v14 = *this;
                v20 = *(_DWORD *)(v13 + 124);
                v19 = *(_DWORD *)(v10 + 236) | (*(_DWORD *)(v10 + 240) << 16);
                v15 = sub_5E8830((_DWORD *)v10, 0);
                (*(void (__thiscall **)(_DWORD *, int, int, int))(v14 + 20))(this, v15, v19, v20);
              }
              v16 = 0;
              v27 = *(_DWORD *)(v10 + 212);
              if ( *(int *)(v10 + 208) > 0 )
              {
                do
                {
                  v17 = *(_DWORD **)(v27 + 4 * v16++);
                  (*(void (__thiscall **)(_DWORD *, _DWORD *, _DWORD))(*this + 28))(this, v17, 0);
                  (*(void (__thiscall **)(_DWORD *, int, _DWORD *))(*this + 48))(this, v10, v17);
                  sub_5F77D0(v28, a3, (int)v17);
                  if ( sub_5FA770(v29, a3, (int)v17, 0) )
                    this[2] = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this[2387] + 328))(
                                this[2387],
                                v17[20],
                                v17[13],
                                0,
                                v17[2],
                                v17[14],
                                v17[21]);
                }
                while ( v16 < *(_DWORD *)(v10 + 208) );
                v8 = v30;
              }
              if ( a4 && v22 == v23 - 1 )
              {
                *(_BYTE *)(v10 + 200) = 0;
                *(_DWORD *)(v10 + 208) = 0;
              }
              ++v21;
            }
            while ( v21 < v31 );
            v9 = v22;
          }
          v22 = ++v9;
        }
        while ( v9 < v23 );
        v7 = v24;
      }
      if ( a4 )
      {
        *v7 = 0;
        **(_DWORD **)(v8 + 776) = 0;
        *(_DWORD *)(v8 + 728) = 0;
        *(_DWORD *)(v8 + 800) = 0;
      }
      ++v7;
      result = v25 - 1;
      v18 = v25 == 1;
      v24 = v7;
      --v25;
    }
    while ( !v18 );
  }
  return result;
}
