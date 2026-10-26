char __thiscall sub_610E20(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // esi
  _DWORD *v4; // edi
  int v5; // ebp
  int v6; // eax
  int v7; // ebx
  _DWORD *v8; // edi
  int v9; // esi
  float v11; // [esp+10h] [ebp-130h]
  _DWORD *v12; // [esp+24h] [ebp-11Ch]
  int *v14; // [esp+2Ch] [ebp-114h]
  int v15; // [esp+30h] [ebp-110h]
  _BYTE v16[8]; // [esp+34h] [ebp-10Ch] BYREF
  _BYTE v17[236]; // [esp+3Ch] [ebp-104h] BYREF
  int v18; // [esp+128h] [ebp-18h]
  int v19; // [esp+12Ch] [ebp-14h]
  int v20; // [esp+13Ch] [ebp-4h]

  v3 = a2;
  v4 = this;
  v5 = sub_5E8220(a2, a2[63]);
  v6 = sub_5E82A0(v3, v3[63]);
  v7 = 0;
  v15 = v5 + v6;
  v12 = v4 + 705;
  if ( v5 < v5 + v6 )
  {
    v8 = v4 + 193;
    while ( 1 )
    {
      v14 = (int *)sub_5E3450(v3, a3, v7);
      v9 = sub_5E80D0(v3, v5);
      if ( (*(int (__thiscall **)(_DWORD *, int *))(*this + 328))(this, v14) )
        sub_60A820(v12, v14);
      if ( !this[2412] )
      {
        sub_610DF0(v9, v16);
        v20 = 0;
        sub_609BF0(v18);
        sub_60A000(v19);
        sub_60A360(v8, v7);
        v20 = 1;
        `eh vector destructor iterator'(v17, 0x18u, 8, nullsub_7);
        v20 = -1;
        nullsub_7(v16);
      }
      if ( v9 )
      {
        sub_60A500(*(_DWORD *)(v9 + 136));
        v11 = *((float *)this + 1214) + *(float *)(v9 + 132);
        sub_60A580((int)v12, v11);
        sub_60A3A0(v12, *(_DWORD *)(v9 + 140));
        sub_60A3F0(v12, *(_DWORD *)(v9 + 144));
        sub_60A440(v12, *(_DWORD *)(v9 + 148));
        sub_60A490((int)v12, *(_BYTE *)(v9 + 128));
      }
      ++v5;
      ++v7;
      v8 += 64;
      v12 += 62;
      if ( v5 >= v15 )
        break;
      v3 = a2;
    }
    v4 = this;
  }
  return sub_60A790(&v4[64 * v7 + 193]);
}
