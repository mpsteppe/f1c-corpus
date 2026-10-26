// Address: 0x0045af50
// Size: 255 bytes
// Name: sub_45AF50
// Type: int __thiscall(int this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_45AF50(int this)
{
  double v2; // st7
  double v3; // st6
  int v4; // ecx
  double v5; // st6
  _DWORD *v6; // eax
  int v7; // edi
  int v8; // ebx
  char *v9; // eax
  _DWORD *v10; // ecx
  int v11; // ebp
  float v13; // [esp+Ch] [ebp-144h]
  double v14; // [esp+10h] [ebp-140h]
  float v15[6]; // [esp+18h] [ebp-138h] BYREF
  _BYTE v16[4]; // [esp+30h] [ebp-120h] BYREF
  char v17; // [esp+34h] [ebp-11Ch] BYREF

  v14 = *(double *)(this + 384) / *(double *)(this + 40);
  sub_4DD550(v15);
  v2 = (v15[0] - v15[3]) * 0.5 + v14;
  *(double *)(this + 792) = v2;
  v3 = v15[1] - v15[4];
  v13 = v15[2] - v15[5];
  if ( v3 <= v13 )
    v3 = v13;
  *(_DWORD *)(this + 80) = 9;
  v4 = 0;
  v5 = v3 * 0.5 + v14;
  v6 = (_DWORD *)(this + 92);
  *(double *)(this + 800) = v5;
  *(float *)(this + 204) = sqrt(v5 * v5 + v2 * v2);
  do
  {
    *(v6 - 2) = 0;
    *(v6 - 1) = 0;
    *v6 = 0;
    v7 = *(_DWORD *)(this + 80);
    ++v4;
    v6 += 3;
  }
  while ( v4 < v7 );
  v8 = *(_DWORD *)(this + 80);
  if ( v7 > 0 )
  {
    v9 = &v17;
    v10 = (_DWORD *)(this + 88);
    do
    {
      *((_DWORD *)v9 + 2) = *(v10 - 1);
      *((_DWORD *)v9 + 3) = *v10;
      v11 = v10[1];
      *((_DWORD *)v9 - 1) = 0;
      *(_DWORD *)v9 = 0;
      *((_DWORD *)v9 + 1) = 0;
      *((_DWORD *)v9 + 4) = v11;
      v10 += 3;
      v9 += 32;
      --v7;
    }
    while ( v7 );
  }
  return sub_54F830(v16, v8);
}
