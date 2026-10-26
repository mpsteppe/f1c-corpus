int __thiscall sub_417230(_DWORD *this)
{
  int v2; // edi
  int v3; // ebx
  int result; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // edi
  int v8; // ebx
  int v9; // edi
  int v10; // ebx
  char *v11; // eax
  int v12; // edi
  int v13; // ebx
  char *v14; // eax
  char v15; // cl
  int v16; // edi
  int v17; // ebx
  int *v18; // eax
  float v19; // [esp+8h] [ebp-10h]
  float v20; // [esp+8h] [ebp-10h]
  float v21; // [esp+8h] [ebp-10h]
  float v22; // [esp+8h] [ebp-10h]
  float v23; // [esp+8h] [ebp-10h]
  float v24; // [esp+8h] [ebp-10h]

  v2 = 0;
  if ( (int)this[9] > 0 )
  {
    v3 = 0;
    do
    {
      v19 = dbl_FB1D18;
      sub_416370((_DWORD *)(v3 + this[10]), v19);
      ++v2;
      v3 += 40;
    }
    while ( v2 < this[9] );
  }
  if ( (int)this[12] > 0 )
    return off_16C93BC();
  v5 = 0;
  if ( (int)this[15] > 0 )
  {
    v6 = 0;
    do
    {
      v20 = dbl_FB1D18;
      sub_416370((_DWORD *)(v6 + this[16]), v20);
      ++v5;
      v6 += 40;
    }
    while ( v5 < this[15] );
  }
  v7 = 0;
  if ( (int)this[27] > 0 )
  {
    v8 = 0;
    do
    {
      v21 = dbl_FB1D18;
      sub_416370((_DWORD *)(v8 + this[28]), v21);
      ++v7;
      v8 += 40;
    }
    while ( v7 < this[27] );
  }
  v9 = 0;
  if ( (int)this[18] > 0 )
  {
    v10 = 0;
    do
    {
      if ( v10 >= 16800
        || (v11 = (char *)&unk_9204A0 + 22616 * (v9 / 4), *((_DWORD *)v11 + 3705) == -1)
        || !v11[296 * (v9 % 4) + 3232] )
      {
        v22 = dbl_FB1D18;
        sub_416370((_DWORD *)(v10 + this[19]), v22);
      }
      ++v9;
      v10 += 40;
    }
    while ( v9 < this[18] );
  }
  v12 = 0;
  if ( (int)this[21] > 0 )
  {
    v13 = 0;
    while ( v13 < 8400 )
    {
      v14 = (char *)&unk_9204A0 + 22616 * (v12 / 2);
      if ( v12 % 2 )
      {
        if ( !*((_DWORD *)v14 + 1105) )
          break;
        v15 = v14[4484];
      }
      else
      {
        if ( !*((_DWORD *)v14 + 1088) )
          break;
        v15 = v14[4416];
      }
      if ( !v15 )
        break;
LABEL_29:
      ++v12;
      v13 += 40;
      if ( v12 >= this[21] )
        goto LABEL_30;
    }
    v23 = dbl_FB1D18;
    sub_416370((_DWORD *)(v13 + this[22]), v23);
    goto LABEL_29;
  }
LABEL_30:
  result = this[24];
  v16 = 0;
  if ( result > 0 )
  {
    v17 = 0;
    do
    {
      if ( v17 >= 33600 || (v18 = &dword_921628[5654 * (v16 / 8) + 17 * (v16 % 8)], !*v18) || !*((_BYTE *)v18 + 64) )
      {
        v24 = dbl_FB1D18;
        sub_416370((_DWORD *)(v17 + this[25]), v24);
      }
      result = this[24];
      ++v16;
      v17 += 40;
    }
    while ( v16 < result );
  }
  return result;
}
