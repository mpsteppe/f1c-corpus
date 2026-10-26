int __thiscall sub_59B050(int this, char a2)
{
  _DWORD *v3; // ebx
  int v4; // ebp
  int v5; // eax
  _DWORD *v6; // edi
  int v7; // edx
  int v8; // edx
  _DWORD *v9; // edi
  int v10; // edx
  int v11; // eax
  int v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // ebp
  _DWORD *v15; // edi
  int v16; // ebx
  int v17; // eax
  int v19; // [esp+4h] [ebp-A4h]
  int v20; // [esp+8h] [ebp-A0h]
  _DWORD v21[3]; // [esp+10h] [ebp-98h] BYREF
  _DWORD v22[3]; // [esp+1Ch] [ebp-8Ch] BYREF
  _DWORD v23[3]; // [esp+28h] [ebp-80h] BYREF
  _DWORD v24[3]; // [esp+34h] [ebp-74h] BYREF
  _DWORD v25[10]; // [esp+40h] [ebp-68h] BYREF
  _BYTE v26[64]; // [esp+68h] [ebp-40h] BYREF

  if ( (*(_DWORD *)(this + 20) & 0x4000000) == 0 )
  {
    sub_5904C0(v25);
    sub_590590(v25, *(_DWORD *)(this + 256), *(_DWORD *)(this + 260), *(_DWORD *)(this + 264));
    sub_5905D0((int)v25, *(float *)(this + 268), *(float *)(this + 272), *(float *)(this + 276));
    v3 = 0;
    v20 = 0;
    if ( *(int *)(this + 280) > 0 )
    {
      v4 = 0;
      do
      {
        v19 = 0;
        if ( ((unsigned int)&unk_800000 & *(_DWORD *)(this + 20)) != 0 )
        {
          v5 = *(_DWORD *)(this + 284);
          v6 = *(_DWORD **)(v5 + v4 + 12);
          if ( *(int *)(v5 + v4 + 8) > 0 )
          {
            do
            {
              (*(void (__cdecl **)(int, _DWORD *, _DWORD *, _BYTE *))(*(_DWORD *)dword_7E8E58 + 4))(
                dword_7E8E58,
                v6,
                v23,
                v26);
              (**(void (__cdecl ***)(int, int, _DWORD *, _BYTE *))dword_7E8E58)(dword_7E8E58, (int)(v6 + 7), v24, v26);
              if ( (*(_BYTE *)(*(_DWORD *)(this + 312) + 60) & 0x10) == 0 )
              {
                *v6 = v23[0];
                v6[1] = v23[1];
                v6[2] = v23[2];
                v6[7] = v24[0];
                v6[8] = v24[1];
                v6[9] = v24[2];
              }
              v7 = v6[13];
              v6[14] = v6[12];
              v6[15] = v7;
              v6 += 16;
              ++v19;
            }
            while ( v19 < *(_DWORD *)(*(_DWORD *)(this + 284) + v4 + 8) );
            v3 = 0;
          }
          sub_59E170(0, 0, 0, 0.0, 0.0, 0.0);
        }
        else
        {
          v8 = *(_DWORD *)(this + 284);
          v9 = *(_DWORD **)(v8 + v4 + 12);
          if ( *(int *)(v8 + v4 + 8) > 0 )
          {
            do
            {
              (*(void (__cdecl **)(int, _DWORD *, _DWORD *, _BYTE *))(*(_DWORD *)dword_7E8E58 + 4))(
                dword_7E8E58,
                v9,
                v21,
                v26);
              (**(void (__cdecl ***)(int, int, _DWORD *, _BYTE *))dword_7E8E58)(dword_7E8E58, (int)(v9 + 3), v22, v26);
              if ( (*(_BYTE *)(*(_DWORD *)(this + 312) + 60) & 0x10) == 0 )
              {
                *v9 = v21[0];
                v9[1] = v21[1];
                v9[2] = v21[2];
                v9[3] = v22[0];
                v9[4] = v22[1];
                v9[5] = v22[2];
              }
              v10 = v9[9];
              v9[10] = v9[8];
              v9[11] = v10;
              v9 += 12;
              ++v19;
            }
            while ( v19 < *(_DWORD *)(*(_DWORD *)(this + 284) + v4 + 8) );
            v3 = 0;
          }
        }
        *(_DWORD *)(*(_DWORD *)(this + 284) + v4 + 52) = -1;
        *(_DWORD *)(*(_DWORD *)(this + 284) + v4 + 28) = 0;
        *(_DWORD *)(*(_DWORD *)(this + 284) + v4 + 32) = 0;
        *(_DWORD *)(*(_DWORD *)(this + 284) + v4 + 36) = 0;
        *(_DWORD *)(*(_DWORD *)(this + 284) + v4 + 40) = 0;
        *(_DWORD *)(*(_DWORD *)(this + 284) + v4 + 56) = 0;
        v11 = *(_DWORD *)(this + 284) + v4;
        if ( *(int *)(v11 + 60) > 0 )
          *(_DWORD *)(v11 + 56) |= 0x1000u;
        if ( (a2 & 4) != 0 )
        {
          v12 = *(_DWORD *)(*(_DWORD *)(this + 284) + v4 + 4);
          *(_DWORD *)(v12 + 156) |= 0x8000u;
        }
        v4 += 64;
        ++v20;
      }
      while ( v20 < *(_DWORD *)(this + 280) );
    }
    sub_59BF20(COERCE_FLOAT(1));
    sub_59CC90(this);
    sub_59BA20(0);
    sub_59CAA0(this);
    *(_DWORD *)(this + 268) = 0;
    *(_DWORD *)(this + 276) = 0;
    *(_DWORD *)(this + 272) = 0;
    *(_DWORD *)(this + 264) = 0;
    *(_DWORD *)(this + 260) = 0;
    *(_DWORD *)(this + 256) = 0;
    *(_DWORD *)(this + 268) = 0;
    v13 = operator new(0x1C4u);
    if ( v13 )
    {
      v14 = v13 + 1;
      *v13 = 8;
      v15 = v13 + 1;
      v16 = 8;
      do
      {
        sub_5B58A0(v15);
        v15 += 14;
        --v16;
      }
      while ( v16 );
      v3 = v14;
    }
    v17 = *(_DWORD *)(this + 20) | 0x4000000;
    *(_DWORD *)(this + 272) = v3;
    *(_DWORD *)(this + 20) = v17;
    nullsub_10();
  }
  return 0;
}
