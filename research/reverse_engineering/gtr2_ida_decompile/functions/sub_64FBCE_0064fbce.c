float *__thiscall sub_64FBCE(float *this, float *a2, unsigned int a3, int a4)
{
  void *v6; // eax
  int v7; // eax
  BOOL v8; // eax
  bool v9; // zf
  unsigned int v10; // ecx
  int v11; // ecx
  int v12; // esi
  int v13; // edi
  int v14; // eax
  int v15; // edi
  int v16; // esi
  int v17; // edi
  int v18; // ecx
  int v19; // esi
  void *v20; // eax
  void *v21; // edi
  float v23; // [esp+Ch] [ebp-14h]
  float v24; // [esp+10h] [ebp-10h]
  float v25; // [esp+14h] [ebp-Ch]
  float v26; // [esp+18h] [ebp-8h]
  unsigned int v27; // [esp+28h] [ebp+8h]

  *(_DWORD *)this = &off_7374D0;
  this[8] = *a2;
  this[1] = a2[1];
  this[24] = a2[2];
  this[25] = a2[3];
  qmemcpy(this + 15, a2 + 10, 0x18u);
  v6 = &unk_9143C8;
  if ( !*((_DWORD *)a2 + 16) )
    v6 = &unk_914348;
  *((_DWORD *)this + 13) = v6;
  v27 = a3 >> 3;
  *((_DWORD *)this + 30) = a3 >> 3;
  this[21] = 0.0;
  this[22] = 0.0;
  *((_DWORD *)this + 3) = a3 != 0;
  *((_DWORD *)this + 2) = a4;
  this[6] = a2[19];
  v7 = *((_DWORD *)this + 1);
  v8 = v7 == 41 || v7 == 40;
  v9 = *((_DWORD *)this + 6) == 0;
  *((_DWORD *)this + 7) = v8;
  this[14] = 0.0;
  this[4] = a2[18];
  this[5] = 0.0;
  this[23] = 0.0;
  if ( !v9 )
  {
    v10 = *((_DWORD *)a2 + 19);
    v23 = (double)BYTE2(v10) * 0.0039215689;
    v24 = (double)BYTE1(v10) * 0.0039215689;
    v25 = (double)(unsigned __int8)v10 * 0.0039215689;
    v26 = (double)HIBYTE(v10) * 0.0039215689;
    this[9] = v23;
    this[10] = v24;
    this[11] = v25;
    this[12] = v26;
  }
  if ( a4 == 2 )
  {
    if ( *((_DWORD *)this + 1) == 61 )
      goto LABEL_14;
    this[4] = 0.0;
  }
  if ( a4 == 3 )
    this[4] = 0.0;
LABEL_14:
  v11 = *((_DWORD *)this + 15);
  v12 = *((_DWORD *)this + 16);
  v13 = *((_DWORD *)this + 18);
  v14 = *((_DWORD *)this + 17) - v11;
  *((_DWORD *)this + 26) = v14;
  v15 = v13 - v12;
  v16 = *((_DWORD *)this + 19);
  *((_DWORD *)this + 27) = v15;
  v17 = *((_DWORD *)this + 20);
  *((_DWORD *)this + 29) = v27 * v14;
  *((_DWORD *)this + 28) = v17 - v16;
  if ( a3 )
  {
    *((_DWORD *)this + 8) += v16 * *((_DWORD *)this + 25) + *((_DWORD *)this + 16) * *((_DWORD *)this + 24) + v27 * v11;
    this[17] = this[26];
    this[18] = this[27];
    v18 = *((_DWORD *)this + 28);
    this[15] = 0.0;
    this[16] = 0.0;
    this[19] = 0.0;
    *((_DWORD *)this + 20) = v18;
  }
  if ( *((_DWORD *)a2 + 17) )
  {
    v19 = *((_DWORD *)this + 26) + 2;
    v20 = operator new(16 * v19);
    v21 = v20;
    if ( v20 )
      sub_41D1B0((int)v20, 16, v19, (int)sub_681563);
    else
      v21 = 0;
    *((_DWORD *)this + 23) = v21;
    if ( v21 )
      memset(v21, 0, 16 * (*((_DWORD *)this + 26) + 2));
  }
  return this;
}
