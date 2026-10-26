int __stdcall sub_644F37(int a1, void (__stdcall *a2)(char *, float *, float *, int), int a3)
{
  int v3; // ebx
  int v4; // esi
  int v5; // eax
  int v6; // edi
  void *v7; // eax
  void *v8; // esi
  int v10; // eax
  int v11; // ebx
  int v12; // eax
  int v13; // esi
  char *v14; // edi
  _BYTE v15[84]; // [esp+8h] [ebp-E0h] BYREF
  _BYTE v16[24]; // [esp+5Ch] [ebp-8Ch] BYREF
  int v17; // [esp+74h] [ebp-74h]
  _BYTE v18[24]; // [esp+7Ch] [ebp-6Ch] BYREF
  unsigned int v19; // [esp+94h] [ebp-54h]
  unsigned int v20; // [esp+98h] [ebp-50h]
  _BYTE v21[20]; // [esp+9Ch] [ebp-4Ch] BYREF
  float v22[2]; // [esp+B0h] [ebp-38h] BYREF
  float v23[2]; // [esp+B8h] [ebp-30h] BYREF
  float v24; // [esp+C0h] [ebp-28h]
  float v25; // [esp+C4h] [ebp-24h]
  unsigned int v26; // [esp+C8h] [ebp-20h]
  signed int v27; // [esp+CCh] [ebp-1Ch]
  float v28; // [esp+D0h] [ebp-18h]
  int v29; // [esp+D4h] [ebp-14h]
  int i; // [esp+D8h] [ebp-10h]
  void *Block; // [esp+DCh] [ebp-Ch]
  int v32; // [esp+E0h] [ebp-8h]
  int v33; // [esp+E4h] [ebp-4h] BYREF

  v33 = 0;
  sub_64E466(v21);
  v3 = a1;
  if ( a1 && a2 )
  {
    v26 = (*(int (__stdcall **)(int))(*(_DWORD *)a1 + 52))(a1);
    v5 = (*(int (__stdcall **)(int, _DWORD, _BYTE *))(*(_DWORD *)a1 + 68))(a1, 0, v16);
    if ( v5 >= 0 )
    {
      v6 = v17;
      v7 = operator new(16 * v17);
      v8 = v7;
      if ( v7 )
      {
        sub_41D1B0((int)v7, 16, v6, (int)sub_681563);
        Block = v8;
      }
      else
      {
        Block = 0;
      }
      if ( Block )
      {
        v32 = 0;
        if ( v26 )
        {
          while ( 1 )
          {
            v4 = (*(int (__stdcall **)(int, int, _BYTE *))(*(_DWORD *)v3 + 68))(v3, v32, v18);
            if ( v4 < 0 )
              break;
            (*(void (__stdcall **)(int, int, int *))(*(_DWORD *)v3 + 72))(v3, v32, &v33);
            v10 = v32 ? sub_64E610(v15, v33, 0, 0, 0, 0) : sub_64E610(v15, v33, 0, 0, 0, 0x20000);
            v4 = v10;
            if ( v10 < 0 )
              break;
            v11 = v19;
            v27 = v20;
            v28 = *(float *)&v20;
            v24 = 1.0 / (double)v19;
            v25 = 1.0 / (double)v20;
            v23[0] = v24;
            v23[1] = v25;
            v12 = sub_659124(v15);
            v13 = v12;
            if ( !v12 )
            {
              v4 = -2005530516;
              break;
            }
            sub_64FE1D(v12);
            for ( i = 0; i < v27; ++i )
            {
              v29 = 0;
              v14 = (char *)Block;
              if ( v11 > 0 )
              {
                v28 = ((double)i + 0.5) * v25;
                do
                {
                  v22[1] = v28;
                  v22[0] = ((double)v29 + 0.5) * v24;
                  a2(v14, v22, v23, a3);
                  v14 += 16;
                  ++v29;
                }
                while ( v29 < v11 );
              }
              (*(void (__thiscall **)(int, int, _DWORD, void *))(*(_DWORD *)v13 + 8))(v13, i, 0, Block);
            }
            (**(void (__thiscall ***)(int, int))v13)(v13, 1);
            if ( v33 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v33 + 8))(v33);
              v33 = 0;
            }
            if ( ++v32 >= v26 )
              goto LABEL_12;
            v3 = a1;
          }
        }
        else
        {
LABEL_12:
          v4 = 0;
        }
      }
      else
      {
        v4 = -2147024882;
      }
      if ( v33 )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)v33 + 8))(v33);
        v33 = 0;
      }
      j__free(Block);
    }
    else
    {
      v4 = v5;
    }
  }
  else
  {
    v4 = -2005530516;
  }
  sub_64E60B(v21);
  return v4;
}
