char __thiscall sub_4A7120(_DWORD *this, int a2, int a3, int a4, float a5)
{
  char result; // al
  int v7; // ebp
  int v8; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // edi
  int v14; // ebp
  int *v15; // edx
  int v16; // edx
  char *v17; // eax
  int v18; // eax
  CHAR *v19; // ecx
  CHAR *v20; // eax
  CHAR *v21; // eax
  int v22; // [esp+4h] [ebp-4h]
  float v23; // [esp+4h] [ebp-4h]
  float v24; // [esp+10h] [ebp+8h]
  float v25; // [esp+14h] [ebp+Ch]
  float v26; // [esp+18h] [ebp+10h]

  result = a2;
  if ( a2 )
  {
    v7 = *(_DWORD *)(a2 + 40);
    v8 = this[76] + this[74];
    v22 = v7;
    v9 = a3;
    if ( LOBYTE(a5) )
      v9 = a3 - v8 * ((v7 - 1) / 2);
    v10 = v9 + v8 * v7;
    if ( v10 > 800 )
      v9 -= v8 * ((v10 - 800) / v8 + 1);
    v11 = this[3];
    if ( v9 < v11 )
    {
      v12 = (v11 - v9) / v8;
      if ( v12 >= 1 )
      {
        if ( v12 > 99 )
          v12 = 99;
      }
      else
      {
        v12 = 1;
      }
      v9 += v8 * v12;
    }
    v13 = 0;
    if ( v7 > 0 )
    {
      do
      {
        v14 = v13;
        if ( v13 >= 0 && v13 < *(_DWORD *)(a2 + 40) )
        {
          v15 = *(int **)(a2 + 28);
          if ( v13 <= 0 )
          {
LABEL_18:
            if ( v15 )
            {
              v16 = *v15;
              goto LABEL_21;
            }
          }
          else
          {
            while ( v15 )
            {
              v15 = (int *)v15[1];
              if ( --v14 <= 0 )
                goto LABEL_18;
            }
          }
        }
        v16 = 0;
LABEL_21:
        sub_4A7120(v16, v9 + v13 * (this[76] + this[74]), a4 + this[77] + this[75], COERCE_FLOAT(1));
        ++v13;
      }
      while ( v13 < v22 );
    }
    result = LOBYTE(a5);
    if ( LOBYTE(a5) )
    {
      v23 = (double)a3 * 0.00125;
      v25 = (double)a4 * 0.0016666667;
      v24 = (double)(int)this[74] * 0.00125;
      v26 = (double)(int)this[75] * 0.0016666667;
      v17 = sub_49C9C0(this);
      v18 = sub_4AD420(v17);
      if ( v18 )
      {
        v19 = (CHAR *)this[72];
        if ( !v19 )
          v19 = &byte_629120;
        v20 = *(CHAR **)(v18 + 8);
        if ( !v20 )
          v20 = &byte_629120;
        return sub_506C20((int)v20, this[78], (int)v19, v23, v25, 0.0, v24, v26, 0, 0);
      }
      else
      {
        v21 = (CHAR *)this[72];
        if ( !v21 )
          v21 = &byte_629120;
        return sub_506C20(0, this[78], (int)v21, v23, v25, 0.0, v24, v26, 0, 0);
      }
    }
  }
  return result;
}
