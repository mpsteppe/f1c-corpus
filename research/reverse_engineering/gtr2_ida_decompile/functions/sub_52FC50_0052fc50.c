char __thiscall sub_52FC50(float *this, float *a2)
{
  unsigned __int64 v2; // rax
  int v3; // edi
  unsigned __int64 v4; // rax
  int v5; // esi
  unsigned __int64 v6; // rax
  int v7; // ebx
  unsigned __int64 v8; // rax
  int v9; // ecx
  float *v10; // edi
  int v11; // esi
  bool v12; // zf
  char result; // al
  char v14; // [esp+Bh] [ebp-Dh]
  float *v15; // [esp+Ch] [ebp-Ch]
  int v17; // [esp+14h] [ebp-4h]
  int v18; // [esp+1Ch] [ebp+4h]

  v14 = 0;
  v2 = (unsigned __int64)((a2[4] - a2[7] - this[585]) * this[586]);
  v3 = v2;
  if ( (v2 & 0x80000000) == 0LL )
  {
    if ( (int)v2 < 8 )
      goto LABEL_6;
    v3 = 7;
  }
  else
  {
    v3 = 0;
  }
  v14 = 1;
LABEL_6:
  v4 = (unsigned __int64)((a2[7] + a2[4] - this[585]) * this[586]);
  v5 = v4;
  if ( (v4 & 0x80000000) == 0LL )
  {
    if ( (int)v4 < 8 )
      goto LABEL_11;
    v5 = 7;
  }
  else
  {
    v5 = 0;
  }
  v14 = 1;
LABEL_11:
  v6 = (unsigned __int64)((a2[6] - a2[7] - this[587]) * this[588]);
  v7 = v6;
  if ( (v6 & 0x80000000) == 0LL )
  {
    if ( (int)v6 < 8 )
      goto LABEL_16;
    v7 = 7;
  }
  else
  {
    v7 = 0;
  }
  v14 = 1;
LABEL_16:
  v8 = (unsigned __int64)((a2[6] + a2[7] - this[587]) * this[588]);
  v9 = v8;
  v18 = (unsigned __int64)((a2[6] + a2[7] - this[587]) * this[588]);
  if ( (v8 & 0x80000000) == 0LL )
  {
    if ( (int)v8 < 8 )
      goto LABEL_21;
    v18 = 7;
  }
  else
  {
    v18 = 0;
  }
  v9 = v18;
  v14 = 1;
LABEL_21:
  if ( v3 <= v5 )
  {
    v15 = &this[72 * v3 + 9 * v7];
    v17 = v5 - v3 + 1;
    do
    {
      if ( v7 <= v9 )
      {
        v10 = v15;
        v11 = v9 - v7 + 1;
        do
        {
          sub_52F2E0();
          v10 += 9;
          --v11;
        }
        while ( v11 );
        v9 = v18;
      }
      v12 = v17 == 1;
      v15 += 72;
      --v17;
    }
    while ( !v12 );
  }
  result = v14;
  if ( v14 )
    return sub_52F2E0();
  return result;
}
