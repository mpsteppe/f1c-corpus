int __thiscall sub_4181C0(_DWORD *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // edi
  int v5; // ebx
  int v6; // edi
  int v7; // ebx
  int v8; // edi
  int v9; // ebx
  char *v10; // eax
  int v11; // edi
  int v12; // ebx
  char *v13; // eax
  char v14; // cl
  int result; // eax
  int v16; // edi
  int v17; // ebx
  int v18; // eax
  int v19; // edx
  int v20; // ecx
  int *v21; // eax
  float v22; // [esp+0h] [ebp-10h]
  float v23; // [esp+0h] [ebp-10h]
  float v24; // [esp+0h] [ebp-10h]
  float v25; // [esp+0h] [ebp-10h]
  float v26; // [esp+0h] [ebp-10h]
  float v27; // [esp+0h] [ebp-10h]

  v2 = 0;
  if ( (int)this[9] > 0 )
  {
    v3 = 0;
    do
    {
      v22 = dbl_7DA9D0;
      sub_416400((_DWORD *)(v3 + this[10]), v22);
      ++v2;
      v3 += 40;
    }
    while ( v2 < this[9] );
  }
  v4 = 0;
  if ( (int)this[12] > 0 )
  {
    v5 = 0;
    do
    {
      v23 = dbl_7DA9D0;
      sub_416400((_DWORD *)(v5 + this[13]), v23);
      ++v4;
      v5 += 40;
    }
    while ( v4 < this[12] );
  }
  v6 = 0;
  if ( (int)this[15] > 0 )
  {
    v7 = 0;
    do
    {
      v24 = dbl_7DA9D0;
      sub_416400((_DWORD *)(v7 + this[16]), v24);
      ++v6;
      v7 += 40;
    }
    while ( v6 < this[15] );
  }
  v8 = 0;
  if ( (int)this[18] > 0 )
  {
    v9 = 0;
    do
    {
      if ( v9 >= 7840
        || (v10 = (char *)&unk_62BF68 + 25304 * (v8 / 4), *((_DWORD *)v10 + 4146) == -1)
        || !v10[304 * (v8 % 4) + 2296] )
      {
        v25 = dbl_7DA9D0;
        sub_416400((_DWORD *)(v9 + this[19]), v25);
      }
      ++v8;
      v9 += 40;
    }
    while ( v8 < this[18] );
  }
  v11 = 0;
  if ( (int)this[21] > 0 )
  {
    v12 = 0;
    while ( v12 < 3920 )
    {
      v13 = (char *)&unk_62BF68 + 25304 * (v11 / 2);
      if ( v11 % 2 )
      {
        if ( !*((_DWORD *)v13 + 879) )
          break;
        v14 = v13[3580];
      }
      else
      {
        if ( !*((_DWORD *)v13 + 862) )
          break;
        v14 = v13[3512];
      }
      if ( !v14 )
        break;
LABEL_27:
      ++v11;
      v12 += 40;
      if ( v11 >= this[21] )
        goto LABEL_28;
    }
    v26 = dbl_7DA9D0;
    sub_416400((_DWORD *)(v12 + this[22]), v26);
    goto LABEL_27;
  }
LABEL_28:
  result = this[24];
  v16 = 0;
  if ( result > 0 )
  {
    v17 = 0;
    do
    {
      if ( v17 >= 23520
        || (v18 = 6326 * (v16 / 12),
            v19 = 17 * (v16 % 12),
            v20 = dword_62CD68[v18 + v19],
            v21 = &dword_62CD68[v18 + v19],
            !v20)
        || !*((_BYTE *)v21 + 64) )
      {
        v27 = dbl_7DA9D0;
        sub_416400((_DWORD *)(v17 + this[25]), v27);
      }
      result = this[24];
      ++v16;
      v17 += 40;
    }
    while ( v16 < result );
  }
  return result;
}
