char __thiscall sub_4E09C0(float *this, float *a2)
{
  __int64 v3; // rax
  int v4; // edi
  __int64 v5; // rax
  int v6; // esi
  __int64 v7; // rax
  int v8; // ebx
  __int64 v9; // rax
  int v10; // ecx
  int v11; // edi
  int v12; // esi
  bool v13; // zf
  char result; // al
  char v15; // [esp+Bh] [ebp-Dh]
  float *v16; // [esp+Ch] [ebp-Ch]
  int v18; // [esp+14h] [ebp-4h]
  int v19; // [esp+1Ch] [ebp+4h]

  v15 = 0;
  v3 = (__int64)((a2[4] - a2[7] - this[585]) * this[586]);
  v4 = v3;
  if ( (int)v3 >= 0 )
  {
    if ( (int)v3 < 8 )
      goto LABEL_6;
    v4 = 7;
  }
  else
  {
    v4 = 0;
  }
  v15 = 1;
LABEL_6:
  v5 = (__int64)((a2[7] + a2[4] - this[585]) * this[586]);
  v6 = v5;
  if ( (int)v5 >= 0 )
  {
    if ( (int)v5 < 8 )
      goto LABEL_11;
    v6 = 7;
  }
  else
  {
    v6 = 0;
  }
  v15 = 1;
LABEL_11:
  v7 = (__int64)((a2[6] - a2[7] - this[587]) * this[588]);
  v8 = v7;
  if ( (int)v7 >= 0 )
  {
    if ( (int)v7 < 8 )
      goto LABEL_16;
    v8 = 7;
  }
  else
  {
    v8 = 0;
  }
  v15 = 1;
LABEL_16:
  v9 = (__int64)((a2[7] + a2[6] - this[587]) * this[588]);
  v10 = v9;
  v19 = (__int64)((a2[7] + a2[6] - this[587]) * this[588]);
  if ( (int)v9 >= 0 )
  {
    if ( (int)v9 < 8 )
      goto LABEL_21;
    v19 = 7;
  }
  else
  {
    v19 = 0;
  }
  v10 = v19;
  v15 = 1;
LABEL_21:
  if ( v4 <= v6 )
  {
    v16 = &this[72 * v4 + 9 * v8];
    v18 = v6 - v4 + 1;
    do
    {
      if ( v8 <= v10 )
      {
        v11 = (int)v16;
        v12 = v10 - v8 + 1;
        do
        {
          sub_4E01A0(v11, (int)a2);
          v11 += 36;
          --v12;
        }
        while ( v12 );
        v10 = v19;
      }
      v13 = v18 == 1;
      v16 += 72;
      --v18;
    }
    while ( !v13 );
  }
  result = v15;
  if ( v15 )
    return sub_4E01A0((int)(this + 576), (int)a2);
  return result;
}
