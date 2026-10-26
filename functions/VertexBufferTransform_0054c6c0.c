int __thiscall sub_54C6C0(int this, char a2)
{
  int v3; // ebp
  int v4; // eax
  _DWORD *v5; // edi
  int v6; // edx
  int v7; // edx
  _DWORD *v8; // edi
  int v9; // edx
  int v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // edi
  int v13; // ebp
  _DWORD *v14; // eax
  int v15; // eax
  int v17; // [esp+4h] [ebp-A4h]
  _DWORD *v18; // [esp+8h] [ebp-A0h]
  int v19; // [esp+Ch] [ebp-9Ch]
  _DWORD v20[3]; // [esp+10h] [ebp-98h] BYREF
  _DWORD v21[3]; // [esp+1Ch] [ebp-8Ch] BYREF
  _DWORD v22[3]; // [esp+28h] [ebp-80h] BYREF
  _DWORD v23[3]; // [esp+34h] [ebp-74h] BYREF
  _DWORD v24[10]; // [esp+40h] [ebp-68h] BYREF
  _BYTE v25[64]; // [esp+68h] [ebp-40h] BYREF

  if ( (*(_DWORD *)(this + 20) & 0x4000000) == 0 )
  {
    F_10FloatStructInitializer(v24);
    MultiFieldSetter(v24, *(_DWORD *)(this + 256), *(_DWORD *)(this + 260), *(_DWORD *)(this + 264));
    EulerAngleToRotationMatrix((int)v24, *(float *)(this + 268), *(float *)(this + 272), *(float *)(this + 276));
    v19 = 0;
    if ( *(int *)(this + 280) > 0 )
    {
      v3 = 0;
      do
      {
        v17 = 0;
        if ( ((unsigned int)&unk_800000 & *(_DWORD *)(this + 20)) != 0 )
        {
          v4 = *(_DWORD *)(this + 284);
          v5 = *(_DWORD **)(v4 + v3 + 12);
          if ( *(int *)(v4 + v3 + 8) > 0 )
          {
            do
            {
              (*(void (__cdecl **)(int, _DWORD *, _DWORD *, _BYTE *))(*(_DWORD *)dword_8B8F24 + 4))(
                dword_8B8F24,
                v5,
                v20,
                v25);
              (**(void (__cdecl ***)(int, int, _DWORD *, _BYTE *))dword_8B8F24)(dword_8B8F24, (int)(v5 + 7), v21, v25);
              if ( (*(_BYTE *)(*(_DWORD *)(this + 312) + 60) & 0x10) == 0 )
              {
                *v5 = v20[0];
                v5[1] = v20[1];
                v5[2] = v20[2];
                v5[7] = v21[0];
                v5[8] = v21[1];
                v5[9] = v21[2];
              }
              v6 = v5[13];
              v5[14] = v5[12];
              v5[15] = v6;
              v5 += 16;
              ++v17;
            }
            while ( v17 < *(_DWORD *)(*(_DWORD *)(this + 284) + v3 + 8) );
          }
          sub_54B4D0(*(_DWORD *)(this + 312), 0, 0, 0, 0.0, 0.0, 0.0);
        }
        else
        {
          v7 = *(_DWORD *)(this + 284);
          v8 = *(_DWORD **)(v7 + v3 + 12);
          if ( *(int *)(v7 + v3 + 8) > 0 )
          {
            do
            {
              (*(void (__cdecl **)(int, _DWORD *, _DWORD *, _BYTE *))(*(_DWORD *)dword_8B8F24 + 4))(
                dword_8B8F24,
                v8,
                v22,
                v25);
              (**(void (__cdecl ***)(int, int, _DWORD *, _BYTE *))dword_8B8F24)(dword_8B8F24, (int)(v8 + 3), v23, v25);
              if ( (*(_BYTE *)(*(_DWORD *)(this + 312) + 60) & 0x10) == 0 )
              {
                *v8 = v22[0];
                v8[1] = v22[1];
                v8[2] = v22[2];
                v8[3] = v23[0];
                v8[4] = v23[1];
                v8[5] = v23[2];
              }
              v9 = v8[9];
              v8[10] = v8[8];
              v8[11] = v9;
              v8 += 12;
              ++v17;
            }
            while ( v17 < *(_DWORD *)(*(_DWORD *)(this + 284) + v3 + 8) );
          }
        }
        *(_DWORD *)(*(_DWORD *)(this + 284) + v3 + 52) = -1;
        *(_DWORD *)(*(_DWORD *)(this + 284) + v3 + 28) = 0;
        *(_DWORD *)(*(_DWORD *)(this + 284) + v3 + 32) = 0;
        *(_DWORD *)(*(_DWORD *)(this + 284) + v3 + 36) = 0;
        *(_DWORD *)(*(_DWORD *)(this + 284) + v3 + 40) = 0;
        *(_DWORD *)(*(_DWORD *)(this + 284) + v3 + 56) = 0;
        if ( (a2 & 4) != 0 )
        {
          v10 = *(_DWORD *)(*(_DWORD *)(this + 284) + v3 + 4);
          *(_DWORD *)(v10 + 156) |= 0x8000u;
        }
        v3 += 64;
        ++v19;
      }
      while ( v19 < *(_DWORD *)(this + 280) );
    }
    F_3DBoundingBoxExtentsComputation(COERCE_FLOAT(1));
    BoundingBoxComputationFromVertexData(this);
    sub_54D080(0);
    FlagSetLoop(this);
    *(_DWORD *)(this + 268) = 0;
    *(_DWORD *)(this + 264) = 0;
    *(_DWORD *)(this + 260) = 0;
    *(_DWORD *)(this + 256) = 0;
    *(_DWORD *)(this + 276) = 0;
    *(_DWORD *)(this + 272) = 0;
    *(_DWORD *)(this + 268) = 0;
    v11 = (_DWORD *)OperatorNewNhMallocWrapper(452);
    if ( v11 )
    {
      *v11 = 8;
      v18 = v11 + 1;
      v12 = v11 + 1;
      v13 = 8;
      do
      {
        StructZeroInitWithBaseCall(v12);
        v12 += 14;
        --v13;
      }
      while ( v13 );
      v14 = v18;
    }
    else
    {
      v14 = 0;
    }
    *(_DWORD *)(this + 272) = v14;
    v15 = *(_DWORD *)(this + 20) | 0x4000000;
    *(_DWORD *)(this + 264) = 0;
    *(_DWORD *)(this + 260) = 0;
    *(_DWORD *)(this + 256) = 0;
    *(_DWORD *)(this + 20) = v15;
    EmptyStub_b160();
  }
  return 0;
}
