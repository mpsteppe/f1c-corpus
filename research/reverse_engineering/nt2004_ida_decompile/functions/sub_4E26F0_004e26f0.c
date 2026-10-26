int __thiscall sub_4E26F0(float ***this, int a2, char *String2, int a4, char a5)
{
  int v6; // esi
  int v7; // ebx
  int i; // eax
  int v9; // edi
  int v10; // ebx
  const char *v11; // eax
  int v12; // esi
  int v13; // eax
  float *v14; // eax
  float *v15; // esi
  float **v16; // eax
  float **v17; // ecx
  int v19; // [esp+Ch] [ebp-19Ch]
  int v20; // [esp+10h] [ebp-198h]
  int v21; // [esp+14h] [ebp-194h]
  _DWORD v22[100]; // [esp+18h] [ebp-190h] BYREF

  v6 = sub_4E8260(a4);
  v7 = 0;
  v19 = v6;
  v20 = 0;
  if ( v6 > 0 )
  {
    memset(v22, 0, sizeof(v22));
    if ( v6 > 100 )
    {
      v19 = 100;
      v6 = 100;
    }
    if ( !sub_4D1B50(&dword_7D3C50, 0, v6 - 1, (int)v22) )
    {
      for ( i = 0; i < v6; ++i )
        v22[i] = i;
    }
    while ( 1 )
    {
      v9 = 0;
      v21 = 0;
      if ( v6 > 0 )
        break;
LABEL_31:
      if ( !a5 || v7 >= a2 )
        return v7;
    }
    while ( 1 )
    {
      if ( v7 >= a2 )
        goto LABEL_31;
      v10 = sub_4E8590(v22[v9]);
      v11 = *(const char **)v10;
      if ( !*(_DWORD *)v10 )
        v11 = &byte_629120;
      if ( _strcmpi(v11, String2) )
        break;
      if ( a5 )
        goto LABEL_19;
LABEL_30:
      v7 = v20;
      v21 = ++v9;
      if ( v9 >= v6 )
        goto LABEL_31;
    }
    if ( a5 || (v12 = 0, (int)this[3] <= 0) )
    {
LABEL_19:
      v14 = (float *)operator new(8u);
      v15 = 0;
      if ( v14 )
      {
        v14[1] = 0.0;
        *v14 = NAN;
        v15 = v14;
      }
      *(_DWORD *)v15 = sub_4E8600(v22[v9]);
      v15[1] = sub_4E2480((char *)(v10 + 246));
      v16 = (float **)operator new(0xCu);
      if ( v16 )
      {
        *v16 = v15;
        v16[1] = 0;
        *((_BYTE *)v16 + 8) = 1;
      }
      else
      {
        v16 = 0;
      }
      if ( *this )
      {
        this[1][1] = (float *)v16;
      }
      else
      {
        *this = v16;
        this[2] = v16;
      }
      v17 = this[3];
      this[1] = v16;
      this[3] = (float **)((char *)v17 + 1);
      ++v20;
    }
    else
    {
      while ( 1 )
      {
        v13 = sub_4E28F0(v12);
        if ( !_strcmpi((const char *)(v10 + 246), (const char *)(v13 + 246)) )
          break;
        if ( ++v12 >= (int)this[3] )
        {
          v9 = v21;
          goto LABEL_19;
        }
      }
      v9 = v21;
    }
    v6 = v19;
    goto LABEL_30;
  }
  return v7;
}
