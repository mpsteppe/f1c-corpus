float *__thiscall sub_54429C(float *this, float *a2, unsigned int a3, int a4)
{
  unsigned int v5; // esi
  void *v6; // ecx
  int v7; // ecx
  unsigned int v8; // ecx
  int v9; // ecx
  float *v10; // ecx
  float *v11; // eax
  int v12; // ecx
  int v13; // ecx
  int v14; // eax
  int v15; // edi
  int v16; // eax
  int v17; // esi
  int v18; // ecx
  bool v19; // zf
  int v20; // eax
  float v22; // [esp+Ch] [ebp-10h]
  float v23; // [esp+10h] [ebp-Ch]
  float v24; // [esp+14h] [ebp-8h]
  float v25; // [esp+18h] [ebp-4h]
  int v26; // [esp+28h] [ebp+Ch]

  *(_DWORD *)this = &off_5F3110;
  sub_53D688((int)(this + 12), 16, 256, (int (__thiscall *)(int))sub_53D5B2);
  this[6] = *a2;
  this[1] = a2[1];
  this[1044] = a2[2];
  this[1045] = a2[3];
  qmemcpy(this + 1036, a2 + 10, 0x18u);
  v5 = 0;
  v6 = &unk_6173C8;
  if ( !*((_DWORD *)a2 + 16) )
    v6 = &unk_617348;
  *((_DWORD *)this + 11) = v6;
  *((_DWORD *)this + 1050) = a3 >> 3;
  this[1042] = 0.0;
  this[1043] = 0.0;
  *((_DWORD *)this + 3) = a3 != 0;
  *((_DWORD *)this + 2) = a4;
  v7 = *((_DWORD *)a2 + 17);
  *((_DWORD *)this + 4) = v7;
  if ( v7 )
  {
    v8 = *((_DWORD *)a2 + 17);
    v22 = (double)BYTE2(v8) * 0.0039215689;
    v23 = (double)BYTE1(v8) * 0.0039215689;
    v24 = (double)(unsigned __int8)v8 * 0.0039215689;
    v25 = (double)HIBYTE(v8) * 0.0039215689;
    this[7] = v22;
    this[8] = v23;
    this[9] = v24;
    this[10] = v25;
    v5 = 0;
  }
  v9 = *((_DWORD *)this + 1);
  if ( v9 == 41 || v9 == 40 )
  {
    *((_DWORD *)this + 5) = 1;
    if ( *((_DWORD *)a2 + 18) )
    {
      v10 = this + 13;
      do
      {
        v26 = *(unsigned __int8 *)(v5 + *((_DWORD *)a2 + 18));
        v5 += 4;
        *(v10 - 1) = (double)v26 * 0.0039215689;
        *v10 = (double)*(unsigned __int8 *)(v5 + *((_DWORD *)a2 + 18) - 3) * 0.0039215689;
        v10 += 4;
        *(v10 - 3) = (double)*(unsigned __int8 *)(v5 + *((_DWORD *)a2 + 18) - 2) * 0.0039215689;
        *(v10 - 2) = (double)*(unsigned __int8 *)(v5 + *((_DWORD *)a2 + 18) - 1) * 0.0039215689;
      }
      while ( v5 < 0x400 );
    }
    else
    {
      v11 = this + 14;
      v12 = 256;
      do
      {
        v11[1] = 1.0;
        *v11 = 1.0;
        v11 += 4;
        --v12;
        *(v11 - 5) = 1.0;
        *(v11 - 6) = 1.0;
      }
      while ( v12 );
    }
  }
  else
  {
    this[5] = 0.0;
  }
  v13 = *((_DWORD *)this + 1038);
  v14 = *((_DWORD *)this + 1040);
  *((_DWORD *)this + 1047) = *((_DWORD *)this + 1039) - *((_DWORD *)this + 1037);
  v15 = *((_DWORD *)this + 1041) - v14;
  v16 = *((_DWORD *)this + 1050);
  v17 = *((_DWORD *)this + 1036);
  v18 = v13 - v17;
  *((_DWORD *)this + 1048) = v15;
  *((_DWORD *)this + 1046) = v18;
  v19 = *((_DWORD *)this + 3) == 0;
  *((_DWORD *)this + 1049) = v18 * v16;
  if ( !v19 )
  {
    *((_DWORD *)this + 6) += *((_DWORD *)this + 1040) * *((_DWORD *)this + 1045)
                           + *((_DWORD *)this + 1037) * *((_DWORD *)this + 1044)
                           + v17 * v16;
    this[1038] = this[1046];
    this[1039] = this[1047];
    v20 = *((_DWORD *)this + 1048);
    this[1036] = 0.0;
    this[1037] = 0.0;
    this[1040] = 0.0;
    *((_DWORD *)this + 1041) = v20;
  }
  return this;
}
