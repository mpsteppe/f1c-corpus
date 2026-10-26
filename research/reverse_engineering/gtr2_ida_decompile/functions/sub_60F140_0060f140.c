int __thiscall sub_60F140(_DWORD *this, int a2, _DWORD *a3)
{
  int v4; // edi
  int v5; // eax
  _DWORD *v6; // ebp
  int v7; // eax
  int v8; // edi
  int v9; // eax
  _BYTE **v10; // edi
  int v11; // ebx
  int v12; // edx
  _DWORD *v13; // ecx
  _DWORD *v14; // edi
  char v15; // bl
  int v16; // edx
  bool v17; // zf
  int v19; // [esp+60h] [ebp-3Ch]
  int v20; // [esp+64h] [ebp-38h]
  int v21; // [esp+78h] [ebp-24h]
  int v22; // [esp+7Ch] [ebp-20h]
  int *v23; // [esp+80h] [ebp-1Ch]
  int v24; // [esp+84h] [ebp-18h]
  int v25; // [esp+88h] [ebp-14h]
  int v26; // [esp+8Ch] [ebp-10h]
  _BYTE **v27; // [esp+90h] [ebp-Ch]
  int v28; // [esp+94h] [ebp-8h]
  int v29; // [esp+98h] [ebp-4h]

  v4 = this[2273];
  v23 = (int *)this[2279];
  (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*this + 44))(this, 168, 0);
  if ( v4 > 0 )
  {
    v25 = v4;
    do
    {
      v5 = *v23;
      v26 = *v23;
      v29 = **(_DWORD **)(*v23 + 764);
      v22 = 0;
      if ( v29 > 0 )
      {
        while ( 1 )
        {
          v6 = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(v5 + 764) + 4) + 4 * v22);
          v7 = sub_5E80D0(v6, 0);
          v8 = *this;
          v20 = *(_DWORD *)(v7 + 124);
          v19 = v6[59] | (v6[60] << 16);
          v9 = sub_5E8830(v6, 0);
          (*(void (__thiscall **)(_DWORD *, int, int, int))(v8 + 20))(this, v9, v19, v20);
          v10 = (_BYTE **)v6[53];
          v11 = 0;
          v24 = 0;
          v27 = v10;
          if ( (int)v6[52] > 0 )
          {
            v12 = *this;
            if ( (**v10 & 8) != 0 )
            {
              (*(void (__thiscall **)(_DWORD *, _DWORD, int, _DWORD, _DWORD))(v12 + 40))(this, 0, dword_FB4134, 0, 0);
              v13 = (_DWORD *)dword_FB4134;
            }
            else
            {
              (*(void (__thiscall **)(_DWORD *, _DWORD, int, _DWORD, _DWORD))(v12 + 40))(this, 0, dword_FB4130, 0, 0);
              v13 = (_DWORD *)dword_FB4130;
            }
            v21 = sub_5F7B60(v13, 0, 0);
          }
          if ( v21 && (int)v6[52] > 0 )
          {
            while ( 1 )
            {
              v14 = v10[v11];
              (*(void (__thiscall **)(_DWORD *, _DWORD *, _DWORD))(*this + 28))(this, v14, 0);
              (*(void (__thiscall **)(_DWORD *, _DWORD *, _DWORD *))(*this + 48))(this, v6, v14);
              if ( (*v14 & 0x400000) != 0 )
              {
                if ( sub_5FA770(v21, (int)a3, (int)v14, 1) )
                {
                  v15 = 0;
                  if ( (*a3 & 0x40000) == 0 )
                  {
                    v28 = this[1202];
                    (*(void (__thiscall **)(_DWORD *, int, int))(*this + 44))(this, 22, 3);
                    v15 = 1;
                  }
                  this[2] = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this[2387] + 328))(
                              this[2387],
                              v14[20],
                              v14[13],
                              0,
                              v14[2],
                              v14[14],
                              v14[21]);
                  if ( v15 )
                  {
                    v16 = *this;
                    this[1202] = v28;
                    (*(void (__thiscall **)(_DWORD *, int, int))(v16 + 44))(this, 22, v28);
                  }
                }
                v11 = v24;
                dword_FB3EBC = 0;
                dword_FB3EB8 = 0;
              }
              if ( ((unsigned int)&byte_800000 & *v14) == 0 && sub_5FA770(v21, (int)a3, (int)v14, 0) )
                this[2] = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this[2387] + 328))(
                            this[2387],
                            v14[20],
                            v14[13],
                            0,
                            v14[2],
                            v14[14],
                            v14[21]);
              v24 = ++v11;
              if ( v11 >= v6[52] )
                break;
              v10 = v27;
            }
          }
          if ( ++v22 >= v29 )
            break;
          v5 = v26;
        }
      }
      v17 = v25 == 1;
      ++v23;
      --v25;
    }
    while ( !v17 );
  }
  return (*(int (__thiscall **)(_DWORD *, int, int))(*this + 44))(this, 168, 15);
}
