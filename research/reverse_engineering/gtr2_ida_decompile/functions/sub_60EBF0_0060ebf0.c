int __thiscall sub_60EBF0(_DWORD *this, int a2, _DWORD *a3, int a4, int a5, char a6)
{
  int v6; // ebx
  int v8; // esi
  BOOL v9; // eax
  int result; // eax
  _DWORD *v11; // esi
  signed int v12; // ebp
  int v13; // ebp
  int v14; // eax
  int v15; // ebx
  int v16; // eax
  int v17; // ebx
  _DWORD *v18; // esi
  char v19; // bl
  int v20; // edx
  bool v21; // zf
  int v22; // [esp+78h] [ebp-50h]
  int v23; // [esp+7Ch] [ebp-4Ch]
  _DWORD **v24; // [esp+90h] [ebp-38h]
  int v25; // [esp+94h] [ebp-34h]
  signed int i; // [esp+98h] [ebp-30h]
  signed int v27; // [esp+9Ch] [ebp-2Ch]
  int v28; // [esp+A0h] [ebp-28h]
  int v29; // [esp+A4h] [ebp-24h]
  int v30; // [esp+A8h] [ebp-20h]
  signed int v31; // [esp+B0h] [ebp-18h]
  int v32; // [esp+B4h] [ebp-14h]
  _DWORD *v33; // [esp+B8h] [ebp-10h]
  int v34; // [esp+BCh] [ebp-Ch]
  _DWORD *v35; // [esp+C0h] [ebp-8h]
  int v36; // [esp+C4h] [ebp-4h]

  v6 = a4;
  v8 = this[a4 + 2271];
  v24 = (_DWORD **)this[a4 + 2277];
  v9 = this[2253] && *((_BYTE *)this + a4 + 9052);
  result = (*(int (__thiscall **)(_DWORD *, int, BOOL))(*this + 44))(this, 28, v9);
  if ( v8 > 0 )
  {
    v30 = v8;
    do
    {
      v11 = *v24;
      v35 = *v24;
      sub_5F7B20(a2);
      v12 = v31;
      for ( i = v31; v12 < v27; i = v12 )
      {
        (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD *, signed int, _DWORD))(*this + 40))(this, 0, v11, v12, 0);
        v29 = sub_5F7B60(v11, 0, v12);
        v33 = (_DWORD *)sub_5F7BF0(v11, v12);
        (*(void (__thiscall **)(_DWORD *, int))(*this + 76))(this, a5);
        v36 = *(_DWORD *)v11[v6 + 189];
        v25 = 0;
        if ( v36 > 0 )
        {
          do
          {
            v13 = *(_DWORD *)(*(_DWORD *)(v11[v6 + 189] + 4) + 4 * v25);
            v14 = sub_5E80D0((_DWORD *)v13, 0);
            v15 = *this;
            v23 = *(_DWORD *)(v14 + 124);
            v22 = *(_DWORD *)(v13 + 236) | (*(_DWORD *)(v13 + 240) << 16);
            v16 = sub_5E8830((_DWORD *)v13, 0);
            (*(void (__thiscall **)(_DWORD *, int, int, int))(v15 + 20))(this, v16, v22, v23);
            v17 = 0;
            v32 = *(_DWORD *)(v13 + 212);
            if ( *(int *)(v13 + 208) > 0 )
            {
              do
              {
                v18 = *(_DWORD **)(v32 + 4 * v17++);
                v28 = v17;
                (*(void (__thiscall **)(_DWORD *, _DWORD *, _DWORD))(*this + 28))(this, v18, 0);
                (*(void (__thiscall **)(_DWORD *, int, _DWORD *))(*this + 48))(this, v13, v18);
                sub_5F77D0(v33, (int)a3, (int)v18);
                if ( (*v18 & 0x400000) != 0 )
                {
                  if ( sub_5FA770(v29, (int)a3, (int)v18, 1) )
                  {
                    v19 = 0;
                    if ( (*a3 & 0x40000) == 0 )
                    {
                      v34 = this[1202];
                      (*(void (__thiscall **)(_DWORD *, int, int))(*this + 44))(this, 22, 3);
                      v19 = 1;
                    }
                    this[2] = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this[2387] + 328))(
                                this[2387],
                                v18[20],
                                v18[13],
                                0,
                                v18[2],
                                v18[14],
                                v18[21]);
                    if ( v19 )
                    {
                      v20 = *this;
                      this[1202] = v34;
                      (*(void (__thiscall **)(_DWORD *, int, int))(v20 + 44))(this, 22, v34);
                    }
                    v17 = v28;
                  }
                  dword_FB3EBC = 0;
                  dword_FB3EB8 = 0;
                }
                if ( ((unsigned int)&byte_800000 & *v18) == 0 && sub_5FA770(v29, (int)a3, (int)v18, 0) )
                  this[2] = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this[2387] + 328))(
                              this[2387],
                              v18[20],
                              v18[13],
                              0,
                              v18[2],
                              v18[14],
                              v18[21]);
              }
              while ( v17 < *(_DWORD *)(v13 + 208) );
              v11 = v35;
            }
            if ( a6 && i == v27 - 1 )
            {
              *(_BYTE *)(v13 + 200) = 0;
              *(_DWORD *)(v13 + 208) = 0;
            }
            v6 = a4;
            ++v25;
          }
          while ( v25 < v36 );
          v12 = i;
        }
        ++v12;
      }
      if ( a6 )
      {
        *v24 = 0;
        *(_DWORD *)v11[v6 + 189] = 0;
        v11[v6 + 177] = 0;
        v11[v6 + 195] = 0;
      }
      result = v30 - 1;
      v21 = v30 == 1;
      ++v24;
      --v30;
    }
    while ( !v21 );
  }
  return result;
}
